#include "platypus.h"
using namespace std;

Platypus::Platypus() : weight(0), age(0), name(""), gender('\0'), alive(false), mutant(false) {}
Platypus::Platypus(float w, short a, string n, char g) : weight(w), age(a), name(n), gender(g), alive(true), mutant(false) {}

// Print function
void Platypus::print() {
    cout << "Name: " << name << endl;
    cout << "Gender: " << (gender == 'm' ? "Male" : "Female") << endl;
    cout << "Weight: " << weight << " kg" << endl;
    cout << "Age: " << age << " months" << endl;
    cout << "Alive: " << (alive ? "Yes" : "No") << endl;
    cout << "Mutant: " << (mutant ? "Yes" : "No") << endl;
    return;
}

// Age function
void Platypus::ageMe() {
    // Check if the platypus is alive
    if (alive) {
        // Increase the age of the platypus by 1
        age++;
        // Generate a random number between 1 and 100
        int chance = rand() % 100 + 1;
        // Check if the random number is less than or equal to 2 percent
        if (chance <= 2)
            // If it is, set the platypus to be a mutant
            mutant = true;
        // Generate a random number between 1 and 100
        chance = rand() % 100 + 1;
        // Check if the random number is less than or equal to the weight of the platypus times 10
        if (chance <= weight * 10)
            // If it is, set the platypus to be dead
            alive = false;
    }
    return;
}


// Fight function
void Platypus::fight(Platypus &p) {
    if (alive && p.alive) {
        // Calculate the fight ratio based on the weight of each platypus
        float fightRatio = (weight / p.weight) * 50;
        // Generate a random number between 1 and 100
        int result = rand() % 100 + 1;
        // Compare the fight ratio with the random number
        if (result < fightRatio) {
            // If the random number is smaller, set the first platypus to alive and the second to dead
            alive = true;
            p.alive = false;
        } else {
            // If the random number is bigger, set the first platypus to dead and the second to alive
            alive = false;
            p.alive = true;
        }
    }
}

// Eat function
void Platypus::eat() {
    if (alive) {
        // Generate number between 1 and 50
        int random = rand() % 50 + 1;
        weight += weight * (random / 10);
    }
    return;
}

// Hatch function
void Platypus::hatch() {
    alive = true;
    mutant = false;
    age = 0;
    gender = (rand() % 2 == 0) ? 'm' : 'f';
    weight = (rand() % 10 + 1) / 10.0;
    name = getRandomName(gender);
    return;
}

// Get random name functions
string Platypus::getRandomName(char gender) {
    vector<string> names;
    ifstream nameFile;
    if (gender == 'm') {
        nameFile.open("m_names.txt");
    } else if (gender == 'f') {
        nameFile.open("f_names.txt");
    }
    if (!nameFile.is_open()) {
        return "";
    }
    string name;
    while (nameFile >> name) {
        names.push_back(name);
    }
    nameFile.close();
    int randomIndex = rand() % names.size();
    return names[randomIndex];
}