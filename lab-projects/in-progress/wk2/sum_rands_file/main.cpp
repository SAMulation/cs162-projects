/*************************
 * Name: Random Number Files
 * Author: Sam Sarsten
 * Date: 01-02-2022
 * Purpose: Practicing reading from and adding to files in C++
 * 
**************************/


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX = 10000;

int main()
{
  ifstream input;
  
  input.open("randomNumbers.txt");
  if(!input.is_open())
  {
    cout << "File failed to open..." << endl;
    exit(1);
  }

  int numbers[MAX];
  int count = 0;
  while (input >> numbers[count])
  {
    count++;
  }

  // Calculate sum
  int sum = 0;
  for (int i = 0; i < count; i++)
  {
    sum += numbers[i];
  }

  cout << "The sum of the numbers in the file was: " << sum << endl; 
  cout << "The average of the numbers in the file was: " << static_cast<double>(sum) / count << endl;

  // Add 100 new numbers to the end of the file
  ofstream output;
  output.open("randomNumbers.txt", ios::app);
  if(!output.is_open())
  {
    cout << "File failed to open..." << endl;
    exit(1);
  }

  srand(time(NULL));

  for (int i = 0; i < 100; i++) {
    output << endl << rand() % 100 + 1;
  }

  // Recalculate the sum in the data file
  sum = count = 0;
  input.clear();  // Needed because reached EOF
  input.seekg(0); // Seek back to ios::beg
  while (input >> numbers[count]) {
    sum += numbers[count];
    count++;
  }

  cout << "The sum after adding 100 values to the file is: " << sum << endl;
  cout << "The average after adding 100 values to the file is: " << static_cast<double>(sum) / count << endl;
  cout << "There are now " << count << " numbers in the file.";

  input.close();
  output.close();

  return 0;
}
