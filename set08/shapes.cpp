#include "shapes.h"
#include <cmath>

using std::pow;

/* Implementation of the base Shape class. */
Shape::Shape()
{
    /* empty */
}

Shape::~Shape()
{
    /* empty */
}


/* Implementation of the Circle subclass. */
Circle::Circle(double radius)
{
    this->radius = radius;
}

Circle::Circle(const Circle & c)
{
    this->radius = c.radius;
}

Circle::~Circle()
{
    /* empty */
}

double Circle::area()
{
    return M_PI * pow(radius, 2);
}

double Circle::perimeter()
{
    return 2 * radius * M_PI;
}

double Circle::height()
{
    return 2 * radius;
}

double Circle::width()
{
    return 2 * radius;
}

void Circle::rotate()
{
    /* no effect */
}


/* Implementation of the Rectangle subclass. */
Rectangle::Rectangle(double height, double width)
{
    this->h = height;
    this->w = width;
}

Rectangle::Rectangle(const Rectangle & r)
{
    this->h = r.h;
    this->w = r.w;
}

Rectangle::~Rectangle(void)
{
    /* empty */
}

double Rectangle::area()
{
    return h * w;
}

double Rectangle::perimeter()
{
    return 2 * (h + w);
}

double Rectangle::height()
{
    return h;
}

double Rectangle::width()
{
    return w;
}

void Rectangle::rotate()
{
    double tmp = h;

    h = w;
    w = tmp;
}


/* Implementation of the Square subclass. */
Square::Square(double length) : Rectangle(length, length)
{
    this->h = length;
    this->w = length;
}

Square::Square(const Square & s) : Rectangle(s.h, s.w)
{
    this->h = s.h;
    this->w = s.w;
}

Square::~Square(void)
{
    /* empty */
}