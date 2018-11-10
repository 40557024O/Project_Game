#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
int main()
{
	int s=rand()%26;
	char alpha='A'+s;
	char str[10]={alpha};
	strcat(str,".txt");
    FILE *fp=fopen(str,"r");
    if(fp==0)
    {
        printf("error\n");
    }
  	char c=fgetc(fp);
    //gotoxy(35, 10);
    while(c!=EOF)
    {

        if(c=='1')
        {
            //setcolor(fgRED, bgBLACK);
            printf("%c",alpha);
        }
        else if(c=='2')
        {
            //setcolor(fgGREEN, bgBLACK);
            printf("!");
        }
        else if(c=='3')
        {
            //setcolor(fgRED, bgBLACK);
            printf("$");
        }
        else if(c=='0')
        {
            //setcolor(fgBLACK, bgBLACK);
            printf(" ");
        }
        else if(c=='\n')
        {
            printf("\n");
		}
        
		c=fgetc(fp);
            
		//gotoxy(35, 10+i+1);
	}
	fclose(fp);
    


}
