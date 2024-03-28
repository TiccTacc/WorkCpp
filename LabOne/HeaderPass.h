#include "StandHeader.h"
#pragma once
using namespace std;

class Password
{
private:
	string sPassword;
public:
	Password();
	Password(string InPass);

	int lvlSecurityPassword();
	friend ostream& operator<<(ostream& stringOut, const Password& sPass);
	friend istream& operator>>(istream& stringIn, Password& sPass);

	friend bool operator==(Password& fPass, Password& sPass);
	friend bool operator!=(Password& fPass, Password& sPass);
};

Password::Password() {
	sPassword = "";
}
Password::Password(string InPass) {
	sPassword = InPass;
}


bool specSumbols(string selectString) {

	const string specSumb{ "!@#$%^&*()-_=+<>?/""'[]{}\\|" };
	if (selectString.find(specSumb) != string::npos) {
		return true;
	}
	return false;

}

int Password::lvlSecurityPassword() {
	
	int lvl = 0, len = 0;
	bool lowercase = false, uppercase = false, specchar = false, numb = false;

	for (size_t i = 0; i < sPassword.size(); i++) {
		len++;

		if (sPassword[i] >= 'a' and sPassword[i] <= 'z')
			lowercase = true;

		if (sPassword[i]>='A' and sPassword[i]<='Z')
			uppercase = true;

		if (sPassword[i] >= '0' and sPassword[i] <= '9')
			numb = true;

		if (specSumbols(sPassword))
			specchar = true;
	}

	if (len >= 8)
		lvl++;
	if (lowercase)
		lvl++;
	if (uppercase)
		lvl++;
	if (numb)
		lvl++;
	if (specchar)
		lvl++;

	return lvl; // min - 0; max - 5

}

bool operator==(Password& fPass, Password& sPass) {
	
	if (fPass.sPassword == sPass.sPassword)
		return true;
	return false;

}

bool operator!=(Password& fPass, Password& sPass) {
	
	if (fPass.sPassword != sPass.sPassword)
		return true;
	return false;

}

ostream& operator<<(ostream& stringOut, const Password& sPass)
{
	stringOut << sPass.sPassword << endl;
	return stringOut;
}

istream& operator>>(istream& stringIn, Password& sPass)
{
	getline(stringIn, sPass.sPassword);
	return stringIn;
}

