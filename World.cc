#include <iostream>
#include <stdlib.h>
#include "World.h"
#include "Creature.h"
#include "Goat.h"
#include "Grass.h"
#include "RandomNum.h"

using namespace std;

/*** reset the world location*/
World::World(int round, int seed):randomnum(seed){
	for(int i=0;i<map_y;i++){
		for(int j=0;j<map_x;j++){
			farm[i][j]=NULL;
		}
	}
	nowpass=1; //the day of farm. 
	totalpass=round; //Num of days the farm need to pass.
}

World::World(){}
World::~World(){}

/*** Run the farm for totalpass days.*/
void World::mainLoop(int display){
	initialize();
	while(nowpass <= totalpass){
		for(int y=0;y<map_y;y++){
			for(int x=0;x<map_x;x++){
				if(farm[y][x] != NULL && farm[y][x]->getfinish() == true){
					// location has creature and died today, nedd to be removed.
					if(farm[y][x]->die() == false){
						delete farm[y][x];
						farm[y][x] = NULL;
						continue;
					}
					if(farm[y][x]->die() == true && farm[y][x]->getfinish() == true){
						//location has creature and died today, can refresh now.
						int direct=randomnum.getRandomNum(0,3);
						int corner_y = y + direction[0][direct];
						int corner_x = x + direction[1][direct];
						if((corner_x >= 0) && (corner_x < map_x) && (corner_y>=0) && (corner_y < map_y)){
							farm[y][x]->setSon(&farm[corner_y][corner_x]);
							farm[y][x]->daily();
						}
						farm[y][x]->getorder();
						farm[y][x]->setfinish(false);
						if(farm[y][x]->getEmpty() == false){
							farm[y][x]=NULL;
						}
					}
				}
			}
		}
		if(nowpass % display == 0)
			show(); //show farm every display days.
		nowpass++;
		newpass(); // refresh a new day parameters.
	}
}

/*** initialize the world and random generate goat and grass.*/
void World::initialize(){
	int temp_x, temp_y;
	for(int i=0;i<initialGoat;){
		temp_y = randomnum.getRandomNum(0,map_y);
		temp_x = randomnum.getRandomNum(0,map_x);
		if(farm[temp_y][temp_x] == NULL){
			farm[temp_y][temp_x] = new Goat();
			i++;
		}
	}
	for(int i=0;i<initialGrass;){
		temp_y = randomnum.getRandomNum(0,map_y);
		temp_x = randomnum.getRandomNum(0,map_x);
		if(farm[temp_y][temp_x] == NULL){
			farm[temp_y][temp_x] = new Grass();
			i++;
		}
	}
}

/*** refresh the world location parameters for a new day.*/
void World::newpass(){
	for(int i=0;i<map_y;i++){
		for(int j=0;j<map_x;j++){
			if(farm[i][j] != NULL){
				farm[i][j]->setfinish(true);
				farm[i][j]->setEmpty(true);
			}
		}
	}	
}

/*** show world farm. */
void World::show(){
	cout<<"  0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4"<<endl;
	for(int i=0;i<map_y;i++){
		cout<<i % 10;
		for(int j=0;j<map_x;j++){
			if(farm[i][j] == NULL)
				cout<<"  ";
			else
				cout<<" "<<farm[i][j]->getcrop();
		}
		cout<<"\n";
	}
	cout<<"-----------------------------------------------------------------------"<<endl;
}
