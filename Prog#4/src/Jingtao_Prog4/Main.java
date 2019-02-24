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

        Menu menu = new Menu();
        DLL orderList = new DLL();
        DLL_Node order;
        Food food;
        Appetizer appetizer; //1
        Entree entree; //2
        Drink drink; //3
        Dessert dessert; //4

        try {
            File file = new File("Menu.txt");
            if(file.isFile() && file.exists()) {
                Scanner sc = new Scanner(file);

                String line = null;
                do {
                    line = sc.nextLine();
                    int k = line.length();

                    String type1 = null;
                    String name1 = null;
                    String des1 = null;
                    String price1 = null;
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


        int i = 1;
        do {
            System.out.println("---------------------------------------------");
            System.out.println("---        1     Display Menu             ---");
            System.out.println("---        2     Place Order              ---");
            System.out.println("---        3     Display Order            ---");
            System.out.println("---        0     Exit                     ---");
            System.out.println("---------------------------------------------");
            System.out.println("           Please input your choice:         ");

            int a = scan.nextInt();


            switch (a) {
//********************************
//* the code in comment is useless
//* for this program4
//********************************
                /*case 1: {
                    int t = 1;
                    do {
                        System.out.println("---        1     Add Appetizers           ---");
                        System.out.println("---        2     Add Entrees              ---");
                        System.out.println("---        3     Add Drinks               ---");
                        System.out.println("---        4     Add Desserts             ---");
                        System.out.println("---        0     Exit                     ---");
                        System.out.println("           Please input your choice:         ");

                        int b = scan.nextInt();
                        scan.nextLine();

                        String type = null;
                        String name = null;
                        String des = null;
                        String price = null;
                        String str = null;

                        try {
                            File file = new File("Menu.txt");
                            if(!file.exists()) {
                                file.createNewFile();
                            }
                            BufferedWriter writer = new BufferedWriter(new FileWriter(file));

                        switch (b) {
                            case 1: {
                                type = "1";
                                System.out.println("Please input name: ");
                                name = scan.nextLine();
                                System.out.println("Please input details: ");
                                des = scan.nextLine();
                                System.out.println("Please input price: ");
                                price = scan.nextLine();
                                appetizer = new Appetizer(type, name, des, price);
                                menu.insert(appetizer);
                                str = type + "|" + name + "|" + des + "|" + price + "|";
                                writer.write(str);
                                break;
                            }
                            case 2: {
                                type = "2";
                                System.out.println("Please input name: ");
                                name = scan.nextLine();
                                System.out.println("Please input details: ");
                                des = scan.nextLine();
                                System.out.println("Please input price: ");
                                price = scan.nextLine();
                                entree = new Entree(type, name, des, price);
                                menu.insert(entree);
                                str = type + "|" + name + "|" + des + "|" + price + "|";
                                writer.write(str);
                                break;
                            }
                            case 3: {
                                type = "3";
                                System.out.println("Please input name: ");
                                name = scan.nextLine();
                                System.out.println("Please input details: ");
                                des = scan.nextLine();
                                System.out.println("Please input price: ");
                                price = scan.nextLine();
                                drink = new Drink(type, name, des, price);
                                menu.insert(drink);
                                str = type + "|" + name + "|" + des + "|" + price + "|";
                                writer.write(str);
                                break;
                            }
                            case 4: {
                                type = "4";
                                System.out.println("Please input name: ");
                                name = scan.nextLine();
                                System.out.println("Please input details: ");
                                des = scan.nextLine();
                                System.out.println("Please input price: ");
                                price = scan.nextLine();
                                dessert = new Dessert(type, name, des, price);
                                menu.insert(dessert);
                                str = type + "|" + name + "|" + des + "|" + price + "|";
                                writer.write(str);
                                break;
                            }
                            case 0: {
                                t = 0;
                                break;
                            }
                            default: {
                                System.out.println("Error occur in inputting");
                                break;
                            }
                        }

                            writer.newLine();
                            writer.flush();
                            writer.close();
                        }catch (Exception e) {
                            e.printStackTrace();
                        }
                    }while(t != 0);
                    break;
                }
                */
                case 1: {
                    menu.display();
                    break;
                }
//********************************
//* case 2 is used to get in the
//* information of order and passed
//* into the order object
//********************************
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
                        orderList.insert_order_info(order, in, in2);
                        System.out.println("Do you want to add more?(0.exit <-> other.continue)");
                        index = scan.nextInt();
                    } while(index != 0);
                    break;
                }
                case 3: {
                    orderList.display_all();
                    break;
                }
                case 0: {
                    System.out.println("            ~~~~~Thanks~~~~~              ");
                    i = 0;
                    break;
                }
                default:
                    System.out.println("Error occur in inputting");
                    break;
            }

        } while(i != 0);

    }
}
