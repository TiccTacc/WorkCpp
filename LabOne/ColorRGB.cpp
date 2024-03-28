#include "StandHeader.h"
#include "HeaderRGB.h"
using namespace std;

int fColorRGB() {

	ColorRGB firstColor, secondColor;

	cout << "Enter the color in RGB format:";
	cin >> firstColor;
	cout << endl;

	if (firstColor.DataCorrectness())
		cout << "The format of the first color is correct." << endl;

	cout << "Enter the color in the KPI format again:";
	cin >> secondColor;
	cout << endl;

	if (secondColor.DataCorrectness())
		cout << "The format of the second color is correct" << endl;

	if (firstColor.operator==(secondColor)) {
		cout << "The colors are the same" << endl;
	}
	else if (firstColor.operator!=(secondColor)) {
		cout << "The colors are not the same" << endl;
	}
	return 0;

}