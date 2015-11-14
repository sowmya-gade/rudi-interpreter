#include <iostream>
#include <fstream>
#include <algorithm>
#include "structureErrors.h"
#include "libs/queue.h"

// Read each line in the file and add it to a queue
bool readFileAndQueue(char* fileName, Queue<std::string>* queue);

// Delete spaces from the beginning and the end
void trim(std::string &str);


/* -------------------------------------------------------- 
						MAIN PROGRAM
 -------------------------------------------------------- */
int main(int argc, char* argv[])
{	
	// Parse the command line input
	if(argc > 3 || argc < 2)
		return -1;
	char* fileName = argv[1];

	// Read input file
	Queue<std::string>* queue;
	bool error = readFileAndQueue(fileName, queue);
	if(error)
		return -1;

	// Check for structure errors
	structureErrors strucErrors;
	//error = strucErrors.Check(queue);
	if(error)
		return -1;

	// Evaluate the program line by line
	//lineEvaluator lineByline;
	//error = lineByline.Check();
	if(error)
		return -1;

	queue->clearQueue();

	// If there are no errors
	return 0;

}


// Read each line in the file and add it to a queue
bool readFileAndQueue(char* fileName, Queue<std::string>* queue)
{
	std::ifstream myFile(fileName);
	bool error = false;

	// Check if file is open
	if(myFile.is_open())
	{	
		// While the file pointer has not reached end of file
		while(!myFile.eof())
		{
			std::string line;

			// Read a line
			std::getline(myFile, line);

			// Remove spaces before and after the text
			trim(line);

			// Remove empty lines
			if(line.size()==0)
				continue ;		

			// Add each line to a queue
			queue->Enqueue(line);

		}
	}
	else
	{
		// Throw an error for opening the file
		std::cout << "File opening error ! \n";
		return error;
	}

	return(!error);
}


// Delete spaces from the beginning and the end
void trim(std::string &str) 
{
	// Trim trailing spaces
	str.erase(std::find_if(str.rbegin(), str.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), str.end());

	// Trim leading spaces
	str.erase(str.begin(), std::find_if(str.begin(), str.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));

}



