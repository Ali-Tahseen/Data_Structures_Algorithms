#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//no need pass struct parameter for C++ class

class Array{
private:
    int *A;
    int size;
    int length;
    void swap(int *x, int *y); // we wrote the swap function to be used by the other functions to it should not be available
    // globally and should be included in the private part of the program
public:
    Array(){
    size = 10;
    length = 0;
    A = new int[size];
    }
    Array(int sz){
    size=sz;
    length = 0;
    A = new int[size];
    }
    ~Array()
    {
        delete []A;
    }
void Display();
void Append(int x);
void Insert(int index, int x);
int Delete(int index);
int Get(int index);
void Set(int index,int x);
int Max();
int Min();
int Sum();
float Avg();
void SortedNum();
void Reverse();
void Reverse2();
int LinearSearch(int key);
int BinarySearch(int key);
//int RBinarySearch(int a[], int l, int h, int key);
Array* Merge(Array arr2); // Needs the second array to merge  and for a class you don't need to write struct
Array* Union(Array arr2);
Array* Difference(Array arr2);
Array* Intersection(Array arr2);
};

void Array::Display()
{
    int i;
    printf("Elements are\n");
    for(i=0;i<length;i++)
        printf("%d\n", A[i]);
}

// As it is modifying the array so it should be a call by address type and x is the value we want to insert
void Array::Append(int x)
{
    if(length<size)
        A[length++]=x;
}

void Array::Insert(int index, int x)
{
    int i;
    if(index>=0 && index <=length)
    {
       for(i=length;i>index;i--)
            A[i]=A[i-1];
       A[index]=x;
       length++;
    }
}

int Array::Delete(int index)
{
    int x=0;
    int i;
    if(index>=0 && index<=length){// check if index is greater than 0 and less than the length of the array
        x=A[index]; // if condition is valid than in the variable x get the variable from a valid index
        // shift the elements
        for(i=index;i<length-1;i++)
            A[i]=A[i+1];
        length--;
        return x;
    }
    return 0;
}

// Get function to get the value at a certain index
int Array::Get(int index)
{
    if(index>=0 && index<length)
        return A[index];
    return -1;
}

// Set function to change the value at a certain index
void Array::Set(int index,int x)
{
    if(index>=0 && index<length)
        A[index]=x;
}

// Max function to find the maximum value from an array
int Array::Max()
{
    int max=A[0];
    int i;
    for(i=1;i<length;i++)
    {
        if(A[i]>max)
            max=A[i];
    }
    return max;
}



int Array::Min()
{
    int min=A[0];
    int i;
    for(i=1;i<length;i++)
    {
        if(A[i]<min)
            min=A[i];
    }
    return min;
}

int Array::Sum()
{
    int s=0;
    int i;
    for(i=0;i<length;i++)
        s+=A[i];

    return s;
}

float Array::Avg()
{
    return (float)Sum()/length;
}


// swap two elements in an array
void Array::swap(int *x, int *y){
    int temp;
    temp=*x;// temp = value from x
    *x=*y; // value of x modified by value of y
    *y=temp;// and value of y will change to value of temp
}


// function for sorting any arrays
void Array::SortedNum(){
    int n=length;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++) { if(A[i]>A[j])
            {
                swap(&A[i],&A[j]);
            }
        }
    }
}

// for call by address use -> and for call by value use dot
// here we pass by value because it has to only search by value
//int LinearSearch(struct array arr,int key){
//    int i;
//    for(i=0;i<arr.length;i++)
//    {
//        if(key==arr.A[i])
//            return i;
//    }
//    return -1;
//}


// Reversing an array with another array. Note: This method takes longer so not preferrable
void Array::Reverse()
{
    int *B;
    int i,j;

    B = new int[size];
    for(i=length-1,j=0;i>=0;i--,j++)
        B[j]=A[i];
    for(i=0;i<length;i++)
        A[i]=B[i];
}

//Reversing an array by swapping first index with last and so on. Note: This method takes less time to swap and reverse the array
void Array::Reverse2()
{
    int i,j;
    for(i=0,j=length-1;i<j;i++,j--)
    {
        swap(&A[i],&A[j]);
    }
}



// here we have to pass by address
int Array::LinearSearch(int key){
    int i;
    for(i=0;i<length;i++)
    {
        if(key==A[i]){
            //transposition swap
            //swap(&arr->A[i],&arr->A[i-1]);
            // move to head
            swap(&A[i],&A[0]);
            return i;
        }

    }
    return -1;
}



//In order to execute Binary search we have to ensure the list is sorted

//Binary Search Using While Loop
int Array::BinarySearch(int key){
    int l,mid,h;
    l=0;
    h=length-1;
    while(l<=h){
    mid=(l+h)/2;
    if(key==A[mid])
        return mid;
    else if(key<A[mid])
        h=mid-1;
    else
        l=mid+1;
    }
    return -1;

}

