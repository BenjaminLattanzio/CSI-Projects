#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

struct timeCalc
{
	int arrivalTime; //variable to hold the arrival time inputted by user
	int execTime; //variable to hold the execution time inputted by user
	int complTime;
	int priorityTime;//variable to hold the priority time inputted by user
	float tart;
	string nameP; //variable to hold each process name inputted by user
	timeCalc() { arrivalTime = 0; execTime = 0; complTime = 0; priorityTime = 0; tart = 0; nameP = ""; }
}temp;


int ch;
int totaltime;
int n = 0;
int i = 0;
int j, x;
int cst = 0;
int minct = 0;
int execTimeime;
float avgtat = 0;


void firstserve(timeCalc[], int n);
void shortestjobnext(timeCalc[], int n);
void priorityTimeiority(timeCalc[], int n);
void priorityTimeint(timeCalc[], int n);


int main()
{
	timeCalc *a;

	cout << "Enter the number of processes : ";
	cin >> n;
	cout << endl;
	a = new timeCalc[n];
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		cout << "Enter the Name of the process , Arrival Time , Execution Time  and priority Time \n";
		cin >> a[i].nameP >> a[i].arrivalTime >> a[i].execTime >> a[i].priorityTime;

	}

	// Sorting priority time by Arrival time
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j >= 1; j--)
		{
			if (a[j].arrivalTime < a[j - 1].arrivalTime)
			{
				temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
			}
		}
	}


	//Calculating Total Time, then outputting to user
	totaltime += a[0].arrivalTime + a[0].execTime;
	for (int i = 1; i < n; i++)
	{
		if (a[i].arrivalTime > totaltime)

			totaltime = a[i].arrivalTime;
		totaltime += a[i].execTime;

	}
	cout << "\n----------- First Come First Serve------------" << endl;
	firstserve(a, n);
	cout << "\n------------ Shortest Job Next ---------------- " << endl;
	shortestjobnext(a, n);
	cout << "\n---------------- Priority Time Scheduling----------------" << endl;
	priorityTimeiority(a, n);
	return 0;
}// End of Main

 // priority time function, calculaties average turn around time
void priorityTimeint(timeCalc a[], int n)
{
	int i = 0;
	float avgtat = 0;
	for (i = 0; i < n; i++)
	{
		a[i].tart = a[i].complTime - a[i].arrivalTime;
	}
	for (i = 0; i < n; i++)
	{
		avgtat += a[i].tart;
	}

	avgtat = avgtat / n;

	cout << "Name" << "\t Arrival " << "\t execTime " << "\t priorityTime" << "\t Completed" << "\t TA Time \n";

	for (i = 0; i < n; i++)
	{
		cout << a[i].nameP << "\t " << a[i].arrivalTime << "\t\t" << a[i].execTime << "\t\t" << a[i].priorityTime << "\t\t" << a[i].complTime << "\t\t" << a[i].tart << "\n";
	}

	cout << " \n Average Turnaround Time= " << avgtat;
	cout << endl;
}

// calculates method first come first serve
void firstserve(timeCalc a[], int n)
{
	timeCalc *b, instance; //creating instance 
	b = new timeCalc[n];

	for (int i = 0; i < n; i++)
	{
		b[i].arrivalTime = a[i].arrivalTime;
		b[i].execTime = a[i].execTime;
		b[i].complTime = a[i].complTime;
		b[i].priorityTime = a[i].priorityTime;
		b[i].tart = a[i].tart;
		b[i].nameP = a[i].nameP;
	}
	int i;
	int temp;
	int execTimeime = b[0].arrivalTime;
	b[0].complTime = execTimeime + b[0].execTime;
	execTimeime = b[0].complTime;

	for (i = 1; i < n; i++)
	{
		temp = b[i].arrivalTime;
		if (temp > execTimeime)
			execTimeime = temp;
		b[i].complTime = execTimeime + b[i].execTime;
		execTimeime = b[i].complTime;
	}
	for (int j = 1; j < n; j++) {//calculates completion time then outputs to user
		for (int i = 0; i < n - 1; i++)
		{
			if (b[i].complTime > b[i + 1].complTime) {
				instance.arrivalTime = b[i].arrivalTime;
				b[i].arrivalTime = b[i + 1].arrivalTime;
				b[i + 1].arrivalTime = instance.arrivalTime;
				instance.complTime = b[i].complTime;
				b[i].complTime = b[i + 1].complTime;
				b[i + 1].complTime = instance.complTime;
				instance.execTime = b[i].execTime;
				b[i].execTime = b[i + 1].execTime;
				b[i + 1].execTime = instance.execTime;
				instance.priorityTime = b[i].priorityTime;
				b[i].priorityTime = b[i + 1].priorityTime;
				b[i + 1].priorityTime = instance.priorityTime;
				instance.tart = b[i].tart;
				b[i].tart = b[i + 1].tart;
				b[i + 1].tart = instance.tart;
				instance.nameP = b[i].nameP;
				b[i].nameP = b[i + 1].nameP;
				b[i + 1].nameP = instance.nameP;
			}
		}
	}
	priorityTimeint(b, n);
}

