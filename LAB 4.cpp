#include <iostream>
#include <cstring>

class Student {
private:
    char *nume;
    char *specialitate;
    int an;
    float medie;

public:
    // Constructor
    Student(const char *nume, const char *specialitate, int an, float medie) {
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);

        this->specialitate = new char[strlen(specialitate) + 1];
        strcpy(this->specialitate, specialitate);

        this->an = an;
        this->medie = medie;
    }

    // Destructor
    ~Student() {
        delete[] nume;
        delete[] specialitate;
    }

    // Funcție de afișare
    void afisare() const {
        std::cout << "Nume: " << nume << ", Specialitate: " << specialitate
                  << ", An: " << an << ", Medie: " << medie << std::endl;
    }

    // Funcție de schimbare a datelor
    void schimbaDate(const char *nouNume, const char *nouaSpecialitate, int noulAn, float nouaMedie) {
        delete[] nume;
        delete[] specialitate;

        nume = new char[strlen(nouNume) + 1];
        strcpy(nume, nouNume);

        specialitate = new char[strlen(nouaSpecialitate) + 1];
        strcpy(specialitate, nouaSpecialitate);

        an = noulAn;
        medie = nouaMedie;
    }

    // Funcție de comparare după medie
    bool operator<(const Student &s) const {
        return medie < s.medie;
    }
};

// Clasa derivată
class StudentDiplomant : public Student {
private:
    char *temaDiploma;

public:
    // Constructor
    StudentDiplomant(const char *nume, const char *specialitate, int an, float medie, const char *temaDiploma)
        : Student(nume, specialitate, an, medie) {
        this->temaDiploma = new char[strlen(temaDiploma) + 1];
        strcpy(this->temaDiploma, temaDiploma);
    }

    // Destructor
    ~StudentDiplomant() {
        delete[] temaDiploma;
    }

    // Funcție de afișare pentru clasa derivată
    void afisare() const {
        Student::afisare();
        std::cout << "Tema de diploma: " << temaDiploma << std::endl;
    }
};

int main() {
    // Exemplu de utilizare
    Student student("Murafa Dan", "Managementul Informational", 2, 7.9);
    student.afisare();

    StudentDiplomant studentDiplomant("Bazatin Bogdan", "FAF", 2, 8.8, "c++ in viata noastra");
    studentDiplomant.afisare();

    return 0;
}
