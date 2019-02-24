//**********************************************************************************************************************
//*Name: Jingtao Cheng
//*ID: 940067494
//*CS202 Winter Program4
//**********************************************************************************************************************

//**********************************************************************************************************************
//* This class is the Tree_node class derived from Base_node class and as the simple node of the binary search tree which has left, right reference and
//* stores the head reference of List_node (a List), class contains insert, retrieve, retrieve related functions
//**********************************************************************************************************************

package com.company;

public class Tree_node extends Base_node {

    private Tree_node left;
    private Tree_node right;
    private List_node head;

//**********************************************************************************************************************
//* default constructor
//**********************************************************************************************************************

    public Tree_node() {
        super();
        this.left = null;
        this.right = null;
        this.head = null;
    }

//**********************************************************************************************************************
//* constructor with a String argument
//**********************************************************************************************************************

    public Tree_node(String destination) {
        super(destination);
        this.left = null;
        this.right = null;
        this.head = null;
    }

//**********************************************************************************************************************
//* copy constructor
//**********************************************************************************************************************

    public Tree_node(Tree_node node) {
        super(node.getDestination());
        this.left = null;
        this.right = null;
        this.head = node.head;
    }

//**********************************************************************************************************************
//* Copy tree node with reference of Tree_node
//**********************************************************************************************************************

    public boolean copy_list_node(Tree_node source) {
        if(source == null) {
            System.out.println("\033[31m NULL passed in <- Tree_node class \033[0m");
            return false;
        }
        return copy_list_node(head, source.head);
    }

    public boolean copy_list_node(List_node head, List_node source) {
        if(source == null) {
            return false;
        }
        head = new List_node();
        if(head.copy_list(source)) {
            //System.out.println("\033[31m copy list success in Tree_node class \033[0m");
            //System.out.println("copy list node success");
        }
        else {
            System.out.println("\033[31m Error in copy list node (Tree_node class)\033[0m");
        }
        copy_list_node(head.getNext(), source.getNext());
        return true;
    }

//**********************************************************************************************************************
//* search by stop time less than passed in argument
//**********************************************************************************************************************

    public boolean sort_by_time(int maxtime, int mintime) {
        if(maxtime == 0 || mintime == 0) {
            System.out.println("Error number");
            return false;
        }
        if(head == null) {
            System.out.println("Empty List");
            return false;
        }
        return sort_by_time(head, maxtime, mintime);
    }

    private boolean sort_by_time(List_node head, int maxtime, int mintime) {
        if(head == null) {
            return false;
        }
        if(maxtime > head.check_time() && mintime < head.check_time()) {
            head.display();
        }
        return sort_by_time(head.getNext(), maxtime, mintime) && true;
    }

//**********************************************************************************************************************
//* Basic functions helps traverse and build trees
//**********************************************************************************************************************

    public Tree_node getLeft() {
        return this.left;
    }

    public Tree_node getRight() {
        return right;
    }

    public void setLeft(Tree_node to_set) {
        this.left = to_set;
    }

    public void setRight(Tree_node to_set) {
        this.right = to_set;
    }

//**********************************************************************************************************************
//* Insert function with 5 arguments, 1 int, 4 String type, and has a return boolean type
//**********************************************************************************************************************

    public boolean insert(int stop_time, String connection, String arrive_connection_time, String departure_time, String arrive_destination_time) {

        List_node temp = new List_node(stop_time, connection, arrive_connection_time, departure_time, arrive_destination_time);
        temp.setNext(head);
        head = temp;
        return true;
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
//* retrieve all related nodes with String keywords and boolean return type
//**********************************************************************************************************************

    public boolean retrieve_related(String key) {
        if(super.retrieve_related(key))
            return true;
        else
            return false;
    }


//**********************************************************************************************************************
//* retrieve nodes in the List equals to the String argument and return the List_node reference
//**********************************************************************************************************************

    public List_node retrieve_List(String name) {
        if(name != null) {
            return retrieve_List(name, head);
        }
        else
            return null;
    }

//**********************************************************************************************************************
//* recursive function of the retrieve list function
//**********************************************************************************************************************

    private List_node retrieve_List(String name, List_node head) {
        if(head == null)
            return null;
        if(head.retrieve(name))
            return head;
        else
            return retrieve_List(name, head.getNext());
    }


//**********************************************************************************************************************
//* retrieve nodes which contains the String keywords in the List and display those nodes
//**********************************************************************************************************************

    public void retrieve_List_related(String key) {
        if(key != null)
            retrieve_List_related(key, head);
        else
            return;
    }


//**********************************************************************************************************************
//* recursive function of retrieve related nodes in the list
//**********************************************************************************************************************

    private void retrieve_List_related(String key, List_node head) {
        if(head == null)
            return;
        if(head.retrieve_related(key)) {
            System.out.println("This Connection contains the keyword \033[31m" + key + "\033[0m");
            head.display();
        }
        else
            retrieve_List_related(key, head.getNext());
    }

//**********************************************************************************************************************
//* Basic display function
//**********************************************************************************************************************

    public void display() {
        System.out.println("To destination: \033[34m" + getDestination() + "\033[0m");
    }

//**********************************************************************************************************************
//* display all information in the list
//**********************************************************************************************************************

    public void display_all_connections() {
        if(head == null)
            System.out.println("Empty: No available connections");
        else
            display_all_connection(head);
    }

//**********************************************************************************************************************
//* recursive function of display all nodes in the List
//**********************************************************************************************************************

    private void display_all_connection(List_node head) {
        if(head == null)
            return;
        head.display();
        display_all_connection(head.getNext());
    }
}
