#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout << "�̸� : ";
	char name[20];
	cin.getline(name, sizeof(name), '\n');
	
	cout << "�� ������ ���� : ";
	int kor, eng, math;
	cin >> kor >> eng >> math;
	cout << endl << endl;

	cout << "              ";
	cout << "=====< ����ǥ >=====";
	cout << "              " << endl;

	cout << "------------------------------------------------" << endl;
	cout << setw(8) << "�̸�";
	cout << setw(8) << "����";
	cout << setw(8) << "����";
	cout << setw(8) << "����";
	cout << setw(8) << "����";
	cout << setw(8) << "���" << endl;
	cout << "------------------------------------------------" << endl;

	cout << setw(8) << name;
	cout << setw(8) << kor;
	cout << setw(8) << eng;
	cout << setw(8) << math;
	cout << setw(8) << kor + eng + math;
	cout << setw(8) << fixed << setprecision(2) << (kor + eng + math) / 3.0 << endl;
}