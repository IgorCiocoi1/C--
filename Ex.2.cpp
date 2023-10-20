#include <iostream>
#include <cassert>

using namespace std;

// Definirea structurii pentru vector
struct Vector {
    float* data;     // Pointer către elementele vectorului
    int size;        // Numărul de elemente în vector
};

// Funcție pentru inițializarea vectorului
void initializare(Vector& vector, int size) {
    vector.size = size;
    vector.data = new float[size];
}

// Funcție pentru eliberarea memoriei alocate pentru vector
void eliminare(Vector& vector) {
    delete[] vector.data;
    vector.size = 0;
    vector.data = nullptr;
}

// Funcție pentru setarea/modificarea dimensiunii vectorului
void setareDimensiune(Vector& vector, int newSize) {
    eliminare(vector);
    initializare(vector, newSize);
}

// Funcție pentru accesarea elementului la o anumită poziție în vector
float& accesareElement(Vector& vector, int index) {
    assert(index >= 0 && index < vector.size);
    return vector.data[index];
}

// Funcție pentru calculul sumei elementelor vectorului
float sumaElementelor(Vector& vector) {
    float suma = 0.0f;
    for (int i = 0; i < vector.size; i++) {
        suma += vector.data[i];
    }
    return suma;
}

// Funcție pentru înmulțirea a doi vectori și returnarea rezultatului
Vector inmultireVectori(Vector& vector1, Vector& vector2) {
    assert(vector1.size == vector2.size);
    Vector rezultat;
    initializare(rezultat, vector1.size);
    for (int i = 0; i < vector1.size; i++) {
        rezultat.data[i] = vector1.data[i] * vector2.data[i];
    }
    return rezultat;
}

int main() {
    Vector v1, v2;
    initializare(v1, 3);
    initializare(v2, 3);

    v1.data[0] = 1.0f;
    v1.data[1] = 2.0f;
    v1.data[2] = 3.0f;

    v2.data[0] = 4.0f;
    v2.data[1] = 5.0f;
    v2.data[2] = 6.0f;

    Vector rezultat = inmultireVectori(v1, v2);

    for (int i = 0; i < rezultat.size; i++) {
        cout << "rezultat.data[" << i << "] = " << rezultat.data[i] << endl;
    }

    eliminare(v1);
    eliminare(v2);
    eliminare(rezultat);

    return 0;
}
