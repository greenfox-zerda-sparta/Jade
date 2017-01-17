#include <iostream>
#include <string>

void greet(std::string input, std::string input2) {
  std::cout << input << " " << input2 << std::endl;
}

int main() {
  std::string input = "Greetings!";
  std::string input2 = "Juli";
  greet(input, input2);
  return 0;
}