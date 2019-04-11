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
			int actual = countInstanceWrapper("word", "../smudger/test.txt");
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(ReplaceWordsCount) {
			/*
				replaceWords(string, string):
				replaceWords should use the given phrase and replace
				words within the given string randomly

				Replace words should name a file the same name but suffixed
				with _smudged	i.e. test.txt --> test_smudged.txt
			*/

			int amountBefore = countInstances("TDD", "../smudger/test.txt");
			replaceWords("TDD", "../smudger/test.txt");
			int amountAfter = countInstances("TDD", "../smudger/test_smudged.txt");

			Assert::IsTrue(amountAfter > amountBefore);
		}
	};

	TEST_CLASS(WordAddition) {
		TEST_METHOD(AddWords) {
			int amountBefore = countInstances("TDD", "../smudger/test.txt");
			addWords("TDD", "../smudger/test.txt");
			int amountAfter = countInstances("TDD", "../smudger/test_smudged.txt");

			Assert::IsTrue(amountAfter > amountBefore);
		}
	};
}