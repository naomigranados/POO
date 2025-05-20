#include <iostream>
#define pi 3.14
#include <string>
using namespace std;

class Circulo {
  float radio;
  public:
  Circulo(){
      radio= 1.0;
  }
  float getRadio(){
      return radio;
  }
  void setRadio(float value){
      radio= value;
  }
  float area() {
      return pi*radio*radio;
  }
};
  class Triangulo{
      float base, altura;
      public:
      Triangulo(){
          base= 1.0;
          altura= 1.0;
      }
      float getBase(){
          return base;
      }
      float getAltura(){
          return altura;
      }
      void setBase(float value){
          base= value;
      }
      void setAltura(float value){
          altura= value;
      }
      float area() {
          return base*altura /2;
      }
};
      

int main(){
    Circulo crl;
    cout<<"radio: "<<crl.getRadio()<<", area: "<<crl.area()<<"\n";
    crl.setRadio(6.0);
    cout<<"nuevo radio: "<<crl.getRadio()<<", area: "<<crl.area()<< "\n";
    
    Triangulo trl;
    cout<<"base: "<<trl.getBase()<<", altura: "<<trl.getAltura()<<", area: "<<trl.area()<<"\n";
    trl.setBase(4.0);
    trl.setAltura(6.0);
    cout<<"nueva base: "<<trl.getBase()<<", nueva altura: "<<trl.getAltura()<<",area: "<<trl.area()<<"\n";
    return 0;
}
