#include "StandHeader.h"
#include "HeaderContribution.h"
using namespace std;

int fContribution() {
	
	int debt = 0;
	Contribution Vklad;
	
	cout << "Enter the deposit amount. The interest rate. The term, in years. The possibility of depositing and withdrawing 0 or 1: " << endl;
	cin >> Vklad;
	cout << endl;
	
	cout << "Enter the amount to add to the deposit: " << endl;
	cin >> debt;
	Vklad += debt;

	cout << "Let's display the data about the contribution on the screen " << Vklad << endl;
	cout << endl;

	cout << "Enter the amount to withdraw from the deposit: " << endl;
	cin >> debt;
	Vklad -= debt;

	cout << "Let's display the data about the contribution on the screen " << Vklad << endl;
	cout << endl;

	return 0;
}