#include "Student_info.h"
#include <vector>
#include <string>
#include <iostream>
#include <limits>

using std::vector;
using std::string;
using std::istream;
using std::cin;
using std::cout;
using std::streamsize;
using std::endl;

bool compare(const Student_info& x, const Student_info& y) {
  return x.name < y.name;
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

// read name, midterm, final and homeword grades for one student.
istream& read(istream& is, Student_info& s) {

  cout << "Enter name, then midterm and final" << endl;

  is >> s.name >> s.midterm >> s.final;

  cout << "Enter homework grades" << endl;

  read_hw(is, s.homework);

  is.ignore(std::numeric_limits<streamsize>::max(), '\n');

  return is;
}