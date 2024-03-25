#pragma once

#include <vector>
#include <string>

namespace cubicalscript {
	enum class TokenType {
		NUMBER,
		STRING,
		BOOL,
		CONST,
		VAR,
		FUNC,
		ENDSTATEMENT,
		CUBICALSTOP,
	};


	struct TokenIdentifier {
		std::vector<std::string> identifiers; 

		static TokenIdentifier tokenIdentifiers[static_cast<int>(TokenType::CUBICALSTOP)];
	};
}