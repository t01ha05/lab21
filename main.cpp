/*
 * Title: Doubly Linked List of Goats
 * Description: This program creates a doubly linked list where each node stores a Goat object. 
 *              It demonstrates how to insert nodes at both the front and back, print the list 
 *              in both forward and reverse order, and handle random Goat object generation.
 * Author: Talha Ahmed
 * Lab: 21
 * Class: COMSC-210 Program Design and Data Structures
 */
 
 #include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

// Constants for the list size and number ranges
const int MIN_NR = 1, MAX_NR = 20, MIN_LS = 5, MAX_LS = 20;

class Goat {
private:
    int age;
    string name;
    string color;

    static const string names[15];
    static const string colors[15];

public:
    // Default constructor
    Goat() {
        age = rand() % (MAX_NR - MIN_NR + 1) + MIN_NR;
        name = names[rand() % 15];
        color = colors[rand() % 15];
    }

    // Parameterized constructor
    Goat(int a, string n, string c) : age(a), name(n), color(c) {}

    // Function to display Goat information
    void display() const {
        cout << name << " (" << color << ", " << age << ")";
    }
};

// Initialize static arrays
const string Goat::names[15] = { "Billy", "Nanny", "Gruff", "Jolly", "Skip", "Buck", "Patches", "Snowy", "Thunder", "Daisy", "Clover", "Chloe", "Ginger", "Rocky", "Sunny" };
const string Goat::colors[15] = { "White", "Black", "Brown", "Gray", "Yellow", "Red", "Blue", "Green", "Gold", "Silver", "Purple", "Pink", "Orange", "Mauve", "Tan" };

class DoublyLinkedList {
private:
    struct Node {
        Goat data; // Now holds a Goat object
        Node* prev;
        Node* next;
        Node(Goat val, Node* p = nullptr, Node* n = nullptr) : data(val), prev(p), next(n) {}
    };
    Node* head;
    Node* tail;

public:
    // Constructor
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Insert at the back
    void push_back(const Goat& goat) {
        Node* newNode = new Node(goat);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Insert at the front
    void push_front(const Goat& goat) {
        Node* newNode = new Node(goat);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Print list forward
    void print() const {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }
        Node* current = head;
        while (current) {
            current->data.display();
            cout << endl;
            current = current->next;
        }
    }

    // Print list backward
    void print_reverse() const {
        if (!tail) {
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

    // Destructor
    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Driver program
int main() {
    srand(time(0)); // Initialize random seed

    DoublyLinkedList list;
    int size = rand() % (MAX_LS - MIN_LS + 1) + MIN_LS;

    // Add random Goats to the list
    for (int i = 0; i < size; ++i) {
        list.push_back(Goat());
    }

    // Print the list forward and backward
    cout << "List forward: " << endl;
    list.print();

    cout << "List backward: " << endl;
    list.print_reverse();

    return 0;
}