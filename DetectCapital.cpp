#include<string>
#include<iostream>
#include<regex>

using namespace std;

class DetectCapital {
public:
	bool detectCapitalUse(string word) {
		return regex_match(word, regex("^[A-Z]?([a-z]*|[A-Z]*)"));
	}
};
