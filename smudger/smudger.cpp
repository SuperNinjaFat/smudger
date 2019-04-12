// smudger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

const string directoryMaster = "super/Documents/GitHub"; //"weeks/Documents/college-directory/year-4/semester-2/software-dev-methods";

int countInstanceWrapper(string phrase, string filename) {
	return countInstances(phrase, filename);
}

int countInstances(string phrase, string filename) {
	// Will check how many instances of the given phrase exist within the filename
	ifstream file;
	file.open(filename);
	if (file.is_open()) {
		stringstream buffer;
		buffer << file.rdbuf();
		file.close();
		string contents = buffer.str();
		
		int fileLength = contents.length();
		int phraseLength = phrase.length();
		int instances = 0;

		// Goes through entire contents
		for(int i = 0; i < fileLength - phraseLength; i++){
			int j;

			// Now checks to see if the phrase is in contents
			for (j = 0; j < phraseLength; j++) {
				if (contents[i + j] != phrase[j])
					break;
			}

			// Checks to see if the entire phrase existed
			if (j == phraseLength) {
				instances++;
				j = 0;
			}
		}
		
		return instances;
	}
	else {
		return -1;
	}
}

void replaceWords(string phrase, string filename) {

}

void addWords(string phrase, string filename) {

}

string* batOutput(string batName, string source) {
	return NULL;
}

void show_usage(string name) {
	std::cerr << "Usage: " << name << " <option(s)> SOURCES"
              << "Options:\n"
              << "\t-h,--help\t\tShow this help message\n"
              << "\t-d,--destination DESTINATION\tSpecify the destination path"
              << std::endl;
}
int argumentEnough(int argc, char* argv[]) {
	if (argc < 3) {
		show_usage(argv[0]);
		return 1;
	}
	else {
		return 0;
	}
	return 2;
}

int main(int argc, char* argv[])
{
	if (argumentEnough(argc, argv) == 1)
		return 1;
	
	cout << countInstances("word", "C:/Users/" + directoryMaster + "/smudger/smudger/test.txt");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
