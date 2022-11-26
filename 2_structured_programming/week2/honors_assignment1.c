#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the required constants
#define DECK_SIZE 52
#define NUM_RUNS 1000000
#define HAND_SIZE 7
#define NUM_PIPS 13
#define NUM_SUITS 4
#define NUM_HAND_TYPES 6

// Define enum for the suit
enum Suit
{
    clubs,
    diamonds,
    hearts,
    spades
};
typedef enum Suit Suit;

// Define the struct for the Card
typedef struct
{
    short pips;
    Suit suit;
} Card;

// Swaps two indices in the given array
void swap(Card cards[], int i, int j)
{
    Card temp = cards[i];
    cards[i] = cards[j];
    cards[j] = temp;
}

// Shuffles the given array randomly
// Uses Fisher-Yates algorithm : http://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle#The_modern_algorithm
void shuffle_array(Card cards[])
{
    // Reset random seed each time
    srand(time(0) + (rand() % 100000));

    for (int i = DECK_SIZE - 1; i >= 1; i--)
    {
        int random_index = rand() % (i + 1);
        swap(cards, i, random_index);
    }
}

// Populates the deck of cards in order
void populate_card_array(Card cards[])
{
    int index = 0;
    for (short suit = 0; suit < NUM_SUITS; suit++)
    {
        for (short pip = 0; pip < NUM_PIPS; pip++)
        {
            Card c = {pip, (Suit)suit};
            cards[index++] = c;
        }
    }
}

// Prints one card
void print_card(Card card)
{
    printf("C{p: %d, s: %d}", card.pips, card.suit);
}

// The following functions evaluate if
// the hand is of a particular type
int is_four_of_a_kind(int pips_counts[])
{
    for (int i = 0; i < NUM_PIPS; i++)
    {
        if (pips_counts[i] >= 4)
            return 1;
    }
    return 0;
}

int is_full_house(int pips_counts[])
{
    int num_pairs = 0;
    int num_triplets = 0;

    for (int i = 0; i < NUM_PIPS; i++)
    {
        if (pips_counts[i] >= 3)
            num_triplets++;
        else if (pips_counts[i] == 2)
            num_pairs++;
    }
    return (num_triplets >= 2) || (num_triplets >= 1 && num_pairs >= 1);
}

int is_triplet(int pips_counts[])
{
    for (int i = 0; i < NUM_PIPS; i++)
    {
        if (pips_counts[i] >= 3)
            return 1;
    }
    return 0;
}

int is_pair(int pips_counts[])
{
    for (int i = 0; i < NUM_PIPS; i++)
    {
        if (pips_counts[i] >= 2)
            return 1;
    }
    return 0;
}

int is_two_pair(int pips_counts[])
{
    int num_pairs = 0;
    for (int i = 0; i < NUM_PIPS; i++)
    {
        if (pips_counts[i] >= 2)
            num_pairs++;
    }
    return num_pairs >= 2;
}

// Prints an array
void print_array(int array[], int size, char *title)
{
    printf("%s\n", title);
    printf("[");
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("]\n\n");
}

// Resets all values of array to 0
void reset_counts_array(int counts[], int size)
{
    for (int i = 0; i < size; i++)
        counts[i] = 0;
}

// Runs the simulation
void run_simulation(Card cards[], int counts[])
{
    // Initializes an array for storing the counts of
    // all the pips in each hand
    int pips_counts[NUM_PIPS];

    // Outer loop running for "NUM_RUNS" time
    for (int i = 0; i < NUM_RUNS; i++)
    {
        shuffle_array(cards);

        // Initialize an array for the hand of cards
        Card hand[HAND_SIZE];
        reset_counts_array(pips_counts, NUM_PIPS);

        // Take first 7 cards of the shuffled deck
        // as the hand
        for (int j = 0; j < HAND_SIZE; j++)
        {
            Card card = cards[j];
            short pips = card.pips;
            hand[j] = card;
            pips_counts[pips] += 1;
        }

        // Based on the hand
        // increase appropriate count
        if (is_four_of_a_kind(pips_counts))
        {
            counts[5] += 1;
        }
        else if (is_full_house(pips_counts))
        {
            counts[4] += 1;
        }
        else if (is_triplet(pips_counts))
        {
            counts[3] += 1;
        }
        else if (is_two_pair(pips_counts))
        {
            counts[2] += 1;
        }
        else if (is_pair(pips_counts))
        {
            counts[1] += 1;
        }
        else
        {
            counts[0] += 1;
        }
    }
}

// Prints the analysis of the given counts of hands
void print_analysis(int counts[], char *hands[])
{
    printf("*----------------*---------*-------------*\n");
    printf("| %-14s | %-7s | %-12s|\n", "Hand", "Count", "Probability");
    printf("*----------------*---------*-------------*\n");
    for (int i = NUM_HAND_TYPES - 1; i >= 0; i--)
    {
        printf("| %-14s | %-7d | %-12lf|\n", hands[i], counts[i], (double)counts[i] / NUM_RUNS);
    }
    printf("*----------------*---------*-------------*\n");
    printf("| %-14s | %-7d | %-12lf|\n", "Total", NUM_RUNS, 1.0);
    printf("*----------------*---------*-------------*\n");
}

int main(void)
{
    // Declare and populate the cards array with 52 cards
    Card cards[DECK_SIZE];
    populate_card_array(cards);

    // Initialize hands and their counts
    char *hands[] = {
        "No Pair",
        "Pair",
        "Two Pairs",
        "Triplet",
        "Full House",
        "Four Of A Kind"};
    int counts[NUM_HAND_TYPES];
    reset_counts_array(counts, NUM_HAND_TYPES);

    // Run the simulation
    run_simulation(cards, counts);

    // Print the analysis result
    print_analysis(counts, hands);
}