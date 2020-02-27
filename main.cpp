#include "Tree.h"
#include<iostream>

using namespace std;

int main()
{
	Tree t;
	cout << "Welcome to Intelli-Ship! " << endl;
	cout << "Let Right and Left be two sides of the river" << endl;
	cout << "Let all missionaries and cannibals start on the left" << endl;
	cout << "Their aim is to get to other side i.e. right" << endl << endl << endl;
	cout << "The start state is mmmccc000000 i.e. all missionaries and cannibals are on left side" << endl;
	cout << "This means that this 12 character string has 6 empty spaces(from the end) " << endl;
	cout << "or 6 0s in the end, denoting everyone is at left" << endl;
	cout << "Our aim is to reach a goal state using BFS such that there are 6 empty spaces (from the start) " << endl;
	cout << "denoting everyone has moved to right" << endl;


	t.BFS("mmmccc000000");


	t.display();


	cin.get();
	cin.ignore();
	return 0;
}