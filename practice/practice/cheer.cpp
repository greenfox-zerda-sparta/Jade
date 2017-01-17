#include <iostream>
#include <string>

void cheer(std::string, std::string);
	
int main() {
	cheer("Hello", " Jade!" );
	return 0;
}

void cheer(std::string param1, std::string param2) {
	std::cout <<param1 << param2 << std::endl;
}