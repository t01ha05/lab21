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


