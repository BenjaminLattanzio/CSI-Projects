#pragma once

#include<iostream>

#include<string>

#include "ArrayStack.h"



using namespace std;

class Command {

public:

	Command();

	Command(string, int , string);

	void setCommand(string);

	string getWords() const;

	string getInput() const;

	void setWords(string& sCommand);

	void display()const;

	int getPosition() const;

	bool operator<<(const Command &p);

private:

	string mInput;

	string mWords;

	int mPosition;

};