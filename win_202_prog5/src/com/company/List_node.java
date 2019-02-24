//**********************************************************************************************************************
//*Name: Jingtao Cheng
//*ID: 940067494
//*CS202 Winter Program4
//**********************************************************************************************************************

//**********************************************************************************************************************
//* This class is the List_node class derived from Base_node class as the basic node of a List of Connections which has
//* 4 private members and retrieve, retrieve related functions
//**********************************************************************************************************************

package com.company;
import java.util.List;

public class List_node extends Base_node { //List of possible Connections

    private List_node next;
    //use Destination in base class represent the Connection
    private int Stop_time;

    private String Arrival_Connection_time;
    private String Departure_time;
    private String Arrival_Destination_time;

//**********************************************************************************************************************
//* default constructor
//**********************************************************************************************************************

    public List_node() {
        super();
        this.next = null;
        this.Stop_time = 0;
        this.Arrival_Connection_time = null;
        this.Departure_time = null;
        this.Arrival_Destination_time = null;
    }

//**********************************************************************************************************************
//* constructor with 5 arguments and return the reference of List_node
//**********************************************************************************************************************

    public List_node(int stop_time, String connection, String arrival_Connection_time, String departure_time, String arrival_Destination_time) {
        super(connection);
        this.Stop_time = stop_time;
        this.Arrival_Connection_time = arrival_Connection_time;
        this.Departure_time = departure_time;
        this.Arrival_Destination_time = arrival_Destination_time;
        this.next = null;
    }

//**********************************************************************************************************************
//* Copy list node
//**********************************************************************************************************************

    public boolean copy_list(List_node source) {
        if(source == null) {
            System.out.println("\033[31m Empty source list node \033[0m");
            return false;
        }
        //System.out.println("\033[31m copy list success (in List_node class) \033[0m");

        super.insert(source.getDestination());
        this.Stop_time = source.Stop_time;
        this.Arrival_Connection_time = source.Arrival_Connection_time;
        this.Departure_time = source.Departure_time;
        this.Arrival_Destination_time = source.Arrival_Destination_time;
        this.next = null;
        return true;
    }

//**********************************************************************************************************************
//* check stop time and return
//**********************************************************************************************************************

    public int check_time() {
        return this.Stop_time;
    }

//**********************************************************************************************************************
//* retrieve function with boolean return type
//**********************************************************************************************************************

    public boolean retrieve(String name) {
        if(super.retrieve(name))
            return true;
        else
            return false;
    }

//**********************************************************************************************************************
//* retrieve related functions with boolean return type
//**********************************************************************************************************************

    public boolean retrieve_related(String key) {
        if(super.retrieve_related(key))
            return true;
        else
            return false;
    }

//**********************************************************************************************************************
//* basic functions helps traverse and build Linear linked list
//**********************************************************************************************************************

    public List_node getNext() {
        return next;
    }

    public void setNext(List_node to_set) {
        this.next = to_set;
    }

//**********************************************************************************************************************
//* basic display functions
//**********************************************************************************************************************

    public void display() {
        System.out.println("Connection: \033[31m" + super.getDestination() + "\033[0m");
        System.out.println("\033[34m Stop \033[31m" + Stop_time + "\033[34m Hours \033[0m");
        System.out.println("Arrive at " + super.getDestination() + " on " + Arrival_Connection_time);
        System.out.println("Departure from" + super.getDestination() + " on " + Departure_time);
        System.out.println("Arrive at Destination on " + Arrival_Destination_time);
    }
}
