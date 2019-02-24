//********************************
//* Name: Jingtao Cheng
//* ID: 940067494
//* CS202 Program4
//********************************

package Jingtao_Prog4;
//****************************************
// This class is the basic node of the bst
// uber and store the baisc information of
// each uber driver including name, distance,
// stars and etc
//****************************************
public class Uber_driver {

    private Uber_driver left;
    private Uber_driver right;

    private String name;
    private String distance;
    private String stars;
//****************************************
// This is the default constructor
//****************************************
    public Uber_driver() {
        this.name = null;
        this.distance = null;
        this.stars = null;
    }
//****************************************
// This is the copy constructor
//****************************************
    public Uber_driver(String name1, String distance1, String stars1) {
        this.name = name1;
        this.distance = distance1;
        this.stars = stars1;
    }
//****************************************
// This function used to return name
//****************************************
    public String getName() {
        return this.name;
    }
//****************************************
// This function used to reutrn the left
// reference
//****************************************
    public Uber_driver getLeft() {
        return left;
    }
 //****************************************
// This function used to return right
 // reference
//****************************************
    public Uber_driver getRight() {
        return right;
    }
//****************************************
// This function used to set the left reference
//****************************************
    public void setLeft(Uber_driver to_set) {
        this.left = to_set;
    }
//****************************************
// This function used to set the right reference
//****************************************
    public void setRight(Uber_driver to_set) {
        this.right = to_set;
    }
//****************************************
// This function used to display information
// stored in the uber driver node
//****************************************
    public void display() {
        if(name != null) {
            System.out.println(" Uber driver: " + name + " ; ");
            System.out.println(" Distance:    " + distance + " ; ");
            System.out.println(" Stars:       " + stars + " ; ");
        }
        else
            System.out.println(" No Uber driver ");
    }

}
