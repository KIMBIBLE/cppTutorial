#include "smartAry.h"

int main()
{
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(2);
	int chulSize = 3;
	int matelSize = 5;
	SmartArray a(chulSize);
	cout << " ö���� �� ������ ���� �Է� : ";
	int sum = 0;
	for (int i = 0; i < chulSize; i++)
	{
		int temp;
		cin >> temp;
		if (a.put(i, temp) == false) 
		{
			cout << "�迭 ���� ����" << endl;
			break;
		}
		sum += a.getAry()[i];
	}
	cout << "ö���� ���� : " << sum << endl;
	cout << "ö���� ��� : " << sum / (double)chulSize << endl;

	SmartArray b(matelSize);
	cout << " ������ �ټ� ������ ���� �Է� : ";
	sum = 0;
	for (int i = 0; i < matelSize; i++)
	{
		int temp;
		cin >> temp;
		if (b.put(i, temp) == false)
		{
			cout << "�迭 ���� ����" << endl;
			break;
		}
		sum += b.getAry()[i];
	}
	cout << "������ ���� : " << sum << endl;
	cout << "������ ��� : " << sum / (double)matelSize << endl;

	if (a > b)
		cout << "ö���� �ְ����� ���ں��� ũ��" << endl;
	else
		cout << "ö���� �ְ����� ���ں��� ũ�� �ʴ�" << endl;
}