//********************************
//* Name: Jingtao Cheng
//* ID: 940067494
//* CS202 Program4
//********************************

package Jingtao_Prog4;

//********************************
// This class is the binary search
// tree class of restaurant which
// which contain the root of the
// restaurant nodes
// it also contains the insert
// retrieve, retrieve related and
// remove, remove all and display
// function. It also have function
// to find the inorder successor
// most function return a boolean
// and Restaurant(node) type
//********************************

public class BST_Restaurant {

    private Restaurant root;
//********************************
// This is the default construction
//********************************
    public BST_Restaurant() {
        this.root = null;
    }
//********************************
// This is the insert function
// which passed in 3 arguments include
// String and 2 objective type
// and this is the wrapper function
//********************************
    public void insert_Restaurant(String name, BST_Uber uber_list, Menu menu) {
        root = insert_Restaurant(name, uber_list, menu, this.root);
    }
//********************************
// This is the private insert
// function which invoked by it's
// wrapper and return a Restaurant
// (node) type
//********************************
    private Restaurant insert_Restaurant(String name, BST_Uber uber_list, Menu menu, Restaurant root) {
        if(root == null) {
            root = new Restaurant(name, uber_list, menu);
            return root;
        }
        else {
            if (name.compareToIgnoreCase(root.getName()) < 0) {
                root.setLeft(insert_Restaurant(name, uber_list, menu, root.getLeft()));
            }
            if (name.compareToIgnoreCase(root.getName()) >= 0) {
                root.setRight(insert_Restaurant(name, uber_list, menu, root.getRight()));
            }
        }
        return root;
    }
//****************************************
// This is the retrieve function with pass
// in a String arguments and this is the
// public wrapper function
//****************************************
    public boolean retrieve(String name) {
        if(root == null)
            return false;
        return retrieve(name, root);
    }
//****************************************
// This is the private recursive function
// used to retrieve the restaurant in the
// bst with the same name and return a
// boolean type
//****************************************
    private boolean retrieve(String name, Restaurant root) {
        if(root == null)
            return false;
        if(name.compareToIgnoreCase(root.getName()) < 0) {
            return retrieve(name, root.getLeft());
        }
        if(name.compareToIgnoreCase(root.getName()) >= 0) {
            if(name.equals(root.getName())) {
                root.display();
                return true;
            }
            return retrieve(name, root.getRight());
        }
        return false;
    }
//****************************************
// This is the public wrapper function of
// the relative search function
//****************************************
    public void retrieve_related(String name) {
        if(root == null)
            return;
        retrieve_related(name, root);
    }
//****************************************
// This is the private retrieve function
// use a contain function
//****************************************
    private void retrieve_related(String name, Restaurant root) {
        if(root == null)
            return;
        if(root.getName().contains(name)) {
            root.display();
        }
        retrieve_related(name, root.getLeft());
        retrieve_related(name, root.getRight());
        return;
    }
//****************************************
// This is the public wrappe function of
// the remove function with one passed in
// argument
//****************************************
    public void remove(String name) {
        if(root == null)
            return;
        root = remove(name, root);
    }
//****************************************
// this is the private remove function using
// recursion to search and set the specific
// node to null to remove the node
//****************************************
    private Restaurant remove(String name, Restaurant root) {
        if(root == null)
            return root;
        if(name.compareToIgnoreCase(root.getName()) < 0) {
            root.setLeft(remove(name, root.getLeft()));
        }
        if(name.compareToIgnoreCase(root.getName()) >= 0) {
            if(name.equals(root.getName())) {
                if(root.getRight() == null) {
                    root = root.getLeft();
                }
                else if(root.getLeft() == null) {
                    root = root.getRight();
                }
                else if(root.getLeft() == null && root.getRight() == null)
                    root = null;
                else {
                    Restaurant temp = FindMin(root);
                    root.setName(temp.getName());
                    root.setUber(temp.getUber());
                    root.setMenu(temp.getMenu());
                    remove(temp.getName(), temp);
                }
            }
            root.setRight(remove(name, root.getRight()));
        }
        return root;
    }
//****************************************
// This is the private function to find the
// inorder successor to help remove the node
//****************************************
    private Restaurant FindMin(Restaurant root) {
        if(root == null)
            return null;
        if(root.getLeft() == null) {
            return root;
        }
        return FindMin(root.getLeft());
    }
//****************************************
// This is the public function to remove
// all the node in the BST recursively
//****************************************
    public Restaurant remove_all() {
        root = remove_all(root);
        root = null;
        return root;
    }
//****************************************
// This is the private function to remove
// all the node in the restaurant bst
//****************************************
    private Restaurant remove_all(Restaurant root) {
        if(root == null) {
            return null;
        }
        root.setLeft(remove_all(root.getLeft()));
        root.setRight(remove_all(root.getRight()));
        root = null;
        return root;
    }
//****************************************
// This is the wrapper function of the private
// display function
//****************************************
    public void display() {
        display(root);
    }
//****************************************
// This si the private display function to
// show the information stored in the
// bst node of restaurant
//****************************************
    private void display(Restaurant root) {
        if(root == null)
            return;
        root.display();
        display(root.getLeft());
        display(root.getRight());
    }
}
