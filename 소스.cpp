#include<iostream>
#include<cstring>
using namespace std;

class Person
{
	int age;
	char name[50];
public:
	Person(int myage, const char* myname) :age(myage) { strcpy(name, myname); }
	void WhatYourName()const { cout << "My name is " << name << endl; }
	void HowOldAreYou()const { cout << "I'm " << age << " years old" << endl; }
};

class UnivStudent :public Person	//Person�� ���. Person�� public ������ ���ٰ����ϴ�. �������� �Ұ�.
{
	char major[50];
public:
	UnivStudent(const char* myname, int myage, const char* mymajor) :Person(myage, myname) { strcpy(major, mymajor); }	//Person�� ����
	void WhoAreYou()const
	{
		WhatYourName();	//private ������ ������ �� ���� ������, Person ���� �Լ��� ���� ȣ���ؾ� �Ѵ�.
		HowOldAreYou();
		cout << "My major is " << major << endl << endl;
	}
};

int main()
{
	UnivStudent ustd1("LEE", 22, "Computer eng.");
	ustd1.WhoAreYou();

	UnivStudent ustd2("Yoon", 21, "Electronic eng.");
	ustd2.WhoAreYou();
	return 0;
}