// 181172.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "bankaccount.h"
using namespace std;




void main()
{
	
	int id1=549002;
	string username="John Doe";
	bankaccount myaccount(username,id1);
	myaccount.print();
	myaccount.deposit(100000);
	myaccount.withdraw(50000);
	myaccount.print();
	



}
