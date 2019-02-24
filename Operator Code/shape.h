#include "point.h"
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

class Shape
{
    public:
        Shape();
        Shape(int x, int y, const char* c); // Creates a shape with color c and center at point (x,y)
        Shape(const Shape&); // Copy constructor
        ~Shape();

        // These 5 functions will be implemented by you
        Shape& operator =  (const Shape&);
        Shape& operator += (const Point&);

        friend Shape operator + (const Shape&, const Point&);
        friend Shape operator + (const Point&, const Shape&);
        
        friend ostream& operator << (ostream&, const Shape&);

        // These are already implemented
        bool operator == (const Shape&) const;
        bool operator != (const Shape&) const;
        virtual char* display() const;

    private:
        Point center;
        char* color;
};

class Circle : public Shape 
{
    public:
        //Constructor that creates a circle with radius r, centered at point(x,y)
        Circle(int x, int y, int r, const char* c) : Shape(x,y,c), radius(r)  {}; 
        Circle(const Circle &); // Copy constructor

        // These 4 will be implemented in your code
        friend Circle operator + (const Circle&, const Point&);
        friend Circle operator + (const Point&, const Circle&);
        friend ostream& operator << (ostream&, const Circle&);
        Circle& operator =  (const Circle&);

        // You will need this function
        char* display() const;

        // Already implemented
        bool operator == (const Circle&) const;
        bool operator != (const Circle&) const;
        Circle  operator *  (const int scale);
        Circle& operator *= (const int scale);
    private:
        int radius;
};

void tests();
