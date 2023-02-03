#include "student.h"
using namespace std;

Student::Student(string first, string last, int id) {
  firstName = first;
  lastName = last;
  idNum = id;
}

Student::Student() {}

string Student::getFirstName() const { return firstName; }
string Student::getLastName() const { return lastName; }
int Student::getIdNum() const { return idNum; }

void Student::setFirstName(string first) {
  firstName = first;
  return;
}

void Student::setLastName(string last) {
  lastName = last;
  return;
}

void Student::setIdNum(int id) {
  idNum = id;
  return;
}