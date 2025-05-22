#include <iostream>
using namespace std;
#include <cmath>
#define pi 3.14
class FigGeo{
    protected:
       float area;
    public:
        virtual float calcArea() = 0;
        float getArea(){
            return area;
        }
        void saveArea(){
            if(area==0){
                cout<<"calculando area...\n";
                area = calcArea();
            }
        }
};

class Circle: public FigGeo {
    float radius;
    public:
    float calcArea() override {
        return pi*radius*radius;
    }
    Circle(){
        radius = 1.0;
        area = 0;
    }
    Circle(float inData) {
        radius = inData;
        area = 0;
    }
    float getRadius(){
        return radius;
    }
    void setRadius(float value) {
        radius = value;
    }
};

class Triangle: public FigGeo {
    float base;
    float height;
    public:
    float calcArea() override {
        return base*height/2;
    }
    Triangle() {
        base = 1.0;
        height = 1.0;
        area = 0;
    }
    float getBase(){
        return base;
    }
    float getHeight(){
        return height;
    }
    void setBase(float value){
        base = value;
    }
    void setHeight(float value){
        height = value;
    }
};

int main() {
   Circle crl;
    crl.saveArea();
    std::cout << "Area del circulo: " << crl.getArea() <<std::endl ;

    Triangle trl;
    trl.saveArea();
    std::cout << "Area del triangulo: " << trl.getArea() << std::endl;
}
