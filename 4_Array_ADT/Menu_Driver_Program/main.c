#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    printf("Elements are\n");
    for(i=0;i<arr.length;i++)
        printf("%d\n", arr.A[i]);
}

// As it is modifying the array so it should be a call by address type and x is the value we want to insert
void Append(struct Array *arr, int x)
{
    if(arr->length<arr->size)
        arr->A[arr->length++]=x;
}

void Insert(struct Array *arr,int index, int x)
{
    int i;
    if(index>=0 && index <=arr->length)
    {
       for(i=arr->length;i>index;i--)
            arr->A[i]=arr->A[i-1];
       arr->A[index]=x;
       arr->length++;
    }
}

int Delete(struct Array *arr, int index)
{
    int x=0;
    int i;
    if(index>=0 && index<=arr->length){// check if index is greater than 0 and less than the length of the array
        x=arr->A[index]; // if condition is valid than in the variable x get the variable from a valid index
        // shift the elements
        for(i=index;i<arr->length-1;i++)
            arr->A[i]=arr->A[i+1];
        arr->length--;
        return x;
    }
    return 0;
}

// Get function to get the value at a certain index
int Get(struct Array arr,int index)
{
    if(index>=0 && index<arr.length)
        return arr.A[index];
    return -1;
}

// Set function to change the value at a certain index
void Set(struct Array *arr,int index,int x)
{
    if(index>=0 && index<arr->length)
        arr->A[index]=x;
}

// Max function to find the maximum value from an array
int Max(struct Array arr)
{
    int max=arr.A[0];
    int i;
    for(i=1;i<arr.length;i++)
    {
        if(arr.A[i]>max)
            max=arr.A[i];
    }
    return max;
}



int Min(struct Array arr)
{
    int min=arr.A[0];
    int i;
    for(i=1;i<arr.length;i++)
    {
        if(arr.A[i]<min)
            min=arr.A[i];
    }
    return min;
}

int Sum(struct Array arr)
{
    int s=0;
    int i;
    for(i=0;i<arr.length;i++)
        s+=arr.A[i];

    return s;
}

float Avg(struct Array arr)
{
    return (float)Sum(arr)/arr.length;
}


// swap two elements in an array
void swap(int *x, int *y){
    int temp;
    temp=*x;// temp = value from x
    *x=*y; // value of x modified by value of y
    *y=temp;// and value of y will change to value of temp
}


// function for sorting any arrays
void SortedNum(struct Array *arr){
    int n=arr->length;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++) { if(arr->A[i]>arr->A[j])
            {
                swap(&arr->A[i],&arr->A[j]);
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
void Reverse(struct Array *arr)
{
    int *B;
    int i,j;

    B=(int *)malloc(arr->length*sizeof(int));
    for(i=arr->length-1,j=0;i>=0;i--,j++)
        B[j]=arr->A[i];
    for(i=0;i<arr->length;i++)
        arr->A[i]=B[i];
}

//Reversing an array by swapping first index with last and so on. Note: This method takes less time to swap and reverse the array
void Reverse2(struct Array *arr)
{
    int i,j;
    for(i=0,j=arr->length-1;i<j;i++,j--)
    {
        swap(&arr->A[i],&arr->A[j]);
    }
}



// here we have to pass by address
int LinearSearch(struct Array *arr,int key){
    int i;
    for(i=0;i<arr->length;i++)
    {
        if(key==arr->A[i]){
            //transposition swap
            //swap(&arr->A[i],&arr->A[i-1]);
            // move to head
            swap(&arr->A[i],&arr->A[0]);
            return i;
        }

    }
    return -1;
}



//In order to execute Binary search we have to ensure the list is sorted

//Binary Search Using While Loop
int BinarySearch(struct Array arr, int key){
    int l,mid,h;
    l=0;
    h=arr.length-1;
    while(l<=h){
    mid=(l+h)/2;
    if(key==arr.A[mid])
        return mid;
    else if(key<arr.A[mid])
        h=mid-1;
    else
        l=mid+1;
    }
    return -1;

}

//Binary Search Using Recursion
int RBinarySearch(int a[], int l, int h, int key){
    int mid;

    if(l<=h)
    {
        mid=(l+h)/2;
        if(key==a[mid])
            return mid;
        else if(key<a[mid])
            return RBinarySearch(a,1,mid-1,key);
        else
            return RBinarySearch(a, mid+1,h,key);
    }
    return -1;
}


struct Array* Merge(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array)); //create array in heap

    // This while loop will copy the elements from each array to the new array one my one
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else
            arr3->A[k++]=arr2->A[j++];
    }
    //if the size of arr1 is larger or smaller than arr2 then the remaining elements from arr1 or arr2 can be copied by using the
    //following for loop
    for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];
    for(;j<arr2->length;j++)
        arr3->A[k++]=arr2->A[j];

    // arr3 length = length of arr1 + arr2
    arr3->length=arr1->length+arr2->length;
    arr3->size=10;

    return arr3;
}

