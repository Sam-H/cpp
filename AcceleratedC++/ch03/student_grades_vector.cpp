#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;
using std::vector;
using std::sort;

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

  double x;
  vector<double> homework;

  while (cin >> x) {
    homework.push_back(x);
  }

  // check that the student entered some homework grades
  typedef vector<double>::size_type vec_sz;
  vec_sz size = homework.size();
  if (size == 0) {
    cout << endl << "You must enter your grades."
    "Please try again." << endl;
    return 1;
  }

  sort(homework.begin(), homework.end());

  // Computing median of homework grades
  vec_sz mid = size/2;
  double median;
  median = size % 2 == 0 ? (homework[mid-1] + homework[mid]) / 2 : homework[mid];

  // compute final grade
  streamsize prec = cout.precision();
  cout << "Your final grade is " << setprecision(3) << 0.2*midterm + 0.4*final + 0.4*median
   << setprecision(prec) << endl;

  return 0;

}
