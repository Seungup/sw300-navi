#pragma once
#include "pch.h"
using namespace std;

class Friend
{
public:
	Friend();
	Friend(string name, string IP);
	~Friend();

	inline string getName() { return name; }
	inline string getIP() { return IP; }

private:
	string name;
	string IP;

};

