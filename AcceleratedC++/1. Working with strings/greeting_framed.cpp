#include <iostream>
#include <string>

int main() {

  std::cout << "Please enter your first name: ";
  std::string name;
  std::cin >> name;

  // build the greeting message
  const std::string greeting = "Hello, " + name + "!";

  // build the first and second lines
  const std::string spaces(greeting.size(), ' ');
  const std::string second = "* " + spaces + " *";
  const std::string first(second.size(), '*');

  // print everything
  std::cout << std::endl;
  std::cout << first << std::endl;
  std::cout << second << std::endl;
  std::cout << "* "+ greeting + " *" << std::endl;
  std::cout << second << std::endl;
  std::cout << first << std::endl;

}
