#include<iostream>

#include "LinkedList.h"

#include "Editor.h"

#include <fstream>

#include "Command.h"

#include "ArrayStack.h"
#include<conio.h>
#include<sstream>
#include<iterator>
#include<vector>
#include<windows.h>
#include"BinaryNode.h"
#include"BinaryNodeTree.h"
#include"BinarySearchTree.h"
#include "BinaryTreeInterface.h"


using namespace std;





void Editor::readFile() {
	
	string line;
	string line2;
	ifstream myFile;
	ifstream myFile2;
	Keywords = new BinarySearchTree<string>;

	LinkedList <string> myList;

	myFile.open("test.txt");

	myFile2.open("Keywords.txt");

	for (int i = 0; !myFile2.eof(); i++) {

		
		myFile2 >> line2;

		Keywords->add(line2);

	}


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
	 _capacity=0;

	 _numLines = 0;

	 _currentLine=1;

	 _currentPos=1;

}



void Editor::printLine() {

	string myLine;

	int i, j;
	
	for (i = 1; i < _numLines; i++) {

		myLine = _buffer.getEntry(i);

		/*if (i == _currentLine){

		//cout << "^" << myLine << endl;

		for (j = 1; j <= _currentPos; j++){

		cout << " ";

		}

		//cout << "^" << endl;

		}

		else

		cout << " " << myLine << endl;

		*/





		istringstream streamWords{ myLine };



		vector<string> words{

			istream_iterator<string>(streamWords), istream_iterator<string>()

		};

		bool isKeyword;

		for (string currentWord : words) {

			isKeyword = Keywords->contains(currentWord);

			if (isKeyword)

				colorText(FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | 0X80);  //blue



			else

				colorText(0XF0);


			//note: updated to remove the extra blanks

			

				cout << " " << currentWord;

		}

		cout << endl;

	}

	goToXY(_currentPos, _currentLine - 1);

}




void Editor:: goToXY(int column, int line) {

	COORD coord;

	coord.X = column;

	coord.Y = line;

	SetConsoleCursorPosition(

		GetStdHandle(STD_OUTPUT_HANDLE),

		coord);

}

void Editor:: colorText(int value) {

	COORD coord;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	FlushConsoleInputBuffer(hConsole);

	SetConsoleTextAttribute(hConsole, value);

}





void Editor::processCommand(string command) {



	if (command == "j") {
		if(_currentLine!=_numLines-1)
		_currentLine++;



	}



	else if (command == "k") {
		if(_currentLine!=1)
		_currentLine--;

	}



	else if (command == "l") {
		if(_currentPos<= _buffer.getEntry(_currentLine).size())
		_currentPos++;


	}



	else if (command == "h") {
		if(_currentPos!=1)
		_currentPos--;


	}
	else if (command == "d") {
		string in;
		in = _getch();
		if (in == "d")
		deleteLine(command, _currentLine, _buffer.getEntry(_currentLine ));

	}

	else if (command == "u" && myArraystack.isEmpty()!=true) {
		string undo = myArraystack.peek().getWords();
		int value = myArraystack.peek().getPosition();

		if (myArraystack.peek().getInput() == "I") {
			_buffer.remove(myArraystack.peek().getPosition());
			myArraystack.pop();
			_numLines--;
		}
		else if(myArraystack.peek().getInput() == "d"){
			_buffer.insert(value, undo);
			myArraystack.pop();
			_numLines++;
		}
		else if (myArraystack.peek().getInput() == "x") {
			_buffer.remove(myArraystack.peek().getPosition());
			_buffer.insert(value, undo);
			myArraystack.pop();
		}


	}
	else if (command == "I") {
		string input;
		cin >> input;
		insertLine(command, _currentLine, input);
	}
	else if (command == "x") {
		string tempString;

		tempString = _buffer.getEntry(_currentLine);
		
		Command myCommand(command,_currentLine,tempString);
		myArraystack.push(myCommand);
		tempString = tempString.erase(_currentPos-1,1);
		_buffer.replace(_currentLine,tempString);
	
	}





}

bool Editor::deleteLine(string input, int line, string words) {
	
	bool ableToDelete = (_currentLine >= 1 && _currentLine <= _numLines);

	if (ableToDelete){
		Command myCommand(input , line, words);
		myArraystack.push(myCommand);

		_buffer.remove(line);
		_numLines--;
	}
	return ableToDelete;
}

bool Editor::insertLine(string input, int line, string words) {

	bool ableToInsert = (_currentLine >= 1 && _currentLine <= _numLines);

	if (ableToInsert) {
		Command myCommand(input, line, words);
		myArraystack.push(myCommand);

		_buffer.insert(line,words);
		_numLines++;
	}
	return ableToInsert;
}
