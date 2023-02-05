/*************************
 * Name: GameObject Class implemented through HP Game
 * Author: Sam Sarsten
 * Date: 02-04-2023
 * Purpose: Implementing a GameObject class in C++
 *          through a Harry Potter driver
 * NOTE: If using VS Code, use the following 2 commands to run:
 *       g++ -o output_file main.cpp gameObject.cpp character.cpp collectible.cpp
 *       ./output_file
**************************/

#include <iostream>
#include <string>
#include "gameObject.h"
#include "character.h"
#include "collectible.h"
using namespace std;

int main() {
    // Create two instances of the Character class
    Character harry("Harry Potter", 100, "Wand Magic");
    Character hermione;

    // Create two instances of the Collectible class
    Collectible elderWand("wand", 50, "Elder Wand", 55);
    Collectible cloakOfInvisibility;

    // Set values for the second instance of Character class
    hermione.setName("Hermione Granger");
    hermione.setHealth(90);
    hermione.setSuperPower("Book Magic");

    // Set values for the second instance of Collectible class
    cloakOfInvisibility.setLabel("magic_tool");
    cloakOfInvisibility.setMaxInstances(40);
    cloakOfInvisibility.setName("Invisibility Cloak");
    cloakOfInvisibility.setStrength(45);

    // Display initial values of the Character objects
    cout << "Initial Character Information:" << endl;
    cout << "Name: " << harry.getName() << " Health: " << harry.getHealth()
         << " Superpower: " << harry.getSuperPower() << endl;
    cout << "Name: " << hermione.getName() << " Health: " << hermione.getHealth()
         << " Superpower: " << hermione.getSuperPower() << endl;

    // Display initial values of the Collectible objects
    cout << "Initial Collectible Information:" << endl;
    cout << "Label: " << elderWand.getLabel() << " Name: " << elderWand.getName()
         << " Max Instances: " << elderWand.getMaxInstances() << " Strength: "
         << elderWand.getStrength() << endl;
    cout << "Label: " << cloakOfInvisibility.getLabel() << " Name: "
         << cloakOfInvisibility.getName() << " Max Instances: "
         << cloakOfInvisibility.getMaxInstances() << " Strength: "
         << cloakOfInvisibility.getStrength() << endl;

    // Update values of the Character objects
    harry.setHealth(95);
    harry.setSuperPower("Expecto Patronum");
    hermione.setHealth(85);
    hermione.setSuperPower("Alohomora");

    // Update values of the Collectible objects
    elderWand.setMaxInstances(60);
    elderWand.setStrength(57);
    cloakOfInvisibility.setMaxInstances(50);
    cloakOfInvisibility.setStrength(47);

    // Display updated values of the Character objects
    cout << "Updated Character Information:" << endl;
    cout << "Name: " << harry.getName() << " Health: " << harry.getHealth()
         << " Superpower: " << harry.getSuperPower() << endl;
    cout << "Name: " << hermione.getName() << " Health: " << hermione.getHealth()
         << " Superpower: " << hermione.getSuperPower() << endl;

    // Display updated values of the Collectible objects
    cout << "Updated Collectible Information:" << endl;
    cout << "Name: " << elderWand.getName() << " Strength: " << elderWand.getStrength() << endl;
    cout << "Name: " << cloakOfInvisibility.getName() << " Strength: "
         << cloakOfInvisibility.getStrength() << endl;

    // Get new Character object from user input
    Character userChar;
    string name, superpower;
    int health;
    cout << "Enter character name: ";
    getline(cin, name);
    userChar.setName(name);
    cout << "Enter character health: ";
    cin >> health;
    cin.ignore(80, '\n');
    userChar.setHealth(health);
    cout << "Enter character superpower: ";
    getline(cin, superpower);
    userChar.setSuperPower(superpower);

    // Get new Collectible object from user input
    Collectible userCol;
    string label, collectibleName;
    int maxInstances, strength;
    cout << "Enter collectible label: ";
    getline(cin, label);
    userCol.setLabel(label);
    cout << "Enter collectible name: ";
    getline(cin, collectibleName);
    userCol.setName(collectibleName);
    cout << "Enter maximum instances: ";
    cin >> maxInstances;
    cin.ignore(80, '\n');
    userCol.setMaxInstances(maxInstances);
    cout << "Enter collectible strength: ";
    cin >> strength;
    cin.ignore(80, '\n');
    userCol.setStrength(strength);

    // Display new Character object
    cout << "New Character Information:" << endl;
    cout << "Name: " << userChar.getName() << " Health: " << userChar.getHealth()
         << " Superpower: " << userChar.getSuperPower() << endl;

    // Display new Collectible object
    cout << "New Collectible Information:" << endl;
    cout << "Label: " << userCol.getLabel() << " Name: " << userCol.getName()
         << " Max Instances: " << userCol.getMaxInstances() << " Strength: "
         << userCol.getStrength() << endl;

    return 0;
}