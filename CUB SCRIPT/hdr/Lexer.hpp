#pragma once

#include <vector>
#include <string>

namespace cubicalscript {
	enum class TokenType {
		NUMBER,
		BOOL,
		STRING,
		CONST,
		VAR,
		FUNC,
		ENDSTATEMENT,
		IF,
		ELSE,
		WHILE,
		EQUALS,
		BOOLEANOPERATOR,
		BINARYOPERATOR,
		OPENPAREN,
		CLOSEPAREN,
		OPENBRACKET,
		CLOSEBRACKET,
		IDENTIFIER,
		FUNCCALLSTART,
		FUNCCALLEND,
		COMMENT,
		MULTICOMMENTSTART,
		MULTICOMMENTEND,
		ENDOFLINE,
		ENDOFFILE,
		CUBICALFREEZE
	};


	struct TokenIdentifier {
		std::vector<std::string> identifiers; 

		static TokenIdentifier tokenIdentifiers[static_cast<int>(TokenType::CUBICALFREEZE)];
	};
	
	struct Token {
		TokenType type; 
		std::string string; 
	};

}