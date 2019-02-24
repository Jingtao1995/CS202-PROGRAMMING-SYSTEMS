//Name: Jingtao Cheng
//ID: 940067494
//CS202 Winter Program 1
//
//main.cpp

#include "Graph.h"

using namespace std;

int main()
{
    
    int left_longitude = 10;
    int right_longitude = 50;
    int up_latitude = 50;
    int down_latitude = 10;
    /*
    int left_longitude = 0;
    int right_longitude = 0;
    int up_latitude = 0;
    int down_latitude = 0;
    cout<<" Please set restrict airspace (only for the Eastern and Northern Hemisphere )"<<endl;
    cout<<" Please input left longitude "<<endl;
    cin >> left_longitude;
    cout<<" Please input right longitude ( must larger than left latitude ) "<<endl;
    cin >> right_longitude;
    cout<<" Please input higher latitude (only for the Northern Hemisphere ) "<<endl;
    cin >> up_latitude;
    cout<<" Please input lower latitude (only for the Northern Hemisphere ) "<<endl;
    cin >> down_latitude;
    */
    Control_center client(left_longitude, right_longitude, up_latitude, down_latitude);
    
    int response = 0;
    do
    {
        char * name = new char[25];
        int longitude = 0;
        int altitude = 0;
        int latitude = 0;
        int choice = 0;
        cout<<" 1. Add Drone "<<endl;
        cout<<" 2. Search Drone "<<endl; //move and add ajacent
        cout<<" 0. Exit "<<endl;
        

        cin >> response;
    
        switch (response) {
            case 1:
            {
                cout<<"Which Drone do you want to add? "<<endl;
                cout<<"1. Small Drone (Race&Explore) "<<endl;
                cout<<"2. Medium Drone (Photograph&Research) "<<endl;
                cout<<"3. Large Drone (Delivery&agriculture) "<<endl;
                cin>>choice;
                cout<<"Please input your drone's name: "<<endl;
                cin>>name;
                cin.ignore();
                cout<<"Please input drone's position - longitude: "<<endl;
                cin>>longitude;
                cout<<"Please input drone's position - latitude: "<<endl;
                cin>>latitude;
                cout<<"Please input drone's position - altitude: "<<endl;
                cin>>altitude;

                client.add_drone(name,longitude,latitude,altitude, choice);
                
                break;
            }
            case 2:
            {
                client.display();
                cout<<endl<<endl<<endl;
                Vertex * current;
                int response2 = 0;
                cout<<" Please input drone's name "<<endl;
                cin>>name;
                cin.ignore();
                current = client.search(name);
                cout<<endl<<endl<<endl;
                if(current)
                {
                    current->display();
                    cout<<endl<<endl;
                }
                else
                    break;
                do{
                    
                    cout<<"-----------------------"<<endl;
                    cout<<" 1. Add adjacent drone "<<endl;
                    cout<<" 2. Move to another position "<<endl;
                    cout<<" 3. Remove current adjacent drone "<<endl;
                    cout<<" 4. Active drone's utility "<<endl;
                    cout<<" 0. Exit "<<endl;
                    cout<<endl;
                    cin>>response2;
                    
                    switch (response2) {
                        case 1:
                        {
                            
                            char * name3 = new char[25];
                            do{
                                current->display();
                                cout<<"Please input adjacent drone's name: "<<endl;
                                cin>>name3;
                                cin.ignore();
                                if(current->add_adjacent(name3))
                                    cout<<"SUccess"<<endl;
                                else
                                    cout<<"Unsuccess"<<endl;
                            }while(again());
                            break;
                        }
                        case 2:
                        {
                            int a, b, c = 0;
                            cout<<"Please input new position "<<endl;
                            cout<<"New longitude: "<<endl;
                            cin>>a;
                            cout<<"New latitude: "<<endl;
                            cin>>b;
                            cout<<"New altitude: "<<endl;
                            cin>>c;
                            
                            if(current->move(a, b, c))
                                cout<<"Move Success"<<endl<<endl;
                            else
                                cout<<"Move Unsuccess"<<endl<<endl;
                            break;
                        }
                        case 3:
                        {
                            char * name4 = new char[25];
                            do{
                                client.display();
                                cout<<"Please input the drone you want to remove: "<<endl;
                                cin>>name4;
                                cin.ignore();
                                if(current->remove_adjacent(name4))
                                    cout<<"remove success"<<endl<<endl;
                                else
                                    cout<<"remove unsuccess"<<endl<<endl;
                            }while(again());
                            break;
                        }
                        case 4:
                        {
                            current->active_mode();
                            break;
                        }
                        case 0:
                        {
                            break;
                        }
                        default:
                        {
                            cout<<"ERROR 3"<<endl;
                            break;
                        }
                    }
                }while(again());
                
                break;
            }
            case 0:
            {
                cout<<"Thank You";
                return 0;
            }
            default:
            {
                cout<<"ERROR 4"<<endl;
                break;
            }
        }
    
        cout<<endl;
        client.check_safty();
    }while (again());
    
    
    return 0;
}

