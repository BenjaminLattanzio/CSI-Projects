#pragma once



#include<iostream>

#include "LinkedList.h"

#include "Command.h"

#include "LinkedStack.h"
#include"BinaryNode.h"
#include"BinaryNodeTree.h"
#include"BinarySearchTree.h"
#include "BinaryTreeInterface.h"
#include "NotFoundException.h"


using namespace std;



class Editor {

public:

	Editor();

	void printLine();

	void readFile();

	void processCommand(string);

	bool deleteLine(string, int, string);

	bool insertLine(string, int, string);

	void goToXY(int, int);
	
	void colorText(int);

private:

	LinkedList <string> _buffer;

	int _capacity;

	int _numLines;

	int _currentLine;

	int _currentPos;

	string myLine;

	LinkedStack <Command> myStack;

	ArrayStack <Command> myArraystack;

	BinarySearchTree <string> *Keywords;



};