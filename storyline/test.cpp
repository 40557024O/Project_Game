#include <stdio.h>
#include <windows.h>
//#include "ioctrl.h"
int main()
{
    FILE *fp=fopen("startStoryPlot.txt","r");
    if(fp==0)
    {
        printf("error\n");
    }
    char arr[400]={};
    int num=0;
    while(fgets(arr,400,fp))
    {
    	char tem[400]={};
		sscanf(arr,"%s%d",tem,&num);
    	
    	if(!strcmp("color",tem))
    	{
    		system(arr);
    		Sleep(200);
		}
		else if(!strcmp("cls",tem))
    	{
    		system("cls");
		}
		else
		{
			printf("\n%s\n",tem);
			Sleep(num);
		}
        
    }


}
