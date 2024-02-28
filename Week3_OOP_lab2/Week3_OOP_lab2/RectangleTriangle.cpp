/*
 Program Name: RectangleTriangle.cpp
 Programmer: Moris Gomez
 Date: Saturday 02/24/2024
 Version Control: 2.0
 About: Week 3, CSCI 2, Lab 2.
 Description:
 Create different objects of the classes and try to find areas of rectangle and triangle objects.
*/

#include <iostream>
using namespace std;

//create parent class Shape:
class Shape //abstract parent class bc of virtual function.
{
protected:
    double width;
    double height;
public:
    void setData(double w, double h)
    {
        width = w;
        height = h;
    } //close setData member function.
    
    virtual double area() = 0; //pure virtual / abstract function.
    
}; //close parent class Shape.

//create child class Rectangle of parent class:
class Rectangle: public Shape
{
public:
    double area() //not an abstract child class. bc area is being overidden.
    {
        return width * height;
    }
}; //close child class Rectangle.

//create child class Triangle of parent class:
class Triangle: public Shape
{
public:
    double area() //not an abstract child class. bc area is being overidden.
    {
        return (width * height) / 2;
    }
}; //close child class Triangle.

//create driver for program:
int main()
{
    Shape *sPtr; //sPtr points to address of object w/ data type Shape.
    
    //create object for rectangle:
    Rectangle Rect; //object Rect from child class.
    sPtr = &Rect; //assign address of object Rect to sPtr.
    sPtr -> setData(5, 3); //calling setData on Rect. we can do this bc rect gets all of parent's member functions.
    //note: -> allows us to dereference pointer. similar to *sPtr.setData(5, 3).
    cout << "area of rectangle is " << sPtr -> area() << endl;
    //but how do we do this? a parent class cannot access the member functions of a child class. we use a virtual function in parent class.
  
    //create object for triangle:
    Triangle Tri;
    sPtr = &Tri;
    sPtr -> setData(4, 6);
    cout << "area of triangle is " << sPtr -> area() << endl;
    
    
    
    //Student examples: create objects for child classes:
    //1)
    Rectangle Rect1;
    sPtr = &Rect1;
    sPtr -> setData(100, 200);
    cout << "area of another rectangle is " << sPtr -> area() << endl; //prints 20,000
    
    //2)
    Triangle Tri1;
    sPtr = &Tri1;
    sPtr -> setData(10, 2);
    cout << "area of another triangle is " << sPtr -> area() << endl; //prints 10
    
    Rectangle Rect2;
    sPtr = &Rect2;
    sPtr -> setData(1, 9);
    cout << "area of another rectangle is " << sPtr -> area() << endl; //prints 9
    
    //2)
    Triangle Tri2;
    sPtr = &Tri2;
    sPtr -> setData(40, 39);
    cout << "area of another triangle is " << sPtr -> area() << endl; //prints 780
    
    
    return 0;
} //end driver main.

