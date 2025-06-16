#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Interfaz para imprimir detalles
class FigGeoPrinter {
public:
    virtual void PrintDetails() = 0;
};

// Interfaz de repositorio
class Repo {
public:
    virtual int Save(float area) = 0;
    virtual float GetArea(int index) = 0;
    virtual ~Repo() {}
};

// Implementación concreta del repositorio
class VectorRepo : public Repo {
    vector<float> dataBase;
public:
    int Save(float area) override {
        dataBase.push_back(area);
        return dataBase.size() - 1;
    }

    float GetArea(int index) override {
        if (index >= 0 && index < dataBase.size()) {
            return dataBase[index];
        }
        return -1; // valor inválido
    }
};

// Clase abstracta para figuras geométricas
class FigGeo {
protected:
    float area;
    Repo* repo; // Puntero al repositorio

public:
    FigGeo(Repo* r) : area(0), repo(r) {}
    virtual float calcArea() = 0;

    float getArea() {
        return area;
    }

    void saveArea() {
        if (area == 0) {
            cout << "Calculando area...\n";
            area = calcArea();
        }
        repo->Save(area);
    }

    virtual ~FigGeo() {}
};

// Clase concreta: Círculo
class Circle : public FigGeo, public FigGeoPrinter {
    float r;
    const float PI = 3.1416;

public:
    Circle(float radio, Repo* repoPtr) : FigGeo(repoPtr), r(radio) {}

    float calcArea() override {
        return PI * r * r;
    }

    void PrintDetails() override {
        area = calcArea();
        cout << "Circulo - Radio: " << r << " Area: " << area << "\n";
        repo->Save(area);
    }
};

// Clase concreta: Cuadrado
class Square : public FigGeo, public FigGeoPrinter {
    float lado;
public:
    Square(float l, Repo* repoPtr) : FigGeo(repoPtr), lado(l) {}

    float calcArea() override {
        return lado * lado;
    }

    void PrintDetails() override {
        area = calcArea();
        cout << "Cuadrado - Lado: " << lado << " Area: " << area << "\n";
        repo->Save(area);
    }
};

// Clase concreta: Triángulo
class Triangle : public FigGeo, public FigGeoPrinter {
    float base, altura;
public:
    Triangle(float b, float h, Repo* repoPtr) : FigGeo(repoPtr), base(b), altura(h) {}

    float calcArea() override {
        return (base * altura) / 2.0;
    }

    void PrintDetails() override {
        area = calcArea();
        cout << "Triangulo - Base: " << base << " Altura: " << altura << " Area: " << area << "\n";
        repo->Save(area);
    }
};

// Función principal
int main() {
    VectorRepo repositorio;

    Circle c1(5.0, &repositorio);     // Círculo con radio 5
    Square s1(4.0, &repositorio);     // Cuadrado con lado 4
    Triangle t1(6.0, 3.0, &repositorio); // Triángulo con base 6 y altura 3

    c1.PrintDetails();
    s1.PrintDetails();
    t1.PrintDetails();

    cout << "\nAreas guardadas en el repositorio:\n";
    cout << "Area 0: " << repositorio.GetArea(0) << endl;
    cout << "Area 1: " << repositorio.GetArea(1) << endl;
    cout << "Area 2: " << repositorio.GetArea(2) << endl;

    return 0;
}
