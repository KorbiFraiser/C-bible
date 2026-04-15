/* math_demo.c */

#include <stdio.h>
#include <math.h>

int main(void)
{
    double a = 9.0;
    double b = 2.0;
    double x = 0.5;

    printf("=== math.h DEMO ===\n\n");

    /* ---------- Basic functions ---------- */
    printf("sqrt(%.2f) = %.2f\n", a, sqrt(a));
    printf("pow(%.2f, %.2f) = %.2f\n", a, b, pow(a, b));
    printf("fabs(-5.5) = %.2f\n\n", fabs(-5.5));

    /* ---------- Rounding ---------- */
    printf("ceil(2.3) = %.2f\n", ceil(2.3));
    printf("floor(2.3) = %.2f\n\n", floor(2.3));

    /* ---------- Trigonometry (in radians!) ---------- */
    printf("sin(%.2f) = %.2f\n", x, sin(x));
    printf("cos(%.2f) = %.2f\n", x, cos(x));
    printf("tan(%.2f) = %.2f\n\n", x, tan(x));

    /* ---------- Logarithms ---------- */
    printf("log(10) = %.2f (natural log)\n", log(10));
    printf("log10(1000) = %.2f\n\n", log10(1000));

    /* ---------- Define PI ---------- */
    double pi = acos(-1);
    printf("PI = %.10f\n", pi);

    /* ---------- Angle conversion example ---------- */
    double degrees = 90;
    double radians = degrees * pi / 180.0;

    printf("\n%.0f degrees = %.2f radians\n", degrees, radians);
    printf("sin(90°) = %.2f\n", sin(radians));

    printf("\n=== END ===\n");

    return 0;
}