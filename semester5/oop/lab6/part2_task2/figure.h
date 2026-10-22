#ifndef FIGURE_H
#define FIGURE_H

class Figure {
public:
    virtual double area() = 0;
    virtual void show() = 0;
    virtual ~Figure();
};

class Circle : public Figure {
private:
    double radius;
public:
    Circle(double r);
    double area() override;
    void show() override;
    const double* getRadiusAddress() const;
};

class Rectangle : public Figure {
private:
    double a, b;
public:
    Rectangle(double side);
    Rectangle(double x, double y);
    double area() override;
    void show() override;
    const double* getAAddress() const;
    const double* getBAddress() const;
};

#endif
