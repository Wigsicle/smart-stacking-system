#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>

using namespace std;

void teammateNames() //This just prints our names
{
	vector<string> nVect;
	vector<string>::iterator it;
	nVect.push_back("Richard");
	nVect.push_back("Jian Yang");
	nVect.push_back("Hao Ran");
	for (it = nVect.begin(); it != nVect.end(); it++)
	{
		cout << *it << endl;
	}
}

class Stacking
{
public:
	string myText;
	string sarray[4] = {}; //String array to store myText
	int iarray[4] = {}; //Integer array to store the number of boxes
	int rackWeights[3] = { 14, 12, 10 }; //Setting rack weight limit Rack 1, Rack 2, Rack 3
	int total[3] = { 0, 0, 0 }; //Total weight for each rack when boxes are added
	int rack[3][4] = {}; //2D array to simulate a rack
	int skipSpace = 0; //Skip spaces counter
	int A = 0, B = 0, C = 0, D = 0; //Integers to store the different weights A = 5kg, D = 1kg //box counter

	list<int> lBoxes; //Storing boxes into list with their weight
	list<int>::iterator lbit; //List of boxes iterator
	list<int> outstandingBoxes; //Outstanding boxes list
	list<int>::iterator osbit; //Outstanding boxes iterator
	void readFile();
	void pushingBoxes();
	void rackingonRack();
	void display();
	void outBoxes();
	void skipSpaces();
};

void Stacking::readFile() //Method to read file
{
	ifstream MyReadFile("input-file.txt"); //Reads input file
	for (int i = 0; i < 4; i++) //Stores lines in a string array called sarray.
	{
		getline(MyReadFile, myText); //Getline and store in myText
		sarray[i] = myText; //Stores lines in a string array called sarray.
		iarray[i] = stoi(sarray[i].substr(12)); //Converts string to int and stores in iarray.
	}
	A = iarray[0], B = iarray[1], C = iarray[2], D = iarray[3]; //Storing into specific variables and used as a box counter
	MyReadFile.close(); //Close file
}

void Stacking::pushingBoxes() //Method to push boxes
{
	//Pushing boxes into lBoxes list based on their weight e.i 5 5 5 2 3 3 3 1
	for (int i = 0; i < A; i++)
	{
		lBoxes.push_back(5);
	}
	for (int i = 0; i < B; i++)
	{
		lBoxes.push_back(3);
	}
	for (int i = 0; i < C; i++)
	{
		lBoxes.push_back(2);
	}
	for (int i = 0; i < D; i++)
	{
		lBoxes.push_back(1);
	}
	cout << "Visual representaion of the individual boxes - ";
	for (lbit = lBoxes.begin(); lbit != lBoxes.end(); lbit++)
	{
		cout << *lbit << " ";
	}
	cout << endl;
}

void Stacking::rackingonRack() //Method to stack the racks
{
	for (int a = 0; a < 3; a++) //Rack rows loop
	{
		for (int b = 0; b < 4; b++) //Rack columns loop
		{
			if ((rackWeights[a] >= 5) && ((A > 0))) //Checking if rackWeights[] has space and that there are more than zero boxes for that weight
			{
				rack[a][b] = 5;
				rackWeights[a] -= 5;
				total[a] += 5;
				A--;
			}
			else if ((rackWeights[a] >= 3) && ((B > 0)))
			{
				rack[a][b] = 3;
				rackWeights[a] -= 3;
				total[a] += 3;
				B--;
			}
			else if ((rackWeights[a] >= 2) && ((C > 0)))
			{
				rack[a][b] = 2;
				rackWeights[a] -= 2;
				total[a] += 2;
				C--;
			}
			else if ((rackWeights[a] >= 1) && ((D > 0)))
			{
				rack[a][b] = 1;
				rackWeights[a] -= 1;
				total[a] += 1;
				D--;
			}
		}
	}
}

void Stacking::display() //Method to display
{
	//Display
	cout << "Smart Stacking System\n" << endl;
	for (int i = 2; i >= 0; i--)
	{
		cout << "Rack " << i + 1 << " - ";
		for (int t = 0; t < 4; t++)
		{
			if (rack[i][t] == 0)
			{
				if (i == 2)
				{
					cout << "_ ";
				}
				else
				{
					cout << "_ ";
					skipSpace++;
				}
			}
			else
			{
				cout << rack[i][t] << " ";
			}
		}
		cout << " - (Total: " << total[i] << " kg)" << endl; //Print total weight of rack
	}
}

void Stacking::outBoxes() //Method to print outstanding boxes
{
	//Pushing remaining boxes into outstandingBoxes list
	for (int i = 0; i < A; i++)
	{
		outstandingBoxes.push_back(5);
	}
	for (int i = 0; i < B; i++)
	{
		outstandingBoxes.push_back(3);
	}
	for (int i = 0; i < C; i++)
	{
		outstandingBoxes.push_back(2);
	}
	for (int i = 0; i < D; i++)
	{
		outstandingBoxes.push_back(1);
	}

	cout << "Outstanding Boxes: ";
	if (!outstandingBoxes.empty())
	{
		for (osbit = outstandingBoxes.begin(); osbit != outstandingBoxes.end(); osbit++)
		{
			cout << *osbit << " ";
		}
	}
	else
	{
		cout << "0";
	}
}

void Stacking::skipSpaces() //Method to skip spaces 
{
	cout << "\nSkipped Spaces: " << skipSpace << endl;
}

int main()
{
	Stacking myObj;
	teammateNames();
	myObj.readFile();
	myObj.pushingBoxes();
	myObj.rackingonRack();
	myObj.display();
	myObj.outBoxes();
	myObj.skipSpaces();
}