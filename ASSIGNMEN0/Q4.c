// Himanshu Mohanty
// 2105719
// CSE36
#include <stdio.h>
void funLemm(char input1[20], char input2[20], char input3[20]){
    int i=0;
    printf("The same word is: ");
    while(input1[i]!='\0'&&input2[i]!='\0'&&input3[i]!='\0'){
        if(input1[i]==input2[i]&&input1[i]==input3[i]){
            printf("%c",input1[i]);
        }
        i++;
    }
}

int main()
{
    char input1[20], input2[20], input3[20];
    scanf("%s %s %s", input1, input2, input3);
    funLemm(input1,input2,input3);
}