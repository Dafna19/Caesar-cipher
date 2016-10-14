#include "Caesar.h"
#include<iostream>
#define MAX 1000
using namespace std;
/*закомментить Ctrl K, Ctrl C
раскомментить Ctrl K, Ctrl U*/


void main() {
	char string[MAX];
	Caesar c;
	setlocale(LC_ALL, "Russian");
	FILE *f;
	fopen_s(&f, "t.txt", "r");
	fgets(string, MAX, f);

	cout << "your string:\n";
	cout << string << endl;
	c.coding(string, 30);
	cout << "coded string:\n";
	cout << string << endl;
	//c.decoding(string, 5);
	//cout << string << endl;

	// ASCII
	/*for (int i = 0; i < 256; i++) {
		cout << i << " " << (char)i<<endl;
	}*/
	
	
	c.countFreq();
	int k = c.freqTest(string);
	cout << "decoded string:\n";
	c.decoding(string, k);
	cout << string << endl;



	system("PAUSE");
}