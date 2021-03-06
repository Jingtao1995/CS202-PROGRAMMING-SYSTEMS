//**********************************************************************************************************************
//*Name: Jingtao Cheng
//*ID: 940067494
//*CS202 Winter Program4
//**********************************************************************************************************************


package com.company;
//**********************************************************************************************************************
//*this is the civilian class which derived from Person class
//**********************************************************************************************************************

public class Patient extends Person {
//**********************************************************************************************************************
//* Default constructor and call the base class's constructor
//**********************************************************************************************************************

    Patient() {
        super();
    }
//**********************************************************************************************************************
//*this is the copy constructor with two string argument passed in
//**********************************************************************************************************************

    Patient(String name, String description) {
        super(name, description);
    }
//**********************************************************************************************************************
//*this is the override display function
//**********************************************************************************************************************

@Override
    public void display() {
        super.display();
        System.out.println("Patient, Need special care");
    }
}
