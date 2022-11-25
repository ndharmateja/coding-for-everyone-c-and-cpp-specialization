#include <stdio.h>

void double_space(FILE *ifp, FILE *ofp)
{
    rewind(ifp);
    char c;
    while ((c = getc(ifp)) != EOF)
    {
        putc(c, ofp);
        if (c == '\n')
        {
            putc(c, ofp);
        }
    }
}

int main(void)
{
    FILE *ifp = fopen("data.txt", "r");
    FILE *ofp = fopen("data_double_space.txt", "w");

    double_space(ifp, ofp);

    fclose(ifp);
    fclose(ofp);
}