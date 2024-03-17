#include <fstream>
#include <iostream>

using namespace std;

ifstream in("Test.in");
ofstream out("Test.out");


void newline_indent(int tab_ammount) {
	out << '\n';
	for (int i = tab_ammount; i > 0; i--) {
		out << '\t';
	}
}

bool comment;
bool string_input;

int space;
int indenting = 1;

char input [3];

int main() {

	out << '{';
	newline_indent(indenting);


	while (in.get(input [2])) {
		bool hidden_character = false;

		// comment case
		if (input [1] != '}' && input [2] == ';' && string_input == false) {
			comment = true;
		}

		if (input [2] == '{' || input [2] == '(') {
			if (comment == false) {
				indenting++;
				if (input [2] == '(' && input [1] != '{') {
					space ++;
				}
			}
		}
		if (input [2] == '}' || input [2] == ')') {
			if (comment == false) {
				indenting--;
			}
		}

		// consistent indenting
		if (input [2] == ' ') {
			if (comment == false && string_input == false) {
				space++;
				hidden_character = true;
			}
		}

		// make sure all doubles end in .0
		if (
				int(input [0]) > 47 && int(input [0]) < 58
				&& input [1] == '.'
				&& (int(input [2]) < 48 || int(input [2]) > 57)
			) {
			out << 0;
		}

		if (input [2] == '"' && comment == false) {

			string_input = (string_input == false);

			if (input [1] == '{') {
				newline_indent(indenting);
			}
		}

		// spacial cases
		if (input [1] == '\\') {

			if (input [2] == 't') {
				out << '\t';
				hidden_character = true;
			}

			// end of a block case \}
			if (input [2] == '}' || input [2] == ')') {
				newline_indent(indenting);
			}

			// new line \n
			if (input [2] == 'n') {

				// on \\n it must keep comment state
				if (input [0] != '\\') {
					// otherwise it exits comments
					comment = false;
				}

				newline_indent(indenting);

				// space cannot increase unless it's a comment, if it detects a space it adds a new tab
				if (space != 0) {
					out << '\t';
					space = 0;
				}

				// prevents typing n on a new line
				hidden_character = true;
			}

			// line continuation check
			if (input [2] == '\\') {

				// special indenting check
				// we always want (\ and )\

				if (input [0] != '(' && input [0] != ')') {
					space ++;
				}
				hidden_character = true;
			}
		}

		// enable's line breaks
		if (input [2] == '\\') {
			hidden_character = hidden_character == false;
		}

		// read inputs that follow the pattern something=something
		// outputs something = something

		// when remaking the logic, I need to fix cases like !+-*/<>
		// ##
		// ! not
		// + sum
		// - subtract
		// * multiply
		// / devide
		// < smaller than
		// > bigger than
		// )
		// ##

		
		if (space == 3) {
			out << '\t';
			space = 0;
		}

		if (
				input [1] != '!' &&
				input [1] != '+' &&
				input [1] != '-' &&
				input [1] != '*' &&
				input [1] != '/' &&
				input [1] != '<' &&
				input [1] != '>' &&
				input [1] != '=' &&
				input [1] != ' ' &&
					input [2] == '=' &&
					space == 0
			) {
			out << " ";
		}

		// adding indents
		if (input [2] != ' ') {
			if (space != 0 && input [0] != '\\' && input [1] != 'n') {
				out << " ";
			}
			space = 0;
		}

		// type out allowed characters
		if (hidden_character == false) {
			out << input [2];
		}

		// permits spacing between blocks
		if (
			(input [1] == ':' && input [2] == '{') 
			|| (input [1] == '}' && input [2] == ';')
		) {
			out << '\n';
			newline_indent(indenting);
		}

		// don't keep spaces in memory as the logic can fail
		if (input [2] != ' ' || (string_input == false && comment == false)) {
			input [0] = input [1];
			input [1] = input [2];
		}
	}

	out << '\n';
	out << "}";

	return 0;
}