#include "shape.h"

//Step 5 - Implement the Point class operators

Point Point::operator + (const Point& p) const
{
    Point point;
    point.x = x + p.x;
    point.y = y + p.y;
    return point;
}

Point& Point::operator += (const Point& p)
{
    this -> x += p.x;
    this -> y += p.y;
    return *this;
}

bool Point::operator == (const Point& p) const
{
    if(p.x == x && p.y == y)
        return true;
    else
        return false;    
}

ostream& operator << (ostream& out, const Point& p)
{
    out << "( " << p.x << ", " << p.y <<")";
}

//Step 6 - Impelment the Shape class operators

Shape& Shape::operator = (const Shape& s)
{
    center = s.center;
    color = new char[strlen(s.color)+1];
    strcpy(color,s.color);
    return *this;
}

Shape& Shape::operator += (const Point& p)
{
    center += p;
    return *this;    
}

ostream& operator << (ostream& out, const Shape& s)
{
    out << "Center: " << s.center << " Color: " << s.color << ":" << s.display() <<endl;
}

Shape operator + (const Point& p, const Shape& s)
{
    Shape shape(0,0,"Red");
    shape.center = s.center + p;
    shape.color = new char[strlen(s.color)+1];
    strcpy(shape.color,s.color);
    return shape;
}

Shape operator + (const Shape& s, const Point& p)
{
    Shape shape(0,0,"Red");
    shape.center = s.center + p;
    shape.color = new char[strlen(s.color)+1];
    strcpy(shape.color,s.color);
    return shape;
}

//Step 7 Implement the Circle class operators

Circle operator + (const Point& p, const Circle& c)
{
    Circle circle(c);
    circle += p;
    return circle;
}

Circle operator + (const Circle& c, const Point& p)
{
    Circle circle(c);
    circle += p;
    return circle;
}

ostream& operator << (ostream& out, const Circle & s)
{
    out<<s;
}

Circle& Circle::operator =  (const Circle& c)
{
    radius = c.radius;
    Shape :: operator=(c);
}
