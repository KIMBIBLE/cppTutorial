#include "smartAry.h"

int main()
{
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(2);
	int chulSize = 3;
	int matelSize = 5;
	SmartArray a(chulSize);
	cout << " 철이의 세 과목의 점수 입력 : ";
	int sum = 0;
	for (int i = 0; i < chulSize; i++)
	{
		int temp;
		cin >> temp;
		if (a.put(i, temp) == false) 
		{
			cout << "배열 쓰기 실패" << endl;
			break;
		}
		sum += a.getAry()[i];
	}
	cout << "철이의 총점 : " << sum << endl;
	cout << "철이의 평균 : " << sum / (double)chulSize << endl;

	SmartArray b(matelSize);
	cout << " 메텔의 다섯 과목의 점수 입력 : ";
	sum = 0;
	for (int i = 0; i < matelSize; i++)
	{
		int temp;
		cin >> temp;
		if (b.put(i, temp) == false)
		{
			cout << "배열 쓰기 실패" << endl;
			break;
		}
		sum += b.getAry()[i];
	}
	cout << "메텔의 총점 : " << sum << endl;
	cout << "메텔의 평균 : " << sum / (double)matelSize << endl;

	if (a > b)
		cout << "철이의 최고점은 메텔보다 크다" << endl;
	else
		cout << "철이의 최고점은 메텔보다 크지 않다" << endl;
}