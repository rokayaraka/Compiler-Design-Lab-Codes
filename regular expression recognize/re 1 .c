#include<stdio.h>
int Length(char x[]){
int i=0,len=0;
for(i=0;x[i]!='\0';i++)
len++;
return len;
}

int main()
{
char x[10000];
int k=0;
while(k<5){
printf("Enter a string:");
gets(x);
int i=0,count=0,len;
len=Length(x);
if (len==1 && x[0]=='a')
printf("Acceptable\n");
if(len==NULL)
    printf("Acceptable\n");

else{
    for(i=1;x[i]!='\0';i++)
    if (x[i]=='b')
    count++;
    if (count==len-1)
    printf("Acceptable\n");
    if(x[i]==NULL)
        printf("Acceptable\n");
    else
    printf("Not Acceptable\n");
}
k++;
}
}
