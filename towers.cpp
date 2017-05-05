#include <iostream>
#include "towers.h"
#include "mystack.h"
#include <cmath>
using namespace std;
// initialize start-tower by putting discs in, then print out the status of three towers after initialized
void Towers::setDisks()
{
	for (int i = numDisk; i > 0; i--) {
		peg1->push(i);
	}
	plotPegs();
}
// move n discs from tower s to tower d by using a temporary tower t
void Towers::move(int n, MyStack<int>* s, MyStack<int>* t, MyStack<int>* d)
{
	if (n > 0) {
		move(n - 1, s, d, t);
		int foo = s->pop();
		d->push(foo);
		plotPegs();
		move(n-1, t, s, d);
	}
}
//move one discs from tower s to tower d
void Towers::moveOne(MyStack<int>* s, MyStack<int>* d) {
	d->push(s->pop());
}

//destructor
Towers::~Towers()
{
    while (!peg1->isEmpty()) {
    	peg1->pop();
    }
    while (!peg2->isEmpty()) {
    	peg2->pop();
    }
    while (!peg3->isEmpty()) {
    	peg3->pop();
    }

}
Towers::Towers(int num) {
	numDisk = num;
    peg1 = new MyStack<int>(num);
    peg2 = new MyStack<int>(num);
    peg3 = new MyStack<int>(num);

	setDisks();
}

// copy constructor
 Towers::Towers(const Towers & obj)
 {
	numDisk = obj.numDisk;
    peg1 = new MyStack<int>(numDisk);
    peg2 = new MyStack<int>(numDisk);
    peg3 = new MyStack<int>(numDisk);
 }

//operator= overloading
Towers& Towers::operator=(const Towers & obj)
{
	numDisk = obj.numDisk;
    peg1 = new MyStack<int>(numDisk);
    peg2 = new MyStack<int>(numDisk);
    peg3 = new MyStack<int>(numDisk);

	return *this;
}

//display disks on the three pegs in the console window (stdout)
//DO NOT MODIFY THIS FUNCTION
void Towers::plotPegs()
{
  	if (peg1==NULL || peg2==NULL || peg3==NULL) return;

	int n1=peg1->size();
	int n2=peg2->size();
	int n3=peg3->size();
	int numDisk = n1+n2+n3;

	MyStack<int> tmp1(*peg1);
	MyStack<int> tmp2(*peg2);
	MyStack<int> tmp3(*peg3);

	//plot
	for (int i=0; i<numDisk; i++) {
		//peg1
		if (numDisk-n1-i>0) {
			for (int j=0; j<numDisk; j++)
				cout << " ";
		}
		else {
			int m1 = tmp1.top();
			tmp1.pop();
			for (int j=0; j<m1; j++)
				cout << "*";
			for (int j=m1; j<numDisk; j++)
				cout << " ";
		}
		cout <<" | ";

		//peg2
		if (numDisk-n2-i>0) {
			for (int j=0; j<numDisk; j++)
				cout << " ";
		}
		else {
			int m2 = tmp2.top();
			tmp2.pop();
			for (int j=0; j<m2; j++)
				cout << "*";
			for (int j=m2; j<numDisk; j++)
				cout << " ";
		}
		cout <<" | ";

		//peg3
		if (numDisk-n3-i>0) {
			for (int j=0; j<numDisk; j++)
				cout << " ";
		}
		else {
			int m3 = tmp3.top();
			tmp3.pop();
			for (int j=0; j<m3; j++)
				cout << "*";
			for (int j=m3; j<numDisk; j++)
				cout << " ";
		}
		cout<<endl;
	}
	cout << "_________________________________________\n";
}
