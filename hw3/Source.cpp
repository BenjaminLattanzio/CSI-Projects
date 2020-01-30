#include <iostream>

#include <map>

#include <fstream>

#include <algorithm>

#include <string>

#include <sstream>

using namespace std;

int main()

{

	ifstream file;

	string myLine;

	file.open("input.txt"); //opening file named input.txt

	if (file.fail())

	{

		cout << "Failed to open the input file" << endl;

		exit(1);

	}


	map <string, int> found; //using map container allows us to save each word with string while counting the 
	//frequency with int//

	while (!file.eof()) //getting the info from the txt file 

	{



		file >> myLine; //we must read and save each word



		for (int i = 0; i < myLine.length(); i++) //we dont want punctuation to count as word so we make them count as a space

		{

			if (myLine.at(i) == ',' || myLine.at(i) == '.' || myLine.at(i) == ':' || myLine.at(i) == ';')

			{

				myLine.at(i) = ' ';

			}

		}

		//Read the word into string stream

		stringstream ss(myLine);

		string object;

		//Split the line by space

		while (getline(ss, object, ' '))

		{

			//To ignore numbers

			bool isNumber = false;

			//Check for number

			for (int k = 0; k < object.length(); k++)

			{

				//if a number is exist, break from the loop

				if (isdigit(object.at(k)))

				{

					isNumber = true;

					break;

				}

			}

			//if number is exist, ignore

			//otherwise store it into map

			if (isNumber != true)

			{

				//use algorithm transform to convert each word into lower case

				transform(object.begin(), object.end(), object.begin(), tolower);

				//if the word is already exist in the concardance,

				//increment its frequency

				if (found.find(object) != found.end()) //if the word is already found in found container, increment by 1

				{

					found[object]++;

				}

				//if the word is not exist yet in the concardance,

				//intialize the frequency of the word with 1

				else

				{

					found[object] = 1;

				}

			}

		}

	}

	//Print the words and thier frequency from map

	for (map <string, int>::iterator ci = found.begin(); ci != found.end(); ci++)

	{

		cout << (*ci).first << "\t" << (*ci).second << endl;

	}


	system("pause");


}