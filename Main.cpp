#include <fstream>
#include <iostream>

using namespace std;

ifstream in("Test.in");
ofstream out("Test.out");



void indenting(int clear) {
	out << endl;
	for (int i = clear; i > 0; i--) {
		out << '\t';
	}
}

bool comment;
int indentation;
char input [3];

int main() {
	while (in.get(input [2])) {
		if (input [2] == '{' || input [2] == '(') {
			if (comment == false) {
				indentation++;
			}
		}
		if (input [2] == '}' || input [2] == ')') {
			if (comment == false) {
				indentation--;
			}
		}
		if (int(input [0]) > 47 && int(input [0]) < 58 && input [1] == '.' && (int(input [2]) < 48) || int(input [2] > 57) ) {
			out << 0;
		}
		if (input [1] == ':' && input [2] == '{' || input [1] == '}' && input [2] == ';') {
			out << input [2];
			indenting(indentation);
		}
		else if (input [1] == '{' && input [2] == '"') {
			indenting(indentation);
			out << input [2];
		}
		else if (input [1] == '\\') {
			if (input [2] == 'c') {
				comment = true;
			}
			if (input [2] == '}') {
				indenting(indentation);
				out << input [2];
			}
			else if (input [2] == 'n') {
				if(input [0] =! '\\') {
					
				}
				indenting(indentation);
			}
			else if (input [2] == '\\') {
				if (input [0] != '(' && input [0] != ')') {
					out << " ";
				}
				out << '\\';
			}
			else {
				out << input [2];
			}
		}
		else if (input [2] != '\\') {
			out << input [2];
		}
		if (input [2] == input [1] && input [1] == input [0] && input [0] == ' ') {
			out << '\b' << '\b' << '\b' << '\t';
			input [2] = input [1];
			input [1] = input [0];
		}
		input [0] = input [1];
		input [1] = input [2];
	}
	return 0;
}