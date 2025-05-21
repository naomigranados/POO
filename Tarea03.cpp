#include <iostream>
#include <cmath>

class Figura {
protected:
    double area;
public:
    Figura() : area(-1.0) {}
    virtual void calcularArea() = 0; // Método puro virtual
    double obtenerArea() const { return area; }
    virtual ~Figura() {}
};

class Circulo : public Figura {
private:
    double radio;
public:
    Circulo(double r) : radio(r) {}
    void calcularArea() override {
        if (area < 0) {
            area = M_PI * radio * radio;
        }
    }
};

class Cuadrado : public Figura {
private:
    double lado;
public:
    Cuadrado(double l) : lado(l) {}
    void calcularArea() override {
        if (area < 0) {
            area = lado * lado;
        }
    }
};

class Triangulo : public Figura {
private:
    double base, altura;
public:
    Triangulo(double b, double h) : base(b), altura(h) {}
    void calcularArea() override {
        if (area < 0) {
            area = (base * altura) / 2.0;
        }
    }
};

int main() {
    Circulo c(5.0);
    Cuadrado q(4.0);
    Triangulo t(6.0, 3.0);

    c.calcularArea();
    q.calcularArea();
    t.calcularArea();

    std::cout << "Área del círculo: " << c.obtenerArea() << std::endl;
    std::cout << "Área del cuadrado: " << q.obtenerArea() << std::endl;
    std::cout << "Área del triángulo: " << t.obtenerArea() << std::endl;

    // No recalcula porque ya están calculadas
    c.calcularArea();
    q.calcularArea();
    t.calcularArea();

    return 0;
}
