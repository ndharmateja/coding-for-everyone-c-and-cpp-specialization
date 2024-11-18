#include <iostream>

using namespace std;

template <class T>
class list_node
{
public:
    list_node(T data = 0, list_node *next = nullptr) : data(data), next(next) {}
    T data;
    list_node *next;
};

template <class T>
class linked_list
{
public:
    linked_list() : head(nullptr), cursor(nullptr) {}
    void prepend(T data);
    T get_element() { return this->cursor->data; }
    void advance() { this->cursor = this->cursor->next; }
    void print();
    void reset() { this->cursor = this->head; }

private:
    list_node<T> *head;
    list_node<T> *cursor;
    void print_helper();
};

template <class T>
void linked_list<T>::prepend(T data)
{
    list_node<T> *new_node = new list_node<T>(data, this->head);
    if (this->head == nullptr)
        this->cursor = new_node;
    this->head = new_node;
}

template <class T>
void linked_list<T>::print()
{
    // list_node<T> *curr = head;
    // for (list_node<T> *curr = head; curr != nullptr; curr = curr->next)
    //     cout << curr->data << " -> ";
    // cout << "end" << endl;
    this->reset();
    this->print_helper();
}

template <class T>
void linked_list<T>::print_helper()
{
    if (this->cursor == nullptr)
    {
        cout << "end" << endl;
        return;
    }
    cout << this->get_element() << " -> ";
    this->advance();
    this->print_helper();
}

int main(int argc, char const *argv[])
{
    linked_list<int> list;
    for (int i = 0; i < 5; i++)
        list.prepend(i * i);

    list.print();
    return 0;
}
