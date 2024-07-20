grammar JSON;

json:
	STRING
	| NUMBER
	| object
	| array
	| 'true'
	| 'false'
	| 'null';

object: '{' (member (',' member)*)? '}';

member: STRING ':' json;

array: '[' (json (',' json)*)? ']';

STRING: '"' ~["\\]* '"';

NUMBER: '-'? INT ('.' [0-9]+)? EXP?;

fragment INT: '0' | [1-9] [0-9]*;

fragment EXP: [eE] [+\-]? INT;

WS: [ \t\r\n]+ -> skip;