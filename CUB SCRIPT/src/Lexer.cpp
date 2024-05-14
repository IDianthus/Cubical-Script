#include "../hdr/Lexer.hpp"

namespace cubicalscript {
  TokenIdentifier TokenIdentifier::tokenIdentifiers[static_cast<int>(TokenType::CUBICALFREEZE)] = {
    /*NUMBER*/             { {} },
    /*BOOL*/               { {} },
    /*STRING*/             { {} },
    /*CONST*/              { { "const" } },
    /*VAR*/                { { ":global", ":local" } },
    /*FUNC*/               { { "#" } },
    /*ENDSTATEMENT*/       { { ";" } },
    /*IF*/                 { { "if" } },
    /*ELSE*/               { { "else" } },
    /*WHILE*/              { { "goto", "gotoif" } },
    /*EQUALS*/             { { "=" } },
    /*BOOLEANOPERATOR*/    { { "<", ">", "||", "&&", "==", "!=", "<=", ">=" } },
    /*BINARYOPERATOR*/     { { "+", "-", "*", "/", "%", "+=", "-=", "*=", "/=" } },
    /*OPENPAREN*/          { { "(" } },
    /*CLOSEPAREN*/         { { ")" } },
    /*OPENBRACKET*/        { { "[" } },
    /*CLOSEBRACKET*/       { { "]" } },
    /*FUNCCALLSTART*/      { { "{" } },
    /*FUNCCALLEND*/        { { "}" } },
    /*IDENTIFIER*/         { {} },
    /*COMMENT*/            { { "//" } },
    /*MULTICOMMENTSTART*/  { { "/*" } },
    /*MULTICOMMENTEND*/    { { "*/" } },
    /*ENDOFLINE*/          { { "\n", "\r", ";" } },
  };

}