//Binary Search Using Recursion
//int RBinarySearch(int a[], int l, int h, int key){
//    int mid;
//
//    if(l<=h)
//    {
//        mid=(l+h)/2;
//        if(key==a[mid])
//            return mid;
//        else if(key<a[mid])
//            return RBinarySearch(a,1,mid-1,key);
//        else
//            return RBinarySearch(a, mid+1,h,key);
//    }
//    return -1;
//}


Array* Array::Merge(Array arr2)
{
    int i,j,k;
    i=j=k=0;
    Array *arr3=new Array(length+arr2.length); //create array in heap

    // This while loop will copy the elements from each array to the new array one my one
    while(i<length && j<arr2.length)
    {
        if(A[i]<arr2.A[j])
            arr3->A[k++]=A[i++];
        else
            arr3->A[k++]=arr2.A[j++];
    }
    //if the size of arr1 is larger or smaller than arr2 then the remaining elements from arr1 or arr2 can be copied by using the
    //following for loop
    for(;i<length;i++)
        arr3->A[k++]=A[i];
    for(;j<arr2.length;j++)
        arr3->A[k++]=arr2.A[j];

    // arr3 length = length of arr1 + arr2
    arr3->length=length+arr2.length;

    return arr3;
}

// Union function to find common numbers once and all the other unique numbers but on a sorted list it's comparing
// If an index num of one arr is less than other the increment the index and see the next element whether it is equal or not
Array* Array::Union(Array arr2)
{
    int i,j,k;
    i=j=k=0;
    Array *arr3=new Array(length+arr2.length); //create array in heap

    // This while loop will copy the elements from each array to the new array one my one
    while(i<length && j<arr2.length)
    {
        if(A[i]<arr2.A[j])
            arr3->A[k++]=A[i++];
        else if (arr2.A[j]<A[i])
            arr3->A[k++]=arr2.A[j++];
        else
        {
            arr3->A[k++]=A[i++];
            j++;
        }

    }
    //if the size of arr1 is larger or smaller than arr2 then the remaining elements from arr1 or arr2 can be copied by using the
    //following for loop
    for(;i<length;i++)
        arr3->A[k++]=A[i];
    for(;j<arr2.length;j++)
        arr3->A[k++]=arr2.A[j];

    // The size will depend on how many numbers is added to the arr3 from arr1 and arr2
    arr3->length=k;

    return arr3;
}


// Function to find the difference in between two arrays
Array* Array::Difference( Array arr2)
{
    int i,j,k;
    i=j=k=0;
    Array *arr3=new Array(length+arr2.length); //create array in heap

    // This while loop will copy the elements from each array to the new array one my one
    while(i<length && j<arr2.length)
    {
        if(A[i]<arr2.A[j])
            arr3->A[k++]=A[i++];
        else if (arr2.A[j]<A[i])
            j++;
        else
        {
            i++;
            j++;
        }

    }

    for(;i<length;i++)
        arr3->A[k++]=A[i];


    // The size will depend on how many numbers is added to the arr3 from arr1 and arr2
    arr3->length=k;

    return arr3;
}

// Functions to find all the common elements only
Array* Array::Intersection(Array arr2)
{
    int i,j,k;
    i=j=k=0;
    Array *arr3=new Array(length+arr2.length); //create array in heap

    // This while loop will copy the elements from each array to the new array one my one
    while(i<length && j<arr2.length)
    {
        if(A[i]<arr2.A[j])
            i++;
        else if (arr2.A[j]<A[i])
            j++;
        else // only if the arrs are equal then copy them
        {
            arr3->A[k++]=A[i++];
            j++;
        }

    }

    // The size will depend on how many numbers is added to the arr3 from arr1 and arr2
    arr3->length=k;


    return arr3;
}


int main()
{
    // if the function takes in pointers as parameters when we have to pass address of variable using & sign
    // if the function takes in value as parameters then we pass the pointer

    Array *arr1;
    int ch, sz;
    int x, index;

    printf("Enter Size of Array");
    scanf("%d",&sz);

    arr1= new Array(sz);


    do{
    printf("Menu\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Search\n");
    printf("4. Sum\n");
    printf("5. Display\n");
    printf("6. Exit\n");

    printf("enter your choice ");
    scanf("%d", &ch);



    switch(ch)
    {
        case 1: cout<<"Enter an element and index ";
                cin>>x>>index;
                arr1->Insert(index,x);
                break;
        case 2: cout<<"Enter index ";
                cin>>index;
                x=arr1->Delete(index);
                cout<<"Deleted Element is"<<x;
                break;
        case 3:cout<<"Enter element to search";
               cin>>x;
               index=arr1->LinearSearch(x);
               cout<<"Element index "<<index;
               break;
        case 4:cout<<"Sum is "<<arr1->Sum();
        break;
        case 5:arr1->Display();
    }
    }while(ch<6);

    return 0;
}

