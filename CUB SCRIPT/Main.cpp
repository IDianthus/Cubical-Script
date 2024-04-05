#include "Lexer.hpp"
#include <iostream>

int main() {
	char input[6] = {};
	while(std::cin >> input[4]) {
		if(input == "exit") {
			return 0;
		}
		input[0] = input[1];
		input[1] = input[2];
		input[2] = input[3];
		input[3] = input[4];
		std::cout << input << " = " << cubicalscript::TokenType::input;
	}
	return 0;
}