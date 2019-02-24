//**********************************************************************************************************************
//*Name: Jingtao Cheng
//*ID: 940067494
//*CS202 Winter Program4
//**********************************************************************************************************************

//**********************************************************************************************************************
//* This is the client with main class to manage the I/O and other features
//**********************************************************************************************************************
package com.company;

import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) {
        // write your code here

        Scanner scan = new Scanner(System.in);
        BST destination = new BST();

        try {
            File file = new File("Destination.txt");
            if (file.isFile() && file.exists()) {

                Scanner sc = new Scanner(file);
                String line;

                do {
                    line = sc.nextLine();

                    destination.add(line);
                    Tree_node temp = destination.retrieve(line);

                    //System.out.println(line); // for test

                    try {
                        File file2 = new File("Connection.txt");
                        if(file2.isFile() && file2.exists()) {

                            Scanner sc2 = new Scanner(file2);
                            String line2;

                            do {
                                line2 = sc2.nextLine();
                                int k2 = line2.length();

                                int stop_time;
                                String connection;
                                String arrive_connection_time;
                                String departure_time;
                                String arrive_destination_time;

                                int t = 0;
                                int[] index = new int[4];
                                for(int i = 0; i < line2.length(); i++) {
                                    if(line2.substring(i,i+1).equals(",")) {
                                        index[t] = i;
                                        ++t;
                                    }
                                }

                                stop_time = Integer.parseInt(line2.substring(0,index[0]).trim());
                                connection = line2.substring(index[0]+1,index[1]).trim();
                                arrive_connection_time = line2.substring(index[1]+1,index[2]).trim();
                                departure_time = line2.substring(index[2]+1,index[3]).trim();
                                arrive_destination_time = line2.substring(index[3]+1,k2).trim();

                                temp.insert(stop_time, connection, arrive_connection_time, departure_time, arrive_destination_time);

                            } while (sc2.hasNext());
                            sc2.close();
                        }
                    } catch (IOException e2) {
                        e2.printStackTrace();
                    }

                } while (sc.hasNext());
                sc.close();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        int i = 1;
        do {
            System.out.println("----------------------------------------------------------------");
            System.out.println("------------    1    Display all Destination        ------------");
            System.out.println("------------    2    Retrieve Destination           ------------");
            System.out.println("------------    3    Retrieve Related Destination   ------------");
            System.out.println("------------    4    Remove One Destination         ------------");
            System.out.println("------------    5    Remove all Destination         ------------");
            System.out.println("------------    0    Exit                           ------------");
            System.out.println("----------------------------------------------------------------");
            System.out.println("                    Please input your choice :                  ");

            int a = scan.nextInt();

            switch (a) {
                case 1: {
                    destination.display();
                    break;
                }
                case 2: {
                    scan.nextLine();
                    System.out.println("Please input \033[31mdestination\033[0m you want to retrieve");
                    String in = scan.nextLine();
                    Tree_node temp = destination.retrieve(in);

                    System.out.println("---------------------------------------------------------------------");
                    System.out.println("   1   Display all information around \033[31mthis destination\033[0m");
                    System.out.println("   2   Insert Connections");
                    System.out.println("   3   Retrieve");
                    System.out.println("   4   Retrieve related");
                    System.out.println("   0   Exit");
                    System.out.println("---------------------------------------------------------------------");
                    System.out.println("                    Please input your choice :                  ");

                    int b = scan.nextInt();

                    switch (b) {
                        case 1: {
                            temp.display();
                            temp.display_all_connections();
                            break;
                        }
                        case 2: {
                            int sign = 1;
                            do {
                                System.out.println("Please input Connection");

                                scan.nextLine();
                                String connection = scan.nextLine();

                                System.out.println("Please input Stop time (hours)");

                                int stop_time = scan.nextInt();

                                System.out.println("Please input Arrive time on Connection");

                                scan.nextLine();
                                String arrive_connection_time = scan.nextLine();

                                System.out.println("Please input Departure time from Connection");

                                String departure_connection_time = scan.nextLine();

                                System.out.println("Please input Arrive time on Destination");

                                String arrive_destination_time = scan.nextLine();

                                temp.insert(stop_time, connection, arrive_connection_time, departure_connection_time, arrive_destination_time);
                                System.out.println("Want continue? (\033[31m0 Exit\033[0m) (Any keys to continue)");
                                sign = scan.nextInt();

                            } while (sign != 0);
                            temp.display();
                            temp.display_all_connections();
                            break;
                        }
                        case 3: {
                            scan.nextLine();
                            System.out.println("Please input Connection you want to retrieve");
                            String connection = scan.nextLine();
                            List_node temp2 = temp.retrieve_List(connection);
                            System.out.println("There are Connections contain the keyword \033[31m" + connection + "\033[0m");
                            temp2.display();
                            break;
                        }
                        case 4: {
                            scan.nextLine();
                            System.out.println("Please input Keyword you want to retrieve");
                            String key = scan.nextLine();
                            System.out.println("There are Connections contain the keyword \033[31m" + key + "\033[0m");
                            temp.retrieve_related(key);
                            break;
                        }
                        case 0: {
                            System.out.println("Back to Enclosing Menu");
                            break;
                        }
                        default: {
                            System.out.println("\033[31m Wrong input \033[0m");
                            break;
                        }
                    }
                    break;
                }
                case 3: {
                    scan.nextLine();
                    System.out.println("Please input Keyword you want to retrieve");
                    String key = scan.nextLine();
                    System.out.println("There are Destinations contain the keyword \033[31m" + key + "\033[0m");
                    destination.retrieve_related(key);
                    break;
                }
                case 4: {
                    scan.nextLine();
                    System.out.println("Please input Destination you want to remove");
                    String des = scan.nextLine();
                    if(destination.remove(des)) {
                        System.out.println("Remove Success");
                        destination.display();
                    }else
                    {
                        System.out.println("Disable to remove");
                    }
                    break;
                }
                case 5: {
                    if(destination.remove_all()) {
                        System.out.println("Remove Success");
                        destination.display();
                    }else
                    {
                        System.out.println("Disable to remove all nodes");
                    }
                    break;
                }
                case 0: {
                    System.out.println("----------------------------------------------------------------");
                    System.out.println("- - - - - - - - - - - - - -  Thanks  - - - - - - - - - - - - - -");
                    System.out.println("----------------------------------------------------------------");
                    i = 0;
                    break;
                }
                default: {
                    System.out.println("\033[31m Wrong input \033[0m");
                    break;
                }
            }
        } while ( i != 0);
    }
}
