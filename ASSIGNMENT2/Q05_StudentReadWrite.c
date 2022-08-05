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
            fscanf(fptr, "Student No.%d\n", &s[i].index);
            fscanf(fptr, "Student Roll No:%d\n", &s[i].roll);
            fscanf(fptr, "Student Name:%s\n", s[i].name);
            fscanf(fptr, "Student Gender:%c\n", &s[i].gender);
            fscanf(fptr, "Student CGPA:%f\n", &s[i].cgpa);
            fscanf(fptr, "Student Placed:%s\n\n", s[i].placed);
            printf("\nStudent No.%d\n", s[i].index);
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
