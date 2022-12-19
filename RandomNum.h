#ifndef _RANDOMNUM_H
#define _RANDOMNUM_H

class RandomNum {
	public:
		RandomNum(int seed=0);
		int getRandomNum(int low, int high) const; 
};

#endif // _RANDOMNUM_H