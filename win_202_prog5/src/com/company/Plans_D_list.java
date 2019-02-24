//**********************************************************************************************************************
//*Name: Jingtao Cheng
//*ID: 940067494
//*CS202 Winter Program4
//**********************************************************************************************************************


package com.company;

//**********************************************************************************************************************
//* This is the Plans_D_list class which is the basic node of doubly linked list and has head and tail pointer. add plans
//* display all plans and retrieve plans functions
//**********************************************************************************************************************


public class Plans_D_list {

    private Flight_plans head;
    private Flight_plans tail;

//**********************************************************************************************************************
//*THis is the default constructor
//**********************************************************************************************************************

    public Plans_D_list() {
        this.head = null;
        this.tail = null;
    }

//**********************************************************************************************************************
//* This is the add plans function with passed in String type argument and a reference of BST object
//**********************************************************************************************************************

    public boolean add_plans(String origination, BST source) {
        if(origination == null || source == null)
            return false;
        if(head == null) {
            head = new Flight_plans(origination, source);
            tail = head;
            return true;
        }
        return add_plans(head, origination, source);
    }

//**********************************************************************************************************************
//*recursive step of add plans function
//**********************************************************************************************************************

    public boolean add_plans(Flight_plans head, String origination, BST source) {

        if(head.getNext() == null) {
            Flight_plans temp = new Flight_plans(origination, source);
            head.setNext(temp);
            temp.setPre(head);
            return true;
        }
        return add_plans(head.getNext(), origination, source);
    }

//**********************************************************************************************************************
//*This is the display all plans function which will display every node in the doubly linked list
//**********************************************************************************************************************

    public boolean display_all_plans() {
        if(head == null) {
            System.out.println("\033[31m Empty Plans list \033[0m");
        }
        return display_all_plans(head);
    }

//**********************************************************************************************************************
//*this is the recursive step of display all plans function
//**********************************************************************************************************************

    private boolean display_all_plans(Flight_plans head) {
        if(head == null)
            return false;
        head.display_origination();
        head.display_destination();
        return display_all_plans(head.getNext()) && true;
    }

//**********************************************************************************************************************
//*this is the retrieve function which fits the  String type passed in argument, and return a reference of BST object
//**********************************************************************************************************************

    public BST retrieve_plans(String origination) {
        if(origination == null) {
            System.out.println("\033[31m NULL input \033[0m");
            return null;
        }
        return retrieve_plans(origination, head);
    }

//**********************************************************************************************************************
//*this is the recursive step of retrieve plans function
//**********************************************************************************************************************

    private BST retrieve_plans(String origination, Flight_plans head) {
        if(head == null) {
            return null;
        }
        if(head.getOrigination().contains(origination)) {
            System.out.println("\033[31m FOUND \033[0m");

            return head.getBST();
        }
        return retrieve_plans(origination, head.getNext());
    }

}
