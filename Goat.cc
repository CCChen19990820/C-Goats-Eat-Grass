#include <iostream>

#include "Creature.h"
#include "Goat.h"
using namespace std;

/*** initial goat*/
Goat::Goat():Creature(true,70,'X'){
	startTime=50;
	endTime=55;
	energy=20;
}

/*** execute goat dailt work*/
void Goat::daily(){
	if((age>=startTime)&&(age<=endTime))
		baby();
	else
		Move();
	LoseEnergy();
}

/*** control grass move location*/
void Goat::Move(){
	if((*son)!=NULL && (*son)->getcrop()=='I')
		EatGrass();
	if(*son==NULL){
		(*son)=this;
		setEmpty(false);
	}
}

/*** control grass life*/
bool Goat::die(){
	if((age==limitage)||(energy==0))
		return false;
	return true;
}

/*** born a new bay goat around mother goat.*/
void Goat::baby(){
	if((*son)!=NULL && (*son)->getcrop()=='I')
		EatGrass();
	if((*son)==NULL){
		(*son)=new Goat();
		(*son)->setfinish(false);
	}
	setEmpty(true);
}

/*** goat kill grass and get energy.*/
void Goat::EatGrass(){
	delete *son;
	(*son)=NULL;
	energy+=5;
}

/*** control goat energy.*/
void Goat::LoseEnergy(){
	energy--;
}

