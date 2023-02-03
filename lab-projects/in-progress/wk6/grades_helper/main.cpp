/*************************
 * Name: Gradebook Class Containing Values of up to 4 tests
 * Author: Sam Sarsten
 * Date: 02-02-2023
 * Purpose: Implementing Gradebook class
 *          in C++ using helper class functions
**************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Gradebook
{
    public:
        Gradebook() {
            defaultTests();
        }

        void addTest(int score) {
            if (validScore(score) && checkNumTests())
            {
                tests[numTests++] = score;
                checkLowest(score);
                computeAverage();
            }
            return;
        }

        float getAverage() const {
            return average;
        }

    private:
        static const int SIZE = 4;
        int tests[SIZE];
        int lowestScore;
        float average;
        int numTests;

        void computeAverage() {
            int total = 0;
            // Add up grades
            for (int i = 0; i < numTests; i++)
                total += tests[i];

            if (numTests < SIZE)
                average = static_cast<float>(total) / (SIZE - 1);
            // Remove lowest test score
            else
            {
                total -= lowestScore;
                average = static_cast<float>(total) / (SIZE - 1);
            }
            return;
        }

        void checkLowest(int score) {
            if (score < lowestScore) 
                lowestScore = score;
            return;
        }

        bool validScore(int score) const {
            return score >= 0 && score <= 100;
        }

        bool checkNumTests() const {
            return numTests < SIZE;
        }

        void defaultTests() {
            for (int i = 0; i < SIZE; i++)
                tests[i] = 0;
            lowestScore = 100;
            average = 0;
            numTests = 0;
            return;
        }
};

int main() {
    Gradebook cs162;
    cout << fixed << setprecision(1);

    cs162.addTest(80);
    cs162.addTest(70);
    cs162.addTest(90);
    cs162.addTest(10);

    cout << cs162.getAverage() << endl;

    cs162 = Gradebook();

    cs162.addTest(80);
    cs162.addTest(70);
    cs162.addTest(90);

    cout << cs162.getAverage() << endl;

    cs162.addTest(100);

    cout << cs162.getAverage() << endl;

    // Array is full, none will be added
    cs162.addTest(100);
    cs162.addTest(100);
    cs162.addTest(100);

    cout << cs162.getAverage() << endl;

    cs162 = Gradebook();

    cs162.addTest(80);
    cs162.addTest(80);
    cs162.addTest(80);
    
    cout << cs162.getAverage() << endl;

    // Won't get added, invalid score
    cs162.addTest(150);

    cout << cs162.getAverage() << endl;

    return 0;
}