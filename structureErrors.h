#include <iostream>
#include <string>
#include "libs/queue.h"

class structureErrors
{
	private:

		// Look for program as the first keyword
		bool checkProgram(Queue<std::string> *program);

		// Look for the begin and end keywords
		bool checkBeginAndEnd(Queue<std::string> *program);

		// Look for declarations
		std::vector<std::string> checkDeclarations(Queue<std::string> *program);

		// Look for open and close brackets - '[' and ']'
		bool checkBrackets(Queue<std::string> *program);

		// Check for then after if statements
		bool checkIf(Queue<std::string> *program);

		// Check while statements
		bool checkWhile(Queue<std::string> *program);

		// Look for any undeclared variables in the program
		bool checkUndeclaredVar(Queue<std::string> *program);

		// Look for comments
		bool removeComments(Queue<std::string> *program);

	public:

		// Check for all types of structure errors
		bool Check(Queue<std::string> *program);
	
};

