#include <string>

void f2(const std::string& s) {
  
}

void f1(std::string& s) {
  f2(s);
}

int main() {

  return 0;
}