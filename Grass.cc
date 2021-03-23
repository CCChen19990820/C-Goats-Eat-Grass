#include <iostream>
#include "Creature.h"
#include "Grass.h"

Grass::Grass():Creature(true,7,'I'){
	startTime=3;
	endTime=5;
}

void Grass::daily(){
	baby();
}

bool Grass::die(){
	if(age==limitage)
		return false;
	return true;
}

void Grass::baby(){
	if(age>=startTime && age<=endTime){
		if((*son)==NULL)
			(*son)=new Grass();
	}
}
