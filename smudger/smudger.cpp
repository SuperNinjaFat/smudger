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

void printMessage() {
	std::cout << "Hello World!\n";
}

int main()
{
	cout << countInstances("word", "../smudger/test.txt");
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
