# Student Grade Analyzer

## Problem statement
Create a menu-driven C program that processes marks in five subjects for multiple students. It reports each student's total, percentage, grade, and pass/fail result, then identifies the class topper and calculates the class average.

## Team details
- Team number: [Enter team number]
- Batch: [Enter batch]
- Members: [Enter the names of all team members]

## Features
- Accepts results for 1 to 30 students.
- Accepts a name and marks from 0 to 100 for each of five subjects.
- Validates numeric inputs and mark ranges.
- A student passes only when every subject mark is at least 40.
- Calculates total out of 500 and percentage.
- Assigns grades using these percentage bands: A (90-100), B (80-89.99), C (70-79.99), D (60-69.99), F (below 60).
- Displays a student-wise report, topper, and class average.
- Lets the user enter a new class list or display the current report from a menu.

## C concepts used
Variables, constants, structures, arrays, loops, conditional statements, functions, pointers, formatted input/output, and basic input validation.

## Algorithm
1. Show the menu until the user chooses Exit.
2. When entering results, read the number of students, then each student's name and five marks.
3. Add the five marks and check whether every subject mark is at least 40.
4. Divide the total by five to calculate the percentage, then assign a grade.
5. When requested, display each result, find the highest total, and calculate the class average percentage.

## Compile and run
Using GCC:

```sh
gcc student_grade_analyzer.c -o student_grade_analyzer
./student_grade_analyzer
```

On Windows with GCC:

```sh
gcc student_grade_analyzer.c -o student_grade_analyzer.exe
student_grade_analyzer.exe
```

## Sample test case
Enter two students:

- Asha: 90, 80, 70, 60, 100
- Ravi: 40, 40, 40, 40, 39

Expected calculations:

| Student | Total | Percentage | Grade | Status |
|---|---:|---:|---|---|
| Asha | 400/500 | 80.00% | B | PASS |
| Ravi | 199/500 | 39.80% | F | FAIL |

The report should identify Asha as the class topper and show a class average of 59.90%. Ravi fails because one subject is below 40, even though his marks in the other subjects meet the minimum.

Actual output: Run the program with the sample marks above to view the formatted report. Replace this line with a screenshot or captured terminal output after running it in the lab environment.

## Notes for the team
Review and adapt the grade bands if the faculty specifies different rules. Add the team details and attach the required sample output before submitting the repository. The faculty guidelines also request a presentation for the Lab 2 demonstration.
