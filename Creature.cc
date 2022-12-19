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

void Creature::Initial(){ // initial farm location.
	crop=' ';
	finish=true;
}

bool Creature::getfinish(){  //get finish location daily.
	return finish;
}

void Creature::setfinish(bool bang){ //set finish location daily.
	finish=bang;
}

void Creature::getorder(){ // control creature age.
	age++;
}

char Creature::getcrop(){ // get location creature type.
	return crop;
}

void Creature::setSon(Creature** Son){ //set the son creature.
	son=Son;
}

void Creature::setEmpty(bool hi){ // set the location empty.
	empty=hi;
}

bool Creature::getEmpty(){ // get location empty.
	return empty;
}
