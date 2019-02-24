//********************************
//* Name: Jingtao Cheng
//* ID: 940067494
//* CS202 Program4
//********************************

package Jingtao_Prog4;

public class Menu {

    private String title;

    private Menu_list head;

    public Menu() {
        this.title = null;
        this.head = null;
    }

    public Menu(String title1) {
        this.title = title1;
        this.head = null;
    }

    public void insert(Food food1) {
        if(head == null) {
            head = new Menu_list(food1);
        }
        Menu_list temp = new Menu_list(food1);
        temp.setNext(head);
        head = temp;
    }

    private void display(Menu_list head) {
        if(head == null)
            return;
        head.display();
        display(head.getNext());
        return;
    }
    public void display() {
        if(head != null)
            display(head);
        else
            System.out.println("Empty Menu");
    }
}
