//Name: Jingtao Cheng
//ID: 940067494
//CS202 Winter Program 2
//
//This is the main cpp file which contains almost all
//of the interface relate to the operations such as 
//insert object into a doubly linked list and import
//all the informations stored in the external file into
//the data structures. There also has interface to the 
//remove, remove all, retrieve and translate functions.

#include "Prog2.h"
#include <iomanip>
#include <fstream>

int main()
{
    client Prog2;


    Text *text = new Text;
    Formal *formal = new Formal;
    Special *special = new Special;
    char response;
    do{
        cout << "Do you want to insert a new method" <<endl;
        cin>>response;
        cin.ignore();
        if(response == 'Y' || response == 'y')
        {
            cout<<"Type 1: Text(Lots of Abbreviation)"<<endl;
            cout<<"Type 2: Formal(Used in Bussiness)"<<endl;
            cout<<"Type 3: Special(Translate to other language)"<<endl;
            int response2;
            cin>>response2;
            switch (response2) {
                case 1:
                {
                    Prog2.read_file(1,text);
                    Prog2.insert(text);
                    cout<<"SUCCESS"<<endl;
                    break;
                }
                case 2:
                {
                    Prog2.read_file(2,formal);
                    Prog2.insert(formal);
                    cout<<"SUCCESS"<<endl;
                    break;
                }
                case 3:
                {
                    Prog2.read_file(3,special);
                    Prog2.insert(special);
                    cout<<"SUCCESS"<<endl;
                    break;
                }
                default:
                {
                    cout<<"ERROR Default"<<endl;
                    break;
                }
            }
        }
    }while(again());

    cout<<"SHOW ALL the insert information...... "<<endl;
    Prog2.display();

    cout<<"Do you want to delete some matchings? "<<endl;
    cout<<"1. Delete from Text type. "<<endl;
    cout<<"2. Delete from Formal type. "<<endl;
    cout<<"3. Delete from Special type. "<<endl;
    cout<<"0. Don't want to delete. "<<endl;

    int response3;
    cin>>response3;
    switch (response3) {
        case 1:
        {
            do{
                cout<<"Input matching keys:"<<endl;
                char * key1 = new char[15];
                cin>>key1;
                cin.ignore();
                if(text->remove(key1))
                    cout<<"SUCCESS"<<endl;
                else
                    cout<<"UNSUCCEED"<<endl;
                delete [] key1;
            }while (again());
            break;
        }
        case 2:
        {
            do{
                cout<<"Input matching keys:"<<endl;
                char * key1 = new char[15];
                cin>>key1;
                cin.ignore();
                if(formal->remove(key1))
                    cout<<"SUCCESS"<<endl;
                else
                    cout<<"UNSUCCEED"<<endl;
                delete [] key1;
            }while (again());
            break;
        }
        case 3:
        {
            do{
                cout<<"Input matching keys:"<<endl;
                char * key1 = new char[15];
                cin>>key1;
                cin.ignore();
                if(special->remove(key1))
                    cout<<"SUCCESS"<<endl;
                else
                    cout<<"UNSUCCEED"<<endl;
                delete [] key1;
            }while (again());
            break;
        }
        case 0:
        {
            break;
        }
        default:
        {
            cout<<"ERROR Defualt"<<endl;
            break;
        }
    }

    cout<<"SHOW ALL the insert information after delete...... "<<endl;
    Prog2.display();

    char * words = new char[20];
    char * sentence = new char[80];
    cout<<"Please input the type you want to transform."<<endl;
    cout<<"1. Text(Abbreviation -> normal)"<<endl;
    cout<<"2. Formal(normal -> formal)"<<endl;
    cout<<"3. Special(English -> somewhat)"<<endl;
    cout<<"0. Exit"<<endl;
    int response4 = 0;
    cin>>response4;

    switch (response4) {
        case 1:
        {
            cout<<"Please input words: "<<endl;
            cin >> words;
            cin.ignore();
            cout<<"Transforming result: "<<endl;
            cout<< words <<" ----->>>>> " << text->translate(words) << endl;
            break;
        }
        case 2:
        {
            cout<<"Please input sentence: "<<endl;
            cin.ignore();
            cin.get(sentence,79);
            cin.ignore();
            cout<<"Converting result: "<<endl;
            Prog2.formal_convert(sentence);
            break;
        }
        case 3:
        {
            cout<<"Please input words: "<<endl;
            cin >> words;
            cin.ignore();
            cout<<"Transforming result: "<<endl;
            cout<< words <<" ----->>>>> " << special->translate(words) << endl;
            break;
        }
        case 0:
        {
            break;
        }
        default:
        {
            cout<<"ERROR Defualt"<<endl;
        }
    }

    delete [] words;
    delete [] sentence;
    cout<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    cout<<"><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><"<<endl;
    cout<<"<><><><><><><><><><><><><><>< Logout ><><><><><><><><><><><><><>"<<endl;
}
