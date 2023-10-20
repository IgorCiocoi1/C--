#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Dog {
string rasa;
string nume;
int varsta;
};

// Funcție pentru alocarea memoriei și inițializarea unui câine
Dog* creareCaine(const string& rasa, const string& nume, int varsta) {
Dog* caine = new Dog;
caine->rasa = rasa;
caine->nume = nume;
caine->varsta = varsta;
return caine;
}

// Funcție pentru modificarea vârstei unui câine
void setareVarsta(Dog* caine, int varsta) {
caine->varsta = varsta;
}

// Funcție pentru eliberarea memoriei alocate pentru un câine
void eliberareCaine(Dog* caine) {
delete caine;
}

// Funcție pentru compararea câinilor în funcție de vârstă și apoi de nume
bool comparareCaini(const Dog& caine1, const Dog& caine2) {
if (caine1.varsta == caine2.varsta) {
return caine1.nume < caine2.nume;
}
return caine1.varsta < caine2.varsta;
}

int main() {
// Creare un vector de câini
vector<Dog> caini;

// Adăugare câini în vector
caini.push_back({"Bulldog", "Bob", 5});
caini.push_back({"Dobermann", "Andrei", 3});
caini.push_back({"Labrador", "Charlie", 2});
caini.push_back({"Golden Retriever", "Azurel", 5});

// Sortare câini conform cerinței
sort(caini.begin(), caini.end(), comparareCaini);

// Afișare câini sortați
for (const Dog& caine : caini) {
cout << "Rasa: " << caine.rasa << ", Nume: " << caine.nume << ", Varsta: " << caine.varsta << endl;
}

return 0;
}
