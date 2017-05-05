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
	int i, x, a, b;
    for (i = 0; i < (pow(2,n)); i++)
    {
    	plotPegs();
        x = s->top();
        if (i % 2 == 0)
        {
            if (x == 1)
            {
                d->push(s->pop());
            }
            else if (x == 2)
            {
                s->push(t->pop());
            }
            else if (x == 3)
            {
                t->push(d->pop());
            }
        }
        else
        {
            if (x == 1)
            {
                a = t->pop();
                b = d->pop();
                if (a < b && b != 999)
                {
                    d->push(b);
                    d->push(a);
                }
                else if (a > b && a != 999)
                {
                    t->push(a);
                    t->push(b);
                }
                else if (b == 999)
                {
                    d->push(a);
                }
                else if (a == 999)
                {
                    t->push(b);
                }
            }
            else if (x == 2)
            {
                a = s->pop();
                b = d->pop();
                if (a < b && b != 999)
                {
                    d->push(b);
                    d->push(a);
                }
                else if (a > b && a != 999)
                {
                    s->push(a);
                    s->push(b);
                }
                else if (b == 999)
                {
                    d->push(a);
                }
                else if (a == 999)
                {
                    s->push(b);
                }
            }
            else if (x == 3)
            {
                a = s->pop();
                b = t->pop();
                if (a < b && b != 999)
                {
                    t->push(b);
                    t->push(a);
                }
                else if (a > b && a != 999)
                {
                    s->push(a);
                    s->push(b);
                }
                else if (b == 999)
                {
                    t->push(a);
                }
                else if (a == 999)
                {
                    s->push(b);
                }
            }
        }
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
	setDisks();
}

//copy constructor
// Towers::Towers(const Towers & value)
// {

// }

// //operator= overloading
// Towers& Towers::operator=(const Towers &)
// {

// }

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
