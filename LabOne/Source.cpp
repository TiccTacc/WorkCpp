#include "StandHeader.h"
using namespace std;


int main() {

	setlocale(LC_ALL, "rus");

	int selectedJobs = 0;
	cout << "Select a task:"
		<< "0 - exit" << endl
		<< "1 - Matrix" << endl
		<< "2 - Time" << endl
		<< "3 - Point" << endl
		<< "4 - RGB" << endl
		<< "5 - Contribution" << endl
		<< "6 - Stopwatch" << endl;
	cin >> selectedJobs;

	switch (selectedJobs)
	{
		case 1: {
			int fMatrix();
			fMatrix();
			break; 
		}
		case 2:{}
		case 3:{}
		case 4:{}
	
		default:{
			exit;
		}
	}

	return 0;

}
