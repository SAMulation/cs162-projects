#ifndef COURSE_H
#define COURSE_H
#include <string>
#include "student.h"
using namespace std;

class Course {
  public:
    Course(string, string, float);
    string getTitle() const;
    string getNumber() const;
    float getCredits() const;
    int getNumStudents() const;
    Student getStudentEnrolled(int) const;
    void setTitle(string);
    void setNumber(string);
    void setCredits(float);
    void addStudent(const Student&);
    bool operator==(const Course&) const;
    Course& operator+=(const Course&);
    friend ostream& operator<<(ostream&, const Course&);
  private:
    string title;
    string number;
    float credits;
    Student studentsEnrolled[30];
    int numStudents;
};

#endif
