#include <iostream>
#include <stdlib.h>
#include <string> 
using namespace std;

int hour = 00;
int minute = 00;
int second = 00;

void setHour(int newHour) {
	hour = newHour;
}

int getHour() {
	return hour;
}

void setMinute(int newMinute) {
	minute = newMinute;
}

int getMinute() {
	return minute;
}

void setSecond(int newSecond) {
	second = newSecond;
}

int getSecond() {
	return second;
}

string twoDigitString(int n) {
	string paddedNumber;
	string error = "ERROR: twoDigit function got bad input";

	if (n >= 0 && n <= 9) {
		paddedNumber = "0" + to_string(n);
		return paddedNumber;
	}
	else if (n >= 10) {
		return to_string(n);
	}
	else {
		return error;
	}
}

string nCharString(size_t n, string c) {
	string border;
	/*string error = "ERROR: displayBorder got negative input";*/

	for (int i = 0; i < n && n >= 0; i++) {
		border.append(c);
	}
	return border;

}

string formatTime12(int h, int m, int s) {
	string output;

	if (h == 12) {
		cout << twoDigitString(12) << ":" << twoDigitString(m) << ":" << twoDigitString(s) << " P M";
	}
	else if (h >= 13) {
		cout << twoDigitString(h - 12) << ":" << twoDigitString(m) << ":" << twoDigitString(s) << " P M";
	}
	else if (h == 0) {
		cout << twoDigitString(12) << ":" << twoDigitString(m) << ":" << twoDigitString(s) << " A M";
	}
	else {
		cout << twoDigitString(h) << ":" << twoDigitString(m) << ":" << twoDigitString(s) << " A M";
	}
	return output;
}

string formatTime24(int h, int m, int s) {
	string output = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s);
	return output;
}

void printMenu() {
	cout << "          " << nCharString(27, "*") << endl;
	cout << "          * 1- Add One Hour         *" << endl << endl;
	cout << "          * 2- Add One Minute       *" << endl << endl;
	cout << "          * 3- Add One Second       *" << endl << endl;
	cout << "          * 4- Exit Program         *" << endl << endl;
	cout << "          " << nCharString(27, "*") << endl;
}

unsigned int getMenuChoice(unsigned int maxChoice) {
	int userInput;
	
	bool loop = true;

	while (loop) {
		cin >> userInput;

		if (userInput >= 1 && userInput <= maxChoice) {			
			loop = false;
		}
		else {
			continue;
		}
	}
	return userInput;
}

void displayClocks(unsigned int h, unsigned int m, unsigned int s) {
	cout << nCharString(27, "*") << nCharString(3, " ") << nCharString(27, "*") << endl;
	cout << "*" << nCharString(6, " ") << "12-HOUR CLOCK" << nCharString(6, " ") << "*   ";
	cout << "*" << nCharString(6, " ") << "24-HOUR CLOCK" << nCharString(6, " ") << "*" << endl;
	cout << endl;
	cout << "*" << nCharString(6, " "); cout << formatTime12(h, m, s) << nCharString(7, " ") << "*   ";
	cout << "*" << nCharString(8, " ") << formatTime24(h, m, s) << nCharString(9, " ") << "*" << endl;
	cout << nCharString(27, "*") << "   " << nCharString(27, "*") << endl;
}

void addOneHour() {
	setHour(getHour() + 1);
	
	if (getHour() == 24) {
		setHour(0);
	}
}

void addOneMinute() {
	setMinute(getMinute() + 1);

	if (getMinute() == 60) {
		setMinute(0);
		addOneHour();
	}
}

void addOneSecond() {
	setSecond(getSecond() + 1);

	if (getSecond() == 60) {
		setSecond(0);
		addOneMinute();
	}
}

void displayInterface() {
	displayClocks(hour, minute, second);
	cout << endl << endl;
	printMenu();
}

void main() {
	int userChoice = 0;
	displayInterface();
	
	
	while (userChoice != 4) {
		userChoice = getMenuChoice(4);
		if (userChoice == 1) {
			addOneHour();
			displayInterface();
		}
		else if (userChoice == 2) {
			addOneMinute();
			displayInterface();
		}
		else if (userChoice == 3) {
			addOneSecond();
			displayInterface();
		}
	}
}
