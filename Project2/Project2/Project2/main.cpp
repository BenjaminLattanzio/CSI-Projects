#include <iostream>

#include <string>

#include "ArrayStack.h"

#include "LinkedStack.h"

#include "Node.h"

#include "StackInterface.h"

#include <cassert>
#include "Editor.h"

#include "Command.h"



using namespace std;



int main()

{

	ArrayStack <Command> myArraystack;

	Command myCommand;

	string aValue;

	string input;

	string doInput = "y";



	Editor myEdit;
	myEdit.readFile();


	myCommand.setCommand(input);

	if (input == "i") {

		myArraystack.push(myCommand);

		myCommand.display();

	}

	else if (input == "dd") {

		myArraystack.push(myCommand);

		myCommand.display();

	}

	else if (input == "x") {

		myArraystack.push(myCommand);

		myCommand.display();

	}

	else if (input == "u") {

		cout << "Command that is undone: " << endl;

		cout << myArraystack.peek().getCommand() << endl;

		myArraystack.pop();

		cout << "Current command on top: " << endl;

		cout << myArraystack.peek().getCommand() << endl;

	}

	else {

		myCommand.setCommand(input);

		myCommand.setValue(aValue);

		myArraystack.push(myCommand);

	}
	return 0;
}


