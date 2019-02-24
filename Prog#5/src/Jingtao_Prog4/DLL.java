//********************************
//* Name: Jingtao Cheng
//* ID: 940067494
//* CS202 Program4
//********************************

package Jingtao_Prog4;

public class DLL {

    private DLL_Node head;

    public DLL() {
        this.head = null;
    }

    public DLL_Node insert_order(int number) {
        if(head == null) {
            head = new DLL_Node(number);
            head.setPre(null);
            head.setNext(null);
            return head;
        }
        DLL_Node temp = new DLL_Node(number);
        temp.setPre(null);
        head.setPre(temp);
        temp.setNext(head);
        head = temp;
        return head;
    }

    public void insert_order_info(DLL_Node to_add, String food, String amount, String special) {
        if(to_add != null) {
            to_add.insert_info(food, amount, special);
        }else
            System.out.println("Order List is empty");
    }

    private void display_all(DLL_Node head) {
        if(head == null)
            return;
        head.display();
        display_all(head.getNext());
        return;
    }

    public void display_all() {
        display_all(head);
    }



}
