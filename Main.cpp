#include <fstream>

std::ifstream in;
std::ofstream out;

void newline_indent(int tab_ammount) {
	out << '\n';
	for (int i = tab_ammount; i > 0; i--) {
		out << '   ';
	}
}

int main() {

	bool comment = false;
	bool string_input = false;
	bool name_input = false;

	int space = 0;
	int indenting = 0;

	char input [3] = {};

	in.open ("Test.in", std::ifstream::in);
	out.open ("Test.out", std::ofstream::out);

	while (in.get (input [2])) {
		bool hidden_character = false;

		switch (input [2])
		{
			// case comment
			case (';'):
			if ((string_input && name_input) == false) {
				comment == true;
			}
			break;

			// case
			case ('\"'):
			if (name_input || comment) {
				name_input = false;
				break;
			}
			if (input [1] == '{') {
				name_input = true;
				break;
			}
			string_input = !string_input;
			break;

		default:
			break;
		}

		// comment case
		if (input [2] == ';' && string_input == false) {
			comment = true;
		}

		if (input [2] == '{' || input [2] == '(') {
			if (comment == false) {
				indenting ++;
				if (input [2] == '(' && input [1] != '{') {
					space++;
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
				space ++;
				hidden_character = true;
			}
		}

		// make sure all doubles end in .0
		if (
				int (input [0]) > 47 && int (input [0]) < 58
				&& input [1] == '.'
				&& (int (input [2]) < 48 || int (input [2]) > 57)
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
				out << '   ';
				hidden_character = true;
			}

			// end of a block case \}
			if (input [2] == '}' || input [2] == ')' || input [2] == 'n') {
				newline_indent(indenting);
			}

			// new line \n
			if (input [2] == 'n') {

				newline_indent(indenting);
				comment = false;

				// prevents typing n on a new line
				hidden_character = true;
			}

			// line continuation check
			if (input [2] == '\\') {

				// special indenting check
				// we always want (\ and )\

				if (input [0] != '(' && input [0] != ')') {
					space++;
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
			out << '   ';
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
				out << ' ';
			}
			space = 0;
		}

		// type out allowed characters
		if (hidden_character == false) {
			out << input [2];
			if (input [2] == '\\') {
				newline_indent (indenting);
				input [2] = ' ';
			}
		}

		// permits spacing between blocks
		if ((input [1] == ':' && input [2] == '{') || (input [1] == '}' && input [2] == ';')) {
			out << '\n';
			newline_indent (indenting);
		}

		// don't keep spaces in memory as the logic can fail
		if (input [2] != ' ' || false == (string_input == false || comment == false)) {
			input [0] = input [1];
			input [1] = input [2];
		}
	}

	out << ";\n}";

	return 0;
}