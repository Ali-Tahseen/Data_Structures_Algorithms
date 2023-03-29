#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    printf("Elements are\n");
    for(i=0;i<arr.length;i++)
        printf("%d", arr.A[i]);
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




int main()
{
    struct Array arr={{2,3,4,5,6},10,5};
//    printf("%d\n",BinarySearch(arr,15));
    printf("%d\n",RBinarySearch(arr.A,0,arr.length,9));
    //Display(arr);
    return 0;
}
