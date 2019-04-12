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
			int argc = 2;
			char* argv[2];
			argv[0] = "smudger.exe";
			argv[1] = "NotEnoughArguments";
			argumentEnough(argc, argv);
		}
		TEST_METHOD(TestArgumentEnough)
		{
			int argc = 2;
			char* argv[2];
			argv[0] = "smudger.exe";
			argv[1] = "NotEnoughArguments";
			argumentEnough(argc, argv);
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
			int argc = 3;
			char* argv[3];
			string* actual = batOutput("demo1", "C:/Users/" + directoryMaster + "/smudger/smudger/test.txt");
			string expected[6];
			ifstream file("C:/Users/" + directoryMaster + "/smudger/smudger/demo.bat");
			string myArray[6];
			if (file.is_open()) {
				for (int i = 0; i < sizeof(actual); i++)
				{
					file >> expected[i];
					Assert::AreEqual(expected[i], actual[i]);
				}
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
			int actual = countInstanceWrapper("word", "C:/Users/" + directoryMaster + "/smudger/smudger/test.txt");
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