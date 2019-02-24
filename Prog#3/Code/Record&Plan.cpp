/*--------------------------------------------
    Name: Jingtao Cheng
    Course: CS202
    Date: Nov 19.2017
    Program3
--------------------------------------------*/

#include "Record&Plan.h"

/*--------------------------------------------
 This is the default constructor to initial
 all arguments to NULL
 --------------------------------------------*/
Plan :: Plan()
{
    plan_name = NULL;
    exercise_type = NULL;
}

/*--------------------------------------------
 This is the copy constructor of Plan class and
 will copy all arguments into the object
 --------------------------------------------*/
Plan :: Plan(char * name, char * type, int freq, int days)
{
    plan_name = new char[strlen(name) + 1];
    strcpy(plan_name, name);
    exercise_type = new char[strlen(type) + 1];
    strcpy(exercise_type, type);
    frequency = freq;
    training_days = days;
}

/*--------------------------------------------
 This is the copy constructor of Plan class and
 will copy all information from another object
 --------------------------------------------*/
Plan :: Plan(const Plan & object)
{
    plan_name = new char[strlen(object.plan_name) + 1];
    strcpy(plan_name, object.plan_name);
    exercise_type = new char[strlen(object.exercise_type) + 1];
    strcpy(exercise_type, object.exercise_type);
    frequency = object.frequency;
    training_days = object.training_days;
}

/*--------------------------------------------
 This is the default destructor and will free all
 dynamically allocated memory
 --------------------------------------------*/
Plan :: ~Plan()
{
    delete [] plan_name;
    plan_name = NULL;
    delete [] exercise_type;
    exercise_type = NULL;
}

/*--------------------------------------------
 This is the display function to display all
 information in the Plan object
 --------------------------------------------*/
void Plan :: display()
{
    cout<<"Plan name: " << plan_name << " ; "
    <<"Exercise Type: " << exercise_type << " ; "
    <<"Frequency: " << frequency << " ; "
    <<"Training Days: " << training_days << " ; "
    <<endl;
}

/*--------------------------------------------
 This is the funciton used to compare plan_name
 and return boolean
 --------------------------------------------*/
bool Plan :: compare(char * name)
{
    if(strcmp(plan_name, name) == 0)
        return true;
    return false;
}

/*--------------------------------------------
 This is the default constructor and initial
 next to NULL
 --------------------------------------------*/
Plan_Node :: Plan_Node()
{
    next = NULL;
}

/*--------------------------------------------
 This is the copy constructor and will copy all
 arguments into the node
 --------------------------------------------*/
Plan_Node :: Plan_Node(char * name, char * type, int freq, int days) : Plan(name, type, freq, days), next(NULL){}

/*--------------------------------------------
 THis is the copy constructor copy the object
 from another node
 --------------------------------------------*/
Plan_Node :: Plan_Node(const Plan_Node & object) : Plan(object), next(NULL){}

/*--------------------------------------------
 This is the function used to get next pointer
 --------------------------------------------*/
Plan_Node *& Plan_Node :: go_next()
{
    return next;
}

/*--------------------------------------------
 This is the funciton used to set next pointer
 and connect node in the plan list
 --------------------------------------------*/
void Plan_Node :: set_next(Plan_Node * to_set)
{
    next = to_set;
}

/*--------------------------------------------
 This is the display function used to invoke
 base class's display function
 --------------------------------------------*/
void Plan_Node :: display()
{
    Plan :: display();
}
/*
bool Plan_Node :: search_by_name(char * to_find)
{
    if(Plan :: compare(to_find))
        return true;
    return false;
}
*/

/*--------------------------------------------
 This is the operator overload that overload +
 that meaning insert Plan node into plan list
 --------------------------------------------*/
void Plan_Node :: operator+(Plan_Node * to_connect)
{
    set_next(to_connect);
}

/*--------------------------------------------
 This is the operator overloading overload !=
 that means compare the name
 --------------------------------------------*/
bool Plan_Node :: operator!=(char * to_compare)
{
    return compare(to_compare);
}

/*--------------------------------------------
 This is the default constructor and will initial
 all member to NULL
 --------------------------------------------*/
Record :: Record()
{
    race_record = NULL;
}

/*--------------------------------------------
 This is copy constructor will copy all arguments
 into the object
 --------------------------------------------*/
Record :: Record(char * record, int date)
{
    race_record = new char[strlen(record) + 1];
    strcpy(race_record, record);
    year = date;
}

/*--------------------------------------------
 This is the copy constructor will copy another
 object into this object
 --------------------------------------------*/
Record :: Record(const Record & object)
{
    race_record = new char[strlen(object.race_record) + 1];
    strcpy(race_record, object.race_record);
    year = object.year;
}

/*--------------------------------------------
 This is the default destructor used to free
 dynamically allocated memory
 --------------------------------------------*/
Record :: ~Record()
{
    delete [] race_record;
    race_record = NULL;
}

/*--------------------------------------------
 This is the function used to display information
 int the record object
 --------------------------------------------*/
void Record :: display()
{
    cout << "Race Record: " << race_record << " ; "
    << " In " << year << " years ; " <<endl;
}
/*--------------------------------------------
 This is the compare funciton used to match
 race record
 --------------------------------------------*/
bool Record :: compare(char * to_compare)
{
    if(strcmp(race_record, to_compare) == 0)
        return true;
    return false;
}

/*--------------------------------------------
 This is the default constructor to initial
 next to NULL
 --------------------------------------------*/
Record_Node :: Record_Node()
{
    next = NULL;
}

/*--------------------------------------------
 This is the copy constructor will copy all
 argumetns into this obkect
 --------------------------------------------*/
Record_Node :: Record_Node(char * record, int date) : Record(record, date), next(NULL){}

/*--------------------------------------------
 This is the copy constructor will copy another
 object into this object
 --------------------------------------------*/
Record_Node :: Record_Node(const Record_Node& object) : Record(object), next(NULL){}

/*--------------------------------------------
This is the function used to return next pointer
 --------------------------------------------*/
Record_Node *& Record_Node :: go_next()
{
    return next;
}

/*--------------------------------------------
 This is the function used to conncent list
 by set next pointer
 --------------------------------------------*/
void Record_Node :: set_next(Record_Node * to_set)
{
    next = to_set;
}

/*--------------------------------------------
 This is the display function call base class
 display function
 --------------------------------------------*/
void Record_Node :: display()
{
    Record :: display();
}

/*--------------------------------------------
 This is the funciton to return year member
 --------------------------------------------*/
int Record_Node :: get_year()
{
    return year;
}

/*--------------------------------------------
 This is the operator overloading that means
 to match record
 --------------------------------------------*/
bool Record_Node :: operator!=(char * to_compare)
{
    return compare(to_compare);
}



