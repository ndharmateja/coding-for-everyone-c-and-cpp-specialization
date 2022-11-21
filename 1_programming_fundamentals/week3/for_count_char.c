#include <stdio.h>

int main()
{
    int blanks = 0, digits = 0, total_chars = 0;
    int c;

    for (; (c = getchar()) != EOF; total_chars++)
    {
        if (c == ' ')
            ++blanks;
        else if (c >= '0' && c <= '9')
            ++digits;
    }

    printf("digits: %d, blanks: %d, total chars: %d\n\n", digits, blanks, total_chars);

    return 0;
}