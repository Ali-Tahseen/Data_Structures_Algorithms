#include <iostream>
using namespace std;

// Define a class for a diagonal matrix
class Diagonal
{
private:
    int *A; // Pointer to store diagonal elements
    int n; // Size of the matrix

public:
    // Default constructor to initialize a diagonal matrix with size 2
    Diagonal()
    {
        n=2;
        A=new int[2];
    }

    // Parameterized constructor to initialize a diagonal matrix with given size
    Diagonal(int n)
    {
        this->n=n; // -> n is the private variable and n is the local parameter
        A=new int[n];
    }

    // Destructor to free memory allocated for diagonal elements
    ~Diagonal()
    {
        delete []A;
    }

    // Function to set the value of a matrix element at position (i,j) to x
    void Set(int i,int j,int x)
    {
        // Check if the element is on the diagonal (i.e., i==j)
        if(i==j)
            A[i-1]=x;
    }

    // Function to get the value of a matrix element at position (i,j)
    int Get(int i,int j)
    {
        // Check if the element is on the diagonal (i.e., i==j)
        if(i==j)
            return A[i-1];
        return 0;
    }

    // Function to display the matrix elements in diagonal form
    void Display()
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                // If the element is on the diagonal, print its value
                if(i==j)
                    cout<<A[i-1]<<" ";
                // Otherwise, print 0
                else
                    cout<<"0 ";
            }
            // Print a new line after each row
            cout<<endl;
        }
    }

    // Function to get the size of the matrix
    int GetDimension()
    {
        return n;
    }
};

// Main function
int main()
{
    int d;
    cout<<"Enter Dimensions";
    cin>>d;

    // Create a Diagonal object with size d
    Diagonal dm(d);

    int x;

    cout<<"Enter All Elements";
    for(int i=1;i<=d;i++)
    {
        for(int j=1;j<=d;j++)
        {
            // Prompt the user to enter the value at position (i,j)
            cin>>x;
            // Set the value of the element at position (i,j) to x
            dm.Set(i,j,x);
        }
    }

    // Display the matrix elements in diagonal form
    dm.Display();

    return 0;
}
