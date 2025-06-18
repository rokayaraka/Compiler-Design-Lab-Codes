#include<stdio.h>
#include<string.h>
int main()
{
char str[1000];
printf("Enter a string:");
gets(str);
char* token=strtok(str," ");
while(token!=NULL)
{
printf("%s\n",token);
token=strtok(NULL," ");
}

return 0;
}
