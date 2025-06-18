#include<stdio.h>
#include<string.h>
#define MAX_LINE 100
#define MAX_LENGTH 1000
int main()
{
    char lines[MAX_LINE][MAX_LENGTH];
    int countline=0;
    while(countline<MAX_LINE)
    {
        if(fgets(lines[countline],MAX_LENGTH,stdin)==NULL){
            break;
        }
        size_t len = strlen(lines[countline]);
        if (len > 0 && lines[countline][len - 1] == '\n') {
            lines[countline][len - 1] = '\0';
            len--;
        }

         if (len == 0) {
            break;
        }

        countline++;
    }
     for (int i = 0; i < countline; i++) {
        printf("%s", lines[i]);
    }
    printf("\n");

}
