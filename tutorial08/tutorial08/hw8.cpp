#include <iostream>
using namespace std;

void swap_ptr(char* &r1, char* &r2);

int main()
{
	char *ap = "apple";
	char *bp = "banana";

	cout << "�ٲٱ� �� ���ڿ� : " << ap << " " << bp << endl;
	swap_ptr(ap, bp);
	cout << "�ٲ� ���� ���ڿ� : " << ap << " " << bp << endl;
}

void swap_ptr(char* &r1, char* &r2)
{
	char *tp;
	tp = r1;
	r1 = r2;
	r2 = tp;
}