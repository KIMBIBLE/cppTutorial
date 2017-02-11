#include <iostream>

using namespace std;

void prn(char *);
void prn(char *, int);
void prn(char, int);

int main()
{
	char str[10] = "Star";

	prn(str);
	prn("Moon");
	prn("Gogumi", 3);
	prn('#', 7);
	prn(65, 7);	// ������ ������ 65�� ascii ������ �ν��Ͽ� ��� �����

	return 0;
}

void prn(char *p)
{
	cout << p << endl;
}

void prn(char *p, int rc)
{
	int i;
	for (i = 0; i < rc; i++)
		cout << p << endl;
}

void prn(char ch, int rc)
{
	int i;
	for (i = 0; i < rc; i++)
		cout << ch;
	cout << endl;
}