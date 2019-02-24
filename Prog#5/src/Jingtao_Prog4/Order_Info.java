//********************************
//* Name: Jingtao Cheng
//* ID: 940067494
//* CS202 Program4
//********************************

package Jingtao_Prog4;

//********************************
// THis class is the node of the
// order list, it has next reference
// to if self and two String member
// to store the food and amount of
// order information
//********************************
public class Order_Info {

    private Order_Info next;

    private String food;
    private String amount;
    private String special;
    //********************************
    // Default constructor to initial
    // all the String to null
    //********************************
    public Order_Info() {
        this.next = null;
        this.food = null;
        this.amount = null;
        this.special = null;
    }
    //********************************
    // Copy constructor to pass in
    // the value
    //********************************
    public Order_Info(String food1, String amount1, String special1) {
        this.food = food1;
        this.next = null;
        this.amount = amount1;
        this.special = special1;
    }
    //********************************
    // Display function to display info
    // in the order_info node
    //********************************
    public void display() {
        System.out.println("Food: " + food + " ;     " + "quality: ( " + amount + " ) ;     " + "special instruction: " + special + " ; ");
    }

    //********************************
    // function used to get the next
    // reference by return
    //********************************
    public Order_Info getNext() {
        return next;
    }

    //********************************
    // function used to set next reference
    // by pass in next value
    //********************************
    public void setNext(Order_Info next1) {
        this.next = next1;
    }
}
