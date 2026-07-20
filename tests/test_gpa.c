#include <stdio.h>
#include "course.h"
#include "courseResult.h"
#include "gpa.h"

int testSemesterCGPA()
{
    Course courses[4];

    courses[0] = createCourse("A", "A", 3.0, 1);
    courses[1] = createCourse("B", "B", 3.0, 1);
    courses[2] = createCourse("C", "C", 3.0, 2);
    courses[3] = createCourse("D", "D", 3.0, 2);

    CourseResult results[4];

    results[0] = createCompletedCourseResult(&courses[0], 300);
    results[1] = createCompletedCourseResult(&courses[1], 240);
    results[2] = createCompletedCourseResult(&courses[2], 210);
    results[3] = createCompletedCourseResult(&courses[3], 180);

    CourseResult filtered[10];

    filterCourseResultsBySemester(results, 4, 1, filtered);

    double gpa = calculateGPA(
        filtered,
        countCourseResultsBeforeNull(filtered, 10)
    );
    printf("GPA = %.2f\n",gpa);
    return gpa > 3.99 && gpa < 4.01;
}

int main()
{
    printf("GPA module tests\n");

    int passed = 0;
    int total = 0;

    total++;

    if (testSemesterCGPA())
        passed++;

    printf("Passed %d/%d tests\n", passed, total);

    if (passed == total)
        return 0;

    return 1;
}