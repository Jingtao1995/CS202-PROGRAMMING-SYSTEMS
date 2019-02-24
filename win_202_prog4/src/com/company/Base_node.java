//**********************************************************************************************************************
//*Name: Jingtao Cheng
//*ID: 940067494
//*CS202 Winter Program4
//**********************************************************************************************************************

//**********************************************************************************************************************
//* This class is the abstract class of general nodes which contain the String type and insert, retrieve, retrieve
//* related functions
//**********************************************************************************************************************

package com.company;

abstract class Base_node { //a prototype of each node

    private String Destination;

//**********************************************************************************************************************
//* default constructor
//**********************************************************************************************************************

    public Base_node() {
        this.Destination = null;
    }

//**********************************************************************************************************************
//* constructor with argument
//**********************************************************************************************************************

    public Base_node(String destination) {
        this.Destination = destination;
    }

//**********************************************************************************************************************
//* Insert function with String argument
//**********************************************************************************************************************

    public boolean insert(String destination) {
        if(destination != null) {
            this.Destination = destination;
            return true;
        }
        else
            return false;
    }

//**********************************************************************************************************************
//* Retrieve function with a boolean return type
//**********************************************************************************************************************

    public boolean retrieve(String name) {
        if(this.Destination.contains(name))
            return true;
        else
            return false;
    }

//**********************************************************************************************************************
//* Retrieve related function with a boolean return type
//**********************************************************************************************************************

    public boolean retrieve_related(String key) {
        if(this.Destination.contains(key))
            return true;
        else
            return false;
    }

//**********************************************************************************************************************
//* pure function
//**********************************************************************************************************************

    abstract void display();


//**********************************************************************************************************************
//* this function can return the private String member
//**********************************************************************************************************************

    public String getDestination() {
        return this.Destination;
    }
}
