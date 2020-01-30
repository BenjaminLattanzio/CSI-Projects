#include "Command.h"

#include <iostream>

using namespace std;



Command::Command() {



}



Command::Command(string input,int position, string words) {

	mInput = input;

	mWords = words;

	mPosition = position;
}



void Command::setCommand(string input) {



	mInput = input;



}



void Command::setWords(string& sWords) {



	mWords = sWords;

}



string Command::getWords()const {



	return mWords;

}

string Command::getInput()const {



	return mInput;

}


int Command::getPosition()const {



	return mPosition;

}



void Command::display()const {

	cout << mInput << endl;

}

