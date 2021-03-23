#include <iostream>
#include <stdlib.h>
#include "World.h"
#include "Creature.h"
#include "Goat.h"
#include "Grass.h"
#include "RandomNum.h"

using namespace std;

World::World(int round, int seed):randomnum(seed){
	for(int i=0;i<map_y;i++){
		for(int j=0;j<map_x;j++){
			farm[i][j]=NULL;
		}
	}
	nowpass=1;
	totalpass=round;
}

World::World(){}

World::~World(){}

void World::mainLoop(int display){
	initialize();
	while(nowpass<=totalpass){
		for(int y=0;y<map_y;y++){
			for(int x=0;x<map_x;x++){
				if(farm[y][x]!=NULL && farm[y][x]->getfinish()==true){
					if(farm[y][x]->die()==false){
						delete farm[y][x];
						farm[y][x]=NULL;
						continue;
					}
					if(farm[y][x]->die()==true&&farm[y][x]->getfinish()==true){
						int direct=randomnum.getRandomNum(0,3);
						int corner_y=y+direction[0][direct];
						int corner_x=x+direction[1][direct];
						if((corner_x>=0)&&(corner_x<map_x)&&(corner_y>=0)&&(corner_y<map_y)){
							farm[y][x]->setSon(&farm[corner_y][corner_x]);
							farm[y][x]->daily();
						}
						farm[y][x]->getorder();
						farm[y][x]->setfinish(false);
						if(farm[y][x]->getEmpty()==false){
							farm[y][x]=NULL;
						}
					}
				}
			}
		}
		if(nowpass%display==0)
			show();
		nowpass++;
		newpass();
	}
}

void World::initialize(){
	int temp_x,temp_y;
	for(int i=0;i<initialGoat;){
		temp_y=randomnum.getRandomNum(0,map_y);
		temp_x=randomnum.getRandomNum(0,map_x);
		if(farm[temp_y][temp_x]==NULL){
			farm[temp_y][temp_x]=new Goat();
			i++;
		}
	}
	for(int i=0;i<initialGrass;){
		temp_y=randomnum.getRandomNum(0,map_y);
		temp_x=randomnum.getRandomNum(0,map_x);
		if(farm[temp_y][temp_x]==NULL){
			farm[temp_y][temp_x]=new Grass();
			i++;
		}
	}
}

void World::newpass(){
	for(int i=0;i<map_y;i++){
		for(int j=0;j<map_x;j++){
			if(farm[i][j]!=NULL){
				farm[i][j]->setfinish(true);
				farm[i][j]->setEmpty(true);
			}
		}
	}	
}
void World::show(){
	//cout<<nowpass<<endl;
	cout<<"  0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4"<<endl;
	for(int i=0;i<map_y;i++){
		cout<<i%10;
		for(int j=0;j<map_x;j++){
			if(farm[i][j]==NULL)
				cout<<"  ";
			else
				cout<<" "<<farm[i][j]->getcrop();
		}
		cout<<"\n";
	}
	cout<<"-----------------------------------------------------------------------"<<endl;
}
