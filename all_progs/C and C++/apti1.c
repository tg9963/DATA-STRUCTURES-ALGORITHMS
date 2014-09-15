
#include<stdlib.h>
#include<stdio.h>
//using namespace std;

int main()
{
    char p[] = "geeksquiz";
    char t;
    int i, j;
    for(i=0,j=strlen(p); i<j; i++,j--)
    {
        t = p[i];
        p[i] = p[j-i-1];
        p[j-i-1] = t;
    }
    printf("%s", p);
    return 0;
}

