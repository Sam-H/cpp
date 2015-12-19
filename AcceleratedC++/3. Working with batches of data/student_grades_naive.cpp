#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;

int main() {

  // ask for student's name
  cout << "Please enter your first name: ";
  string name;
  cin >> name;
  cout << "Hello, " << name << "!" << endl;

  // ask for and read the midterm and final grades
  cout << "Please enter your midterm and final grades: ";
  double midterm, final;
  cin >> midterm >> final;

  // ask for homework grades
  cout << "Please enter your homework grades: ";

  // number of grades read so far
  int count = 0;
  double sum = 0;

  double x;

  while (cin >> x) {
    ++count;
    sum += x;
  }

  // compute final grade
  streamsize prec = cout.precision();
  cout << "Your final grade is " << setprecision(3) << 0.2*midterm + 0.4*final + 0.4*sum/count
   << setprecision(prec) << endl;

}
