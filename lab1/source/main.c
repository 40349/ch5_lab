#include<stdio.h>
#include<stdlib.h>
#define STUDENTS 3
#define EXAMS 4
void minimum(int grade[][EXAMS], int pupils, int tests);
void maximum(int grade[][EXAMS], int pupils, int tests);
void average(int grade[][EXAMS], int pupils, int tests);
void printArray(int grade[][EXAMS], int pupils, int tests);
void printMenu();
int main()
{
	int studentGrades[STUDENTS][EXAMS] = { {77,68,86,73},
										   {96,87,89,78},
										   {70,90,86,81} };
	void(*processGrages[4])(int[STUDENTS][EXAMS], int, int)
		= { printArray,minimum,maximum,average };
	int choice = 0;
	while (choice != 4)
	{
		do
		{
			printMenu();
			scanf_s("%d", &choice);
		} while (choice < 0 || choice>4);
		if (choice != 4)
		{
			(*processGrages[choice])(studentGrades, STUDENTS, EXAMS);
		}
		else
		{
			printf("\tProgram Ended. \n");
		}
	}
	system("pause");
	return 0;
}
void minimum(int grade[][EXAMS], int pupils, int tests)
{
	int i, j;
	int lowGrade = 100;
	for (i = 0; i < pupils; i++)
	{
		for (j = 0; j < tests; j++)
		{
			if (grade[i][j] < lowGrade)
			{
				lowGrade = grade[i][j];
			}
		}
	}
	printf("\n\tThe lowest grade is %d", lowGrade);
	printf("\n");
}
void maximum(int grade[][EXAMS], int pupils, int tests)
{
	int i, j;
	int highGrade = 0;
	for (i = 0; i < pupils; i++)
	{
		for (j = 0; j < tests; j++)
		{
			if (grade[i][j] > highGrade)
			{
				highGrade = grade[i][j];
			}
		}
	}
	printf("\n\tThe highest grade is %d", highGrade);
	printf("\n");
}
void average(int grade[][EXAMS], int pupils, int tests)
{
	int i, j, total;
	for (i = 0; i < pupils; i++)
	{
		total = 0;
		for (j = 0; j < tests; j++)
		{
			total += grade[i][j];
		}
	}
	printf("\n\tThe average grade for student %d is %.1f", i+1,(double)total/tests);
	printf("\n");
}
void printArray(int grade[][EXAMS], int pupils, int tests)
{
	int i, j;
	printf("\n\t\t\t[0]\t[1]\t[2]\t[3]");
	for (i = 0; i < pupils; i++)
	{
		printf("\n\tstudentGrades[%d]", i);
		for (j = 0; j < tests; j++)
		{
			printf("%-7d\t", grade[i][j]);
		}
	}
	printf("\n");
}
void printMenu()
{
	printf("\n");
	printf("\tEnter a choice:\n");
	printf("\t0 Print the array of grades\n");
	printf("\t1 Find the minimum grades\n");
	printf("\t2 Find the maximum grades\n");
	printf("\t3 Print the average on all tests for each student\n");
	printf("\t4 End program\n");
	printf("Choice:");
}