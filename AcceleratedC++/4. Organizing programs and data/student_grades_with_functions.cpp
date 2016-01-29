#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

using std::cin;
using std::istream;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;
using std::vector;
using std::sort;
using std::domain_error;

// compute the median of a vector<double>
// note that calling this function copies the entire argument vector
double median(vector<double> vec) {

  typedef vector<double>::size_type vec_sz;

  vec_sz size = vec.size();
  if (size == 0) {
    throw domain_error("median of an empty vector");
  }

  sort(vec.begin(), vec.end());
  vec_sz mid =
  size / 2;
  return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];

}

// compute a student's overall grade from midterm and final exam grades and homework grade
double grade(double midterm, double final, double homework) {
  return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// compute a student's overall grade from midterm and final exam grades
// and vector of homework grades.
// this function does not copy its argument, because median does so for us.
double grade(double midterm, double final, const vector<double>& hw) {
  if (hw.size() == 0)
    throw domain_error("student has done no homework");
  return grade(midterm, final, median(hw));

}

// read homework grades from an input stream into a vector<double>
istream& read_hw(istream& in, vector<double>& hw) {

  // Verify that the input stream is not in an error state
  if (in) {

    hw.clear();

    double x;
    while (in >> x) {
      hw.push_back(x);
    }

    // clear the stream so that input will work for the next student
    in.clear();

  }

  return in;
}

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

  vector<double> homework;

  read_hw(cin, homework);

  // compute final grade

  double final_grade;

  try {
    final_grade = grade(midterm, final, homework);
    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3) << final_grade
     << setprecision(prec) << endl;
  } catch (domain_error) {
    cout << endl << "Enter your grades please";
    return 1;
  }

  return 0;

}

