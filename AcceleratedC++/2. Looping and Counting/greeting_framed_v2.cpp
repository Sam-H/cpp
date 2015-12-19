#include <iostream>
#include <string>

using std::cin;
using std::endl;
using std::cout;
using std::string;

// Greet with unknown number of rows.
int main() {

  cout << "Please enter your first name: ";
  string name;
  cin >> name;

  // build the greeting message
  const string greeting = "Hello, " + name + "!";

  // number of blank rows wanted
  const int pad = 2;

  // total number of rows
  const int rows = 2*pad + 3;

  // size of a row
  const string::size_type cols = greeting.size() + pad * 2 + 2;

  // separate the output from the input
  cout << endl;

  // invariant: we have written r rows so far
  for (int r = 0; r < rows ; r++) {

   string::size_type c = 0;

    // invariant: we have written c characters so far in the current row
    while (c != cols) {
      if (r == pad + 1 && c == pad + 1) {
        cout << greeting;
        c += greeting.size();
      } else {
        if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1) {
          cout << "*";
        } else {
          cout << " ";
        }
        ++c;
      }
    }
    cout << endl;
  }

  return 0;

}