#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout << "이름 : ";
	char name[20];
	cin.getline(name, sizeof(name), '\n');
	
	cout << "세 과목의 점수 : ";
	int kor, eng, math;
	cin >> kor >> eng >> math;
	cout << endl << endl;

	cout << "              ";
	cout << "=====< 성적표 >=====";
	cout << "              " << endl;

	cout << "------------------------------------------------" << endl;
	cout << setw(8) << "이름";
	cout << setw(8) << "국어";
	cout << setw(8) << "영어";
	cout << setw(8) << "수학";
	cout << setw(8) << "총점";
	cout << setw(8) << "평균" << endl;
	cout << "------------------------------------------------" << endl;

	cout << setw(8) << name;
	cout << setw(8) << kor;
	cout << setw(8) << eng;
	cout << setw(8) << math;
	cout << setw(8) << kor + eng + math;
	cout << setw(8) << fixed << setprecision(2) << (kor + eng + math) / 3.0 << endl;
}