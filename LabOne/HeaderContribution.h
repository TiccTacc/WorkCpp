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
