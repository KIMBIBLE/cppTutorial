#include <iostream>
#include <string.h>
using namespace std;

#define MAX_STRING_LEN 100

void input(char *message, double *p1, double *p2);
void input(char *message, char *s1, char *s2);
double max(double dnum1, double dnum2);
char *max(char *str1, char *str2);

int main()
{
	double dnum1, dnum2;
	input("두 실수 입력 : ", &dnum1, &dnum2);
	cout << "큰 값 : " << max(dnum1, dnum2) << endl;

	char str1[MAX_STRING_LEN];
	char str2[MAX_STRING_LEN];
	input("두 문자열 입력 : ", str1, str2);
	cout << "긴 문자열 : " << max(str1, str2) << endl;
}

void input(char *message, double *p1, double *p2)
{
	cout << message;
	cin >> *p1 >> *p2;
}

void input(char *message, char *s1, char *s2)
{
	cout << message;
	cin >> s1 >> s2;
}

double max(double dnum1, double dnum2)
{
	if (dnum1 >= dnum2)
		return dnum1;
	else
		return dnum2;
}
char *max(char *str1, char *str2)
{
	if (strcmp(str1, str2) >= 0)
		return str1;
	else
		return str2;
}
