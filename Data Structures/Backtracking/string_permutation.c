#include<stdio.h>
#include<string.h>
void swap(char *a, char *b);
void Permutation(char *s, int i, int n);

void Permutation(char *s, int i, int n)
{
    static int count;
    int j;

    if(i==n)
    {
        count++;
        printf("(%d) %s\n",count,s);
    }
    else
    {
        for(j=i;j<=n;j++)
        {
            swap((s+i),(s+j));
            Permutation(s,i+1,n);
            swap((s+i),(s+j)); //backtracking
        }
    }
}
void swap(char *a, char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void main()
{
    char s[20];
    int i=0, n;
    printf("\nEnter a string: ");
    gets(s);
    n = strlen(s);
    Permutation(s,i,n-1);
}