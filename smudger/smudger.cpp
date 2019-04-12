// smudger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

const string directoryMaster = "super/Documents/GitHub"; //"weeks/Documents/college-directory/year-4/semester-2/software-dev-methods"; 


string readFile(string filename) {
	string contents = "";
	ifstream file;
	file.open(filename);
	if (file.is_open()) {
		stringstream buffer;
		buffer << file.rdbuf();
		file.close();
		contents = buffer.str();
	}
	return contents;
}

vector<string> readFileToVector(string filename) {
	vector<string> contents;
	string word;
	ifstream file;
	file.open(filename);
	while (file >> word) {
		contents.push_back(word);
	}
	return contents;
}

int countInstances(string phrase, string filename) {
	// Will check how many instances of the given phrase exist within the filename
	string contents = readFile(filename);
	if (contents != "") {
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

string newName(string filename) {
	string newFilename = filename;
	return newFilename.insert(filename.size() - 4, "_smudged");
}

int wordsInFile(string contents, int fileLength) {
	int words = 0;
	for (int i = 0; i < fileLength; i++) {
		if (contents[i] == ' ')
			words++;
	}
	return words;
}

void replaceWords(string phrase, string filename) {

	//create name for new file
	string newFilename = newName(filename);

	ifstream file;
	file.open(filename);
	if (file.is_open()) {
		stringstream buffer;
		buffer << file.rdbuf();
		file.close();
		string contents = buffer.str();

		int fileLength = contents.length();

		//finds how many words there are in the entire file
		int words = wordsInFile(contents, fileLength);
		//generate a random place to inject the word
		int loc = generateRandLoc(words);


		ofstream outputFile;
		outputFile.open(newFilename);
		if (outputFile.is_open()) {
			vector<string> contents = readFileToVector(filename);
			for (int i = 0; i < int(contents.size()); i++) {
				if (i != loc) {
					if (i == contents.size())
						outputFile << contents[i].c_str();
					else 
						outputFile << contents[i].c_str() << ' ';
				}
				else {
					outputFile << phrase << ' ';
				}
			}
			outputFile.close();
		}
	}
}

void addWords(string phrase, string filename) {

	//create name for new file
	string newFilename = newName(filename);

	ifstream file;
	file.open(filename);
	if (file.is_open()) {
		stringstream buffer;
		buffer << file.rdbuf();
		file.close();
		string contents = buffer.str();

		int fileLength = contents.length();

		//finds how many words there are in the entire file
		int words = wordsInFile(contents, fileLength);
		//generate a random place to inject the word
		int loc = generateRandLoc(words);


		ofstream outputFile;
		outputFile.open(newFilename);
		if (outputFile.is_open()) {
			vector<string> contents = readFileToVector(filename);
			for (int i = 0; i < int(contents.size()); i++) {
				if (i != loc) {
					if (i == contents.size())
						outputFile << contents[i].c_str();
					else
						outputFile << contents[i].c_str() << ' ';
				}
				else {
					outputFile << contents[i].c_str() << ' ' << phrase << ' ';
				}
			}
			outputFile.close();
		}
	}
}

int generateRandLoc(int wordAmount) {
	//adapted from http://www.cplusplus.com/reference/cstdlib/rand/
	/* initialize random seed: */
	srand(time(NULL));
	return rand() % wordAmount + 1;
}

void batOutput(string batName, string source) {
	ofstream batch;
	batch.open(batName);
	if (batch.is_open()) {
		vector<string> contents = readFileToVector(source);
		batch << "cd ..\n";
		for (int i = 0; i < int(contents.size()); i++) {
			batch << "\nsam " << contents[i].c_str();
		}
	}
	batch.close();
}

/*
Arguments entered should be 
[0] program name
[1] -d or a -h
[2] filename
[3] -r  or -a
[4] the word
*/
argument argumentHandler(int argc, char* argv[]) {
	argument obj;
	if (argc == 5) {
		if (argv[1] == "-h") {
			show_usage(argv[1]);
		}
		else if (argv[1] == "-d") {
			if (argv[3] == "-r" || argv[3] == "-a") {
				obj.filename = argv[2];
				obj.command = argv[3];
				obj.phrase = argv[4];
				return obj;
			}
		}
	} 
	return obj;
}

void show_usage(string name) {
	std::cerr << "Usage: " << name << " <option(s)> SOURCES"
              << "Options:\n"
              << "\t-h,--help\t\tShow this help message\n"
              << "\t-d,--destination DESTINATION\tSpecify the destination path"
              << std::endl;
}

int argumentEnough(int argc, char* argv[]) {
	if (argc < 5) {
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
	//addWords("ploopy", "C:/Users/" + directoryMaster + "/smudger/smudger/test.txt");
	//batOutput("testingBat.bat", "C:/Users/" + directoryMaster + "/smudger/smudger/test.txt");
	if (argumentEnough(argc, argv) == 1)
		return 1;
	argumentHandler(argc, argv);
	//cout << countInstances("word", "C:/Users/" + directoryMaster + "/smudger/smudger/test.txt");
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
