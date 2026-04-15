/* complex_numbers.c */

#include <stdio.h>
#include <complex.h>
#include <math.h>

double complex add(double complex a, double complex b);
double complex mul(double complex a, double complex b);
void printComplex(const char *name, double complex z);


int main(void)
{
    double complex z1 = 3.0 + 4.0 * I;
    double complex z2 = 1.0 - 2.0 * I;

    double complex sum = add(z1, z2);
    double complex prod = mul(z1, z2);

    printf("Complex Numbers Example Program\n\n");

    printComplex("z1", z1);
    printComplex("z2", z2);

    printf("\nSum:\n");
    printComplex("sum", sum);

    printf("\nProduct:\n");
    printComplex("prod", prod);

    return 0;
}


/* ---------- add ---------- */
double complex add(double complex a, double complex b)
{
    return a + b;
}

/* ---------- multiply ---------- */
double complex mul(double complex a, double complex b)
{
    return a * b;
}

/* ---------- pretty print ---------- */
void printComplex(const char *name, double complex z)
{
    double re = creal(z);
    double im = cimag(z);

    printf("%s = %.2f %c %.2fi\n", name, re, (im < 0 ? '-' : '+'), (im < 0 ? -im : im));

    printf("|%s| = %.2f\n", name, cabs(z));
    printf("conj(%s) = %.2f %c %.2fi\n\n", name, creal(conj(z)), (cimag(conj(z)) < 0 ? '-' : '+'), (cimag(conj(z)) < 0 ? -cimag(conj(z)) : cimag(conj(z))));
}