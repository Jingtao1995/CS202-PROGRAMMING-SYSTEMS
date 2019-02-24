//********************************
//* Name: Jingtao Cheng
//* ID: 940067494
//* CS202 Program4
//********************************

package Jingtao_Prog4;
//****************************************
// This class is the format of bst and store
// each uber dirver object
//****************************************
public class BST_Uber {

    private Uber_driver root;
//****************************************
// This is the defualt constructor
//****************************************
    public BST_Uber() {
        this.root = null;
    }
//****************************************
// This insert function passed in 3 arguments
//****************************************
    public void insert_Uber(String name, String distance, String stars) {
        root = insert_Uber(name, distance, stars, this.root);
    }
//****************************************
// This private insert function used to
// insert information recursively
//****************************************
    public Uber_driver insert_Uber(String name, String distance, String stars, Uber_driver root) {
        if(root == null) {
            root = new Uber_driver(name, distance, stars);
            return root;
        }
        if(name.compareToIgnoreCase(root.getName()) < 0) {
            root.setLeft(insert_Uber(name, distance, stars, root.getLeft()));
        }
        if(name.compareToIgnoreCase(root.getName()) >= 0) {
            root.setRight(insert_Uber(name, distance, stars, root.getRight()));
        }
        return root;
    }
//****************************************
// This display funciton to show the infor
// store in the uber driver object
//****************************************
    public void display() {
        display(root);
    }
//****************************************
// Recursively traverse the uber driver tree
// and display the information
//****************************************
    private void display(Uber_driver root) {
        if(root == null)
            return;
        root.display();
        display(root.getLeft());
        display(root.getRight());
    }
}
