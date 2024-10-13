#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

const int MIN_NR = 1, MAX_NR = 20, MIN_LS = 5, MAX_LS = 20;

class Goat {
    private:
        int age;
        string name;
        string color;

        static const string names[15];
        static const string colors[15];
    public:

    Goat(){
        age = rand() % (MAX_NR - MIN__NR +1) + MIN_NR;
        name = names[rand()% 15];
        color = colors[rand() % 15];
    }

    Goat(int a, string n, string c) : age(a), name (n), color(c) {}

    void display() const {
        cout << name << " (" << color << "," << age << ")";
    }
};

const string Goat::names[15] = { "Billy", "Nanny", "Gruff", "Jolly", "Skip", "Buck", "Patches", "Snowy", "Thunder", "Daisy", "Clover", "Chloe", "Ginger", "Rocky", "Sunny" };
const string Goat::colors[15] = { "White", "Black", "Brown", "Gray", "Yellow", "Red", "Blue", "Green", "Gold", "Silver", "Purple", "Pink", "Orange", "Mauve", "Tan" };

class DoublyLinkedList {
private:
    struct Node {
         Goat data;
        Node* prev;
        Node* next;
        Node(Goat val, Node* p = nullptr, Node* n = nullptr ) : data (val),prev(p), next(n) {}
    };
    Node* head;
    Node* tail;

public:

DoubleLinkedList () : head(nullptr), tail(nullptr){}

void push_back(const Goat& goat) {
    Node* newNode = new Node(goat);
    if(!tail) {
        head = tail = newNode;

    } else {
        tail->next = newNode;
        newNode->prev=tail;
        tail = newNode;
    }
}

void push_front(const Goat& goat) {
    Node* newNode = new Node (goat);
    if(!head) {
        head = tail = newNode;
    } else {
        newNode->next=head;
        head->prev = newNode;
        head = newNode;
    }
}

void print() const {
    if(!head) {
        cout << "List is empty" <<endl;
        return;
    }
    Node* current = head;
    while (current) {
        current->data.display();
        cout << endl;
        current = current->next;
    }
}

void print_reverse() const{
    if(!tail) {
        cout << "List is empty" << endl;
        return;
    }
    Node* current = tail;
    while (current) {
        current->data.display();
        cout << endl;
        current = current->prev;
    }
}

