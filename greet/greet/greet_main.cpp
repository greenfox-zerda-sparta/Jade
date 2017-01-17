#include <iostream>
#include <string>

void greet(std::string input) {
  std::cout << input << std::endl;
}

int main() {
  std::string input = "Juli";
  greet(input);
  return 0;
}