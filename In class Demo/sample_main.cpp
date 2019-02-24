//Sample use of operator overloading
#include "kstring.h"

int main()
{
    kstring obj1, obj2;
    
    obj1 = obj2; //  obj1.operator=(obj2);
    obj1 = "hello";
    
    cin >> obj2;  // cin >> a;   
    
    cout << "here it comes: " <<obj2 <<endl;