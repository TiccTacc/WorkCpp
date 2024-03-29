#include "StandHeader.h"
#include "HeaderPass.h"
using namespace std;

int fPass() {

	Password PassUsers, againPass;
	cout << "please enter the password: ";
	cin >> PassUsers;

	int lvlPass = PassUsers.lvlSecurityPassword();
	switch (lvlPass)
	{
	case (0): {
		cout << "The password is easier than easy" << endl;
		break;
	}
	case(1): {
		cout << "The password is easy" << endl;
		break;
	}
	case(2): {
		cout << "The password is average" << endl;
		break;
	}
	case(3): {
		cout << "The password is normal" << endl;
		break;
	}
	case(4): {
		cout << "The Password Is Great" << endl;
		break;
	}
	case(5): {
		cout << "Even great hackers won't crack the password" << endl;
		break;
	}
	default:
		break;
	}

	cout << "Enter the password again.";
	cin >> againPass;

	if (PassUsers == againPass) {
		cout << "Passwords are equal" << endl;
	}
	else if (PassUsers != againPass) {
		cout << "Passwords are not equal" << endl;
	}
	else {
		cout << "Some kind of game" << endl;
	}
	return 0;
}
