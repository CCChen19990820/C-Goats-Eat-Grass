#include <iostream>

#include "Creature.h"
#include "Goat.h"
using namespace std;
Goat::Goat():Creature(true,70,'X'){
	startTime=50;
	endTime=55;
	energy=20;
}

void Goat::daily(){
	if((age>=startTime)&&(age<=endTime)){
		baby();
	}
	else{
		Move();
	}
	LoseEnergy();
}

void Goat::Move(){
	if((*son)!=NULL && (*son)->getcrop()=='I'){
		EatGrass();
	}
	if(*son==NULL){
		(*son)=this;
		//(*son)->setfinish(false);
		setEmpty(false);
	}

}

bool Goat::die(){
	if((age==limitage)||(energy==0)){
		return false;
	}
	return true;
}

void Goat::baby(){
	if((*son)!=NULL && (*son)->getcrop()=='I'){
		EatGrass();
	}
	if((*son)==NULL){
		(*son)=new Goat();
		(*son)->setfinish(false);
	}
	setEmpty(true);
}

void Goat::EatGrass(){
	delete *son;
	(*son)=NULL;
	energy+=5;
}

void Goat::LoseEnergy(){
	energy--;
}

