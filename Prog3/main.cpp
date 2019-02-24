//Name: Jingtao Cheng
//ID: 940067494
//CS202 Winter Program 3
//
//main file
//main.cpp
//This is the main file of Program 3
//This program is aiming to create an object-oriented program to help people watch
//their interesting events of 2017 winter olympics. This application can help the user
//find out when a particular sport will be taking place and even when we expect a 
//particular athlete to be competing.


#include "rb_tree.h"

using namespace std;

int main()
{
    rb_tree tree;
    char * sport_name = new char[25];
    char * athlete_name = new char[25];
    char * detail = new char[50];
    char * _time = new char[25];
    char * channel = new char[25];
    int medals;

    read_file(tree);
    do{
        char response;
        tree.display_all();
        cout<<"Do you want to add sport?(Y/y) or do you want to search your favorite Sport?(N/n)"<<endl;
        cin>>response;
        cin.ignore();
        if(response == 'Y' || response == 'y')
        {
            cout<<"Please input Sport's name you want to add: ";
            cin>>sport_name;
            cin.ignore();
            cout<<"Please input details about that event: ";
            cin>>detail;
            cin.ignore();
            cout<<"Please input time that event will open: ";
            cin>>_time;
            cin.ignore();
            cout<<"Please input channel that event will be: ";
            cin>>channel;
            cin.ignore();

            Sport * new_sport = new Sport;
            new_sport->insert(sport_name, detail, _time, channel);
            //tree += *new_sport;
            tree.insert(*new_sport);
            system("clear");
            cout<<"Add success."<<endl;
            tree.display_all();

            do {
                cout<<"Do you want to add athletes?"<<endl;
                char response3;
                cin>>response3;
                cin.ignore();
                if(response3 == 'Y' || response3 == 'y')
                {
                    node * sport_node = tree.retrieve(sport_name);
                    if(sport_node == NULL)
                        cout<<"Error"<<endl;
                    
                    cout<<"Please input athlete's name: ";
                    cin>>athlete_name;
                    cin.ignore();
                    cout<<"Please input athlete's Event: ";
                    cin>>sport_name;
                    cin.ignore();
                    cout<<"Please input medals: ";
                    cin>>medals;

                    Athlete * new_athlete = new Athlete;
                    new_athlete->insert(athlete_name, sport_name, medals);
                    system("clear");
                    if(sport_node->Sport::insert_athlete(*new_athlete))
                        cout<<"Add success."<<endl;
                    else
                        cout<<"Add athlete Error."<<endl;
                    tree.display_all();
                    
                    do {
                        cout<<"Do you want to add records to this athlete?"<<endl;
                        char response4;
                        cin>>response4;
                        cin.ignore();
                        if(response4 == 'Y' || response4 == 'y')
                        {
                            Athlete * new_athlete2 = sport_node->retrieve(athlete_name);
                            if(new_athlete2 == NULL)
                                cout<<"Error"<<endl;
                            
                            cout<<"Please input Medals s/he got: ";
                            cin>>detail;
                            cin.ignore();
                            cout<<"Please input time when s/he go medals: ";
                            cin>>_time;
                            cin.ignore();

                            Record * new_record = new Record;
                            new_record->insert(detail,_time);
                            system("clear");
                            if(new_athlete2->Athlete::insert_record(*new_record))
                                cout<<"Add success."<<endl;
                            else
                                cout<<"Add record Error."<<endl;
                            tree.display_all();
                        }
                    } while(again2());//end add record
                    cout<<"Add record ended."<<endl;
                }
            } while(again1());
            cout<<"Add athlete ended."<<endl;
        }
        else
        {
            cout<<"Add sport ended."<<endl;
            cout<<"Please input your favorite Sport's name:";
            cin>>sport_name;
            cin.ignore();
            if(tree.display(sport_name))
                cout<<"End"<<endl;
            else
                cout<<"Did not Find. "<<endl;
        }
    }while(again());

    delete [] sport_name;
    delete [] athlete_name;
    delete [] detail;
    delete [] _time;
    delete [] channel;
}
