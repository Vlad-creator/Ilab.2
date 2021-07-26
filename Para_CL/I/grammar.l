%option C++

%{
	#include "grammar.tab.hh"
%}

WS      [ /t/n/v]+
DIG     [0-9]
DIG1    [1-9]

%%

{WS}
"+"  		 return yy::parser::token_type::PLUS;
"-"  		 return yy::parser::token_type::MINUS;
"="  		 return yy::parser::token_type::EQUAL;
";"  		 return yy::parser::token_type::SCOLON;
{DIG1}{DIG}* return yy::parser::token_type::NUMBER;
.            return yy::parser::token_type::ERR;

%%
