//********************************
//* Name: Jingtao Cheng
//* ID: 940067494
//* CS202 Program4
//********************************

//********************************
// This class is the node of Menu
// list, it has next reference to
// itself, and has private member
// of Food object which is the
// dynamic binding to subclass of
// food class
//********************************
package Jingtao_Prog4;

public class Menu_list {

    private Menu_list next;

    private Food food;

    //********************************
    // default constructor to initial
    // all to null
    //********************************
    public Menu_list() {
        this.next = null;
        this.food = null;
    }

    //********************************
    // copy constructor
    //********************************
    public Menu_list(Food food1) {
        this.food = food1;
        this.next = null;
    }
    //********************************
    // display function used to call
    // display function in food class
    //********************************
    public void display() {
        food.display();
    }
    //********************************
    // function used to get next by
    // return next reference
    //********************************
    public Menu_list getNext() {
        return this.next;
    }

    //********************************
    // function used to set next by
    // pass in value
    //********************************
    public void setNext(Menu_list next1) {
        this.next = next1;
    }
}

