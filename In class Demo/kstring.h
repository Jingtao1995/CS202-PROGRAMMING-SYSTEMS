//Sample implementation of a string
//class to demonstrate operator overloading
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

class kstring
{
     public:
        kstring();
        kstring(const kstring &);
        ~kstring();
        kstring & operator= (const kstring &);
        kstring & operator= (const char *);
        friend ostream & operator<< (ostream &,
                              const kstring &);
        friend istream & operator>> (istream &,
                              kstring &);
        
     
     private:
       char * str;
       int len;
      
};