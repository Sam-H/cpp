#include <iostream>
#include <string>

int main () {

  // ask for the person's name
  std::cout << "Please enter your first and last names: ";

  // read the name
  std::string firstname;
  std::string lastname;
  // Example of chained input
  std::cin >> firstname >> lastname;
  std::cout << "Hello, " << firstname << " " << lastname << "!" << std::endl;

}
