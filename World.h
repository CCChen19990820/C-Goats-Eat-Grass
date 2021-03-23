#include "RandomNum.h"

using namespace std;

class Creature;

const int map_x=35,map_y=20;
const int initialGoat=5,initialGrass=10;
const int direction[2][4]={{1,0,-1,0},{0,1,0,-1}};

class World{
	public:

		World(int round,int seed);
		World();
		~World();
		void mainLoop(int display);
		void show();
		void initialize();
		void newpass();

	private:
		int nowpass,totalpass;
		Creature* farm[map_y][map_x];
		RandomNum randomnum;
};
