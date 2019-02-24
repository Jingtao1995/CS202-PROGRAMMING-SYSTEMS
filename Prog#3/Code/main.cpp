/*--------------------------------------------
    Name: Jingtao Cheng
    Course: CS202
    Date: Nov 19.2017
    Program3
--------------------------------------------*/

#include "AVL_Tree.h"
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    AVL_Tree tree;
    tree.read_file();
    int selection = 0;
    
    while(selection != 4)
    {
        char race[21] = {};
        int date = 0;
        char record[21] = {};
        int time = 0;
        char name[21] = {};
        char exercise[21] = {};
        int freq = 0;
        int days = 0;
        
        cout<<" \n"
        <<" \n"<<endl;
        cout<<"=====================================\n"
        <<"|             The Menu              |\n"
        <<"|                                   |\n"
        <<"| 1. Add race detail.               |\n"
        <<"| 2. Search for race.               |\n"
        <<"| 3. Display all.                   |\n"
        <<"| 4. Exit.                          |\n"
        <<"|                                   |\n"
        <<"=====================================\n"
        <<"Please input your selcetion."<<endl;
        cout<<" "<<endl;
        cin>>selection;
        //cin.ignore();
        switch(selection)
        {
            case 1:
            {
                cout << "Input race type: ";
                cin >> race;
                cin.ignore();
                cout << "Race year: ";
                cin >> date;
                AVL_Node * temp = tree.insert_race(race, date);
                
                int choice = 0;
                
                while(choice != 5)
                {
                    cout<<" \n"
                    <<" \n"<<endl;
                    cout<<"=====================================\n"
                    <<"|             Sub Menu              |\n"
                    <<"|                                   |\n"
                    <<"| 1. Add plan.                      |\n"
                    <<"| 2. Add record.                    |\n"
                    <<"| 3. Display all plan.              |\n"
                    <<"| 4. Display all record.            |\n"
                    <<"| 5. Exit.                          |\n"
                    <<"|                                   |\n"
                    <<"=====================================\n"
                    <<"Please input your selcetion."<<endl;
                    cout<<" "<<endl;
                    cin >> choice;
                    //cin.ignore();
                    switch (choice) {
                        case 1:
                        {
                            cout << "Input plan name: ";
                            cin >> name;
                            cin.ignore();
                            cout << "Input exercise type: ";
                            cin >> exercise;
                            cin.ignore();
                            cout << "Input exercise frequency(how many times a week): ";
                            cin >> freq;
                            cout << " Input trainning days: ";
                            cin >> days;
                            
                            const Plan_Node object(name, exercise, freq, days);
                            tree.insert_plan(object, temp);
                            
                            break;
                        }
                        case 2:
                        {
                            cout << "Input race historical record: ";
                            cin >> record;
                            cin.ignore();
                            cout << "Input race year: ";
                            cin >> time;
                            
                            Record_Node object(record, time);
                            tree.insert_record(object, temp);
                            break;
                        }
                        case 3:
                        {
                            temp -> display_plan();
                            break;
                        }
                        case 4:
                        {
                            temp -> display_record();
                            break;
                        }
                        case 5:
                        {
                            break;
                        }
                        default:
                            cout<<"Your selection should between 1-5"<<endl;
                    }
                }
                
                create_file(race, date, record, time, name, exercise, freq, days);
                
                break;
            }
            case 2:
            {
                cout << "Race type you want to search: ";
                cin >> race;
                cin.ignore();
                tree.search_race(race);
            }
            case 3:
            {
                tree.display();
                break;
            }
            case 4:
                break;
            default:    cout << "Your selection should between 1-4"<<endl;

        }
    }
        return 0;
}
