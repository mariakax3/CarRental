#pragma once

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

const string str_ERROR = "\nERROR OCCURED: ";
const string str_INVALID = "Ivalid data type entered.\n\n";
const string str_MIN = "Please enter a positive number.\n\n";
const string str_REQ = "Value does not meet given requirement.\n\n";


inline void clrStream() {
	cin.clear();
	cin.ignore(10000, '\n');
}

template <class TYPE>
inline TYPE getInput(TYPE &input, string coutStatement, string minRange) {
	while (true) {
		cout.width(40);
		cout << left << coutStatement;
		if (getline(cin >> ws, input) && input >= minRange) {
			cin.clear();
			for (int i = 0; i < input.length(); i++) {
				if (input[i] == 44) {
					input[i] = 46;
				}
			}
			return input;
		}
		else {
			cin.clear();
			cout << str_ERROR << str_INVALID;
		}
	}
}

template <class TYPE>
inline TYPE getInput(TYPE &input, string coutStatement) {
	while (true) {
		int w = 40;
		if (coutStatement == "") { w = 0; }
		cout.width(w);
		cout << left << coutStatement;
		if (w == 0) { cout << ">> "; };
		if (cin >> input) {
			if (input <= 0) { 
				clrStream();
				cout << str_ERROR << str_MIN;
			}
			else {
				clrStream();
				return input;
			}
		}
		else {
			clrStream();
			cout << str_ERROR << str_INVALID;
		}
	}
}

template <class TYPE>
inline TYPE getInput(TYPE &input, string coutStatement, TYPE v1, TYPE v2, int w) {
	while (true) {
		cout.width(w);
		cout << left << coutStatement;
		if (cin >> input) {
			if (input < v1 || input > v2) {
				clrStream();
				cout << str_ERROR << str_REQ;
				if (w == 0) { cout << ">> "; };
			}
			else {
				clrStream();
				return input;
			}
		}
		else {
			clrStream();
			cout << str_ERROR << str_INVALID;
			if (w == 0) { cout << ">> "; };
		}
	}
}

inline int getYear() {
	time_t t = time(NULL);
	tm *timePtr = localtime(&t);
	return timePtr->tm_year + 1900;
}
