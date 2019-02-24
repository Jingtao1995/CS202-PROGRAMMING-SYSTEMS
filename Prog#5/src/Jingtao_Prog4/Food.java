//********************************
//* Name: Jingtao Cheng
//* ID: 940067494
//* CS202 Program4
//********************************

package Jingtao_Prog4;

//********************************
// This class is the abstract class
// of food which contains the several
// String member and functions
//********************************
public abstract class Food {

    private String type;
    private String name;
    private String desription;
    private String price;
    //********************************
    // default constructor to initial
    // all the String to null
    //********************************
    public Food() {
        this.type = null;
        this.name = null;
        this.desription = null;
        this.price = null;
    }
    //********************************
    // copy constructor to pass in
    // value
    //********************************
    public Food(String type1, String name1, String desription1, String price1) {
        this.type = type1;
        this.name = name1;
        this.desription = desription1;
        this.price = price1;
    }

    //********************************
    // display function used to display
    // info in the class
    //********************************
    public void display() {
        if(name == null)
            return;
        System.out.println("Name: "+name);
        if(desription != null)
            System.out.println("Detail: "+desription);
        if(price != null)
            System.out.println("$" + price);
    }
    //********************************
    // This get() and set() following
    // is not necessary
    //********************************
    /*
    public String get_type() { return type; }

    public String get_name() {
        return name;
    }

    public String get_description() {
        return desription;
    }

    public String get_price() {
        return price;
    }

    public void setType(String to_set) { this.type = to_set; }

    public void setName(String name1) {
        this.name = name1;
    }

    public void setDesription(String desription1) {
        this.desription = desription;
    }

    public void setPrice(int price1) {
        this.price = price;
    }
    */
}
