#include <stdio.h>

#define SUBJECTS 5
#define MAX_STUDENTS 30
#define NAME_LENGTH 50

struct Student {
    char name[NAME_LENGTH];
    int marks[SUBJECTS];
    int total;
    float percentage;
    char grade;
    int passed;
};

int readInteger(const char prompt[], int minimum, int maximum) {
    int value;
    int result;
    int ch;

    while (1) {
        printf("%s", prompt);
        result = scanf("%d", &value);

        if (result == 1) {
            while ((ch = getchar()) != '\n' && ch != EOF) {
                /* Clear any extra characters on the line. */
            }
            if (value >= minimum && value <= maximum) {
                return value;
            }
        } else {
            while ((ch = getchar()) != '\n' && ch != EOF) {
                /* Clear invalid input before asking again. */
            }
        }

        printf("Enter a whole number from %d to %d.\n", minimum, maximum);
    }
}

void calculateResult(struct Student *student) {
    int i;
    student->total = 0;
    student->passed = 1;

    for (i = 0; i < SUBJECTS; i++) {
        student->total += student->marks[i];
        if (student->marks[i] < 40) {
            student->passed = 0;
        }
    }

    student->percentage = (float)student->total / SUBJECTS;

    if (student->percentage >= 90) {
        student->grade = 'A';
    } else if (student->percentage >= 80) {
        student->grade = 'B';
    } else if (student->percentage >= 70) {
        student->grade = 'C';
    } else if (student->percentage >= 60) {
        student->grade = 'D';
    } else {
        student->grade = 'F';
    }
}

void enterStudents(struct Student students[], int *studentCount) {
    int i;
    int j;
    int count;
    char prompt[80];

    count = readInteger("Number of students (1-30): ", 1, MAX_STUDENTS);
    *studentCount = count;

    for (i = 0; i < count; i++) {
        printf("\nStudent %d name: ", i + 1);
        scanf(" %49[^\n]", students[i].name);

        for (j = 0; j < SUBJECTS; j++) {
            sprintf(prompt, "  Subject %d marks (0-100): ", j + 1);
            students[i].marks[j] = readInteger(prompt, 0, 100);
        }

        calculateResult(&students[i]);
    }
    printf("\nStudent results saved.\n");
}

void displayReport(const struct Student students[], int studentCount) {
    int i;
    int topperIndex;
    int classTotal;

    if (studentCount == 0) {
        printf("Enter student results first.\n");
        return;
    }

    topperIndex = 0;
    classTotal = 0;

    printf("\nSTUDENT RESULT REPORT\n");
    printf("---------------------------------------------------------------\n");
    printf("Name                 Total   Percent   Grade   Status\n");
    printf("---------------------------------------------------------------\n");

    for (i = 0; i < studentCount; i++) {
        printf("%-20s %3d/500   %6.2f%%     %c     %s\n",
               students[i].name,
               students[i].total,
               students[i].percentage,
               students[i].grade,
               students[i].passed ? "PASS" : "FAIL");

        classTotal += students[i].total;
        if (students[i].total > students[topperIndex].total) {
            topperIndex = i;
        }
    }

    printf("---------------------------------------------------------------\n");
    printf("Class topper: %s (%d/500, %.2f%%)\n",
           students[topperIndex].name,
           students[topperIndex].total,
           students[topperIndex].percentage);
    printf("Class average: %.2f%%\n",
           (float)classTotal / (studentCount * SUBJECTS));
    printf("Pass rule: at least 40 marks in every subject.\n");
    printf("Grade rule: A >= 90, B >= 80, C >= 70, D >= 60, otherwise F.\n");
}

int main(void) {
    struct Student students[MAX_STUDENTS];
    int studentCount;
    int choice;

    studentCount = 0;

    do {
        printf("\nSTUDENT GRADE ANALYZER\n");
        printf("1. Enter or replace student results\n");
        printf("2. Display class report\n");
        printf("3. Exit\n");
        choice = readInteger("Choose an option: ", 1, 3);

        if (choice == 1) {
            enterStudents(students, &studentCount);
        } else if (choice == 2) {
            displayReport(students, studentCount);
        } else {
            printf("Goodbye.\n");
        }
    } while (choice != 3);

    return 0;
}
