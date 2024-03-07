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
int clear;
char word [3];


int main() {
	while (in.get(word [2])) {
		if (word [2] == '{' || word [2] == '(') {
			if (comment == false) {
				clear++;
			}
		}
		if (word [2] == '}' || word [2] == ')') {
			if (comment == false) {
				clear--;
			}
		}
		if (int(word [0]) > 47 && int(word [0]) < 58 && word [1] == '.' && word [2] == ')') {
			out << 0;
		}
		if (word [1] == ':' && word [2] == '{' || word [1] == '}' && word [2] == ';') {
			out << word [2];
			indenting(clear);
		}
		else if (word [1] == '{' && word [2] == '"') {
			indenting(clear);
			out << word [2];
		}
		else if (word [1] == '\\') {
			if (word [2] == 'c') {
				comment = true;
			}
			if (word [2] == '}') {
				indenting(clear);
				out << word [2];
			}
			else if (word [2] == 'n') {
				comment = false;
				indenting(clear);
			}
			else if (word [2] == '\\') {
				if (word [0] != '(' && word [0] != ')') {
					out << " ";
				}
				out << '\\';
			}
			else {
				out << word [2];
			}
		}
		else if (word [2] != '\\') {
			out << word [2];
		}
		if (word [2] == word [1] && word [1] == word [0] && word [0] == ' ') {
			out << '\b' << '\b' << '\b' << '\t';
			word [2] = word [1];
			word [1] = word [0];
		}
		word [0] = word [1];
		word [1] = word [2];
	}
	return 0;
}