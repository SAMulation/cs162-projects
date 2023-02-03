/*************************
 * Name: Course Class containing Student Class
 * Author: Sam Sarsten
 * Date: 02-03-2023
 * Purpose: Implementing a Course class in C++
 *          with an encapsulated Student class
 * NOTE: If using VS Code, use the following 2 commands to run:
 *       g++ -o output_file main.cpp course.cpp student.cpp
 *       ./output_file
**************************/

#include "course.h"
#include "student.h"
#include <iostream>
using namespace std;

int main()
{
    // Creating objects of Student class
    Student student1("Mouse", "Mickey", 45678);
    Student student2("Duck", "Daffy", 87654);
    Student student3("Mouse", "Minnie", 65748);
    
    // Creating objects of Course class
    Course course1("Computer Science", "CS162", 4.0);
    course1.addStudent(student1);
    course1.addStudent(student2);
    course1.addStudent(student3);

    // Displaying the information of the course
    cout << "Information of course 1:" << endl;
    cout << course1 << endl;
    
    // Creating another object of Course class
    Course course2("Writing", "WR121", 3.0);
    
    // Comparing two courses
    cout << "Are course 1 and course 2 equal? ";
    if (course1 == course2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    // Adding the students from one course to another
    course2 += course1;

    // Displaying the information of the updated course
    cout << "Information of course 2 after adding students from course 1: " << endl;
    cout << course2 << endl;
    
    return 0;
}
