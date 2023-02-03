/*************************
 * Name: Student Class Containing Array
 * Author: Sam Sarsten
 * Date: 01-25-2023
 * Purpose: Implementing Student class containing
 *          an array with C++
**************************/

#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_COURSES = 7;

struct Name {
    string first;
    string last;
};

struct Course {
    string discipline;
    int number;
};

class Student {
    public:
        // Default constructor
        Student()
        {
            name.first = "";
            name.last = "";
            idNo = 0;
            numCourses = 0;
        }

        Student(string f, string l)
        {
            name.first = f;
            name.last = l;
            idNo = 0;
            numCourses = 0;
        }

        // Accessor functions
        Name getName() const { return name; }
        int getIdNo() const { return idNo; }
        int getNumCourses() const { return numCourses; }
        Course getCourse(int index) const { return courses[index]; }

        // Mutator functions
        void setFirstName(string firstName) { name.first = firstName; return; }
        void setLastName(string lastName) { name.last = lastName; return; }
        void setIdNo(int id) { idNo = id; return; }
        void addCourse(Course c) {
            if (numCourses < MAX_COURSES)
            {
                courses[numCourses].discipline = c.discipline;
                courses[numCourses].number = c.number;
                numCourses++;
            }
            return;
        }

        // Member Functions
        void deleteCourse(int courseNumber) {
            for (int i = 0; i < numCourses; i++)
            {
                if (courses[i].number == courseNumber)
                {
                    for (int j = i; j < numCourses - 1; j++)
                        // Shift courses down an index
                        courses[j] = courses[j + 1];
                    numCourses--;
                    break;
                }
            }
            return;
        }

    private:
        Name name;
        int idNo;
        Course courses[MAX_COURSES];
        int numCourses;
};

int main()
{
    Student students[3];
    students[0].setFirstName("Bugs");
    students[0].setLastName("Bunny");
    students[0].setIdNo(45678);
    Course c1 = { "CS", 162 };
    Course c2 = { "MATH", 101 };
    students[0].addCourse(c1);
    students[0].addCourse(c2);

    students[1].setFirstName("Daffy");
    students[1].setLastName("Duck");
    students[1].setIdNo(87654);
    Course c3 = { "BIO", 221 };
    students[1].addCourse(c3);

    students[2].setFirstName("Minnie");
    students[2].setLastName("Mouse");
    students[2].setIdNo(65748);
    Course c4 = { "HIST", 105 };
    Course c5 = { "PHIL", 201 };
    students[2].addCourse(c4);
    students[2].addCourse(c5);

    for (int i = 0; i < 3; i++)
    {
        cout << "Student " << i + 1 << " Name: " << students[i].getName().first << " " << students[i].getName().last << endl;
        cout << "ID: " << students[i].getIdNo() << endl;
        cout << "Courses:" << endl;
        for (int j = 0; j < students[i].getNumCourses(); j++)
        {
            cout << '\t' << students[i].getCourse(j).discipline << " " << students[i].getCourse(j).number << endl;
        }
        cout << endl;
    }

    students[0].deleteCourse(c1.number);
    students[2].deleteCourse(c4.number);
    cout << "After removing courses:" << endl << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "Student " << i + 1 << " Name: " << students[i].getName().first << " " << students[i].getName().last << endl;
        cout << "ID: " << students[i].getIdNo() << endl;
        cout << "Courses:" << endl;
        for (int j = 0; j < students[i].getNumCourses(); j++)
        {
            cout << '\t' << students[i].getCourse(j).discipline << " " << students[i].getCourse(j).number << endl;
        }
        cout << endl;
    }

    return 0;
}