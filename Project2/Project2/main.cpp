#include <iostream>

#include <string>

#include "ArrayStack.h"

#include "LinkedStack.h"

#include "Node.h"

#include "StackInterface.h"

#include <cassert>
#include "Editor.h"

#include "Command.h"
#include<conio.h>
#include "NotFoundException.h"




using namespace std;



int main()

{

	ArrayStack <Command> myArraystack;

	Command myCommand;

	string aValue;

	string input;

	string doInput = "y";
	bool check = true;


	Editor myEdit;
	myEdit.readFile();
	myEdit.printLine();
	
	while (check) {
		input=_getch();

		if (input == "q")
			break;
		else
			
		
		
		myCommand.setCommand(input);
		myEdit.processCommand(input);
		system("cls");
		myEdit.printLine();

	}
	

	


	
	return 0;
}



