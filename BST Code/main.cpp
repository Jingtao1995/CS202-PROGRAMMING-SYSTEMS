#include "table.h"
using namespace std;

int main()
{
    table BST;	
    BST.build();
    BST.display();

    /*  PLACE YOUR FUNCTION CALL HERE */
    //cout << "Height: " << BST.height() << endl;
    //cout << "Count number matches root's data: " << BST.count() << endl;
    //cout << "Count number of smallest node's right subtree: " <<BST.count_right_subtree() <<endl;
    //cout << "Largest: " <<BST.remove_largest() << endl;
    cout << "Display largest 2: " << endl;
    BST.display_largest2();

    //table new_BST;
    //new_BST.copy(BST);
    //cout<<"Display new BST: "<<endl;
    //new_BST.display(0);

    //BST.display(0);

    return 0;
}
