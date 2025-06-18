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
printf("Enter a string((a|b)*b(a|b)*b(a|b)*):");
gets(x);
int i,count=0;
int len=Length(x);

if (len<2)
printf("Not Acceptable\n");

else{
for(i=0;x[i]!='\0';i++)
if (x[i]=='b')
count++;
if (count>=2)

printf("Acceptable\n");

else
printf("Not Acceptable\n");

}
k++; }
return 0;
}
