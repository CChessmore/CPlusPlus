//PLEASE NOTE
//All constructors and functions assume valid input!

//Declare classes for square, triangle, circle for 2D shapes
class Square {
    public:
        int sides = 4;
        float side_length;
        Square::createSquare(float size) {
            this->side_length = size;
        }

};

class triangle {

    //Constructor will try to make the triangle is "real" by making interior angles add up to 180
    //If none is given, the triangle will be equilateral
    Triangle::newTriangle(float side1, float side2, float side3){
        this->sides[0] = side1;
        this->sides[1] = side2;
        this->sides[2] = side3;
    }
};

class circle {

};

//Declare classes for cube, 3 & 4 sided pyramids, cylinder, and sphere for 3D shapes

class Cube {
    public:
        int faces = 6;
        float height;
        float width;
        float depth;
        Cube::makeCube(float h, float w, float d) {
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
        PyramidBase3::createBaseThree(float l, float h) {
            this->side_lengths = l;
            this->height = h;
        }

};

class PyramidBase4 {
    public:
        float side_lengths;
        float height;
        PyramidBase4::createBaseFour(float l, float h) {
            this->side_lengths = l;
            this->height = h;
        }
};

class Cylinder {
    public:
        float radius;
        float height;
        Cylinder::createCylinder(float r, float h) {
            this->radius = r;
            this->height = h;
        }

};

class Sphere {
    float radius;
    Sphere::createSphere(float r) {
        this->radius = r;
    }
};