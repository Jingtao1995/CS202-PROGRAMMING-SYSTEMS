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

public class Drink extends Food{ //4 arguments

//********************************
// This is the copy constructor
// and call the super class's
// constructor
//********************************
    public Drink(String type, String name, String des, String price) {
        super(type, name, des, price);
    }
    //********************************
    // override function display
    //********************************
    public void display() {
        System.out.println("        Drink        ");
        super.display();
    }
}
