//********************************
//* Name: Jingtao Cheng
//* ID: 940067494
//* CS202 Program4
//********************************

package Jingtao_Prog4;
//****************************************
// This class is the restaurant class as the
// simple node of bst of restaurant which
// store the name of restaurant and menu
// object and uber object
//****************************************
public class Restaurant {

    private Restaurant left;
    private Restaurant right;

    private String name;
    private BST_Uber uber;
    private Menu menu;
//****************************************
// default constructor of restaurant class
//****************************************
    public Restaurant() {
        this.name = null;
        this.uber = null;
        this.menu = null;
        this.left = null;
        this.right = null;
    }
//****************************************
// copy constructor of restaurant class
//****************************************
    public Restaurant(String name1, BST_Uber uber1, Menu menu1) {
        this.name = name1;
        this.uber = uber1;
        this.menu = menu1;
        this.left = null;
        this.right = null;
    }
//****************************************
// getname function to return the name of
// restaurant
//****************************************
    public String getName() {
        return this.name;
    }
//****************************************
// function used to return the uber reference
//****************************************
    public BST_Uber getUber() {
        return uber;
    }
//****************************************
// funciton used to return menu reference
//****************************************
    public Menu getMenu() {
        return menu;
    }
//****************************************
// function used to set name of restaurnt
//****************************************
    public void setName(String name) {
        this.name = name;
    }
//****************************************
//  function usde to pass in uber reference
//****************************************
    public void setUber(BST_Uber uber) {
        this.uber = uber;
    }
//****************************************
// function used to passed in menu reference
//****************************************
    public void setMenu(Menu menu) {
        this.menu = menu;
    }
//****************************************
// function usded to return the left reference
//****************************************
    public Restaurant getLeft() {
        return left;
    }
//****************************************
// function used to return right reference
//****************************************
    public Restaurant getRight() {
        return right;
    }
//****************************************
//  funciton usde to set left reference
//****************************************
    public void setLeft(Restaurant set_left) {
        this.left = set_left;
    }
//****************************************
//  function used to set right reference
//****************************************
    public void setRight(Restaurant set_right) {
        this.right = set_right;
    }
//****************************************
// display function used to show the infor
// in the restaurant node
//****************************************
    public void display() {
        if(name != null) {
            System.out.println("  " + name + "  ");
        }
        else
            System.out.println(" No Restaurant ");
    }
/*
    public void display_menu() {
        menu.display();
    }

    public void display_uber() {
        uber.display();
    }
*/
}
