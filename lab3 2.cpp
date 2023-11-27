#include <iostream>

using namespace std;

class Stack {
private:
    int* elements; // pointer către zona de memorie alocată dinamic
    int size; // dimensiunea stivei
    int top; // indicele elementului din vârful stivei

public:
    // Constructorul clasei
    Stack(int s) {
        size = s;
        elements = new int[size];
        top = -1;
    }

    // Destructorul clasei
    ~Stack() {
        delete[] elements;
    }

    // Operatorul de adunare a două stive
    Stack operator+(const Stack& other) {
        Stack result(size + other.size);
        for (int i = 0; i <= top; i++) {
            result.elements[i] = elements[i];
        }
        for (int i = 0; i <= other.top; i++) {
            result.elements[top + i + 1] = other.elements[i];
        }
        result.top = top + other.top + 1;
        return result;
    }

    // Operatorul de atribuire
    void operator=(const Stack& other) {
        delete[] elements;
        size = other.size;
        elements = new int[size];
        top = other.top;
        for (int i = 0; i <= top; i++) {
            elements[i] = other.elements[i];
        }
    }

    // Operatorul de returnare a unei stive noi cu ultimele n elemente
    Stack operator()(int n) {
        Stack result(n);
        int start = top - n + 1;
        for (int i = start; i <= top; i++) {
            result.elements[i - start] = elements[i];
        }
        result.top = n - 1;
        return result;
    }

    // Funcția de calcul a normei elementelor stivei
    friend int calculateNorm(const Stack& stack) {
        int norm = 0;
        for (int i = 0; i <= stack.top; i++) {
            norm += stack.elements[i];
        }
        return norm;
    }

    // Operatorul de comparare "=="
    friend bool operator==(const Stack& stack1, const Stack& stack2) {
        if (stack1.top != stack2.top) {
            return false;
        }
        for (int i = 0; i <= stack1.top; i++) {
            if (stack1.elements[i] != stack2.elements[i]) {
                return false;
            }
        }
        return true;
    }

    // Operatorul de comparare "!="
    friend bool operator!=(const Stack& stack1, const Stack& stack2) {
        return !(stack1 == stack2);
    }

    // Operatorul de comparare "<"
    friend bool operator<(const Stack& stack1, const Stack& stack2) {
        return calculateNorm(stack1) < calculateNorm(stack2);
    }

    // Operatorul de comparare ">"
    friend bool operator>(const Stack& stack1, const Stack& stack2) {
        return calculateNorm(stack1) > calculateNorm(stack2);
    }

    // Operatorul de ieșire "<<"
    friend ostream& operator<<(ostream& os, const Stack& stack) {
        for (int i = 0; i <= stack.top; i++) {
            os << stack.elements[i] << " ";
        }
        return os;
    }

    // Operatorul de intrare ">>"
    friend istream& operator>>(istream& is, Stack& stack) {
        for (int i = 0; i < stack.size; i++) {
            is >> stack.elements[i];
            stack.top = i; // Actualizăm top la fiecare citire
        }
        return is;
    }
};

int main() {
    Stack stack1(5);
    Stack stack2(3);

    // Introduceți elementele în stive
    cout << "Introduceți elementele în stiva 1: ";
    cin >> stack1;
    cout << "Introduceți elementele în stiva 2: ";
    cin >> stack2;

    // Adunarea a două stive
    Stack stack3 = stack1 + stack2;
    cout << "Rezultatul adunării: " << stack3 << endl;

    // Atribuirea unei stive
    Stack stack4(0);
    stack4 = stack3;
    cout << "Stiva atribuită: " << stack4 << endl;

    // Returnarea unei stive noi cu ultimele n elemente
    int n;
    cout << "Introduceți numărul de elemente pentru stiva nouă: ";
    cin >> n;
    Stack stack5 = stack4(n);
    cout << "Stiva nouă: " << stack5 << endl;

    // Compararea stivelor
    if (stack1 == stack2) {
        cout << "Stiva 1 este egală cu stiva 2" << endl;
    } else {
        cout << "Stiva 1 nu este egală cu stiva 2" << endl;
    }

    if (stack1 != stack2) {
        cout << "Stiva 1 este diferită de stiva 2" << endl;
    } else {
        cout << "Stiva 1 nu este diferită de stiva 2" << endl;
    }

    if (stack1 < stack2) {
        cout << "Stiva 1 este mai mică decât stiva 2" << endl;
    } else {
        cout << "Stiva 1 nu este mai mică decât stiva 2" << endl;
    }

    if (stack1 > stack2) {
        cout << "Stiva 1 este mai mare decât stiva 2" << endl;
    } else {
        cout << "Stiva 1 nu este mai mare decât stiva 2" << endl;
    }

    return 0;
}
