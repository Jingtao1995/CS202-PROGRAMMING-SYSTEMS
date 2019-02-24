//**********************************************************************************************************************
//*Name: Jingtao Cheng
//*ID: 940067494
//*CS202 Winter Program4
//**********************************************************************************************************************


package com.company;

//**********************************************************************************************************************
//*this is the flight_plans class stores the information about flight's (String) origination and the BST object stores
//*the destination and connection information, there also with add destination, display destination, get set next and pre,
//*get destination and get BST functions.
//**********************************************************************************************************************

public class Flight_plans {

    private String Origination;

    private BST Destinations;

    private Flight_plans pre;
    private Flight_plans next;

//**********************************************************************************************************************
//*this is the default constructor
//**********************************************************************************************************************

    public Flight_plans() {
        Origination = null;
        Destinations = new BST();
        pre = null;
        next = null;
    }
//**********************************************************************************************************************
//*this is the copy constructor with String argument and BST reference
//**********************************************************************************************************************

    public Flight_plans(String origination, BST source) {
        this.Origination = origination;
        Destinations = new BST();

        if(source == null) {
            System.out.println("Empty BST passed in");
        }
        if(add_Destinations(source)) {
            //System.out.println("add destinations success");
        }else {
            System.out.println("\033[31m Error in add destinations (Flight plans class) \033[0m");
        }

        this.pre = null;
        this.next = null;
    }
//**********************************************************************************************************************
//*this is the add function to add destination information by copy the passed in BST reference
//**********************************************************************************************************************

    public boolean add_Destinations(BST source) {
        if(source == null) {
            System.out.println("\033[31m Empty source tree (Flight plans class) \033[0m");
            return false;
        }
        if(Destinations.copy_tree(source)) {
            //System.out.println("Success");
            return true;
        }
        else {
            System.out.println("\033[31m Error in copy tree (Flight plans class) \033[0m");
            return false;
        }
    }
//**********************************************************************************************************************
//*THose are the functions help to build and traverse the doubly linked list
//**********************************************************************************************************************

    public Flight_plans getNext() {
        return next;
    }

    public Flight_plans getPre() {
        return pre;
    }

    public void setPre(Flight_plans pre) {
        this.pre = pre;
    }

    public void setNext(Flight_plans next) {
        this.next = next;
    }

    public String getOrigination() {
        return this.Origination;
    }

    public BST getBST() {
        return this.Destinations;
    }
//**********************************************************************************************************************
//*this is the display function to display all the information stores in the BST nodes
//**********************************************************************************************************************

    public void display_origination() {
        if(Origination != null)
            System.out.println("\033[34m Origination: \033[33m" + Origination + "\033[0m");
        else
            System.out.println("\033[31m NULL Origination \033[0m");
    }
//**********************************************************************************************************************
//*this is the recursive step of display destination function
//**********************************************************************************************************************

    public void display_destination() {
        if(Destinations != null)
            this.Destinations.display_destinations();
        else
            System.out.println("\033[31m Empty tree \033[0m");
    }



}
