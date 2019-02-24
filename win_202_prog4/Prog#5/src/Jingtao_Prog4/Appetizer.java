//********************************
//* Name: Jingtao Cheng
//* ID: 940067494
//* CS202 Program4
//********************************

//********************************
// This class is inherited from
// the food class and overrider
// the display function
//********************************
package Jingtao_Prog4;

public class Appetizer extends Food { //3 arguments
//********************************
// This is the copy constructor
// and call the super class's
// constructor
//********************************
    public Appetizer(String type, String name, String des, String price) {
        super(type, name, des, price);
    }
    //********************************
    // override function display
    //********************************
    public void display() {
        System.out.println("        Appetizers      ");
        super.display();
    }
}
