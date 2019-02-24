//**********************************************************************************************************************
//*Name: Jingtao Cheng
//*ID: 940067494
//*CS202 Winter Program4
//**********************************************************************************************************************

//**********************************************************************************************************************
//* This class is the binary search tree class of Destinations which contains the root reference of the Tree_node class
//* It also has the insert, retrieve, retrieve related nodes by keywords, remove one nodes and find Inorder successor,
//* remove all nodes, etc. Most functions are return by boolean and return by reference.
//**********************************************************************************************************************

package com.company;

public class BST {

    private Tree_node root;

//**********************************************************************************************************************
//* This is the default constructor
//**********************************************************************************************************************

    public BST() {
        this.root = null;
    }

//**********************************************************************************************************************
//* This is the insert functions with String argument and will return a reference of Tree_node
//* this is the Wrapper function
//**********************************************************************************************************************

    public Tree_node add(String des) {
        root = add(des, root);
        return root;
    }

//**********************************************************************************************************************
//* This is the recursive function of insert function, and will return a reference of Tree_node
//**********************************************************************************************************************

    private Tree_node add(String des, Tree_node root) {
        if(root == null) {
            root = new Tree_node(des);
            return root;
        }
        else {
            if(root.getDestination().compareToIgnoreCase(des) > 0) {
                root.setLeft(add(des, root.getLeft()));
            }
            else {
                root.setRight(add(des, root.getRight()));
            }
        }
        return root;
    }

//**********************************************************************************************************************
//* This class is the retrieve class with a String argument, and will return a reference of Tree_node class
//**********************************************************************************************************************

    public Tree_node retrieve(String name) {
        if(name == null) {
            System.out.println("Input NUll String");
            return null;
        }
        else {
            return retrieve(name, root);
        }
    }

//**********************************************************************************************************************
//* This is the recursive retrieve function which will return a reference of Tree_node class
//**********************************************************************************************************************

    private Tree_node retrieve(String name, Tree_node root) {
        if(root == null)
            return null;
        if(root.retrieve(name))
            return root;
        if(root.getDestination().compareToIgnoreCase(name) > 0) {
            return retrieve(name, root.getLeft());
        }
        else
            return retrieve(name, root.getRight());
    }

//**********************************************************************************************************************
//* This is the retrieve related function which will display a node which matches or contains the keywords
//**********************************************************************************************************************

    public void retrieve_related(String key) {
        if(key == null) {
            System.out.println("Input NUll String");
            return;
        }
        else
            retrieve_related(key, root);
    }

//**********************************************************************************************************************
//* This is the recursive function of retrieve related functions
//**********************************************************************************************************************

    private void retrieve_related(String key, Tree_node root) {
        if(root == null)
            return;
        if(root.retrieve_related(key)) {
            root.display();
        }
        retrieve_related(key, root.getLeft());
        retrieve_related(key, root.getRight());
    }

//**********************************************************************************************************************
//* This is the remove function with boolean return type.
//**********************************************************************************************************************

    public boolean remove(String name) {
        if(name == null) {
            System.out.println("Input NUll String");
            return false;
        }
        else
            root = remove(name, root);
        return true;
    }

//**********************************************************************************************************************
//* This is the recursive remove function with a Tree_node class return type;
//**********************************************************************************************************************

    private Tree_node remove(String name, Tree_node root) {
        if(root == null)
            return root;
        if(root.getDestination().compareToIgnoreCase(name) > 0) {
            root.setLeft(remove(name, root.getLeft()));
        }
        if(root.getDestination().compareToIgnoreCase(name) < 0) {
            root.setRight(remove(name, root.getRight()));
        }
        else
        {
            if(root.getLeft() == null) {
                return root.getRight();
            }
            else if(root.getRight() == null) {
                return root.getLeft();
            }
            else if(root.getLeft() == null && root.getRight() == null) {
                return null;
            }
            else {
                Tree_node temp = new Tree_node(getInorder(root.getRight()));

                remove(temp.getDestination(),root);

                temp.setRight(root.getRight());
                temp.setLeft(root.getLeft());
                root = temp;

                return root;
            }
        }
        return root;
    }

//**********************************************************************************************************************
//* This is the function to get the inorder successor, and will return the reference of Inorder node
//**********************************************************************************************************************

    public Tree_node getInorder(Tree_node root) {
        if(root == null)
            return null;
        if(root.getLeft() == null)
            return root;
        return getInorder(root.getLeft());
    }


//**********************************************************************************************************************
//* This is the wrapper function of remove all function and return a boolean type
//**********************************************************************************************************************

    public boolean remove_all() {
        if(root == null) {
            System.out.println("Already empty");
            return true;
        }
        return remove_all(root);
    }

//**********************************************************************************************************************
//* This is the recursive function of remove all function
//**********************************************************************************************************************

    private boolean remove_all(Tree_node root) {
        if(root == null)
            return false;
        remove_all(root.getLeft());
        remove_all(root.getRight());
        this.root = null;
        return true;
    }

//**********************************************************************************************************************
//* This is the wrapper function of display function, which will display all infor in every tree nodes
//**********************************************************************************************************************


    public void display() {
        if(root == null) {
            System.out.println("Empty Tree");
            return;
        }else
            display(root);
    }

//**********************************************************************************************************************
//* This is the recursive function of display function
//**********************************************************************************************************************

    private void display(Tree_node root) {
        if(root == null)
            return;
        root.display();
        System.out.println("-------------------------------------------------");
        root.display_all_connections();
        display(root.getLeft());
        display(root.getRight());
    }
}
