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
	//cout << str3[6] << endl;	// 배열과 마찬가지로 할당된 공간 이외의 영역을 접근할 경우 런타임에러
	cout << str3.at(2) << endl << endl;
	//cout << str1.at(0) << endl;	// null string 0번방도 접근 불가

	cout << boolalpha << str1.empty() << endl;	// null string 검사 가능
	cout << str2.empty() << noboolalpha << endl << endl;
	
	cout << str1.length() << ",";
	cout << str2.length() << ",";
	cout << str3.length() << endl << endl;

	cout << str2 << endl;
	str2.insert(3, str3);
	cout << str2 << endl;
	str2.erase(3, str3.length());
	cout << str2 << endl << endl;

	cout << "문자열 내에 찾는 문자가 있는 경우 : " << str2.find('e') << endl;
	cout << "문자열 내에 찾는 문자가 없는 경우 : " << str2.find('k') << endl << endl;
	// 모든 비트가 1인 int형 데이터 리턴

	string str4 = "califonia dream!!";
	cout << "문자열 내에 찾는 문자열이 있는 경우 : " << str4.find(str2) << endl;
	cout << "문자열 내에 찾는 문자열이 없는 경우 : " << str4.find("apple") << endl << endl;
	
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
