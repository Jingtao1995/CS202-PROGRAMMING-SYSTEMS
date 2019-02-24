#include "table.h"
using namespace std;

//These are the functions that you will be writing for Lab #10

int table::height()
{
    if(!root)
        return 0;
    return height(root);
}

int table::height(node * root)
{
    if(!root)
        return 0;
    int lheight = height(root->left);
    int rheight = height(root->right);
    if(lheight > rheight)
        return (lheight+1);
    else
        return (rheight+1);
}

//STEP 1
int table::count()	//SAMPLE wrapper function
{
	return count(root);
}

int table::count(node * root){
    if(!root)
        return 0;
    else
        return count(root,root->data);
}

int table::count(node * root, int data){
    if(!root)
        return 0;
    if(root->data == data)
        return count(root->left,data) + count(root->right,data) +1;
    else
        return count(root->left,data) + count(root->right,data);
}


//STEP 2
int table::count_right_subtree(){
    if(!root)
        return 0;
    else
        return count_right_subtree(root);
}
int table::count_right_subtree(node * root){
    if(!root)
        return 0;
    if(root->left == NULL)
        return counting(root->right);
    else
        return count_right_subtree(root->left);
}

int table::counting(node * root){
    if(!root)
        return 0;
    return counting(root->left)+counting(root->right)+1;
}

//STEP 3
int table::remove_largest(){
    if(!root)
        return 0;
    return remove_largest(root);
}
int table::remove_largest(node * & root){
    if(!root)
        return 0;
    if(root->right == NULL)
    {
        int largest = root->data;
        node * temp = root;
        root = root->left;
        delete temp;
        temp = NULL;
        return largest;
    }
    return remove_largest(root->right);
}


//STEP 4
int table::sum(){}
int table::sum(node * root){}

//STEP 5
int table::copy(table & to_copy){
    if(to_copy.root == NULL)
        return 0;
    return copy(root, to_copy.root);
}
int table::copy(node * & destination, node * source){
    if(!source)
        return 0;
    if(source->data % 2 == 0)
    {
        insert(destination,source->data);
    }
    return copy(destination, source->left)+copy(destination, source->right);
}
int table::insert(node *& root, int data)
{
    if(!root)
    {
        root = new node;
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        return 1;
    }
    if(root->data <= data)
    {
        return insert(root->right, data);
    }
    else
        return insert(root->left, data);
}

//STEP 6a Challenge
int table::create_full(){}
int table::create_full(node * & new_tree){}


//STEP 6b
bool table::is_full(){
    if(!root)
        return false;
    return is_full(root);
}
bool table::is_full(node * root){
    if(!root)
        return true;
    if(!root->left && !root->right)
        return true;
    if(root->left && root->right)
        return true;
    return false;
}


//STEP 6c
int table::display_largest(){}
int table::display_largest(node * root){}


//STEP 6d
int table::display_largest2(){
    if(!root)
        return 0;
    return display_largest2(root);
}
int table::display_largest2(node * root){
    if(!root)
        return 0;
    int i = 0;
    return display_largest2(root, i);
}
int table::display_largest2(node * root, int & i)
{
    if(!root || i >= 2)
        return 0;
    display_largest2(root->right, i);
    if(i == 0 || i == 1 )
    {
        cout << root->data << endl;
    }
    ++i;
    display_largest2(root->left, i);
}






