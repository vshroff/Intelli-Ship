#ifndef TREE_H
#define TREE_H
#include<iostream>
#include<list>
#include<queue> 
#include<unordered_set>
#include<algorithm>
#include<string>

using namespace std;


class Tree {

private:

	struct Node
	{
		string state;
		Node *parent;
		string action;

	};
	Node *root;

	vector <Node*> display_list; //list to store nodes that can be displayed later

	string goal = "000000cccmmm"; //since start is set to mmmccc000000

public:



	//Breadth First Search Algorithm
	void BFS(string problem)
	{

		//checking to see that the current problem state is the goal state or not
		if (problem == goal)
		{
			cout << "Already in Solution state!" << endl;
			return;
		}

		queue <Node*> frontier; //container
		unordered_set <Node*> explored; //a set to keep track of visited nodes


		//unique_ptr<Node> newnode(new Node);

		//Creating a new node and giving it the problem state, this will be the first parent node
		Node *newnode = new Node();
		newnode->state = problem;


		//we push this node into our container
		frontier.push(newnode);


		//While container is not empty
		while (!frontier.empty())
		{
			//We insert this node in the visited/explored set to keep track of nodes
			explored.insert(frontier.front());

			//using a vector here which we can later traverse to display all the actions
			display_list.push_back(frontier.front());


			//Creating a child node
			Node* n = new Node();

			//childnode function gives the child of the current node
			n = childNode(frontier.front());


			//popping the node from the frontier queue
			frontier.pop();

			//if the child node isn't already explored, we push it in the frontier
			if (explored.find(n) == explored.end())
			{

				if (n->state == goal)
				{

					return;
				}

				frontier.push(n);

			}

		}

	}

	/*
	Function to generate the child node for every node by
	making a call to the compute a LEGAL action for every state
	*/

	Node* childNode(Node * n)
	{
		Node* child = new Node();
		child->parent = n;
		child->state = "";
		string parent_state = n->state;
		child->state = compute_action(n); //computing the action of each state


		return child;
	}

	/*
	This function is called by the childnode function, to COMPUTE THE CHILD FOR EACH PARENT


	This function performs 2 important tasks:-
	1) computes the next state of any given current state i.e. Computed legal ction on the basis of State Space Diagram
	2) checks if the current state is a goal state i.e. GOAL TEST
	Hence, this is computation as well as GOAL TEST function
	*/
	string compute_action(Node * n)
	{

		//An array of all possible states as described in the state diagram
		string A[12] = {
			"mmmccc000000",
			"0mm0cc00c00m",
			"mmm0cc00c000",
			"mmm000ccc000",
			"mmmc00cc0000",
			"00mc00cc00mm",
			"m0mcc0c000m0",
			"000cc0c00mmm",
			"000ccc000mmm",
			"00000c0ccmmm",
			"000c0c0c0mmm",
			"000000cccmmm"
		};


		string curr_state = n->state;

		/*
		COMPUTATION of each state's action is done through a set of swaps at each state
		since different states have different encoding schemes,
		I have used a simple if/else structure to move from one state to the next
		*/

		if (curr_state == A[0])
		{

			//shifting right
			swap(curr_state[0], curr_state[11]);
			swap(curr_state[3], curr_state[8]);
			//s = curr_state;

			// Given an action to every node to reach the next state
			n->action = "One Missionary and Cannibal move to the right side of the river";


			return curr_state;

		}
		if (curr_state == A[1])
		{
			//shifting left 
			swap(curr_state[11], curr_state[0]);

			n->action = "The missonary comes back to the left";
			return curr_state;

		}
		if (curr_state == A[2])
		{
			//shifting right
			swap(curr_state[4], curr_state[7]);
			swap(curr_state[5], curr_state[6]);

			n->action = "Two Cannibals move to the right";
			return curr_state;

		}
		if (curr_state == A[3])
		{
			//shifting left
			swap(curr_state[8], curr_state[3]);


			n->action = "One Cannibal comes back to the left";
			return curr_state;

		}
		if (curr_state == A[4])
		{
			//shifting right 
			swap(curr_state[0], curr_state[11]);
			swap(curr_state[1], curr_state[10]);

			n->action = "Two Missionaries move to the right";
			return curr_state;

		}
		if (curr_state == A[5])
		{
			//shifting left
			swap(curr_state[11], curr_state[0]);
			swap(curr_state[7], curr_state[4]);

			n->action = "One Missionary and one Cannibal come back to the left";
			return curr_state;

		}
		if (curr_state == A[6])
		{
			//shifting right
			swap(curr_state[0], curr_state[11]);
			swap(curr_state[2], curr_state[9]);

			n->action = "Two Missionaries move to the right side";
			return curr_state;

		}
		if (curr_state == A[7])
		{
			//shifting left
			swap(curr_state[6], curr_state[5]);


			n->action = "One Cannibal comes back to the left";
			return curr_state;

		}
		if (curr_state == A[8])
		{
			//shifting right
			swap(curr_state[3], curr_state[8]);
			swap(curr_state[4], curr_state[7]);

			n->action = "Two Cannibals move to the right";

			return curr_state;

		}
		if (curr_state == A[9])
		{
			//shifting left
			swap(curr_state[8], curr_state[3]);

			n->action = "One Cannibal comes back to the left";

			return curr_state;

		}
		if (curr_state == A[10])
		{
			//shifting right
			swap(curr_state[3], curr_state[8]);
			swap(curr_state[5], curr_state[6]);

			n->action = "Two Cannibals move to the right and All Missionaries and Cannibals are on the right!";
			return curr_state;

		}
		//GOAL testing 
		if (curr_state == A[11])
		{
			//this is the goal state

			return curr_state;

		}


	}

	/*

	Function used to display everything stored in the list after searching

	*/

	void display()
	{
		cout << endl;
		for (int i = 0; i < display_list.size(); i++)
		{
			cout << display_list[i]->action << endl;
		}


	}






};

#endif









