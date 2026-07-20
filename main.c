#include <stdio.h>
#include "gpa.h"

int main()
{
    double current_cgpa;
    double completed_credits;
    double expected_gpa;
    double future_credits;

    printf("Current CGPA: ");
    scanf("%lf", &current_cgpa);

    printf("Completed credits: ");
    scanf("%lf", &completed_credits);

    printf("Expected future GPA: ");
    scanf("%lf", &expected_gpa);

    printf("Future credits: ");
    scanf("%lf", &future_credits);

    printf("Expected CGPA: %.2f\n",
           calculateExpectedCGPA(current_cgpa,
                                 completed_credits,
                                 expected_gpa,
                                 future_credits));

    return 0;
}