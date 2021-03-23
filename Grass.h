#ifndef _GRASS_H
#define _GRASS_H

class Creature;

class Grass: public Creature {
	public:
		Grass();
		~Grass(){}
		virtual void daily();
		virtual bool die();
		virtual void baby();
	private:
		int startTime,endTime;
};

#endif
