#include "happy.h"

int main()
{
	Happy a("ö��"), b("����"), w;
	char item[100];
	int price;

	cout << "ö�̰� ���� ���ϴ�..." << endl;
	while (1)
	{
		cout << "���� ���� : ";
		cin >> item;
		if (strcmp(item, "��") == 0) break;
		cout << "�ݾ� �Է� : ";
		cin >> price;
		a.use(item, price);
	}

	cout << "������ ���� ���ϴ�..." << endl << endl;
	while (1)
	{
		cout << "���� ���� : ";
		cin >> item;
		if (strcmp(item, "��") == 0) break;
		cout << "�ݾ� �Է� : ";
		cin >> price;
		b.use(item, price);
	}

	cout << "���� ���ڴ�?" << endl;
	w = a.winner(b);
	cout << w.getName() << "�̰� �� " << w.getIndex()
		<< "���� ����ϰ� ���� �ݾ��� " << w.getMoney() << "�� �Դϴ�." << endl;

	// ������ ��볻�� ���
	for (int i = 0; i < w.getIndex(); i++)
		cout << w.getList()[i] << " ";
	cout << endl;
}