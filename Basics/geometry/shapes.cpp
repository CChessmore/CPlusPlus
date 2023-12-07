//Get some more math functionality access
#include <math.h>
#include <algorithm>

//Declare classes for square, triangle, circle for 2D shapes
class Square {
    public:
        int sides = 4;
        float side_length;

        Square(float size) {
            this->side_length = size;
        }

        float get_area() {
            return this->side_length*this->side_length;
        }

        float get_perimiter() {
            return this->side_length*4;
        }

    //Compare side_length of squares. If these are not equal, return false, otherwise it will return as True
    friend auto operator ==(Square s1, Square s2)
    {
        return (s1.side_length == s2.side_length);
        
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

        //Use Heron's fomrula to find area, since we only have sides
        float get_area() {
            float s = get_perimeter();

            s = (s*(s-this->side1)*(s-this->side2)*(s-this->side3));
            return sqrt(s);
        }

        float get_perimeter(){
            return this->side1+this->side2+this->side3;
        }

        //Put 3 sides in each array, sort, and compare. If triangles are equal, these will match and return True
        //My gut says there's a better way to do this, but it is eluding me.
        friend auto operator ==(Triangle t1, Triangle t2)
        {
            float t1_arr[] = {t1.side1, t1.side2, t1.side3};
            float t2_arr[] = {t2.side1, t2.side2, t2.side3};

            sort(t1_arr,3);
            sort(t2_arr,3);

            for(int i=0; i<3; i++)
            {
                if(t1_arr[i]!=t2_arr[i]) { return false; }
            }
            return true;
        }

};

class Circle {
    public:
        float radius;

        Circle(float size) {
            this->radius = size;
        }

        float get_area() {
            return M_PI*pow(radius,2);
        }

        float get_perimeter() {
            return 2*M_PI*this->radius;
        }
        
        //If radii are the same, the circles are equal (Specifically in this implementation. I don't know if there's wild magic math to disprove this)
        friend auto operator ==(Circle c1, Circle c2)
        {
            return (c1->radius == c2->radius);
        }
};

//Declare classes for cube, 3 & 4 sided pyramids, cylinder, and sphere for 3D shapes

class Cube {
    public:
        int faces = 6;
        float side;

        Cube(float l) {
            this->side = l;
        }

        //Formulas for surface area and volume
        float get_surface_area() {
            return faces*pow(this->side,2);
        }

        float get_volume() {
            return pow(this->side,3);
        }
    
};

//This pyramid will assume equal side lengths and only ask once for base size
//and once for the height of the object.
class PyramidBase3 {
    public:
        float side_lengths;
        float height;

        PyramidBase3(float l, float h) {
            this->side_lengths = l;
            this->height = h;
        }

        //Formulas for surface area, volume, area of base
        float get_volume() {
            return (1/3*(area_of_base() * this->height));
        }

        float get_surface_area() {
            //1.5 here replaces the 3/2 in the formula
            return (area_of_base() + 1.5*side_lengths*this->height);
        }

        float area_of_base()
        {
            return (this->side_lengths*2);
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

        //Formulas for surface area, volume, area of base
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

        //Formulas for surface area and volume
        //Surface area formula is A=2PIrh + 2PIr^2
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
//Formulas for surface area and volume
    float get_surface_area() {
        return pow((4*M_PI*this->radius),2);
    }

    float get_volume() {
        return ((4/3)*M_PI*pow(this->radius,3));
    }

};