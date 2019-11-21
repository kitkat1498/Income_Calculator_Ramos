/* By Manuel Ramos 
Date: 10/04/2019
Professor: Dr. Tyson McMillan
School: Tarrant County College
Assignment: The array vs the vector | income calculator using C++ 10-29-2019
Lesson: Learned the ups and downs of vectors and arrays and how they compare to one another.
*/
#include <iostream>
#include <vector>
#include <algorithm> //for sort() and reverse()
#include <iomanip> //for setprecision()
#include <numeric>
using namespace std;

void arrayBank(double array[], int sizeOfArray);
void vectorBank(vector<double> &vect);

int main() 
{
  //array style
  double makeBankArray[6] {800.77, 4276.24, 2000.00, 1345.21, 300.00};
  makeBankArray[5] = 500.00;
  arrayBank(makeBankArray, 6);

  //vector style
  vector<double> makeBankVector = {800.77, 4276.24, 2000.00, 1345.21, 300.00};
  makeBankVector.push_back(500.00);
  vectorBank(makeBankVector); //call the vectorBank function

  return 0;  
}

void arrayBank(double array[], int sizeOfArray)
{
  //sort the values ASC (least to greatest) and print the values to the screen with $ appended to the front.
  //in the same function sort the values DESC (greatest to least) and print the values to the screen with $ appended to the front.
  //Additionally, sum up the values in the array, and print your monthly total income to the screen.
  double sum = 0.0;
  sort(array, array+sizeOfArray);//sort the array ASC
  reverse(array,array+sizeOfArray); //sort the array DESC
  //print the array and sum its contents
  cout << "\n\nArray Output: " << endl;
  for(int i = 0; i < sizeOfArray; i++)
  {
    cout << fixed << setprecision(2) << "$" << array[i] << endl;
    //add to the sum the value from the array(increment)
    sum = sum + array[i];
  }
  cout << "\nYour total deposit is: $" << sum << endl;
  

}

void vectorBank(vector<double> &vect)
{
  double sum = 0.0;
  sort(vect.begin(), vect.end());//sort the vector ASC
  reverse(vect.begin(),vect.end());//sort the vector DESC
  cout << "\n\nVector Output: " << endl;
  sum = accumulate(vect.begin(),vect.end(), 0.00); //pass 0.00 to keep precision
  for(double x : vect)
  {
    cout << "$" << x << endl;
  }
  cout << "Your total deposit is: $" << sum << endl;
}