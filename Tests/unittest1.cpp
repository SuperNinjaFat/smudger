#include "stdafx.h"
#include "CppUnitTest.h"
#include "../smudger/pch.h"
#include "../smudger/smudger.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			printMessage();
		}
	};
}