#include <stdio.h>
#include <stdlib.h>
struct STUDENT
{
    int roll;
    char name[30];
    char gender;
    float cgpa;
    char placed[30];
};
int main()
{
    int n;
    printf("Enter the number of student:");
    scanf("%d", &n);
    char temp;
    struct STUDENT s[n];
    FILE *fptr;
    fptr = (fopen("Student.txt", "w"));
    if (fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }
    for (int i = 0; i < n; i++)
    {
        printf("\nSTUDENT No.%d\n", (i + 1));
        printf("Enter student roll number:");
        scanf("%d", &s[i].roll);
        printf("Enter student name:");
        scanf("%s", s[i].name);
        scanf("%c", &temp);
        printf("Enter student gender:");
        scanf("%c", &s[i].gender);
        printf("Enter student CGPA:");
        scanf("%f", &s[i].cgpa);
        printf("Placed:");
        scanf("%s", s[i].placed);
        fprintf(fptr, "Student No.%d\n", (i + 1));
        fprintf(fptr, "Student Roll No:%d\n", s[i].roll);
        fprintf(fptr, "Student Name:%s\n", s[i].name);
        fprintf(fptr, "Student Gender:%c\n", s[i].gender);
        fprintf(fptr, "Student CGPA:%f\n", s[i].cgpa);
        fprintf(fptr, "Student Placed:%s\n\n", s[i].placed);
        printf("\n\n");
    }
    printf("\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nSTUDENT No.%d\n", (i + 1));
        printf("Roll:%d\n", s[i].roll);
        printf("Name:%s\n", s[i].name);
        printf("Gender:%c\n", s[i].gender);
        printf("CGPA:%.2f\n", s[i].cgpa);
        printf("Placed:%s\n", s[i].placed);
        printf("\n\n");
    }
    fclose(fptr);
    return 0;
}
