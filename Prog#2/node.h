//Name: Jingtao Cheng 
//ID: 940067494
//node.h
//This file was a header file for format a linear
//linked list for questions which belongs to practice
//objects.

#include <iostream>
#include <cstdio>
#include <cstring>
#include <time.h>

using namespace std;

//question class was a base class of node of linear linked
//list, it contians question and question number
class question
{
protected:
	char * _question;
	int number;
public:
	question(); //default constructor
	question(const char * initial); //copy constructor by argumetns
	question(const question &); //copy constructor by reference
	~question();//destructor
	//compare function used to check _question
	//and return true or false
	int compare(const char * match) const;
	//compare function used to check number
	//and return true or false
	int compare(const int num) const;
	//display funtion to display private member
	void display() const;
};

//node(of LLL) class derived from question class used to build
//the node for LLL
class lll_node : public question
{
private:
	lll_node * next; //next pointer point to lll_node
public:
	lll_node();//default constructor
	lll_node(const char * problem);//copy constructor by arguments
	lll_node(const question &);//copy constructor by reference
	~lll_node();//destructor

	//display function to invoke display function in
	//the question class
	void display();
	//function used to get node's next for traverse or
	//other purpose
	lll_node *& get_next();
	//function used to connect each node
	bool connect_next(lll_node * connection);
};
