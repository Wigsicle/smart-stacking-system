#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

class Stacking
{
public:
	Stacking();

private:

};

Stacking::Stacking()
{
}

int main()
{
	string myText;
	string sarray[4] = {};
	int iarray[4] = {};
	ifstream MyReadFile("input-file.txt"); //Reads input file
	int rackWeights[3] = { 14, 12, 10 }; //Setting rack weight limit
	int total[3] = { 0, 0, 0 }; //Total weight for each rack when boxes are added
	int rack[3][4] = {}; //Rack
	int skipSpaces = 0;

	for (int i = 0; i < 4; i++) //Stores lines in a string array called sarray.
	{
		getline(MyReadFile, myText);
		sarray[i] = myText; //Stores lines in a string array called sarray.
		iarray[i] = stoi(sarray[i].substr(12)); //Converts string to int and stores in iarray.
	}
	int A = iarray[0], B = iarray[1], C = iarray[2], D = iarray[3];

	list<int> lBoxes; //Storing boxes into list with their weight
	list<int> outstandingBoxes; //Outstanding boxes list
	list <int>::iterator osbit; //Outstanding boxes iterator

	//Pushing boxes into lBoxes list based on their weight e.i 5 5 5 2 3 3 3 1
	for (int i = 0; i < iarray[0]; i++)
	{
		lBoxes.push_back(5);
	}
	for (int i = 0; i < iarray[1]; i++)
	{
		lBoxes.push_back(3);
	}
	for (int i = 0; i < iarray[2]; i++)
	{
		lBoxes.push_back(2);
	}
	for (int i = 0; i < iarray[3]; i++)
	{
		lBoxes.push_back(1);
	}
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
	//Display
	cout << "Monke Stacking System\n" << endl;
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
					skipSpaces++;
				}
			}
			else
			{	
				cout << rack[i][t] << " ";
			}
		}
		cout << " - (Total: " << total[i] << " kg)" << endl; //Print total weight of rack
	}
	
	MyReadFile.close(); //Close file

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
	cout << "\nSkipped Spaces: " << skipSpaces << endl;
}
