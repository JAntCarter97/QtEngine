#pragma once

class __declspec(dllexport) Profiler
{
public:
	Profiler();
	~Profiler();
	void initialize(const char* fileName);
	void shutdown();
	void newFrame();
	void addEntry(const char* category, float time);
private:
	const char* m_fileName;
	static const unsigned int M_MAX_FRAME_SAMPLES = 500;
	static const unsigned int M_MAX_PROFILE_CATEGORIES = 20;
	int m_frameIndex;
	int m_categoryIndex;
	int m_numUsedCategories;
	struct m_ProfileCategory
	{
		const char* m_name;
		float m_samples[M_MAX_FRAME_SAMPLES];
	} categories[M_MAX_PROFILE_CATEGORIES];
};

