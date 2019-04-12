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
			show_usage("smudger.exe");
		}
		TEST_METHOD(TestArgumentNotEnough)
		{
			int argc = 1;
			char* argv[1];
			argv[0] = "smudger.exe";
			Assert::AreEqual(1, argumentEnough(argc, argv));
		}
		TEST_METHOD(TestArgumentEnough)
		{
			int argc = 5;
			char* argv[5];
			argv[0] = "smudger.exe";
			argv[1] = "-d";
			argv[2] = "test.txt";
			argv[3] = "-r";
			argv[4] = "hello";
			Assert::AreEqual(0, argumentEnough(argc, argv));
		}
		TEST_METHOD(TestArgumentHandler)
		{
			int argc = 5;
			char* argv[5];
			argv[0] = "smudger.exe";
			argv[1] = "-d";
			argv[2] = "test.txt";
			argv[3] = "-r";
			argv[4] = "hello";
			argument actual = argumentHandler(argc, argv);
			argument expected;
			expected.command = "-r";
			expected.filename = "test.txt";
			expected.phrase = "hello";
			Assert::AreEqual((expected.command + expected.filename + expected.phrase), (actual.command + actual.filename + actual.phrase));
		}
	};

	TEST_CLASS(VOX)
	{
	public:
		TEST_METHOD(SamOutput) {
			/*
				batOutput(int, char*[]) :
				outputs a bat file that can read it out loud with this program
				https://simulationcorner.net/index.php?page=sam
				Use demo.bat as an example, same.exe can only read 12 words long
			*/
			string outputName = "demo.bat";
			batOutput(outputName, "C:/Users/" + directoryMaster + "/smudger/smudger/test.txt");
			ifstream expectedFile;
			vector<string> expected;
			string expectedFileName = "C:/Users/" + directoryMaster + "/smudger/smudger/testingBat.bat";
			expectedFile.open(expectedFileName);
			if (expectedFile.is_open()) {
				expected = readFileToVector(expectedFileName);
				expectedFile.close();
			}
			ifstream actualFile;
			vector<string> actual;
			string actualFileName = "C:/Users/" + directoryMaster + "/smudger/smudger/" + outputName;
			actualFile.open(expectedFileName);
			if (actualFile.is_open()) {
				vector<string> contents = readFileToVector(expectedFileName);
				actualFile.close();
			}
			for (int i = 0; i < int(expected.size()); i++) {
					Assert::AreEqual(expected[i], actual[i]);
			}
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
			int actual = countInstances("word", "C:/Users/" + directoryMaster + "/smudger/smudger/test.txt");
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

			int amountBefore = countInstances("TDD", "C:/Users/" + directoryMaster + "/smudger/smudger/test.txt");
			replaceWords("TDD", "C:/Users/" + directoryMaster + "/smudger/smudger/test.txt");
			int amountAfter = countInstances("TDD", "C:/Users/" + directoryMaster + "/smudger/smudger/test_smudged.txt");

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

			int amountBefore = countInstances("TDD", "C:/Users/" + directoryMaster + "/smudger/smudger/test.txt");
			addWords("TDD", "C:/Users/" + directoryMaster + "/smudger/smudger/test.txt");
			int amountAfter = countInstances("TDD", "C:/Users/" + directoryMaster + "/smudger/smudger/test_smudged.txt");

			Assert::IsTrue(amountAfter > amountBefore);
		}
	};
}