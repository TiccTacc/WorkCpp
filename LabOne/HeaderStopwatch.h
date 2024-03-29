#include "StandHeader.h"
#pragma once
using namespace std;

class Stopwatch
{
private:
	vector<double> history;
	clock_t start, stop;
public:

	Stopwatch();
	void StartWatch();
	double StopWatching();
	void ClearHistory();
	friend ostream& operator<<(ostream& StringOut, Stopwatch& Stopwatching);
};

Stopwatch::Stopwatch() {
	start = stop = 0;
	history = *new vector<double>;
}

void Stopwatch::StartWatch() {
	start = clock();
}
double Stopwatch::StopWatching() {
	
	stop = clock();

	double result = ((double)stop - start / ((double)CLOCKS_PER_SEC));
	history.emplace_back(result);

	return result;

}
void Stopwatch::ClearHistory() {
	history.clear();
	history.resize(0);
}
ostream& operator<<(ostream& StringOut, Stopwatch& Stopwatching) {

	StringOut << "The number of entries in the history: " << Stopwatching.history.size() << endl;

	for (int i = 0; i < Stopwatching.history.size(); i++)
		StringOut << i + 1 << ") " << Stopwatching.history[i] << " sec." << endl;

	return StringOut;
}