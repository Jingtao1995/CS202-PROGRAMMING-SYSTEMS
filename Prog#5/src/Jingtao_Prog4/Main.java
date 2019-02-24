//********************************
//* Name: Jingtao Cheng
//* ID: 940067494
//* CS202 Program4
//********************************

//********************************
// This is the client with main
// class to manage the input and
// output or some I/O things
//********************************
package Jingtao_Prog4;


import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) {
//********************************
//* use utility Scanner to receive
//* input
//********************************
        Scanner scan = new Scanner(System.in);
//********************************
//* implement the object for easy
//* insert and create new object
//********************************

        BST_Restaurant bst_restaurant = new BST_Restaurant();

        BST_Uber bst_uber = new BST_Uber();


        Menu menu = new Menu();
        DLL orderList = new DLL();
        DLL_Node order;
        Food food;
        Appetizer appetizer; //1
        Entree entree; //2
        Drink drink; //3
        Dessert dessert; //4
//********************************
// Open a file of Menu to import
// menu list
//********************************
        try {
            File file = new File("Menu.txt");
            if(file.isFile() && file.exists()) {
                Scanner sc = new Scanner(file);
                String line;
                do {
                    line = sc.nextLine();
                    int k = line.length();
                    String type1;
                    String name1;
                    String des1;
                    String price1;
//********************************
//* use substring to separate a
//* string to several string except
//* separator
//********************************
                    int[] index = new int[3];
                    int t = 0;
                    for(int i = 0; i < line.length(); i++)
                    {
                        if(line.substring(i,i+1).equals(","))
                        {
                            index[t] = i;
                            ++t;
                        }
                    }
                    type1 = line.substring(0,index[0]).trim();
                    name1 = line.substring(index[0]+1,index[1]).trim();
                    des1 = line.substring(index[1]+1,index[2]).trim();
                    price1 = line.substring(index[2]+1,k).trim();


//********************************
//* create new object for easier
//* insert into menu object
//********************************
                    if(line.substring(0,1).equals("1")) {
                        appetizer = new Appetizer(type1, name1, des1, price1);
                        menu.insert(appetizer);
                    }
                    if(line.substring(0,1).equals("2")) {
                        entree = new Entree(type1, name1, des1, price1);
                        menu.insert(entree);
                    }
                    if(line.substring(0,1).equals("3")) {
                        drink = new Drink(type1, name1, des1, price1);
                        menu.insert(drink);
                    }
                    if(line.substring(0,1).equals("4")) {
                        dessert = new Dessert(type1, name1, des1, price1);
                        menu.insert(dessert);
                    }
                } while(sc.hasNext());
                sc.close();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
//********************************
// Open a new file fof Uber driver
// list to import the Uber driver
//********************************
        try {
            File file2 = new File("Uber.txt");
            if(file2.isFile() && file2.exists()) {
                Scanner sc2 = new Scanner(file2);
                String line;
                do {
//********************************
//* use substring to separate a
//* string to several string except
//* separator
//********************************
                    line = sc2.nextLine();
                    int k = line.length();
                    String name2;
                    String distance;
                    String stars;
                    int[] index = new int[3];
                    int t = 0;
                    for (int i = 0; i < line.length(); i++) {
                        if (line.substring(i, i + 1).equals(",")) {
                            index[t] = i;
                            ++t;
                        }
                    }
                    name2 = line.substring(0, index[0]).trim();
                    distance = line.substring(index[0] + 1, index[1]).trim();
                    stars = line.substring(index[1] + 1, k).trim();

                    bst_uber.insert_Uber(name2,distance,stars);

                } while (sc2.hasNext());
                sc2.close();
            }
        } catch (IOException e2) {
        e2.printStackTrace();
    }
//********************************
// Open a file of restaurant info
// to import that information into
// memory
//********************************
        try {
            File file3 = new File("Restaurant.txt");
            if(file3.isFile() && file3.exists()) {
                Scanner sc3 = new Scanner(file3);
                String line;
                do {
                    line = sc3.nextLine();
                    bst_restaurant.insert_Restaurant(line, bst_uber, menu);
                } while (sc3.hasNext());
                sc3.close();
            }
        } catch (IOException e2) {
            e2.printStackTrace();
        }

//********************************
// Bilding the interface of the
// program to easier control
//********************************

        int i = 1;
        do {
//********************************
// first level of command interface
// mainly solve the problem of
// display restaurant list and
// search restaurant and relatively
// search the restaurant and
// remove and remove all restaurant
//********************************
            System.out.println("--------------------------------------------------");
            System.out.println("---        1     Display All Restaurant        ---");
            System.out.println("---        2     Retrieve Restaurant           ---");
            System.out.println("---        3     Retrieve Related Restaurant   ---");
            System.out.println("---        4     Remove One Restaurant         ---");
            System.out.println("---        5     Remove All Restaurant         ---");
            System.out.println("---        0     Exit                          ---");
            System.out.println("--------------------------------------------------");
            System.out.println("             Please input your choice:            ");

            int a = scan.nextInt();

            switch (a) {
                case 1: {
                    bst_restaurant.display();
//********************************
// second level of command interface
// mainly control the menu and order
// placement and choose the Uber
// driver...
//********************************
                    int i2 = 1;
                    do {
                        System.out.println("---------------------------------------------");
                        System.out.println("---        1     Display Menu             ---");
                        System.out.println("---        2     Place Order              ---");
                        System.out.println("---        3     Find a Uber              ---");
                        System.out.println("---        0     Exit                     ---");
                        System.out.println("---------------------------------------------");
                        System.out.println("           Please input your choice:         ");

                        int b = scan.nextInt();

                        switch (b) {
                            case 1: {
                                menu.display();
                                break;
                            }
                            case 2: {
                                int index = 1;
                                int count = 0;
                                do {
                                    ++count;
                                    scan.nextLine();
                                    System.out.println("Please input your order: ");
                                    String in = scan.nextLine();
                                    System.out.println("How many " + in + " do you want: ");
                                    String in2 = scan.nextLine();
                                    order = orderList.insert_order(count);
                                    System.out.println("What special instructions do you want? ");
                                    String in3 = scan.nextLine();
                                    orderList.insert_order_info(order, in, in2, in3);
                                    System.out.println("Do you want to add more?(0.exit <-> other.continue)");
                                    index = scan.nextInt();
                                } while(index != 0);
                                orderList.display_all();
                                break;
                            }
                            case 3: {
                                scan.nextLine();
                                bst_uber.display();
                                System.out.println("Please choose your Uber driver: ");
                                String in4 = scan.nextLine();
                                System.out.println("Make sure your Uber driver: " + in4 + " ; ");
                                break;
                            }
                            case 0: {
                                System.out.println("            ~~~~~Thanks~~~~~              ");
                                i2 = 0;
                                i = 0;
                                break;
                            }
                        }

                    }while (i2 != 0);

                    break;
                }
                case 2: {
                    scan.nextLine();
                    System.out.println("Please input name of restaurant: ");
                    String in = scan.nextLine();
                    bst_restaurant.retrieve(in);
                    break;
                }
                case 3: {
                    scan.nextLine();
                    System.out.println("Please input keywords: ");
                    String in2 = scan.nextLine();
                    bst_restaurant.retrieve_related(in2);
                    break;
                }
                case 4: {
                    scan.nextLine();
                    System.out.println("Please input name of restaurant: ");
                    String in3 = scan.nextLine();
                    bst_restaurant.remove(in3);
                    break;
                }
                case 5: {
                    bst_restaurant.remove_all();
                    break;
                }
                case 0: {
                    System.out.println("            ~~~~~Thanks~~~~~              ");
                    i = 0;
                    break;
                }
                default: {
                    System.out.println("Error occur in inputting");
                    break;
                }
            }

        } while(i != 0);

    }
}
