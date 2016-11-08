#include "Caesar.h"
#include<iostream>
#define MAX 1000
using namespace std;
/*comment Ctrl K, Ctrl C
uncomment Ctrl K, Ctrl U
argv[1] - books for a full statistics, argv[2] - a table with the full statistics
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
	c.coding(string, 71);
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