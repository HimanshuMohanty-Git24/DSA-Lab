#include <stdio.h>
#include <stdlib.h>
struct STUDENT
{
    int roll;
    char name[30];
    char gender;
    float cgpa;
    char placed[30];
    int index;
};
int main()
{
    int n;
    printf("Enter the number of student:");
    scanf("%d", &n);
    struct STUDENT s[n];
    FILE *fptr;
    fptr = (fopen("Student.txt", "r"));
    if (fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }
    for (int i = 0; i < n; i++)
    {
        if (!feof(fptr))
        {
            fscanf(fptr, "\nStudent No.%d\nRoll: %d \nName:%s \nGender:%c \nCGPA:%.2f \nPlaced:%s \n", &s[i].index, &s[i].roll, s[i].name, &s[i].gender, &s[i].cgpa, s[i].placed);
            printf("\nStudent No.%d\n", (s[1].index + 1));
            printf("Roll No.:%d\n", s[i].roll);
            printf("Name:%s\n", s[i].name);
            printf("Gender:%c\n", s[i].gender);
            printf("CGPA:%.2f\n", s[i].cgpa);
            printf("Placed:%s\n", s[i].placed);
        }
        else
        {
            printf("\nOOPS!! There are only %d students in the file.", (i + 1));
            break;
        }
        printf("\n");
    }

    fclose(fptr);
    return 0;
}
