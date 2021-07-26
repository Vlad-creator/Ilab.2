#include <iostream>

#include "NumDriver.hpp"

// here we can return non-zero if lexing is not done inspite of EOF detected
int yyFlexLexer::yywrap() {
  return 1;
}

int main()
{
  std::cout << "start";
  FlexLexer* lexer = new yyFlexLexer;
  yy::NumDriver driver(lexer);
  driver.parse();
  driver.printout();
}