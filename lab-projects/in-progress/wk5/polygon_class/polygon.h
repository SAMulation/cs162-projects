#ifndef POLYGON_H
#define POLYGON_H

class Polygon {
public:
    Polygon() : n(3), side(1), x(0), y(0) {}
    Polygon(const int&, const double&, const double&, const double&);

    int get_n() const { return n; }
    double get_side() const { return side; }
    double get_x() const { return x; }
    double get_y() const { return y; }

    void set_n(const int&);
    void set_side(const double&);
    void set_x(const double&);
    void set_y(const double&);

    double get_perimeter() const;
    double get_area() const;

    private:
        int n;
        double side;
        double x;
        double y;
};

#endif
