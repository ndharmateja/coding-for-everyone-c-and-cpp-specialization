#include <stdio.h>

enum day
{
    sun,
    mon,
    tue,
    wed,
    thu,
    fri,
    sat
};

// * We can declare this to use "day d" instead of "enum day d"
// * everywhere, including return types of functions
typedef enum day day;

void print_day(day d)
{
    if (d == sun)
        printf("sunday");
    else if (d == mon)
        printf("monday");
    else if (d == tue)
        printf("tuesday");
    else if (d == wed)
        printf("wednesday");
    else if (d == thu)
        printf("thursday");
    else if (d == fri)
        printf("friday");
    else if (d == sat)
        printf("saturday");
    else
        printf("%d invalid", d);
    printf("\n");
}

day next_day(day d)
{
    return (d + 1) % 7;
}

int main(void)
{
    day d = sat;
    print_day(d);
    d = next_day(d);
    print_day(d);
    d = next_day(d);
    print_day(d);
}