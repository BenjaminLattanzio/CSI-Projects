#pragma once

using namespace std;

class MemoryManagement
{
	int avalibleSpace[5], reqspace[5], allocspace[5], done[5], freespace[5], partitions, jobs, jobname[5];
	//array alocation, partitions and jobs are vairables

public:
	MemoryManagement();
	void firstFit();
	void bestFit();
	void nextFit();
	void worstFit();
};