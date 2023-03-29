// This program implements a sparse matrix using C
#include <stdio.h>
#include <stdlib.h>

// Struct for each non-zero element in the matrix
struct Element {
    int i; // Row index
    int j; // Column index
    int x; // Value
};

// Struct for the sparse matrix
struct Sparse {
    int m; // Number of rows
    int n; // Number of columns
    int num; // Number of non-zero elements
    struct Element *ele; // Array of non-zero elements
};

// Function to create a sparse matrix
void create(struct Sparse *s) {
    int i;
    printf("Enter Dimensions: ");
    scanf("%d %d", &s->m, &s->n);
    printf("Number of Non-zero Elements: ");
    scanf("%d", &s->num);
    s->ele = (struct Element *)malloc(s->num * sizeof(struct Element));
    printf("Enter Non-zero Elements:\n");
    for (i = 0; i < s->num; i++) {
        scanf("%d %d %d", &s->ele[i].i, &s->ele[i].j, &s->ele[i].x);
    }
}

// Function to display the sparse matrix
void display(struct Sparse s) {
    int i, j, k = 0;
    for (i = 0; i < s.m; i++) {
        for (j = 0; j < s.n; j++) {
            if (i == s.ele[k].i && j == s.ele[k].j) {
                printf("%d ", s.ele[k++].x);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

// Function to add two sparse matrices
struct Sparse *add(struct Sparse *s1, struct Sparse *s2) {
    struct Sparse *sum;
    int i, j, k;
    i = j = k = 0;
    // Check if dimensions of the two matrices are the same
    if (s1->n != s2->n || s1->m != s2->m) {
        return NULL;
    }
    sum = (struct Sparse *)malloc(sizeof(struct Sparse)); // create an object of sparse matrix
    sum->ele = (struct Element *)malloc((s1->num + s2->num) * sizeof(struct Element)); // dynamically create an array of elements
    // Traverse both matrices and add the corresponding non-zero elements
    while (i < s1->num && j < s2->num) {
        if (s1->ele[i].i < s2->ele[j].i) {
            sum->ele[k++] = s1->ele[i++]; // copy and increment the index
        } else if (s1->ele[i].i > s2->ele[j].i) {
            sum->ele[k++] = s2->ele[j++];
        } else {
            if (s1->ele[i].j < s2->ele[j].j) {
                sum->ele[k++] = s1->ele[i++];
            } else if (s1->ele[i].j > s2->ele[j].j) {
                sum->ele[k++] = s2->ele[j++];
            } else {
                sum->ele[k] = s1->ele[i];
                sum->ele[k++].x = s1->ele[i++].x + s2->ele[j++].x;
            }
        }
    }
    // Add the remaining elements from s1 and s2
    for (; i < s1->num; i++) {
        sum->ele[k++] = s1->ele[i];
    }
    for (; j < s2->num; j++) {
        sum->ele[k++] = s2->ele[j];
    }
    sum->m = s1->m;
    sum->n = s1->n;
    sum->num = k;
    return sum;
}

// Main function
int main() {
    struct Sparse s1, s2, *s3;
    create(&s1);
    create(&s2);
    s3 = add(&s1, &s2);
    printf("First Matrix:\n");
    display(s1);
    printf("Second Matrix:\n");
    display(s2);
    printf("Sum Matrix:\n");
    display(*s3);
    return 0;
}
