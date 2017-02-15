#include <iostream>
#include <iomanip>
using namespace std;

int **dataAlloc(int student, int subject);
void dataInput(int **cp, int student, int subject);
void output(int **cp, int student, int subject);
void dataFree(int **cp, int student);

int main()
{
	int student;
	cout << "�л� �� : ";
	cin >> student;

	int subject;
	cout << "���� �� : ";
	cin >> subject;

	int **p2Ddata = dataAlloc(student, subject);
	dataInput(p2Ddata, student, subject);
	output(p2Ddata, student, subject);
	dataFree(p2Ddata, student);
}


int **dataAlloc(int student, int subject)
{
	int **cp;
	cp = new int* [student];

	for (int i = 0; i < student; i++)
		cp[i] = new int [subject];

	return cp;
}

void dataInput(int **cp, int student, int subject)
{
	for (int i = 0; i < student; i++)
	{
		cout << i + 1 << "�� �л� ���� �Է� : ";
		for (int j = 0; j < subject; j++)
			cin >> cp[i][j];
	}
}

void output(int **cp, int student, int subject)
{
	for (int i = 0; i < student; i++)
	{
		int tot = 0;
		cout << i + 1 << "�� : ";
		for (int j = 0; j < subject; j++)
		{
			cout << setw(5) << cp[i][j];
			tot += cp[i][j];
		}
		cout << "  ���� : " << tot << endl;
	}
}

void dataFree(int **cp, int student)
{
	for (int i = 0; i < student; i++)
		delete[] cp[i];
	delete[] cp;
}