#include <iostream>
#include <cstring>

using namespace std;

class Point
{
    public:
        Point() { x = 0; y = 0; };
        Point(int x, int y);
        Point(const Point& p);

        // These 4 functions are to be implemented by you
        Point  operator + (const Point&) const;
        Point& operator += (const Point&);
        friend ostream& operator << (ostream&, const Point&);
        bool operator == (const Point&) const;
 
        // These functions have already been implemented
        Point& operator = (const Point&);
        Point  operator * (const int scale) const;
        Point& operator *= (const int scale);

        bool operator != (const Point&) const;
        
        friend istream& operator >> (istream&, Point&);

        // Used to test your implementation --Do not use--
        bool isEqual(const Point&) const;
 
    private:
        int x;
        int y;
};
