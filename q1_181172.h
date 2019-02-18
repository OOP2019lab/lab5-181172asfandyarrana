#include <iostream>
#include <string>
using namespace std;

class bankaccount
{
	string name;
	int id;
	float balance;
	float balancelimit;
	int *transaction;
	int maxtrans;
	int currentnotrans;
public:
	bankaccount(string name,int accountno);
	~bankaccount();
	void print();
	void withdraw(int);
	void deposit(int);
	void increaseTranCapacity();
};

