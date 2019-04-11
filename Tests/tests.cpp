#include "stdafx.h"
#include "CppUnitTest.h"
#include "../smudger/pch.h"
#include "../smudger/smudger.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{		
	TEST_CLASS(ArgumentHandling)
	{
	public:
		
		TEST_METHOD(TestPrintMessage)
		{
			printMessage();
		}
	};

	TEST_CLASS(WordReplacement)
	{
	public:
		TEST_METHOD(CountInstances) {
			/*
				countInstances(string, string) :
				countInstances should simply check the amount of times that
				the passed phrase / word appears within the given filename
			*/
			int expected = 3;
			int actual = countInstances("word", "C:/Users/weeks/Documents/college-directory/year-4/semester-2/software-dev-methods/smudger/smudger/test.txt");
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(ReadFile) {
			/*
				readFile(string):
				readFile should open the given file and return the entire contents
			*/

			string actual = "Welcome to smudger. This is a program that will ask a user for the path of a textfile and also ask for a word or phrase. This word or phrase will then be used to randomly replace words from within the given textfile. Give it a shot and smudge your files!";
			string expected = readFile("C:/Users/weeks/Documents/college-directory/year-4/semester-2/software-dev-methods/smudger/smudger/test.txt");
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(ReplaceWordsCount) {
			/*
				replaceWords(string, string):
				replaceWords should use the given phrase and replace
				words within the given string randomly

				Replace words should output to a file with the same name but suffixed
				with _smudged	i.e. test.txt --> test_smudged.txt
			*/

			int amountBefore = countInstances("TDD", "C:/Users/weeks/Documents/college-directory/year-4/semester-2/software-dev-methods/smudger/smudger/test.txt");
			replaceWords("TDD", "C:/Users/weeks/Documents/college-directory/year-4/semester-2/software-dev-methods/smudger/smudger/test.txt");
			int amountAfter = countInstances("TDD", "C:/Users/weeks/Documents/college-directory/year-4/semester-2/software-dev-methods/smudger/smudger/test_smudged.txt");

			Assert::IsTrue(amountAfter > amountBefore);
		}
	};

	TEST_CLASS(WordAddition) {
		TEST_METHOD(AddWords) {
			/*
				addWords(string, string):
				addWords should use the given phrase and insert it
				into the file at random points

				Add words should output to a file with the same name but suffixed
				with _smudged	i.e. test.txt --> test_smudged.txt
			*/

			int amountBefore = countInstances("TDD", "C:/Users/weeks/Documents/college-directory/year-4/semester-2/software-dev-methods/smudger/smudger/test.txt");
			addWords("TDD", "C:/Users/weeks/Documents/college-directory/year-4/semester-2/software-dev-methods/smudger/smudger/test.txt");
			int amountAfter = countInstances("TDD", "C:/Users/weeks/Documents/college-directory/year-4/semester-2/software-dev-methods/smudger/smudger/test_smudged.txt");

			Assert::IsTrue(amountAfter > amountBefore);
		}
	};
}