// Union function to find common numbers once and all the other unique numbers but on a sorted list it's comparing
// If an index num of one arr is less than other the increment the index and see the next element whether it is equal or not
struct Array* Union(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array)); //create array in heap

    // This while loop will copy the elements from each array to the new array one my one
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else if (arr2->A[j]<arr1->A[i])
            arr3->A[k++]=arr2->A[j++];
        else
        {
            arr3->A[k++]=arr1->A[i++];
            j++;
        }

    }
    //if the size of arr1 is larger or smaller than arr2 then the remaining elements from arr1 or arr2 can be copied by using the
    //following for loop
    for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];
    for(;j<arr2->length;j++)
        arr3->A[k++]=arr2->A[j];

    // The size will depend on how many numbers is added to the arr3 from arr1 and arr2
    arr3->length=k;
    arr3->size=10;

    return arr3;
}


// Function to find the difference in between two arrays
struct Array* Difference(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array)); //create array in heap

    // This while loop will copy the elements from each array to the new array one my one
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else if (arr2->A[j]<arr1->A[i])
            j++;
        else
        {
            i++;
            j++;
        }

    }

    for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];


    // The size will depend on how many numbers is added to the arr3 from arr1 and arr2
    arr3->length=k;
    arr3->size=10;

    return arr3;
}

// Functions to find all the common elements only
struct Array* Intersection(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array)); //create array in heap

    // This while loop will copy the elements from each array to the new array one my one
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            i++;
        else if (arr2->A[j]<arr1->A[i])
            j++;
        else // only if the arrs are equal then copy them
        {
            arr3->A[k++]=arr1->A[i++];
            j++;
        }

    }

    // The size will depend on how many numbers is added to the arr3 from arr1 and arr2
    arr3->length=k;
    arr3->size=10;

    return arr3;
}


int main()
{
    // if the function takes in pointers as parameters when we have to pass address of variable using & sign
    // if the function takes in value as parameters then we pass the pointer

    struct Array arr1;
    int ch;
    int x, index;

    printf("Enter Size of Array");
    scanf("%d",&arr1.size);
    arr1.A=(int *)malloc(arr1.size*sizeof(int));


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
        case 1: printf("Enter an element and index ");
            scanf("%d%d",&x,&index);
            Insert(&arr1,index,x);
            break;

        case 2: printf("Enter index");
            scanf("%d",&index);
            x=Delete(&arr1,index);
            printf("Deleted Element is %d\n", x);
            break;

        case 3: printf("Enter an element to search");
            scanf("%d",&x);
            index=LinearSearch(&arr1,x);
            printf("Element index %d",index);
            break;

        case 4: printf("Sum is %d\n", Sum(arr1));
            break;

        case 5: Display(arr1);
            break;
    }
    }while(ch<6);

    return 0;
}

