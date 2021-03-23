#ifndef _CREATURE_H
#define _CREATURE_H
//class World;

class Creature{
	public:
		Creature(bool fi,int Age,char on);
		virtual ~Creature(){}
		virtual void daily()=0;
		virtual bool die()=0;
		virtual void baby()=0;
		void Initial();
		bool getfinish();
		void setfinish(bool bang);
		void getorder();
		char getcrop();
		void setSon(Creature** Son);
		void setEmpty(bool hi);
		bool getEmpty();
	protected:
		char crop;
		bool finish,empty;
		int age;
		int limitage;
		Creature** son;
};
#endif
