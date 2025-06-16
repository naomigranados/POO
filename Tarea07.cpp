#include <iostream>
#include <memory>
#include <cmath>
using namespace std;

// Clase base abstracta
class Figura {
public:
    virtual double calcularArea() const = 0;
    virtual ~Figura() {}
};

// Subclase: Cuadrado
class Cuadrado : public Figura {
    double lado;
public:
    Cuadrado(double l) : lado(l) {}
    double calcularArea() const override {
        return lado * lado;
    }
};

// Subclase: Círculo
class Circulo : public Figura {
    double radio;
public:
    Circulo(double r) : radio(r) {}
    double calcularArea() const override {
        return M_PI * radio * radio;
    }
};

// Subclase: Triángulo
class Triangulo : public Figura {
    double base, altura;
public:
    Triangulo(double b, double h) : base(b), altura(h) {}
    double calcularArea() const override {
        return 0.5 * base * altura;
    }
};

// Fábrica de figuras
class FiguraFactory {
public:
    static unique_ptr<Figura> crearFigura(const string& tipo) {
        if (tipo == "cuadrado") {
            double lado;
            cout << "Ingrese el lado del cuadrado: ";
            cin >> lado;
            return make_unique<Cuadrado>(lado);
        } else if (tipo == "circulo") {
            double radio;
            cout << "Ingrese el radio del circulo: ";
            cin >> radio;
            return make_unique<Circulo>(radio);
        } else if (tipo == "triangulo") {
            double base, altura;
            cout << "Ingrese la base y altura del triangulo: ";
            cin >> base >> altura;
            return make_unique<Triangulo>(base, altura);
        } else {
            return nullptr;
        }
    }
};

// Función principal
int main() {
    string tipo;
    cout << "Que figura desea calcular (cuadrado/circulo/triangulo)? ";
    cin >> tipo;

    auto figura = FiguraFactory::crearFigura(tipo);
    if (figura) {
        cout << "El area de la figura es: " << figura->calcularArea() << endl;
    } else {
        cout << "Tipo de figura no valida." << endl;
    }

    return 0;
}


