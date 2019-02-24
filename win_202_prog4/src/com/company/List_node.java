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
        System.out.println("Connection: " + super.getDestination());
        System.out.println("Stop " + Stop_time + " Hours");
        System.out.println("Arrive at " + super.getDestination() + " on " + Arrival_Connection_time);
        System.out.println("Departure from" + super.getDestination() + " on " + Departure_time);
        System.out.println("Arrive at Destination on " + Arrival_Destination_time);
    }
}
