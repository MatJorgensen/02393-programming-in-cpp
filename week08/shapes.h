#ifndef __shape__
#define __shape__

class Shape {

    public:
        // constructor
        Shape();

        //destructor
        ~Shape();

        virtual double area(void) = 0;

        virtual double perimeter(void) = 0;

        virtual double height(void) = 0;

        virtual double width(void) = 0;

        virtual void rotate(void) = 0;

    private:
        double h;
        double w;
};

class Circle : public Shape 
{ 
    public: 
        Circle(double radius);
    
        Circle(const Circle & c);
        
        ~Circle(void);

        double area(void);
        double perimeter(void);
        double height(void);
        double width(void);
        void rotate(void);

    private:
        double radius;
};

class Rectangle : public Shape 
{ 
    public:
        Rectangle(double height, double width);
    
        Rectangle(const Rectangle & r);
        
        ~Rectangle(void);

        double area(void);
        double perimeter(void);
        double height(void);
        double width(void);
        void rotate(void);
    
    private:
        double h;
        double w;
};

class Square : public Rectangle 
{ 
    public:
        Square(double length);
    
        Square(const Square & s);
        
        ~Square(void);

    private:
        double h;
        double w;
};



#endif