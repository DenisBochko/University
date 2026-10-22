#ifndef NEW_FIG_H
#define NEW_FIG_H

#include "figure.h"

class Triangle : public Figure {
private:
    double a, b, c;
public:
    Triangle(double x, double y, double z);
    double area() override;
    void show() override;
};

#endif
