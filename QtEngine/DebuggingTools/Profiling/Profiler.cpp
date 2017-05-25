#include "Profiler.h"
#include <cassert>
#include <fstream>
#include <ios>
using std::ofstream;
using std::ios;
typedef unsigned int uint;

Profiler::Profiler()
{
	// empty
}

Profiler::~Profiler()
{
	// empty
}

void Profiler::initialize(const char* fileName)
{
	this->m_fileName = fileName;
	m_frameIndex = -1;
	m_categoryIndex = 0;
	m_numUsedCategories = 0;
}

void Profiler::shutdown()
{
	ofstream outStream(m_fileName, ios::trunc);
	for (unsigned int i = 0; i < m_numUsedCategories; i++)
	{
		outStream << categories[i].m_name;
		((i + 1) < m_numUsedCategories) ? outStream << ',' : outStream << '\n';
	}

	// Account for last frame if they added entries
	uint numActualFrames = m_frameIndex;
	if (m_categoryIndex == m_numUsedCategories)
		numActualFrames++;

	for (unsigned int frame = 0; frame < numActualFrames; frame++)
	{
		for (unsigned int cat = 0; cat < m_numUsedCategories; cat++)
		{
			outStream << categories[cat].m_samples[frame];
			((cat + 1) < m_numUsedCategories) ? outStream << ',' : outStream << '\n';
		}
	}
}

void Profiler::newFrame()
{
	if (m_frameIndex > 0)
		assert(m_categoryIndex == m_numUsedCategories);
	m_frameIndex++;
	m_categoryIndex = 0;
}

void Profiler::addEntry(const char* category, float time)
{
	// Temp: Because Category is static stop from out of bounds
	// TODO: Change to logging for more debug help
	assert(m_frameIndex < M_MAX_FRAME_SAMPLES);
	assert(m_categoryIndex < M_MAX_PROFILE_CATEGORIES);

	m_ProfileCategory& pc = categories[m_categoryIndex];
	pc.m_name = category;
	if (m_frameIndex == 0)
	{
		pc.m_name = category;
		m_numUsedCategories++;
	}
	else
	{
		assert(pc.m_name == category && category != NULL);
		assert(m_categoryIndex < m_numUsedCategories);
	}
	m_categoryIndex++;
	pc.m_samples[m_frameIndex] = time;
}