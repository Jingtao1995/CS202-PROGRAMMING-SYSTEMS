#include "clist.h"


int main()
{
    list object;
    object.build();		//builds a circular LL
    object.display();	//displays the list

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    
    list new_object;

    object.copy_special(new_object);

    new_object.display();

    cout<<"------------------------------------------------------------------"<<endl;

    object.display(); //resulting list after your function call!
    
    return 0;
}
