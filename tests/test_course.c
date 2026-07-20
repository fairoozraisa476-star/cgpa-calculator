#include <stdio.h>
#include <string.h>
#include "course.h"

int testCourseSemester()
{
    Course course = createCourse(
        "CSE 4202",
        "Structured Programming II Lab",
        1.5,
        2
    );

    return course.semester == 2;
}

int testCourseCounter()
{
    Course courses[10];

    courses[0] = createCourse("CSE 4107", "Structured Programming I", 3.0, 1);
    courses[1] = createCourse("CSE 4108", "Structured Programming I Lab", 1.5, 1);
    courses[2] = createCourse((char *)null_course_code, "NULL", 0.0, 0);

    return countCoursesBeforeNull(courses, 10) == 2;
}

int main()
{
    printf("Course module tests\n");

    int passed = 0;
    int total = 0;

    total++;
    if (testCourseSemester())
        passed++;

    total++;
    if (testCourseCounter())
        passed++;

    printf("Passed %d/%d tests\n", passed, total);

    if (passed == total)
        return 0;

    return 1;
}