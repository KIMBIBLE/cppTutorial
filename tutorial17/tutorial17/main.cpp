#include "time.h"

int main()
{
	Time a(3, 21);
	Time b(2.7);
	cout << "�⺻ ��� ����(�ð�, ��)" << endl;
	cout << a << endl;
	cout << b << endl;

	Time::mode_change();
	cout << "��� ��带 �ٲ� ��" << endl;
	cout << a << endl;
	cout << b << endl;


	cout << "a + b" << endl;
	Time::mode_change();
	cout << "[plus ��]" << endl;
	cout << " a : " << a << endl;
	cout << " b : " << b << endl;
	cout << "[plus ���] : ";
	cout << a.plus(b) << endl;
	cout << "[plus ��]" << endl;
	cout << " a : " << a << endl;
	cout << " b : " << b << endl;
}