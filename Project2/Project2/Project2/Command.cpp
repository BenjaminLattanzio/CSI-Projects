#include "Command.h"

#include <iostream>

using namespace std;



Command::Command() {



}



Command::Command(string input, string value) {

	mInput = input;

	mValue = value;

}



void Command::setCommand(string input) {



	mInput = input;



}



void Command::setValue(string& sValue) {



	mValue = sValue;

}



string Command::getCommand()const {



	return mInput;

}



void Command::display()const {

	cout << mInput << endl;

}

