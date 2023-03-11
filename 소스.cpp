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

class UnivStudent :public Person	//Person을 상속. Person의 public 공간에 접근가능하다. 역방향은 불가.
{
	char major[50];
public:
	UnivStudent(const char* myname, int myage, const char* mymajor) :Person(myage, myname) { strcpy(major, mymajor); }	//Person을 선언
	void WhoAreYou()const
	{
		WhatYourName();	//private 변수에 접근할 수 없기 때문에, Person 내에 함수를 만들어서 호출해야 한다.
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