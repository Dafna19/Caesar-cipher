#include "Caesar.h"
#include <iostream>


int Caesar::find(int n) {//индекс
	int add = -1;
	for (int i = 0; i < 256; i++) {
		if (freq[i] == n)
			return i;//нашли точное совпадение
		if (freq[i] > n - 3 || freq[i] < n + 3)
			add = i;
	}
	return add;//неточное совпадение
}

void Caesar::coding(char * t, int k ) {
	int i = 0;
	while (t[i] != '\0') {
		t[i] = (t[i] + k) % 256;
		i++;
	}
}

void Caesar::decoding(char * t, int k) {
	int i = 0;
	while (t[i] != '\0') {
		if (t[i] - k < 0)
			t[i] = t[i] - k + 256;
		else
			t[i] = t[i] - k;
		i++;
	}
}

void Caesar::countFreq() {//считает статистику по большому тексту
	for (int i = 0; i < 256; i++)
		freq[i] = 0;

	int sum = 0;
	FILE *text, *freqTable;
	fopen_s(&text, "books.txt", "r");
	while (!feof(text)) {
		int k = getc(text);
		freq[k]++;//считает
		sum++;
	}
	//записывает частоты в файл
	fopen_s(&freqTable, "table.txt", "wb");
	for (int i = 0; i < 256; i++) {
		freq[i] = freq[i] / sum;
		//std::cout << i << " [" << (char)i << "] " << freq[i] << std::endl;
		fwrite(&freq[i], sizeof(float), 1, freqTable);
	}
	fclose(text);
	fclose(freqTable);
}

int Caesar::freqTest(char * t) {
	int key, sum = 0;
	FILE *tabl;
	float currFreq[256];
	for (int i = 0; i < 256; i++)
		currFreq[i] = 0;

	fopen_s(&tabl, "table.txt", "r");
	for (int i = 0; i < 256; i++)
		fread(&freq[i], sizeof(float), 1, tabl);

	int i = 0;
	while (t[i] != '\0') {//заполение текущей статистики
		int n = (t[i] + 256) % 256;
		currFreq[n]++;
		i++;
		sum++;
	}
	for (int i = 0; i < 256; i++) {
		currFreq[i] = currFreq[i] / sum;//частоты
		//std::cout << i << " [" << (char)i << "] " << currFreq[i] << std::endl;
	}

	int maxi, maxi2;
	float max = 0, max2 = 0;
	for (int i = 0; i < 256; i++) {//поиск ключа
		if (currFreq[i] > max2) {
			max2 = currFreq[i];
			maxi2 = i;
		}
		if (freq[i] > max) {
			max = freq[i];
			maxi = i;
		}
	}
	key = (maxi2 - maxi + 256) % 256;

	//std::cout << "max freq in line = " << currFreq[maxi2] << " " << maxi2 << std::endl;
	//std::cout << "max freq = " << freq[maxi] << " " << maxi << std::endl;


	std::cout << "key = " << key << std::endl;

	fclose(tabl);
	return key;
}

void Caesar::show()
{
	FILE *tabl;
	fopen_s(&tabl, "table.txt", "r");
	for (int i = 0; i < 256; i++)
		fread(&freq[i], sizeof(float), 1, tabl);
	for (int i = 0; i < 256; i++)
		std::cout << i << " [" << (char)i << "] " << freq[i] << std::endl;
	fclose(tabl);
}
