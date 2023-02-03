#ifndef STUDENT_H
#define STUDENT_H
using namespace std;

#include <string>

class Student {
  public:
    Student(string firstName, string lastName, int idNum);
    Student();
    string getFirstName() const;
    string getLastName() const;
    int getIdNum() const;
    void setFirstName(string);
    void setLastName(string);
    void setIdNum(int);
  private:
    string firstName;
    string lastName;
    int idNum;
};

#endif
