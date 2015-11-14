#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

/*Домашняя работа от 29.10.2015*/

typedef struct Student
{
	char *name;
	double averageMark;
	int age;

} student;

int comp(const void * a, const void * b)
{
	return ((student*)a)->averageMark - ((student*)b)->averageMark;
}

void fileOutput(FILE *file, char *filename, student *students, int count)
{
	fopen_s(&file, filename, "w");

	for (int i = 0; i < count; i++) {
		fprintf_s(file, "%s %lf %d\n",
			students[i].name,
			students[i].averageMark,
			students[i].age);
	}

	fclose(file);
}

void main()
{
	char *filename = "in.txt";
	FILE *file;
	fopen_s(&file, filename, "r");

	student *students = malloc(sizeof(student));
	int countOfStudents = 0;
	while (!feof(file))
	{
		students[countOfStudents].name = malloc(sizeof(char)*50);
		fscanf_s(file, "%s %lf %d\n",
			students[countOfStudents].name, 49,
			&students[countOfStudents].averageMark,
			&students[countOfStudents].age);
		countOfStudents++;
		students = realloc(students, sizeof(student)*(countOfStudents+1));
	}

	fclose(file);

	qsort(students, countOfStudents, sizeof(student), comp);

	fileOutput(file, "out1.txt", students, countOfStudents);
	
	free(students);
}