#include <iostream>

class Coordonate2D {
private:
    double x, y;

public:
    // Constructor
    Coordonate2D(double xVal = 0.0, double yVal = 0.0) : x(xVal), y(yVal) {}

    // atribuire si comparare
    Coordonate2D& operator=(const Coordonate2D& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
        }
        return *this;
    }

    bool operator==(const Coordonate2D& other) const {
        return (x == other.x) && (y == other.y);
    }

    bool operator!=(const Coordonate2D& other) const {
        return !(*this == other);
    }

    // Functii prietene pentru operatorii + si -
    friend Coordonate2D operator+(const Coordonate2D& c1, const Coordonate2D& c2);
    friend Coordonate2D operator-(const Coordonate2D& c1, const Coordonate2D& c2);

    // Functii prietene pentru operatorii + si - cu numere obisnuite
    friend Coordonate2D operator+(const Coordonate2D& c, double num);
    friend Coordonate2D operator+(double num, const Coordonate2D& c);
    friend Coordonate2D operator-(const Coordonate2D& c, double num);
    friend Coordonate2D operator-(double num, const Coordonate2D& c);

    // Metode pentru afisare
    void afisare() const {
        std::cout << "(" << x << ", " << y << ")";
    }
};

// Implementare pentru operatorul +
Coordonate2D operator+(const Coordonate2D& c1, const Coordonate2D& c2) {
    return Coordonate2D(c1.x + c2.x, c1.y + c2.y);
}

// Implementare pentru operatorul -
Coordonate2D operator-(const Coordonate2D& c1, const Coordonate2D& c2) {
    return Coordonate2D(c1.x - c2.x, c1.y - c2.y);
}

// Implementare pentru operatorul + cu numere obisnuite
Coordonate2D operator+(const Coordonate2D& c, double num) {
    return Coordonate2D(c.x + num, c.y + num);
}

// Implementare pentru operatorul + cu numere obisnuite (invers)
Coordonate2D operator+(double num, const Coordonate2D& c) {
    return Coordonate2D(c.x + num, c.y + num);
}

// Implementare pentru operatorul - cu numere obisnuite
Coordonate2D operator-(const Coordonate2D& c, double num) {
    return Coordonate2D(c.x - num, c.y - num);
}

// Implementare pentru operatorul - cu numere obisnuite (invers)
Coordonate2D operator-(double num, const Coordonate2D& c) {
    return Coordonate2D(num - c.x, num - c.y);
}

int main() {
    Coordonate2D c1(1.0, 2.0);
    Coordonate2D c2(3.0, 4.0);

    Coordonate2D suma = c1 + c2;
    std::cout << "Suma: ";
    suma.afisare();
    std::cout << std::endl;

    Coordonate2D diferenta = c1 - c2;
    std::cout << "Diferenta: ";
    diferenta.afisare();
    std::cout << std::endl;

    Coordonate2D c3 = c1 + 5.0;
    std::cout << "Adaugare 5.0: ";
    c3.afisare();
    std::cout << std::endl;

    Coordonate2D c4 = 10.0 + c2;
    std::cout << "Adaugare 10.0 (invers): ";
    c4.afisare();
    std::cout << std::endl;

    return 0;
}
