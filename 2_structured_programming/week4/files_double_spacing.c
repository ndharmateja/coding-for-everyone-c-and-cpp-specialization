#include <stdio.h>

void print_file(FILE *fp)
{
    rewind(fp);
    char c;
    while ((c = getc(fp)) != EOF)
        putc(c, stdout);
}

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

int main(int argc, char const *argv[])
{

    const char *input_filename = argv[1];
    const char *output_filename = argv[2];

    FILE *ifp = fopen(input_filename, "r+");
    FILE *ofp = fopen(output_filename, "w+");

    double_space(ifp, ofp);

    printf("Input file (%s) contents: \n", input_filename);
    print_file(ifp);

    printf("\nOutput file (%s) contents after double spacing: \n", output_filename);
    print_file(ofp);

    fclose(ifp);
    fclose(ofp);
}