#include <iostream>
#include <cmath>
using namespace std;

class Vector {
private:
    double x;
    double y;
    double z;

public:
    
    Vector() : x(0.0), y(0.0), z(0.0) {}

    
    Vector(double x, double y, double z) : x(x), y(y), z(z) {}

    // Конструктор копіювання
    Vector(const Vector& other) : x(other.x), y(other.y), z(other.z) {}

    // Перевантаження оператора додавання (+)
    Vector operator+(const Vector& other) const {
        return Vector(x + other.x, y + other.y, z + other.z);
    }

    // Перевантаження оператора віднімання (-)
    Vector operator-(const Vector& other) const {
        return Vector(x - other.x, y - other.y, z - other.z);
    }

    // Перевантаження оператора присвоювання (=)
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
            z = other.z;
        }
        return *this;
    }

    // Перевантаження оператора порівняння (==)
    bool operator==(const Vector& other) const {
        return (x == other.x && y == other.y && z == other.z);
    }

    // Перевантаження оператора порівняння (!=)
    bool operator!=(const Vector& other) const {
        return !(*this == other);
    }

    // Перевантаження оператора виводу (<<)
    friend ostream& operator<<(ostream& out, const Vector& vector) {
        out << "(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
        return out;
    }

    void input() {
        cout << "Введіть координати вектора (x y z): ";
        cin >> x >> y >> z;
    }
};

int main() {
    setlocale(LC_CTYPE, "ukr");
    Vector v1, v2;

    
    cout << "Введення координат першого вектора:\n";
    v1.input();

    
    cout << "Введення координат другого вектора:\n";
    v2.input();

    
    Vector sum = v1 + v2;
    cout << "Сума векторів: " << sum << endl;

    
    Vector diff = v2 - v1;
    cout << "Різниця векторів: " << diff << endl;

    
    if (v1 == v2) {
        cout << "Вектори рівні" << endl;
    }
    else {
        cout << "Вектори не рівні" << endl;
    }

    return 0;
}