//Function to calculate shortest job next
void shortestjobnext(timeCalc a[], int n)
{
	timeCalc *b, instance; //creating instance
	b = new timeCalc[n];

	for (int i = 0; i < n; i++)
	{
		b[i].arrivalTime = a[i].arrivalTime;
		b[i].execTime = a[i].execTime;
		b[i].complTime = a[i].complTime;
		b[i].priorityTime = a[i].priorityTime;
		b[i].tart = a[i].tart;
		b[i].nameP = a[i].nameP;
	}

	int time = 0;
	int x = 0;
	int minct = 0;
	while (time < totaltime)
	{
		int j = 0;
		for (int i = 0; i < n; i++)
		{
			if (b[i].arrivalTime <= time)
			{
				j = i + 1;
			}
		}
		if (j > 0)
		{
			int x = 0;
			minct = b[0].execTime;
			for (int i = 1; i < j; i++)
			{
				if (minct > b[i].execTime)
				{
					x = i;
					minct = b[i].execTime;
				}
			}
			time += b[x].execTime;
			b[x].complTime = time;
			b[x].execTime += 1000;
			b[x].arrivalTime += 1000;
		}
		else
		{
			time++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		b[i].execTime -= 1000;
		b[i].arrivalTime -= 1000;
	}
	for (int j = 1; j < n; j++) {//outputting completion time to user.
		for (int i = 0; i < n - 1; i++)
		{
			if (b[i].complTime > b[i + 1].complTime) {
				instance.arrivalTime = b[i].arrivalTime;
				b[i].arrivalTime = b[i + 1].arrivalTime;
				b[i + 1].arrivalTime = instance.arrivalTime;
				instance.complTime = b[i].complTime;
				b[i].complTime = b[i + 1].complTime;
				b[i + 1].complTime = instance.complTime;
				instance.execTime = b[i].execTime;
				b[i].execTime = b[i + 1].execTime;
				b[i + 1].execTime = instance.execTime;
				instance.priorityTime = b[i].priorityTime;
				b[i].priorityTime = b[i + 1].priorityTime;
				b[i + 1].priorityTime = instance.priorityTime;
				instance.tart = b[i].tart;
				b[i].tart = b[i + 1].tart;
				b[i + 1].tart = instance.tart;
				instance.nameP = b[i].nameP;
				b[i].nameP = b[i + 1].nameP;
				b[i + 1].nameP = instance.nameP;
			}
		}
	}

	priorityTimeint(b, n);

}

//function for priority time
void priorityTimeiority(timeCalc a[], int n)
{
	timeCalc *b, instance;
	b = new timeCalc[n];
	for (int i = 0; i < n; i++)
	{
		b[i].arrivalTime = a[i].arrivalTime;
		b[i].execTime = a[i].execTime;
		b[i].complTime = a[i].complTime;
		b[i].priorityTime = a[i].priorityTime;
		b[i].tart = a[i].tart;
		b[i].nameP = a[i].nameP;
	}
	int  time = 0;
	while (time < totaltime)
	{
		j = 0;
		for (i = 0; i < n; i++)
		{
			if (b[i].arrivalTime <= time)
			{
				j = i + 1;
			}
		}
		if (j > 0)
		{
			int x = 0;
			int minpriorityTime = b[0].priorityTime;
			for (i = 1; i < j; i++)
			{
				if (minpriorityTime > b[i].priorityTime)
				{
					x = i;
					minpriorityTime = b[i].priorityTime;
				}
				else
					if (minpriorityTime == b[i].priorityTime)
					{
						if (b[x].arrivalTime > b[i].arrivalTime)
						{
							x = i;
							minpriorityTime = b[i].priorityTime;
						}
						else if (b[x].arrivalTime == b[i].arrivalTime)
						{
							if (b[x].execTime > b[i].execTime)
							{
								x = i;
								minpriorityTime = b[i].priorityTime;
							}
						}
					}
			}
			time += b[x].execTime;
			b[x].complTime = time;
			b[x].priorityTime += 1000;
			b[x].arrivalTime += 1000;
		}
		else
		{
			time++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		b[i].priorityTime -= 1000;
		b[i].arrivalTime -= 1000; \
	}
	for (int j = 1; j < n; j++) {
		for (int i = 0; i < n - 1; i++)
		{
			if (b[i].complTime > b[i + 1].complTime) {
				instance.arrivalTime = b[i].arrivalTime;
				b[i].arrivalTime = b[i + 1].arrivalTime;
				b[i + 1].arrivalTime = instance.arrivalTime;
				instance.complTime = b[i].complTime;
				b[i].complTime = b[i + 1].complTime;
				b[i + 1].complTime = instance.complTime;
				instance.execTime = b[i].execTime;
				b[i].execTime = b[i + 1].execTime;
				b[i + 1].execTime = instance.execTime;
				instance.priorityTime = b[i].priorityTime;
				b[i].priorityTime = b[i + 1].priorityTime;
				b[i + 1].priorityTime = instance.priorityTime;
				instance.tart = b[i].tart;
				b[i].tart = b[i + 1].tart;
				b[i + 1].tart = instance.tart;
				instance.nameP = b[i].nameP;
				b[i].nameP = b[i + 1].nameP;
				b[i + 1].nameP = instance.nameP;
			}
		}
	}

	priorityTimeint(b, n);
	system("pause");

}
