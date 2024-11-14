#include <stdio.h>

typedef struct
{
    float real;
    float imaginary;
} complex;

void print_complex(complex a)
{
    printf("%f %s %fi\n", a.real, a.imaginary < 0 ? "-" : "+", a.imaginary < 0 ? -a.imaginary : a.imaginary);
}

int main(void)
{
    complex a = {1.0, 2.0};
    print_complex(a);
    a.imaginary = 3.5;
    print_complex(a);
    a.imaginary = -3.5;
    print_complex(a);
    a.real = -1.45;
    print_complex(a);
}