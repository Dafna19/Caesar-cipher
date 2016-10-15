#pragma once
#include <stdio.h>


class Caesar {
private:
	float freq[256];
	int find(int n);	
	void counting(bool b, float * fr, char *t, FILE *f);
public:
	void coding(char* t,int k);
	void decoding(char* t, int k);
	void countFreq(char *book, char *table);
	int freqTest(char *t, char *table);
	void show();
};