#include<iostream>

#include "LinkedList.h"

#include "Editor.h"

#include <fstream>

#include "Command.h"



using namespace std;





void Editor::readFile() {

	string line;

	ifstream myFile;

	myFile.open("test.txt");

	LinkedList <string> myList;







	if (!myFile.is_open()) {

		cout << "File doesn't open" << endl;

	}
	else
		cout << "open" << endl;






	for (int i = 0; !myFile.eof(); i++) {

		getline(myFile, line);

		_buffer.insert(i, line);
		_numLines++;
	}



}





Editor::Editor() {



}



void Editor::printLine() {

	int i, j;

	for (i = 1; i < _numLines + 1; i++) {

		myLine = _buffer.getEntry(i);

		if (i == _currentLine) {

			cout << "^" << _buffer.getEntry(i) << endl;

			for (int j = 1; j < _currentPos; j++) {

				cout << " ";

			}

			cout << "^" << endl;

		}

		else

			cout << " " << _buffer.getEntry(i) << endl;

	}

}





void Editor::processCommand(char command) {



	if (command == 'j') {



	}



	else if (command == 'k') {



	}



	else if (command == 'l') {



	}



	else if (command == 'h') {



	}





}

