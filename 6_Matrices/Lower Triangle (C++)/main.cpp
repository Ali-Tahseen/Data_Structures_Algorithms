#include <iostream>
using namespace std;

// Lower Triangular Matrix class
class LTMatrix{
private:
    int n;      // size of the square matrix
    int* A;     // pointer to the array storing the matrix elements
public:
    // Constructor: Initializes the matrix with given size
    LTMatrix(int n){
        this->n = n;
        A = new int [n * (n + 1)/2];
    }

    // Destructor: Deallocates memory for the matrix
    ~LTMatrix(){ delete[] A; }

    // Display: Prints the matrix elements; row-based by default
    void Display(bool row=true);

    // setRowMajor: Sets the element at (i, j) using row-major mapping
    void setRowMajor(int i, int j, int x);

    // setColMajor: Sets the element at (i, j) using column-major mapping
    void setColMajor(int i, int j, int x);

    // getRowMajor: Returns the element at (i, j) using row-major mapping
    int getRowMajor(int i, int j);

    // getColMajor: Returns the element at (i, j) using column-major mapping
    int getColMajor(int i, int j);

    // getN: Returns the size of the matrix
    int getN(){ return n; }
};

// setRowMajor function implementation
void LTMatrix::setRowMajor(int i, int j, int x) {
    if (i >= j){
        int index = ((i * (i - 1))/2) + j - 1;
        A[index] = x;
    }
}

// setColMajor function implementation
void LTMatrix::setColMajor(int i, int j, int x) {
    if (i >= j){
        int index = (n * (j-1) - (((j-2) * (j-1))/2)) + (i-j);
        A[index] = x;
    }
}

// getRowMajor function implementation
int LTMatrix::getRowMajor(int i, int j) {
    if (i >= j){
        int index = ((i * (i - 1))/2) + j - 1;
        return A[index];
    } else {
        return 0;
    }
}

// getColMajor function implementation
int LTMatrix::getColMajor(int i, int j) {
    if (i >= j){
        int index = (n * (j-1) - (((j-2) * (j-1))/2)) + (i-j);
        return A[index];
    } else {
        return 0;
    }
}

// Display function implementation
void LTMatrix::Display(bool row) {
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (i >= j){
                if (row){
                    cout << getRowMajor(i, j) << " ";
                } else {
                    cout << getColMajor(i, j) << " ";
                }
            } else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}

// Main function
int main() {
    // Create and set a row-major lower triangular matrix
    LTMatrix rm(4);
    rm.setRowMajor(1, 1, 1);
    rm.setRowMajor(2, 1, 2);
    rm.setRowMajor(2, 2, 3);
    rm.setRowMajor(3, 1, 4);
    rm.setRowMajor(3, 2, 5);
    rm.setRowMajor(3, 3, 6);
    rm.setRowMajor(4, 1, 7);
    rm.setRowMajor(4, 2, 8);
    rm.setRowMajor(4, 3, 9);
    rm.setRowMajor(4, 4, 10);

    // Display the row-major matrix
    rm.Display();
    cout << endl;

    // Create and set a column-major lower triangular matrix
    LTMatrix cm(4);
    cm.setColMajor(1, 1, 1);
    cm.setColMajor(2, 1, 2);
    cm.setColMajor(2, 2, 3);
    cm.setColMajor(3, 1, 4);
    cm.setColMajor(3, 2, 5);
    cm.setColMajor(3, 3, 6);
    cm.setColMajor(4, 1, 7);
    cm.setColMajor(4, 2, 8);
    cm.setColMajor(4, 3, 9);
    cm.setColMajor(4, 4, 10);

    cm.Display(false);

    return 0;
}
