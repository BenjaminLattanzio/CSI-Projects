#include<iostream>
#include"MemoryManagement.h"
using namespace std;

MemoryManagement::MemoryManagement()
{
	bool tooManypartitions = true, tooManyJobs = true;
	cout << "Enter the number of partitions" << endl;
	while (tooManypartitions) {
		cin >> partitions;// partitions variable holds th number of partitions
		if (partitions > 5 || partitions < 1)
			cout << "Partition number is not accepted. Please enter a new value" << endl;

		else
			tooManypartitions = false; //setting bool to false since there is not too many partitions
	}
	cout << "Enter the fixed space for each partition\n";
	for (int i = 0; i < partitions; i++)
	{
		cout << "Partition " << i << "\t";
		cin >> avalibleSpace[i];// array to store avaliable space
		freespace[i] = avalibleSpace[i];
	}
	cout << "Enter the number of Jobs" << endl;;
	while (tooManyJobs) {
		cin >> jobs;//holds number of jobs
		if (jobs > 5 || jobs < 1)
			cout << "Job number invalid. Please enter a new value" << endl;

		else
			tooManyJobs = false;
	}
	cout << "Enter the required size for each process\n";
	for (int i = 0; i < jobs; i++)
	{
		cout << "Job " << i << "\t";
		cin >> reqspace[i];//array holding required space
	}
}

void MemoryManagement::firstFit()
{
	for (int k = 0; k < 5; k++) {
		allocspace[k] = 0;
		freespace[k] = avalibleSpace[k];
		done[k] = 0;
		jobname[k] = 5;
	}
	int check;
	for (int i = 0; i < jobs; i++) {
		check = 0;// initially setting check to zero
		for (int j = 0; j < partitions; j++) {
			if (reqspace[i] <= avalibleSpace[j] && done[j] != 1 && check == 0) {
				allocspace[j] = reqspace[i];
				jobname[j] = i;
				freespace[j] = avalibleSpace[j] - allocspace[j];
				done[j] = 1;
				check = 999;
			}
		}
	}
	cout << "First Fit\nAvailable space " << "   Allocated space  " << "  Partition Waste "  << "  Job State\n";
	for (int i = 0; i < partitions; i++) { 
		if (jobname[i] != 5)
			cout << "Partition " << i << ':' << avalibleSpace[i] << "\t\t" << allocspace[i] << "(Job: " << jobname[i] << ')' << "\t\t" << freespace[i] << "\t" << " Running" << endl;
		else
			cout << "Partition " << i << ':' << avalibleSpace[i] << "\t\t" << allocspace[i] << "(No Job)" << "\t\t" << freespace[i] << "\t" << " Waiting" << endl;
	}
	int waste = 0;
	for (int a = 0; a < partitions; a++)
		waste += freespace[a];
	cout << "WASTE=" << waste << endl;


}

void MemoryManagement::bestFit()
{
	for (int k = 0; k < 5; k++) {
		allocspace[k] = 0;
		freespace[k] = avalibleSpace[k];
		done[k] = 0;
		jobname[k] = 5;
	}
	int temp, check;
	for (int i = 0; i < jobs; i++)
	{
		check = 0;
		temp = reqspace[i];
		for (int k = temp; k < 999; k++)
		{
			for (int j = 0; j < partitions; j++)
			{
				if (temp == avalibleSpace[j] && (done[j] != 1) && check == 0)
				{
					allocspace[j] = reqspace[i];
					jobname[j] = i;
					freespace[j] = avalibleSpace[j] - allocspace[j];
					done[j] = 1;
					check = -999;
				}
			}
			temp++;
		}
	}
	cout << "Best Fit\nAvailable space  " << "   Allocated space  " << "  Partition Waste " << "  Job State\n";
	for (int i = 0; i < partitions; i++) {
		if (jobname[i] != 5)
			cout << "Partition " << i << ':' << avalibleSpace[i] << "\t\t" << allocspace[i] << "(Job: " << jobname[i] << ')' << "\t\t" << freespace[i] << "\t" << " Running" << endl;
		else
			cout << "Partition " << i << ':' << avalibleSpace[i] << "\t\t" << allocspace[i] << "(No Job)" << "\t\t" << freespace[i] << "\t" << " Waiting" << endl;
	}
	int waste = 0;
	for (int a = 0; a < partitions; a++)
		waste += freespace[a];
	cout << "WASTE=" << waste << endl;

}

void MemoryManagement::worstFit()
{
	for (int k = 0; k < 5; k++) {
		allocspace[k] = 0;
		freespace[k] = avalibleSpace[k];
		done[k] = 0;
		jobname[k] = 5;
	}
	int temp, check;
	for (int i = 0; i < partitions; i++)
	{
		for (int j = 0; j < partitions - 1; j++)
		{
			if (avalibleSpace[j] < avalibleSpace[j + 1])
			{
				temp = avalibleSpace[j];
				avalibleSpace[j] = avalibleSpace[j + 1];
				avalibleSpace[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < jobs; i++)
	{
		check = 0;
		for (int j = 0; j < partitions; j++)
		{
			if ((reqspace[i] <= avalibleSpace[j]) && (done[j] != 1) && check == 0)
			{
				allocspace[j] = reqspace[i];
				jobname[j] = i;
				freespace[j] = avalibleSpace[j] - allocspace[j];
				done[j] = 1;
				check = 999;
			}

		}
	}

	cout << "Worst Fit\nAvailable space  " << "   Allocated space  " << "  Partition Waste " << "  Job State\n";
	for (int i = 0; i < partitions; i++) {
		if (jobname[i] != 5)
			cout << "Partition " << ':' << avalibleSpace[i] << "\t\t" << allocspace[i] << "(Job: " << jobname[i] << ')' << "\t\t" << freespace[i] << "\t" << " Running" << endl;
		else
			cout << "Partition " << ':' << avalibleSpace[i] << "\t\t" << allocspace[i] << "(No Job)" << "\t\t" << freespace[i] << "\t" << " Waiting" << endl;
	}
	int waste = 0;
	for (int a = 0; a < partitions; a++)
		waste += freespace[a];
	cout << "WASTE=" << waste << endl;

}

void MemoryManagement::nextFit()
{
	for (int k = 0; k < 5; k++) {
		allocspace[k] = 0;
		freespace[k] = avalibleSpace[k];
		done[k] = 0;
		jobname[k] = 5;
	}
	int check, tmp = 0;
	for (int i = 0; i < jobs; i++) {
		check = 0;
		for (int j = tmp; j < partitions; j++) {
			if (reqspace[i] <= avalibleSpace[j] && done[j] != 1 && check == 0) {
				tmp = j;
				allocspace[j] = reqspace[i];
				jobname[j] = i;
				freespace[j] = avalibleSpace[j] - allocspace[j];
				done[j] = 1;
				check = 999;
			}

		}
	}
	cout << "Next Fit\nAvailable space  " << "   Allocated space  " << "  Partition Waste " << "  Job State\n";
	for (int i = 0; i < partitions; i++) {
		if (jobname[i] != 5)
			cout <<"Partition " << i << ':' << avalibleSpace[i] << "\t\t" << allocspace[i] << "(Job: " << jobname[i] << ')' << "\t\t" << freespace[i] << "\t" << " Running" << endl;
		else
			cout << "Partition " << i << ':' << avalibleSpace[i] << "\t\t" << allocspace[i] << "(No Job)" << "\t\t" << freespace[i] << "\t" << " Waiting" << endl;
	}
	int waste = 0;
	for (int a = 0; a < partitions; a++)
		waste += freespace[a];
	cout << "WASTE=" << waste << endl;

}