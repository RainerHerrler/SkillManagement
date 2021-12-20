/*
 * Mytools.cpp
 *
 *  Created on: 29.11.2021
 *      Author: herrler
 */

#include "Mytools.h"

namespace Mytools {
string& trim(string &input) {
	input.erase(input.find_last_not_of(" \n\r\t") + 1);
	return input;
}

bool startsWith(const string &input, const char *startStr) {
	return input.rfind(startStr, 0) == 0;
}

string query(const string& inputText) {
	cout << inputText;
	string readLine;
	std::getline(std::cin, readLine);
	trim(readLine);
	return readLine;
}

void tokenize(string &text, vector<string> &words, string delim) {
	size_t pos = 0;
	while ((pos = text.find(delim)) != string::npos) {
		words.push_back(text.substr(0, pos));
		text.erase(0, pos + delim.length());
	}
	if (!text.empty())
		words.push_back(text.substr(0, pos));
	// just for testing
//    for (const auto &str : words) {
//        cout << str << endl;
//    }
}

}
