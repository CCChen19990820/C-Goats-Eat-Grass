#ifndef _GOAT_H
#define _GOAT_H

class Creature;

class Goat: public Creature{
	public:
		Goat();
		~Goat(){}
		virtual void daily();
		virtual bool die();
		virtual void baby();
		void Move();
		void EatGrass();
		void LoseEnergy();
	private:
		int energy;
		int startTime,endTime;
};

#endif