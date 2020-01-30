#pragma once



#include<iostream>

#include "LinkedList.h"

#include "Command.h"

#include "LinkedStack.h"



using namespace std;



class Editor {

public:

	Editor();

	void printLine();

	void readFile();

	void processCommand(char);



private:

	LinkedList <string> _buffer;

	int _capacity;

	int _numLines;

	int _currentLine;

	int _currentPos;

	string myLine;

	LinkedStack <Command> myStack;





};