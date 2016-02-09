#include <iomanip>
#include <algorithm>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cstdio>
#include "Student_info.h"
#include "grade.h"

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;
using std::vector;
using std::sort;
using std::max;
using std::domain_error;

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

