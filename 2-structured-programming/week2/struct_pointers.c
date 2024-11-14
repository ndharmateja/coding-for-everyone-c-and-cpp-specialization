#include <stdio.h>
#include <math.h>
#include <wchar.h>
#include <locale.h>

enum suit
{
    clubs,
    diamonds,
    hearts,
    spades
};
typedef enum suit suit;

typedef struct
{
    int value;
    suit suit;
} card;

void print_value(int card_value)
{
    char value_string[3] = {'\0', '\0', '\0'};
    if (card_value == 1)
    {
        value_string[0] = 'A';
    }
    else if (card_value >= 2 && card_value <= 9)
    {
        value_string[0] = (char)card_value + 48;
    }
    else if (card_value == 10)
    {
        value_string[0] = '1';
        value_string[1] = '0';
    }
    else if (card_value == 11)
    {
        value_string[0] = 'J';
    }
    else if (card_value == 12)
    {
        value_string[0] = 'Q';
    }
    else if (card_value == 13)
    {
        value_string[0] = 'K';
    }

    printf("%s", value_string);
}

void print_suit(suit card_suit)
{
    wchar_t suit;
    setlocale(LC_CTYPE, "");

    if (card_suit == hearts)
        suit = 0x2661;
    else if (card_suit == clubs)
        suit = 0x2667;
    else if (card_suit == spades)
        suit = 0x2664;
    else if (card_suit == diamonds)
        suit = 0x2662;

    printf("%lc", suit);
}

void print_card_arrow(card *c)
{

    print_value(c->value);
    print_suit(c->suit);
    printf("\n");
}

void print_card_dot(card c)
{

    print_value(c.value);
    print_suit(c.suit);
    printf("\n");
}

int main(void)
{
    card c1 = {13, spades};
    card *c1_pointer = &c1;

    print_card_dot(c1);
    print_card_arrow(c1_pointer);

    return 0;
}
