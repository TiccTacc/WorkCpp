#include "StandHeader.h"
#pragma once
using namespace std;

class ColorRGB
{
private:
	int Red, Green, Blue;
public:
	ColorRGB();
	bool DataCorrectness();
	bool operator==(ColorRGB& ColorChek);
	bool operator!=(ColorRGB& ColorChek);

	friend ostream& operator<<(ostream& stringOut,	const ColorRGB& ColorOut);
	friend istream& operator>>(istream& StringIn,	ColorRGB& ColorIn);
};

ColorRGB::ColorRGB() {
	Red = Green = Blue = 0;
}

bool ColorRGB::DataCorrectness() {
	if ((Red < 0 or Red > 255) 
		or (Green < 0 or Green > 255)
		or (Blue < 0 or Blue > 255)) {

		return false;
	}
	return true;
}

bool ColorRGB::operator==(ColorRGB& ColorChek) {

	if (Red == ColorChek.Red
		and Green == ColorChek.Green
		and Blue == ColorChek.Blue) {
		return true;
	}
	return false;
}
bool ColorRGB::operator!=(ColorRGB& ColorChek) {
	
	if (Red == ColorChek.Red
		and Green == ColorChek.Green
		and Blue == ColorChek.Blue) {
		
		return false;

	}

	return true;

}
ostream& operator<<(ostream& stringOut, const ColorRGB& ColorOut)
{
	stringOut << "Red: " << ColorOut.Red << endl;
	stringOut << " Green: " << ColorOut.Green << endl;
	stringOut << "Blue: " << ColorOut.Blue << endl;
	return stringOut;
}

istream& operator>>(istream& StringIn, ColorRGB& ColorIn)
{
	StringIn >> ColorIn.Red;
	StringIn >> ColorIn.Green;
	StringIn >> ColorIn.Blue;

	return StringIn;
}