#pragma once

class Fitness
{
private:
	int num;		// ȸ����ȣ
	char *name;	// ����
	double weight;	// ������(kg����)
	double height;	// ����(Ű-cm����)

public:
	// Constructor, Destructor Func()
	Fitness();	// (default) ȸ����ȣ 0, ���� null string, ������ 0kg, ���� 0cm���� �ʱ�ȭ
	Fitness(int num, char *name, double weight, double height);
	Fitness(Fitness &r);
	~Fitness();	// �����Ҵ�� �޸�(name) ���� �ʿ�

				// Operator Overloading Func()
	Fitness & operator=(Fitness &r);
	bool operator ==(Fitness &r);

	// Setter Func()
	void setNum(int num);			// num ��� �ʱ�ȭ �Լ�
	void setName(char *name);		// name ��� �ʱ�ȭ �Լ�
	void setWeight(double weight);	// weight ��� �ʱ�ȭ �Լ�
	void setHeight(double height);	// height ��� �ʱ�ȭ �Լ�

								// Getter Func()
	int getNum();			// num ��� �� ���� �Լ�
	char *getName();		// name ��� �� ���� �Լ�
	double getWeight();		// weight ��� �� ���� �Լ�
	double getHeight();		// height ��� �� ���� �Լ�

						// etc Func()
	double bmi();	// �ش� ȸ���� bmi ����Ͽ� �����ϴ� �Լ�
};