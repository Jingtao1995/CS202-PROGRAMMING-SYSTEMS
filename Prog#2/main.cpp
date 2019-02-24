//Name: Jingtao Cheng 
//ID: 940067494
//main.cpp

#include "prog_2.h"

#define max 20
#define MAX 40
using namespace std;

int main()
{
    client prog2;
    char * title = new char[max];
    char * description = new char[MAX];
    cout << "Please add materials for reviewing. " << endl;
    do{
        cout << "Which material do you want to add ? " << endl
        << " 1. Textbook. " << endl
        << " 2. Practice Questions. " << endl
        << " 3. PPT. " << endl;
        int response = 0;
        cout << "Your response : ";
        cin >> response;

        cin.ignore();
        cout << "Add title for your material : ";
        cin >> title;
        cin.ignore();
        cout << endl << "Add description for your material : ";
        cin >> description;
        cin.ignore();
        cout << endl;

        switch (response){
            case 1 :
            {
                prog2.add_textbook(title, description);

                break;
            }
            case 2 :
            {
                prog2.add_practice(title, description);

                do{
                    cout << "Please add questions : ";
                    char * questions = new char[MAX];
                    cin >> questions;
                    cin.ignore();

                    prog2.add_questions(questions);
                }while(again());
                break;
            }
            case 3 :
            {
                prog2.add_ppt(title, description);

                break;
            }
            default :
            {
                cout << "Error in inputing. " << endl;
                break;
            }
        }
        prog2.display();
        cout << endl;
    }while(again());

    delete [] title;
    delete [] description;

    cout << "Select to review materials. " << endl;

    do{
        cout << " 1.Select textbook to review. " << endl
        << " 2. Select questions to review. " << endl
        << " 3. Select ppt to review. " << endl;
        int choose = 0;
        cin >> choose;
        switch (choose){
            case 1:
            {
                cout << "How many books do you want to review : ";
                int number = 0;
                cin >> number;
                prog2.list_n_textbook(number);
                cout << endl;
                break;
            }
            case 2:
            {
                cout << "How many questions do you want to practice : ";
                int number = 0;
                cin >> number;
                prog2.list_n_questions(number);
                cout << endl;
                break;
            }
            case 3:
            {
                cout << "How many ppts do you want to review : ";
                int number = 0;
                cin >> number;
                prog2.list_n_ppt(number);
                cout << endl;
                break;
            }
            default:
                cout << "Wrong Input. " << endl;
                break;
        }

        cout << "Reviewed materials lists below : " << endl;
        prog2.display_reviewed_material();
/*
        cout << "Do you want to remove material. " << endl;
        do{
            cout << " Please input material's title you want to remove. " << endl;
            char * name = new char[max];
            cin >> name;
            cin.ignore();
            if(prog2.remove_material(name))
                cout << " SUCCESS! " << endl;
            else
                cout << " FAILED. " << endl;
            delete [] name;
        }while(again());
*/
        cout << "Do you want to search material. " << endl;
        do{
            cout << " Please input material's title you want to retrieval. " << endl;
            char * name = new char[max];
            cin >> name;
            cin.ignore();
            if(prog2.search_material(name))
                cout << " SUCCESS! " << endl;
            else
                cout << " FAILED. " << endl;
            delete [] name;
        }while(again());

    }while(again());
    cout << endl << "               Program exit, data released.                " << endl;
}
