#include <iostream>
#include <string>

int main () {

  // ask for the person's name
  std::cout << "Please enter your first name: ";

  // read the name
  std::string name;
  std::cin >> name ;

  // greeting
  std::cout << "Hello, " << name << "!" << std::endl;

}
