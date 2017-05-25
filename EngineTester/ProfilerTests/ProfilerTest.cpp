#include <gtest\gtest.h>
#include <DebuggingTools\Profiling\Profiler.h>
#include <iostream>
#include <fstream>
#include <string>
using std::ifstream;
using std::string;

namespace
{
	char* categoryArr[] =
	{
		"Category1",
		"Category2",
		"Category3"
	};

	const char* const PROFILE_FILE_NAME = "profiles.csv";
	const unsigned int NUM_CATEGORIES = sizeof(categoryArr) / sizeof(*categoryArr);
	const int NUM_FRAMES = 5;
	Profiler profiler;

}


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

void writeSamples()
{
	int sampleNumber = 0;
	for (int frame = 0; frame < NUM_FRAMES; frame++)
	{
		profiler.newFrame();
		for (unsigned int cat = 0; cat < NUM_CATEGORIES; cat++)
		{
			profiler.addEntry(categoryArr[cat], sampleNumber++);
		}
	}
}

void checkSamples()
{
	ifstream input(PROFILE_FILE_NAME);
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

TEST(Profiler, SampleProfiles)
{
	profiler.initialize(PROFILE_FILE_NAME);
	writeSamples();
	checkSamples();
	profiler.shutdown();
}

//TODO: Write entries to file.
TEST(Profiler, ExcludeIncompleteFrames)
{
	profiler.initialize(PROFILE_FILE_NAME);
	writeSamples();
	profiler.newFrame();
	profiler.addEntry(categoryArr[0], 15);
	profiler.shutdown();
	checkSamples();

	profiler.initialize(PROFILE_FILE_NAME);
	writeSamples();
	profiler.newFrame();
	profiler.addEntry(categoryArr[0], 15);
	profiler.addEntry(categoryArr[1], 16);
	profiler.shutdown();
	checkSamples();
}