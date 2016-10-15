#include "Caesar.h"
#include <iostream>


/*int Caesar::find(int n) {//������
	int add = -1;
	for (int i = 0; i < 256; i++) {
		if (freq[i] == n)
			return i;//����� ������ ����������
		if (freq[i] > n - 3 || freq[i] < n + 3)
			add = i;
	}
	return add;//�������� ����������
}*/

void Caesar::counting(bool b, float * fr, char *t, FILE *f){//0 - �� �������,  1 - �� �����
	for (int i = 0; i < 256; i++)
		fr[i] = 0;
	int sum = 0;

	if (b) {//�� �����
		while (!feof(f)) {
			int k = getc(f);
			fr[k]++;//�������
			sum++;
		}
	}
	else { //�� �������
		int i = 0;
		while (t[i] != '\0') {//��������� ������� ����������
			int n = (t[i] + 256) % 256;
			fr[n]++;
			i++;
			sum++;
		}
	}

	for (int i = 0; i < 256; i++)
		fr[i] = fr[i] / sum;//�������
}

void Caesar::coding(char * t, int k ) {
	int i = 0;
	while (t[i] != '\0') {
		t[i] = (t[i] + k) % 256;
		i++;
	}
	std::cout << "key = " << k << std::endl;
}

void Caesar::decoding(char * t, int k) {
	int i = 0;
	while (t[i] != '\0') {
		t[i] = (t[i] - k + 256) % 256;
		++i;
	}
}

//�������� ��� ������ �����
void Caesar::countFreq(char *book, char *table) {//������� ���������� �� �������� ������
	FILE *text, *freqTable;
	fopen_s(&text, book, "r");
	counting(1, freq, NULL, text);

	//���������� ������� � ����
	fopen_s(&freqTable, table, "wb");
	for (int i = 0; i < 256; i++) {
		//std::cout << i << " [" << (char)i << "] " << freq[i] << std::endl;
		fwrite(&freq[i], sizeof(float), 1, freqTable);
	}
	fclose(text);
	fclose(freqTable);
}

int Caesar::freqTest(char * t, char *table) {
	int key;
	FILE *tabl;
	float currFreq[256];
	counting(0, currFreq, t, NULL);//������� ����������

	fopen_s(&tabl, table, "r");
	for (int i = 0; i < 256; i++)
		fread(&freq[i], sizeof(float), 1, tabl);

	int maxi, maxi2;
	float max = 0, max2 = 0;
	for (int i = 0; i < 256; i++) {//����� �����
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
