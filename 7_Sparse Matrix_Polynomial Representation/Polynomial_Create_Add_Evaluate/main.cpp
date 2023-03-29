#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent a single term in a polynomial
struct Term {
    int coeff; // coefficient of the term
    int exp;   // exponent of the term
};

// Define a struct to represent a polynomial as a collection of terms
struct Poly {
    int n;          // number of terms in the polynomial
    struct Term *terms; // array of terms in the polynomial
};

// Function to create a polynomial by taking input from the user
void create(struct Poly *p) {
    int i;
    printf("Number of terms?"); // ask the user for the number of terms in the polynomial
    scanf("%d", &p->n); // read the input from the user and store it in the polynomial's n field
    p->terms = (struct Term*)malloc(p->n * sizeof(struct Term)); // allocate memory for the terms array
    printf("Enter terms\n");
    for (i = 0; i < p->n; i++) {
        scanf("%d%d", &p->terms[i].coeff, &p->terms[i].exp); // read the coefficient and exponent of each term from the user
    }
}

// Function to display a polynomial to the console
void display(struct Poly p) {
    int i;
    for (i = 0; i < p.n; i++) {
        printf("%dx%d+", p.terms[i].coeff, p.terms[i].exp); // print each term to the console
    }
    printf("\n");
}

// Function to add two polynomials and return the result as a new polynomial
struct Poly *add(struct Poly *p1, struct Poly *p2) {
    int i, j, k;
    struct Poly *sum; // define a pointer to hold the sum of the two polynomials
    sum = (struct Poly*)malloc(sizeof(struct Poly)); // allocate memory for the sum polynomial
    sum->terms = (struct Term*)malloc((p1->n + p2->n) * sizeof(struct Term)); // allocate memory for the terms array of the sum polynomial
    i = j = k = 0;
    while (i < p1->n && j < p2->n) {
        if (p1->terms[i].exp > p2->terms[j].exp) {
            sum->terms[k++] = p1->terms[i++]; // add the term from p1 to the sum polynomial
        } else if (p1->terms[i].exp < p2->terms[j].exp) {
            sum->terms[k++] = p2->terms[j++]; // add the term from p2 to the sum polynomial
        } else {
            sum->terms[k].exp = p1->terms[i].exp; // add the exponent of the term to the sum polynomial
            sum->terms[k++].coeff = p1->terms[i++].coeff + p2->terms[j++].coeff; // add the coefficients of the two terms and add the result to the sum polynomial
        }
    }
    for (; i < p1->n; i++) {
        sum->terms[k++] = p1->terms[i]; // copy the remaining terms from p1 to the sum polynomial
    }
    for (; j < p2->n; j++) {
        sum->terms[k++] = p2->terms[j]; // copy the remaining terms from p2 to the sum polynomial
    }
    sum->n = k; // set the number of terms in the sum polynomial
    return sum; // return a pointer to the sum polynomial
}

// Main function of the program
int main() {
    struct Poly p1, p2, *p3; // declare three polynomial variables: p1, p2 and p3
    create(&p1); // create the first polynomial by taking input from the user
    create(&p2); // create the second polynomial by taking input from the user
    p3 = add(&p1, &p2); // add the first two polynomials and store the result in p3
    printf("\n");
    display(p1); // display the first polynomial to the console
    printf("\n");
    display(p2); // display the second polynomial to the console
    printf("\n");
    display(*p3); // display the sum polynomial to the console
    return 0; // terminate the program
}
