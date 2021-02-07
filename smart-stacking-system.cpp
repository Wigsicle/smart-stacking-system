#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>

using namespace std;

class MyClass
{
public:
	MyClass();
	~MyClass();

private:

};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}

string storingBoxes(int posNum, int weight);

int main()
{
	string myText;
	string sarray[4] = {};
	int iarray[4] = {};
	ifstream MyReadFile("input-file.txt"); //Reads input file
	int rack1 = 10, rack2 = 12, rack3 = 14; //Setting rack weight limit

	for (int i = 0; i < 4; i++) //Stores lines in a string array called sarray.
	{
		getline(MyReadFile, myText);
		sarray[i] = myText; //Stores lines in a string array called sarray.
		iarray[i] = stoi(sarray[i].substr(12)); //Converts string to int and stores in iarray.
	}
	
	list<int> listBoxes; //Storing boxes into vector with their weight

	for (int i = 0; i < iarray[0]; i++)
	{	
		int x = 5;
		listBoxes.push_back(x);
	}
	for (int i = 0; i < iarray[1]; i++)
	{
		int x = 3;
		listBoxes.push_back(x);
	}
	for (int i = 0; i < iarray[2]; i++)
	{
		int x = 2;
		listBoxes.push_back(x);
	}
	for (int i = 0; i < iarray[3]; i++)
	{
		int x = 1;
		listBoxes.push_back(x);
	}
	
	//listBoxes.push_back(storingBoxes(iarray[3], 1));

	

	list<int>::iterator it;
	for (it = listBoxes.begin(); it != listBoxes.end(); it++)
	{
		cout << *it << endl;
	}
	
	//int rack[3][4]; //Rack


	MyReadFile.close();
}

vector<string> storingBoxes(int posNum, int weight) 
{
	vector<string> aVect;

	cout << "posNum: " << posNum << endl;
	for (int i = 0; i < posNum; i++)
	{
		int x = weight;
		string c = to_string(x);
		aVect.push_back(c);
		return aVect;
	}
}