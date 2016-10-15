#include "Caesar.h"
#include<iostream>
#define MAX 1000
using namespace std;
/*закомментить Ctrl K, Ctrl C
раскомментить Ctrl K, Ctrl U
argv[1] - книги дл€ большой статистики, argv[2] - таблица большой статистики
*/


void main(int argc, char* argv[]) {
	char string[MAX];
	Caesar c;
	setlocale(LC_ALL, "Russian");
	FILE *f;
	fopen_s(&f, "t.txt", "r");
	fgets(string, MAX, f);

	cout << "your text:\n";
	cout << string << endl;
	c.coding(string, 300);
	cout << "coded text:\n";
	cout << string << endl;

	/* ASCII
	for (int i = 0; i < 256; i++) {
		cout << i << " " << (char)i<<endl;
	}*/
	
	
	c.countFreq(argv[1], argv[2]);
	int k = c.freqTest(string, argv[2]);
	cout << "decoded text:\n";
	c.decoding(string, k);
	cout << string << endl;



	system("PAUSE");
}