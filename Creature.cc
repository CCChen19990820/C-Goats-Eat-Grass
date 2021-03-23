#include <iostream>
#include "Creature.h"

using namespace std;

Creature::Creature(bool fi,int Age,char on){
	age=0;
	limitage=Age;
	crop=on;
	finish=fi;
	empty=true;
}

void Creature::Initial(){
	crop=' ';
	finish=true;
}

bool Creature::getfinish(){
	return finish;
}

void Creature::setfinish(bool bang){
	finish=bang;
}

void Creature::getorder(){
	age++;
}

char Creature::getcrop(){
	return crop;
}

void Creature::setSon(Creature** Son){
	son=Son;
}

void Creature::setEmpty(bool hi){
	empty=hi;
}

bool Creature::getEmpty(){
	return empty;
}
