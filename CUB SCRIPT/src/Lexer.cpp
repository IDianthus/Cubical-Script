#include "../hdr/Lexer.hpp"

namespace cubicalscript {
	TokenIdentifier TokenIdentifier::tokenIdentifiers[static_cast<int>(TokenType::CUBICALSTOP)] = {
		{ {} },
		{ {} },
		{ {} },
		{ { "const" } },
		{ { "var" } },
		{ { "#" } },
		{ { ";" } },
	};

}

