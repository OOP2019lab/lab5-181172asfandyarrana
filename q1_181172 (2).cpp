#include "bankaccount.h"
#include <iostream>
using namespace std;


//void bankaccount::set



bankaccount::bankaccount(string account,int accountno)
{
	id=accountno;
	name=account;
	balance=0;
	balancelimit=200000;
	maxtrans=10;
	transaction=nullptr;
	transaction=new int[maxtrans];
	currentnotrans=0;
}

void bankaccount::print()
{
	cout<<"The name of the account holder is:     "<<name<<endl;
	cout<<"The account number of the account holder is:     "<<id<<endl;
	cout<<"The balance in the account of the account holder is:     "<<balance<<endl;
	cout<<"The current number of transaction for the account holder is:     "<<currentnotrans<<endl;
	cout<<"The transactions of the account holder are:     "<<endl;
	for(int i=0;i<currentnotrans;i++)
		{
			cout<<transaction[i]<<endl;
		}

}

void bankaccount::withdraw(int money)
{
	if(currentnotrans==maxtrans)
	{
		increaseTranCapacity();
	}
	if(money<=balance )
	{
		balance=balance-money;
		transaction[currentnotrans]=-money;
		currentnotrans++;
		cout<<"Transaction successful!!!"<<endl;
		cout<<"withdraw"<<endl;
	}
	else
	cout<<"Transaction Unsuccessful: Insufficient balance"<<endl;
}
void bankaccount::deposit(int money)
{
	if(currentnotrans==maxtrans)
	{
		increaseTranCapacity();
	}
	if(money+balance<=balancelimit )
	{
		balance=balance+money;
		transaction[currentnotrans]=money;
		currentnotrans++;
		cout<<"Transaction successful!!!"<<endl;
		cout<<"deposit"<<endl;
	}
	else
	cout<<"Exceeded limit"<<endl;
}
bankaccount::~bankaccount()
{
	cout << "in des\n";
	id=0;
	name="";
	balance=0;
	balancelimit=200000;
	maxtrans=10;

	delete[]transaction;

	transaction=nullptr;
	
	currentnotrans=0;
}



void bankaccount:: increaseTranCapacity()  
{
	if(currentnotrans==maxtrans)
	{
		int *temp=new int[maxtrans*2];

		for(int i=0;i<maxtrans;i++)
		{
			temp[i]=transaction[i];
		}
		delete[]transaction;
		transaction=nullptr;
		int *transaction=new int[maxtrans*2];
		for(int i=0;i<maxtrans;i++)
		{
			transaction[i]=temp[i];
		}
		maxtrans=maxtrans*2;
		delete[]temp;
		temp=nullptr;
	}

}