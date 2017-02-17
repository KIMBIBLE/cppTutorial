#pragma once

class Fitness
{
private:
	int num;		// 회원번호
	char *name;	// 성명
	double weight;	// 몸무게(kg단위)
	double height;	// 신장(키-cm단위)

public:
	// Constructor, Destructor Func()
	Fitness();	// (default) 회원번호 0, 성명 null string, 몸무게 0kg, 신장 0cm으로 초기화
	Fitness(int num, char *name, double weight, double height);
	Fitness(Fitness &r);
	~Fitness();	// 동적할당된 메모리(name) 해제 필요

				// Operator Overloading Func()
	Fitness & operator=(Fitness &r);
	bool operator ==(Fitness &r);

	// Setter Func()
	void setNum(int num);			// num 멤버 초기화 함수
	void setName(char *name);		// name 멤버 초기화 함수
	void setWeight(double weight);	// weight 멤버 초기화 함수
	void setHeight(double height);	// height 멤버 초기화 함수

								// Getter Func()
	int getNum();			// num 멤버 값 리턴 함수
	char *getName();		// name 멤버 값 리턴 함수
	double getWeight();		// weight 멤버 값 리턴 함수
	double getHeight();		// height 멤버 값 리턴 함수

						// etc Func()
	double bmi();	// 해당 회원의 bmi 계산하여 리턴하는 함수
};