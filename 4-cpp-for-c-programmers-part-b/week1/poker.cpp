#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

enum class Suit : short
{
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
};

ostream &operator<<(ostream &out, const Suit &suit)
{
    switch (suit)
    {
    case Suit::CLUBS:
        out << "♣";
        break;
    case Suit::DIAMONDS:
        out << "♦";
        break;
    case Suit::HEARTS:
        out << "♥";
        break;
    case Suit::SPADES:
        out << "♠";
        break;
    default:
        break;
    }

    return out;
}

class Rank
{
    friend ostream &operator<<(ostream &out, const Rank &rank);

private:
    int value;

public:
    Rank(int value) : value(value) {}
    int get_value() { return this->value; }
};

ostream &operator<<(ostream &out, const Rank &rank)
{
    if (rank.value == 1)
        out << 'A';
    else if (rank.value == 11)
        out << 'J';
    else if (rank.value == 12)
        out << 'Q';
    else if (rank.value == 13)
        out << 'K';
    else
        out << rank.value;
    return out;
}

class Card
{
    friend ostream &operator<<(ostream &out, const Card &card);

private:
    Suit suit;
    Rank rank;

public:
    Card(Suit suit = Suit::SPADES, Rank rank = 1) : suit(suit), rank(rank) {}
    Suit get_suit() { return this->suit; }
    Rank get_rank() { return this->rank; }
};

ostream &operator<<(ostream &out, const Card &card)
{
    cout << card.rank << card.suit;
    return out;
}

template <class T>
ostream &operator<<(ostream &out, const vector<T> &lst)
{
    cout << "[ ";
    for (auto p = lst.begin(); p != lst.end(); p++)
        out << *p << " ";
    cout << "]";
    return out;
}

class CardUtils
{
private:
    bool are_values_increasing_order(vector<int> &ranks)
    {
        for (int i = 0; i < ranks.size() - 1; i++)
            if (ranks[i] != ranks[i + 1] - 1)
                return false;
        return true;
    }
    void build_counts(vector<Card> &hand, vector<int> &counts)
    {
        for (Card c : hand)
            counts[c.get_rank().get_value()]++;
    }

public:
    bool is_flush(vector<Card> &hand)
    {
        Suit suit = hand[0].get_suit();
        for (auto p = hand.begin() + 1; p != hand.end(); p++)
            if (p->get_suit() != suit)
                return false;
        return true;
    }
    bool is_straight(vector<Card> &hand)
    {
        // Get the ranks and sort them
        vector<int> ranks;
        for (Card c : hand)
            ranks.push_back(c.get_rank().get_value());
        sort(ranks.begin(), ranks.end());

        // If all the values are in increasing order then it is a straight
        if (are_values_increasing_order(ranks))
            return true;

        // Special case straight with Ace: [1, 10, 11, 12, 13]
        // If the first rank is a 1, we can make it 14 and sort it
        // and check again
        if (ranks[0] == 1)
        {
            ranks[0] = 14;
            sort(ranks.begin(), ranks.end());
            if (are_values_increasing_order(ranks))
                return true;
        }

        // Return false otherwise
        return false;
    }
    bool is_straight_flush(vector<Card> &hand) { return is_straight(hand) && is_flush(hand); }
    bool is_four_of_a_kind(vector<Card> &hand)
    {
        vector<int> counts(13);
        build_counts(hand, counts);
        for (auto count : counts)
            if (count == 4)
                return true;
        return false;
    }
    bool is_full_house(vector<Card> &hand)
    {
        vector<int> counts(13);
        build_counts(hand, counts);
        int num_pairs = 0, num_triplets = 0;
        for (auto count : counts)
            if (count == 2)
                num_pairs++;
            else if (count == 3)
                num_triplets++;
        return num_pairs == 1 && num_triplets == 1;
    }
    void init_deck(vector<Card> &deck)
    {
        for (int i = 0; i < 52; i++)
            deck[i] = Card(static_cast<Suit>(i / 13), 1 + (i % 13));
    }
};

int main(int argc, char const *argv[])
{
    // Trials
    int trials = 1000000;
    srand(clock());

    // Initialize deck
    vector<Card> deck(52);
    CardUtils cu;
    cu.init_deck(deck);

    // Run monte carlo sim
    vector<Card> hand(5);
    int straight_count = 0, flush_count = 0, full_house_count = 0;
    int straight_flush_count = 0, four_of_a_kind_count = 0;
    for (int i = 0; i < trials; i++)
    {
        random_shuffle(deck.begin(), deck.end());
        for (int j = 0; j < 5; j++)
            hand[j] = deck[j];
        if (cu.is_straight_flush(hand))
            straight_flush_count++;
        if (cu.is_flush(hand))
            flush_count++;
        if (cu.is_straight(hand))
            straight_count++;
        if (cu.is_four_of_a_kind(hand))
            four_of_a_kind_count++;
        if (cu.is_full_house(hand))
            full_house_count++;
    }

    cout << "Straight:\t" << straight_count << "/" << trials << endl;
    cout << "Flush:\t\t" << flush_count << "/" << trials << endl;
    cout << "Straight flush:\t" << straight_flush_count << "/" << trials << endl;
    cout << "Full house:\t" << full_house_count << "/" << trials << endl;
    cout << "Four of a kind:\t" << four_of_a_kind_count << "/" << trials << endl;
    return 0;
}
