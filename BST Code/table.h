//This class was prepared for a binary search tree implementation of
//a table abstraction. For the lab we will keep the underlying data
//simple - just an integer.
//

#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>

struct node
{
    int data;
    node * left;
    node * right;;
};

class table
{
    public:
      // **** These functions are provided for you
	  table();
	  ~table();
	  int build(); 
	  int display(int=-99);  //Send in zero for the final result

	  //  **** THESE ARE THE WRAPPER Functions that YOU will write!
	  int count();          //STEP 1
	  int count_right_subtree();		//STEP 2
	  int remove_largest();	//STEP 3
      int sum();            //STEP 4
	  int copy(table & to_copy);  //STEP 5

	  //Challenge
  	  int create_full();	//STEP 6a
	  bool is_full();		//STEP 6b
	  int display_largest();	//STEP 6c
	  int display_largest2();	//STEP 6d
      int height();

    private:

 	  node * root;

	  //  ***These are the functions you will be writing recursively!
	  int count(node * root);
	  int count_right_subtree(node * root);
	  int remove_largest(node * & root);
	  int sum(node * root);
	  int copy(node * & destination, node * source);
    
    int count(node *, int);
    int counting(node *);
    int insert(node *&, int);
    int height(node *);


	  //Challenge
      int create_full(node * & new_tree); 
	  bool is_full(node * root);
	  int display_largest(node * root);
	  int display_largest2(node * root);
      int display_largest2(node *,int &);


};
