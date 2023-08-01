//Get some more math functionality access
#include <math.h>

//Declare classes for square, triangle, circle for 2D shapes
class Square {
    public:
        int sides = 4;
        float side_length;

        Square(float size) {
            this->side_length = size;
        }

};

class Triangle {
    public:
        int sides = 3;
        float side1;
        float side2;
        float side3;

        Triangle(float sideA, float sideB, float sideC) {
            this->side1 = sideA;
            this->side2 = sideB;
            this->side3 = sideC;
        }

};

class Circle {
    public:
        float radius;

        Circle(float size) {
            this->radius = size;
        }

};

//Declare classes for cube, 3 & 4 sided pyramids, cylinder, and sphere for 3D shapes

class Cube {
    public:
        int faces = 6;
        float height;
        float width;
        float depth;

        Cube(float h, float w, float d) {
            this->height = h;
            this->width = w;
            this->depth = d;
        }
    
};

//The pyramids will assume equal side lengths and only ask once for base size
//and once for the height of the object.
class PyramidBase3 {
    public:
        float side_lengths;
        float height;

        PyramidBase3(float l, float h) {
            this->side_lengths = l;
            this->height = h;
        }

};

class PyramidBase4 {
    public:
        float length;
        float width;
        float height;

        PyramidBase4(float l, float w, float h) {
            this->length = l;
            this->width = w;
            this->height = h;
        }

        float get_volume() {
            return ((this->length*this->width*this->height )/ 3);
        }

        float get_surface_area() {
            float first_sqrt;
            float second_sqrt;

            //Prepare first side of formula
            first_sqrt = pow((this->width/2),2) + pow(this->height,2);
            first_sqrt = this->length*this->width + this->length*sqrt(first_sqrt);

            //Prepare second side of formula
            second_sqrt = pow((this->length),2) + pow(this->height,2);
            second_sqrt = this->width*sqrt(second_sqrt);

            //Add both sides and return result
            return (first_sqrt + second_sqrt);
        }
};

class Cylinder {
    public:
        float radius;
        float height;

        Cylinder(float r, float h) {
            this->radius = r;
            this->height = h;
        }

        //Formula is A=2PIrh + 2PIr^2
        float get_surface_area() {
            return (2*M_PI*this->radius*this->height + (2*M_PI*pow(this->radius,2)));
        }

        float get_volume() {
            return M_PI*pow(this->radius,2)*this->height;
        }

};

class Sphere {
    float radius;

    Sphere(float r) {
        this->radius = r;
    }

    float get_surface_area() {
        return pow((4*M_PI*this->radius),2);
    }

    float get_volume() {
        return ((4/3)*M_PI*pow(this->radius,3));
    }

};