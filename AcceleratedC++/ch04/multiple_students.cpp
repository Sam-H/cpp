#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>
#include <cstdio>

using std::cin;
using std::istream;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;
using std::vector;
using std::sort;
using std::max;
using std::domain_error;

struct Student_info {
  string name;
  double midterm, final;
  vector<double> homework;
};

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

// read name, midterm, final and homeword grades for one student.
istream& read(istream& is, Student_info& s) {

  cout << "Enter name, then midterm and final" << endl;

  is >> s.name >> s.midterm >> s.final;

  cout << "Enter homework grades" << endl;

  read_hw(is, s.homework);

  is.ignore(std::numeric_limits<streamsize>::max(), '\n');

  return is;
}

double grade(const Student_info& s) {

  return grade(s.midterm, s.final, s.homework);

}

bool compare(const Student_info& x, const Student_info& y) {
  return x.name < y.name;
}

int main() {

  vector<Student_info> students;
  Student_info record;
  string::size_type maxlen = 0;

  while (read(cin, record)) {
    maxlen = max(record.name.size(),maxlen);
    students.push_back(record);
  }

  // sort students by name;
  sort(students.begin(), students.end(), compare);

  for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
    cout << students[i].name
         << string(maxlen - students[i].name.size() + 1, ' ');

    try {
      double final_grade = grade(students[i]);
      streamsize prec = cout.precision();
      cout << setprecision(3) << final_grade << setprecision(prec);
    } catch (domain_error e) {
      cout << e.what();
    }

    cout << endl;
  }

  return 0;

}

