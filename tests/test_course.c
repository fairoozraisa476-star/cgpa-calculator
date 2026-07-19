#include <assert.h>
#include <string.h>
#include "../modules/course.h"

int main(void)
{
    Course course = createCourse("CSE101", "Structured Programming", 3.0);

    assert(strcmp(course.code, "CSE101") == 0);
    assert(strcmp(course.name, "Structured Programming") == 0);
    assert(course.credit == 3.0);

    return 0;
}