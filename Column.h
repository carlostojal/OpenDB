#pragma once

#include <iostream>

using namespace std;

class Column
{
	public:
		Column();
		Column(string name);
		Column(string name, string value);
		string name;
		string value;
};

