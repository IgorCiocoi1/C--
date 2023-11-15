#include <iostream>

class Matrix {
private:
    double *data;   
    int rows;        
    int cols;        
    mutable int errorCode;   

public:
    // constructor
    Matrix() : data(nullptr), rows(0), cols(0), errorCode(0) {}

    
    Matrix(int size) : rows(size), cols(size), errorCode(0) {
        allocateMemory();
        fillWithZeros();
    }

    
    Matrix(int numRows, int numCols) : rows(numRows), cols(numCols), errorCode(0) {
        allocateMemory();
        fillWithZeros();
    }

    // Destructor 
    ~Matrix() {
        delete[] data;
    }

    
    double getElement(int i, int j) const {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            return data[i * cols + j];
        } else {
            
            errorCode = 1;
            return 0.0; 
        }
    }


    void setElement(int i, int j, double value) {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            data[i * cols + j] = value;
        } else {
            errorCode = 1;
        }
    }

    Matrix add(const Matrix &other) const {
        if (rows == other.rows && cols == other.cols) {
            Matrix result(rows, cols);
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    result.setElement(i, j, getElement(i, j) + other.getElement(i, j));
                }
            }
            return result;
        } else {
            Matrix result;
            result.errorCode = 2;
            return result;
        }
    }

    Matrix subtract(const Matrix &other) const {
        if (rows == other.rows && cols == other.cols) {
            Matrix result(rows, cols);
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    result.setElement(i, j, getElement(i, j) - other.getElement(i, j));
                }
            }
            return result;
        } else {
            Matrix result;
            result.errorCode = 2;
            return result;
        }
    }

    Matrix multiply(const Matrix &other) const {
        if (cols == other.rows) {
            Matrix result(rows, other.cols);
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < other.cols; ++j) {
                    double sum = 0.0;
                    for (int k = 0; k < cols; ++k) {
                        sum += getElement(i, k) * other.getElement(k, j);
                    }
                    result.setElement(i, j, sum);
                }
            }
            return result;
        } else {
            Matrix result;
            result.errorCode = 3;
            return result;
        }
    }

    Matrix multiplyByScalar(double scalar) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.setElement(i, j, getElement(i, j) * scalar);
            }
        }
        return result;
    }

    void display() const {
        if (errorCode == 0) {
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    std::cout << getElement(i, j) << " ";
                }
                std::cout << std::endl;
            }
        } else {
            std::cout << "Invalid matrix (error code: " << errorCode << ")" << std::endl;
        }
    }

private:
    void allocateMemory() {
        try {
            data = new double[rows * cols];
        } catch (std::bad_alloc& e) {
            errorCode = 4;
            std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        }
    }

    void fillWithZeros() {
        for (int i = 0; i < rows * cols; ++i) {
            data[i] = 0.0;
        }
    }
};

int main() {
    Matrix a(2, 2);
    Matrix b(2, 2);

    a.setElement(0, 0, 1.0);
    a.setElement(0, 1, 2.0);
    a.setElement(1, 0, 3.0);
    a.setElement(1, 1, 4.0);

    b.setElement(0, 0, 5.0);
    b.setElement(0, 1, 6.0);
    b.setElement(1, 0, 7.0);
    b.setElement(1, 1, 8.0);

    std::cout << "Matricea A:" << std::endl;
    a.display();

    std::cout << "\nMatricea B:" << std::endl;
    b.display();

    Matrix c = a.multiply(b); 
    std::cout << "\n Inmultirea (A * B):" << std::endl;
    c.display();

    Matrix d = a.add(b); 
    std::cout << "\nAdunarea (A + B):" << std::endl;
    d.display();

    Matrix e = a.subtract(b); 
    std::cout << "\nScaderea (A - B):" << std::endl;
    e.display();

    Matrix f = a.multiplyByScalar(2.0); 
    std::cout << "\nInmultimea cu un nr. (A * 2.0):" << std::endl;
    f.display();

    return 0;
}