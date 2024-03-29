#include "StandHeader.h"
#pragma once
using namespace std;

class Contribution
{
private:
	double percent, balance;
	int term;
	bool refillAndTakeOff;
public:
	Contribution();
	Contribution(double Inpercent, double Inbalance, int Interm, bool refATake);
	int calcContr();

	friend Contribution& operator+=(Contribution& Cont, int& PS);
	friend Contribution& operator-=(Contribution& Cont, int& PS);

	friend ostream& operator<<(ostream& stringOut, Contribution& Cont);
	friend istream& operator>>(istream& stringIn, Contribution& a);
};

Contribution::Contribution()
{
	percent = balance = 0;
	term = 0;
	refillAndTakeOff = false;
}

Contribution::Contribution(double Inpercent, double Inbalance, int Interm, bool refATake) {
	
	percent				= Inpercent;
	balance				= Inbalance;
	term				= Interm;
	refillAndTakeOff	= refATake;

}

int Contribution::calcContr() {

	int ubalance = balance;
	if (ubalance <= 0)
		return 0;
	ubalance += ubalance * (percent * term);
	return ubalance;

}

Contribution& operator+=(Contribution& Cont, int& PS) {

	if (Cont.refillAndTakeOff == false)
		Cont.balance += PS;
	return Cont;

}
Contribution& operator-=(Contribution& Cont, int& PS) {
	
	if (Cont.refillAndTakeOff == false)
		Cont.balance -= PS;

	if (Cont.balance <= 0)
		Cont.balance = 0;

	return Cont;

}

ostream& operator<<(ostream& stringOut, Contribution& Cont) { 
	
	stringOut << "Balance: " << Cont.balance << endl;
	stringOut << "The interest rate: " << Cont.percent * 100 << endl;
	stringOut << "Percentages:" << Cont.term << endl;

	if (Cont.refillAndTakeOff)
		stringOut << "You can deposit and withdraw money" << endl;

	stringOut << "Expected income: " << Cont.calcContr() << endl;

	return stringOut;
}
istream& operator>>(istream& stringIn, Contribution& ContIn) {
	
	stringIn >> ContIn.balance >> ContIn.percent >> ContIn.term >> ContIn.refillAndTakeOff;
	ContIn.percent = ContIn.percent / 100;

	return stringIn;

}