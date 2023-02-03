#include "course.h"
#include "student.h"
#include <iostream>
using namespace std;

Course::Course(string title, string number, float credits) :
    title(title), number(number), credits(credits), numStudents(0) {}

string Course::getTitle() const { return title; }
string Course::getNumber() const { return number; }
float Course::getCredits() const { return credits; }
int Course::getNumStudents() const { return numStudents; }
Student Course::getStudentEnrolled(int i) const { return studentsEnrolled[i]; }

void Course::setTitle(string t) {
    title = t;
    return;
}

void Course::setNumber(string n) {
    number = n;
    return;
}

void Course::setCredits(float c) {
    credits = c;
    return;
}

// Add a student to the course
void Course::addStudent(const Student &student) {
    if (numStudents < 30)
        studentsEnrolled[numStudents++] = student;
    else
        cout << "Error: maximum number of students reached for course " << title << endl;
    return;
}

// Overloaded addition operator
Course& Course::operator+=(const Course &c) {
    for (int i = 0; i < c.numStudents; i++)
        addStudent(c.studentsEnrolled[i]);
    return *this;
}

// Overloaded equality operator
bool Course::operator==(const Course &c) const {
    return (title == c.title && number == c.number && credits == c.credits);
}

// Friend function to print information about a course
ostream &operator<<(ostream &output, const Course &course)
{
    output << "Title: " << course.title << endl;
    output << "Number: " << course.number << endl;
    output << "Credits: " << course.credits << endl;
    output << "Number of Students: " << course.numStudents << endl;
    for (int i = 0; i < course.numStudents; i++)
        output << "Student " << i + 1 << ": " << course.studentsEnrolled[i].getFirstName()
           << " " << course.studentsEnrolled[i].getLastName() << endl << "ID #: " << course.studentsEnrolled[i].getIdNum() << "\n\n";
    return output;
}
