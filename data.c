#include "data.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* Creates menu from a list of possible choices the user can choose from as
 * strings.  Empty strings are skipped over, such as when you don't want a 0th
 * choice.  User's input is validated. */
int select_item(char *menu_items[], int size)
{
    int input = -1;

    printf("\n");

    /* Print each menu item */
    for (int i = 0; i < size; i++)
    {
	char *item = menu_items[i];
	if (strcmp(item, "") != 0)
	    printf("%d) %s\n", i, menu_items[i]);
    }

    /* User chooses from items.  Validate user input */
    while (input > size || input < 0)
    {
	char c;
	printf("\nEnter choice: ");
	scanf("%d", &input);
	/* scanf leaves a newline in stdin, so remove it to avoid messing up
	 * future input/fgets calls. */
	while((c = getchar()) != '\n' && c != EOF);
    }

    return input;
}

/* Return ID of student selected by teacher. */
int select_student(Student students[], int sindex)
{
    unsigned int id;
    Student *student = NULL;

    for (int i = 0; i < sindex; i++)
    {
	char *name = students[i].full_name;
	printf("%d) %s\n", i, name);
    }

    printf("\nEnter the ID of the student: ");
    do
    {
	scanf("%d", &id);
	
	if (id > sindex)
	{
	    printf("Invalid student ID.\n"
		   "Enter the ID of the student:");
	}
    } while (id > sindex);
    
    return id;
}

void strip_newline(char *str)
{
    // Remove new line character from student name
    // replace with terminating char
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
    {
	str[len - 1] = '\0';
    }
}

/* Format of file:
 * [student full name] [grade for course 1] [grade for course 2] ... [grade for course n] */
void write_student_file(Student students[], int index)
{
    FILE *f_ptr;
    const char *filename = STUDENTS_FILE_NAME;

    if ((f_ptr = fopen(filename, "w")) == NULL)
    {
	puts("File can't be opened.");
	return;
    }

    for (int i = 0; i < index; i++)
    {
	Student s = students[i];
	char *name = s.full_name;

	/* Write name as first column. */
	fprintf(f_ptr, "%s", name);

	for (int j = 0; j < MAX; j++)
	{
	    /* Write grades in continuing columns. */
	    fprintf(f_ptr, "\t%d", s.course_grades[j]);
	}

	/* New row for next student. */
	fprintf(f_ptr, "\n");
    }

    printf("Printed to file \"%s\".\n", filename);

    fclose(f_ptr);
}

void write_teacher_file(char *teachers[], int index)
{
    FILE *fptr;
    const char *filename = TEACHERS_FILE_NAME;

    if ((fptr = fopen(filename, "w")) == NULL)
    {
	puts("File can't be opened.");
	return;
    }

    for (int i = 0; i < index; i++)
    {
	fprintf(fptr, "%s\n", teachers[i]);
    }

    fclose(fptr);

    printf("Printed to file \"%s\".\n", filename);
}

void write_courses_file(char *courses[], int index)
{
    FILE *fptr;
    const char *filename = COURSES_FILE_NAME;

    if ((fptr = fopen(filename, "w")) == NULL)
    {
	puts("File can't be opened.");
	return;
    }

    for (int i = 0; i < index; i++)
    {
	fprintf(fptr, "%s\n", courses[i]);
    }

    fclose(fptr);
    printf("Printed to file \"%s\".\n", filename);
}

/* Populate list of names into array. */
void read_list_file(char *filename, char *names[], int *index)
{
    FILE *fptr;
    char line[STR_LENGTH];

    *index = 0;

    if ((fptr = fopen(filename, "r")) == NULL)
    {
	return;
    }

    for (int i = 0; fgets(line, sizeof(line), fptr) != NULL && line[0] != '\n'; i++)
    {
	strip_newline(line);
	names[i] = strdup(line);
	(*index)++;
    }

    fclose(fptr);
}

/* Read from file into students array.  Index counts how many students are
 * present in the array. */
void read_student_file(Student students[], int* index)
{
    FILE *fptr;
    const char *filename = STUDENTS_FILE_NAME;
    char line[400];

    *index = 0;

    if ((fptr = fopen(filename, "r")) == NULL)
    {
	return;
    }

    /* Each line corresponds to a student and their grades */
    while (fgets(line, sizeof(line), fptr) != NULL && line[0] != '\n')
    {
	Student new_s;
	char *token_ptr;
	int i = 0;
	/* Stores strings for each token.  First token is name, everything else
	 * is a grade. */
	char tokens[MAX][STR_LENGTH];

	/* Break line apart into tokens and store them. */
	token_ptr = strtok(line, "\t");
	while (token_ptr != NULL)
	{
	    strcpy(tokens[i], token_ptr);
	    token_ptr = strtok(NULL, "\t");
	    i++;
	}

	/* First token is the student's name. */
	strcpy(new_s.full_name, tokens[0]);

	/* Each token after is a course grade. -1 means unenrolled. */
	for (int i = 1; i < MAX; i++)
	{
	    int new_grade;
	    sscanf(tokens[i], "%d", &new_grade);
	    new_s.course_grades[i - 1] = new_grade;
	}

	/* Increment array index of students, which is a soft upper bound of
	 * array. */
	students[*index] = new_s;
	(*index)++;
    }

    fclose(fptr);
}
