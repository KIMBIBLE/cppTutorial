#include "time.h"

int main()
{
	Time a(3, 21);
	Time b(2.7);
	cout << "기본 출력 형태(시간, 분)" << endl;
	cout << a << endl;
	cout << b << endl;

	Time::mode_change();
	cout << "출력 모드를 바꾼 후" << endl;
	cout << a << endl;
	cout << b << endl;


	cout << "a + b" << endl;
	Time::mode_change();
	cout << "[plus 전]" << endl;
	cout << " a : " << a << endl;
	cout << " b : " << b << endl;
	cout << "[plus 결과] : ";
	cout << a.plus(b) << endl;
	cout << "[plus 후]" << endl;
	cout << " a : " << a << endl;
	cout << " b : " << b << endl;
}