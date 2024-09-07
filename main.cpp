#include <iostream>
#include <vector>

class Shape // Abstract class
{
public:
    virtual void drawShape() = 0;   // Pure virtual function
    virtual void rotateShape() = 0; // Pure virtual function
    virtual ~Shape() {};
};

class OpenShape : public Shape // Abstract class
{
public:
    virtual ~OpenShape() {};
};

class ClosedShape : public Shape // Abstract class
{
public:
    virtual ~ClosedShape() {};
};

class Line : public OpenShape // Concrete Class
{
public:
    virtual void drawShape() override
    {
        std::cout << "Drawing a line" << std::endl;
    }
    virtual void rotateShape() override
    {
        std::cout << "Rotating a line" << std::endl;
    }
    virtual ~Line() {};
};

class Circle : public ClosedShape // Concrete Class
{
public:
    virtual void drawShape() override
    {
        std::cout << "Drawing a circle" << std::endl;
    }
    virtual void rotateShape() override
    {
        std::cout << "Rotating a circle" << std::endl;
    }
    virtual ~Circle() {};
};

class Square : public ClosedShape // Concrete Class
{
public:
    virtual void drawShape() override
    {
        std::cout << "Drawing a square" << std::endl;
    }
    virtual void rotateShape() override
    {
        std::cout << "Rotating a square" << std::endl;
    }
    virtual ~Square() {};
};

void drawShapes(const std::vector<Shape *> &shapes)
{
    for (const auto shape : shapes)
    {
        shape->drawShape();
    }
}

int main()
{
    Shape *p1 = new Circle();
    Shape *p2 = new Line();
    Shape *p3 = new Square();

    std::vector<Shape *> shapes{p1, p2, p3};
    drawShapes(shapes);
    return 0;
}