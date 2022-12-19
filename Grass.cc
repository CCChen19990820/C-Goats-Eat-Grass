#include <iostream>
#include "Creature.h"
#include "Grass.h"

/*** initial grass*/
Grass::Grass():Creature(true,7,'I'){
	startTime=3;
	endTime=5;
}

/*** execute grass daily work.*/
void Grass::daily(){
	baby();
}

/*** control grass life*/
bool Grass::die(){
	if(age==limitage)
		return false;
	return true;
}

/*** born a new bay grass around mother grass.*/
void Grass::baby(){
	if(age>=startTime && age<=endTime){
		if((*son)==NULL)
			(*son)=new Grass();
	}
}
