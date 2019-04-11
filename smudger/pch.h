// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#ifndef PCH_H
#define PCH_H

#include <string>

using namespace std;

// TODO: add headers that you want to pre-compile here
void printMessage();
void replaceWords(string phrase, string filename);
void addWords(string phrase, string filename);
int countInstances(string phrase, string filename);
int countInstanceWrapper(string phrase, string filename);


#endif //PCH_H
