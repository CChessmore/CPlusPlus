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

class Triangle {
    public:
        float sideA, sideB, sideC;
        //Constructor takes 3 float inputs. It's possible to create triangles that
        //aren't "real" with this current implementation.
        Triangle::newTriangle(float side1, float side2, float side3){
            this->sideA = side1;
            this->sideB = side2;
            this->sideC = side3;
        }
};

class Circle {
    public:
        float radius;
        Circle::createCircle(float r) {
            this->radius = r;
        }

};

//Declare classes for cube, 3 & 4 sided pyramids, cylinder, and sphere for 3D shapes

class Cube {
    //Technically, this class can handle rectangular prisms as well as cubes
    public:
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
    //Base3 is traingular base pyramids
        float side_lengths;
        float height;
        PyramidBase3::createBaseThree(float l, float h) {
            this->side_lengths = l;
            this->height = h;
        }

};

class PyramidBase4 {
    public:
    //Base4 pyramids are square on bottom, like the pyramids in Egypt
        float side_lengths;
        float height;
        PyramidBase4::createBaseFour(float l, float h) {
            this->side_lengths = l;
            this->height = h;
        }
};

class Cylinder {
    //Possible future project to handle calculus operations with this class?
    public:
        float radius;
        float height;
        Cylinder::createCylinder(float r, float h) {
            this->radius = r;
            this->height = h;
        }

};

class Sphere {
    //It's spherical!
    public:
        float radius;
        Sphere::createSphere(float r) {
            this->radius = r;
        }
};