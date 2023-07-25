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
        float side_lengths;
        float height;

        PyramidBase4(float l, float h) {
            this->side_lengths = l;
            this->height = h;
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

};

class Sphere {
    float radius;
    
    Sphere(float r) {
        this->radius = r;
    }
};