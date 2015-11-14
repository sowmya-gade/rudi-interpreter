#include "structureErrors.h"

bool structureErrors::Check(Queue<std::string> *program)
{
	bool error = false;

	// Look for program as the first keyword
	if(!checkProgram(program))
	{
		std::cout << "keyword program missing \n";
		return error;
	}

	return true;
}


bool structureErrors::checkProgram(Queue<std::string> program)
{
	
}
