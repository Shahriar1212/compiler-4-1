/**
Implementation of the following CGF

A -> aXd
X -> bbX
X -> bcX
X -> d

**/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int i = 0;

int X(char str[], int length)
{
    if(i == length -1)
        return 1;

    else if(str[i] == 'b' && str[i+1] == 'b') {
        i = i+2;
        X(str, length);
    }
    else if(str[i] == 'b' && str[i+1] == 'c') {
        i = i+2;
        X(str, length);
    }
    else
        return 0;
}


int A(char str[], int len)
{
    if(str[0] != 'a') {
        return 0;
    }
    else {
        i++;
        if(X(str, len)) {
            if(str[strlen(str)-1] == 'd')
                return 1;
            else
                return 0;
        }
    }
}

void CFG(char str[], int len)
{

    if(A(str, len)) {
        printf("[+] %s is Accepted by the given CGF\n", str);
    }
    else {
        printf("[-] %s is rejected by the given CGF\n", str);
    }
}

int main()
{
    char str[1000];
    printf("--> ");
    while(scanf("%[^\n]%*c", str) != EOF){
        i = 0;
        int len = strlen(str);

        CFG(str, len);
        printf("--> ");
    }
}
