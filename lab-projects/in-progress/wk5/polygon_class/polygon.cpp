#include "polygon.h"
#include <cmath>

Polygon::Polygon(const int& nval, const double& sideval, const double& xval, const double& yval)
{
    n = nval;
    side = sideval;
    x = xval;
    y = yval;
}

void Polygon::set_n(const int& nval)
{
    n = nval;
    return;
}

void Polygon::set_side(const double& sideval)
{
    side = sideval;
    return;
}

void Polygon::set_x(const double& xval)
{
    x = xval;
    return;
}

void Polygon::set_y(const double& yval)
{
    y = yval;
    return;
}

double Polygon::get_perimeter() const
{
    return n * side;
}

double Polygon::get_area() const
{
    return (n * side * side) / (4 * tan(M_PI / n));
}
