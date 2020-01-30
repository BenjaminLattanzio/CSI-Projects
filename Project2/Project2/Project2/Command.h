#pragma once

#include<iostream>

#include<string>

#include "ArrayStack.h"



using namespace std;

class Command {

public:

	Command();

	Command(string, string);

	void setCommand(string);

	string getCommand() const;

	void setValue(string& sCommand);

	void display()const;

	bool operator<<(const Command &p);

private:

	string mInput;

	string mValue;

};