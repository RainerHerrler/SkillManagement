#ifndef MYTOOLS_H_
#define MYTOOLS_H_

#include <string>
#include <iostream>
#include <vector>

using namespace std;

namespace Mytools {
	string& trim(string& input);
	string query(const string& inputText);
	bool startsWith(const string &input, const char *startStr);
	void tokenize(string& text, vector<string>& words, string delim);
}

#endif /* MYTOOLS_H_ */
