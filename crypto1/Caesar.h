#pragma once
#include <stdio.h>


class Caesar {
private:
	float freq[256];
	int find(int n);	
public:
	void coding(char* t,int k);
	void decoding(char* t, int k);
	void countFreq();
	int freqTest(char *t);
	void show();
};