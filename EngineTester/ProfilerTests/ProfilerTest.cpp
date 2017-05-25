#include <gtest\gtest.h>
#include <DebuggingTools\Profiling\Profiler.h>
#include <iostream>
#include <fstream>
#include <string>
using std::ifstream;
using std::string;

string getNextToken(ifstream &theFile)
{
	char c;
	string ret;

	while (theFile)
	{
		theFile >> std::noskipws;
		theFile >> c;
		if (c == ',' || c == '\n')
			break;
		ret += c;
	}
	return ret;
}

TEST(Profiler, SampleProfiles)
{
	char* categoryArr[] = 
	{
		"Category1",
		"Category2",
		"Category3"
	};
	const unsigned int NUM_CATEGORIES = sizeof(categoryArr) / sizeof(*categoryArr);

	Profiler profiler;
	const char* profilerFileName = "profiles.csv";
	profiler.initialize(profilerFileName);
	const int NUM_FRAMES = 5;
	int sampleNumber = 0;
	for (int frame = 0; frame < NUM_FRAMES; frame++)
	{
		profiler.newFrame();
		for (unsigned int cat = 0; cat < NUM_CATEGORIES; cat++)
		{
			profiler.addEntry(categoryArr[cat], sampleNumber++);
		}
	}
	profiler.shutdown();

	ifstream input(profilerFileName);
	string token;
	EXPECT_EQ(getNextToken(input), "Category1");
	EXPECT_EQ(getNextToken(input), "Category2");
	EXPECT_EQ(getNextToken(input), "Category3");
	for (int i = 0; i < (NUM_FRAMES * NUM_CATEGORIES); i++)
	{
		string buf = getNextToken(input);
		EXPECT_EQ(atoi(buf.c_str()), i);
	}
}