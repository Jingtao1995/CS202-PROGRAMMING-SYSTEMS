   #include "kstring.h"
   //Implementation of the operators
   //overoaded for the "kstring" class
   
   //Default constructor
   kstring::kstring(): str(NULL), len(0) {}
   
   //Copy constructor
   kstring::kstring(const kstring & source)
   {
       len = source.len;
       str = new char[len+1];
       strcpy(str,source.str);
   }
  
   //destructor
   kstring::~kstring()
   {
      delete [] str;
      str = NULL;
      len = 0;
    }
    
//Assignment operators
kstring & kstring::operator= (const kstring & op2)
{
   // Check for self assignment
   if (this == &op2) //same entity???
     return *this; //current kstring object
   
   delete [] str;
   len = op2.len;
   str = new char[len+1];
   strcpy(str, op2.str);
   return *this;
}
   
   
kstring & kstring::operator= (const char * op2)
{
   if (str)
      delete [] str;
   len = strlen(op2);
   str = new char[len+1];
   strcpy(str, op2);
   return *this;
}

ostream & operator<< (ostream & op1,
                              const kstring & op2)
{
   op1<<op2.str;
   return op1;
}
                  
          
istream & operator>> (istream & op1,
                              kstring & op2)
{
   char temp[100];
   op1 >> temp;
   if (op2.str)
      delete [] op2.str;
   op2.len = strlen(temp);
   op2.str = new char[op2.len + 1];
   strcpy(op2.str, temp);
   return op1;
}
     