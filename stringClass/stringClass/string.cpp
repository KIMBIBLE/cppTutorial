#include <iostream>
using namespace std;
#include <string>

int main()
{
	string str1;
	cout << "Null String : " << "[" <<str1 << "]" << endl << endl;

	string str2("dream");
	cout << "[" << str2 << "]" << endl << endl;

	string str3(str2);
	cout << "[" << str3 << "]" << endl << endl;

	cout << str3[2] << endl;
	//cout << str3[6] << endl;	// �迭�� ���������� �Ҵ�� ���� �̿��� ������ ������ ��� ��Ÿ�ӿ���
	cout << str3.at(2) << endl << endl;
	//cout << str1.at(0) << endl;	// null string 0���浵 ���� �Ұ�

	cout << boolalpha << str1.empty() << endl;	// null string �˻� ����
	cout << str2.empty() << noboolalpha << endl << endl;
	
	cout << str1.length() << ",";
	cout << str2.length() << ",";
	cout << str3.length() << endl << endl;

	cout << str2 << endl;
	str2.insert(3, str3);
	cout << str2 << endl;
	str2.erase(3, str3.length());
	cout << str2 << endl << endl;

	cout << "���ڿ� ���� ã�� ���ڰ� �ִ� ��� : " << str2.find('e') << endl;
	cout << "���ڿ� ���� ã�� ���ڰ� ���� ��� : " << str2.find('k') << endl << endl;
	// ��� ��Ʈ�� 1�� int�� ������ ����

	string str4 = "califonia dream!!";
	cout << "���ڿ� ���� ã�� ���ڿ��� �ִ� ��� : " << str4.find(str2) << endl;
	cout << "���ڿ� ���� ã�� ���ڿ��� ���� ��� : " << str4.find("apple") << endl << endl;
	
	cout << str4.find(str2, 0) << endl;
	cout << str4.find(str2, 2) << endl;
	cout << str4.find(str2, 11) << endl << endl;

	string str5;
	str5 = str2;
	cout << str5 << endl << endl;

	cout << str4 << endl;
	str4 += str2;
	cout << str4 << endl << endl;

	cout << str4 << endl;
	cout << str2 << endl;
	cout << str4 + str2 << endl;
	cout << str4 << endl;
	cout << str2 << endl << endl;

	cout << str4 << endl;
	cout << str2 << endl;
	cout << boolalpha << (str4 == str2) << endl;
	cout << (str4 > str2) << endl;
	cout << (str4 < str2) << endl;
}
