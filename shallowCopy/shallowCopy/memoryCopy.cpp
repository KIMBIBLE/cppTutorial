#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<assert.h>
typedef struct _person
{
	char *name;         // ���� ���� ���
	int age;             // ���� ���� ���
	char address[20];   // �ּ� ���� ���
}Person;
void myFlush();
void personInput(Person *sp);
void personOutput(Person sVal);
void personClear(Person *sp);
void stringInput(char *message, char *tp, size_t length);
void personMemCpy(Person *p1, Person *p2);

int main()
{
	Person  var1 = { NULL,0, "" }, var2 = { NULL,0, "" };

	personInput(&var1);  // ����ü �� ����� ���� �Է� �޾ƿ�
	personOutput(var1);

	personInput(&var2);
	personOutput(var2);

	//var1 = var2;    // ���� ����� ���� personClear()�Լ� ���� �� ��Ÿ�ӿ��� �߻�
	personMemCpy(&var1, &var2);

	personOutput(var1); // ����ü ���� ������  ���
	personOutput(var2);

	personClear(&var1);  // ����ü ����� �޸𸮸� �����ϰ� ������ ��� ����
	personClear(&var2);
	getchar();
	return 0;
}


void personMemCpy(Person *p1, Person *p2)
{
	int len;
	
	if (p2->name != NULL)
	{
		if (p1->name != NULL)
			free(p1->name);	// dest ����

		// ���Ҵ�
		len = strlen(p2->name) + 1;
		p1->name = (char *)malloc(sizeof(char) * len);
		strcpy(p1->name, p2->name);
	}

	// �� ����
	p1->age = p2->age;
	strcpy(p1->address, p2->address);

}

//--------------------------------------------------------------------------
void personInput(Person *sp)
{
	char temp[101];
	size_t length;
	stringInput("���� �Է�(100byte �̳�) : ", temp, sizeof(temp));
	length = strlen(temp);
	sp->name = (char *)malloc(sizeof(char) * (length + 1)); //null���� ���� +1
	assert(sp->name != NULL);
	strcpy(sp->name, temp);
	printf("���� �Է� : ");
	scanf("%d", &sp->age);
	myFlush();
	stringInput("�ּ� �Է�(19byte �̳�) : ", temp, sizeof(sp->address));
	strcpy(sp->address, temp);
	return;
}
//---------------------------------------------------------------------------
void stringInput(char *message, char *tp, size_t length)
{
	printf(message);
	fgets(tp, length, stdin);

	if (tp[strlen(tp) - 1] == '\n') // ���ڿ��� ���������� �ԷµǾ�����
	{
		tp[strlen(tp) - 1] = '\0'; // ���ڿ����� ���๮�� ����
	}
	else  // �Էµ� ���ڿ��� �迭�� ũ�⸦ �ʰ��ϰ� �ԷµǾ��ٸ�
	{
		printf("�Էµ� ���ڿ��� �ʹ� �� �Ϻ� ���ڿ��� �߸��� �˴ϴ�.\n");
		myFlush();  // stdin ���ۿ� �����ִ� ���̳� ��� �����
	}
	return;
}
//---------------------------------------------------------------------------
void personOutput(Person sVal)
{
	printf("���� : %s(%d��), �ּ� : %s\n", sVal.name, sVal.age, sVal.address);
	return;
}
//---------------------------------------------------------------------------
void personClear(Person *sp)
{
	if (sp->name != NULL) {
		memset(sp->name, 0, strlen(sp->name));
		free(sp->name);
		sp->name = NULL;
	}
	sp->age = 0;
	memset(sp->address, 0, sizeof(sp->address));

	return;
}
//--------------------------------------------------------------------------
void myFlush()
{
	while (getchar() != '\n');
}

