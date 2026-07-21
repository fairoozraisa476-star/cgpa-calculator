#include <stdio.h>
#include <string.h>
#include "course.h"
#include "courseResult.h"

int testSorting()
{
    Course courses[3];

    courses[0] = createCourse("A", "A", 3.0, 3);
    courses[1] = createCourse("B", "B", 3.0, 1);
    courses[2] = createCourse("C", "C", 3.0, 2);

    CourseResult results[3];

    results[0] = createCompletedCourseResult(&courses[0], 100);
    results[1] = createCompletedCourseResult(&courses[1], 100);
    results[2] = createCompletedCourseResult(&courses[2], 100);

    sortCourseResultsBySemester(results, 3);

    return results[0].course->semester == 1 &&
           results[1].course->semester == 2 &&
           results[2].course->semester == 3;
}

int testFiltering()
{
    Course courses[4];

    courses[0] = createCourse("A", "A", 3.0, 1);
    courses[1] = createCourse("B", "B", 3.0, 2);
    courses[2] = createCourse("C", "C", 3.0, 2);
    courses[3] = createCourse("D", "D", 3.0, 3);

    CourseResult results[4];

    for (int i = 0; i < 4; i++)
    {
        results[i] = createCompletedCourseResult(&courses[i], 100);
    }

    CourseResult filtered[10];

    filterCourseResultsBySemester(results, 4, 2, filtered);

    return countCourseResultsBeforeNull(filtered, 10) == 2;
}

int main()
{
    printf("Course Result module tests\n");

    int passed = 0;
    int total = 0;

    total++;
    if (testSorting())
        passed++;

    total++;
    if (testFiltering())
        passed++;

    printf("Passed %d/%d tests\n", passed, total);

    if (passed == total)
        return 0;

    return 1;
}