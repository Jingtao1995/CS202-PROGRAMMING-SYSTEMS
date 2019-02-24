//********************************
//* Name: Jingtao Cheng
//* ID: 940067494
//* CS202 Program4
//********************************

package Jingtao_Prog4;

//********************************
//* This class is to implement the
//* node of Doubly linked list
//* it has pre and next reference
//* to DLL_Node class and an inter
//* -ger to store the order number
//* and another linear linked list
//* to store the specific info of
//* the order
//********************************
public class DLL_Node {

    int order_number;

    private DLL_Node pre;
    private DLL_Node next;

    private Order_Info head;
//********************************
// default constructor to initial
// all the arguments(String) to
// null and interger to 0
//********************************
    public DLL_Node() {
        order_number = 0;
        this.pre = null;
        this.next = null;
        this.head = null;
    }
//********************************
// Copy constructor to set the
// member in class with arguments
// passed in
//********************************
    public DLL_Node(int number) {
        this.order_number = number;
        this.pre = null;
        this.next = null;
        this.head = null;
    }
    //********************************
    // This function is used to get
    // the next reference by return
    //********************************
    public DLL_Node getNext() {
        return next;
    }
    //********************************
    // This function is used to get
    // the pre reference by return
    //********************************
    public DLL_Node getPre() {
        return pre;
    }

    //********************************
    // This function is used to set the
    // pre reference with the passed in
    // value
    //********************************
    public void setPre(DLL_Node pre) {
        this.pre = pre;
    }

    //********************************
    // This function is used to set the
    // next reference with the passed in
    // value
    //********************************
    public void setNext(DLL_Node next) {
        this.next = next;
    }

    //********************************
    // This function is used to insert
    // the information about order by
    // creating a new order_info object
    //********************************
    public void insert_info(String food1, String amount, String special) {
        if(head == null) {
            head = new Order_Info(food1, amount, special);
            return;
        }
        Order_Info temp = new Order_Info(food1, amount, special);
        temp.setNext(head);
        head = temp;
    }
    //********************************
    // Public display wrapper function
    // to call private display function
    //********************************
    public void display() {
        if(head != null) {
            System.out.println("Order # " + order_number + " : ");
            display(head);
        }else
            System.out.println("Order List Empty");
    }
    //********************************
    // Private display function to
    // recursively show all the orders
    //********************************
    private void display(Order_Info head) {
        if(head == null)
            return;
        head.display();
        display(head.getNext());
        return;
    }
}
