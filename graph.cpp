#include <stdio.h>
#include <string.h>
#include "ioctrl.h"
#include "graph.h"


void color(int tem,int *a,int *b)
{

    switch(tem)
    {
    case 0:
    {
        *a=12;//fgRED
        *b=10;//fgGREEN
    }
    break;
    case 1:
    {
        *a=10;//fgGREEN
        *b=9;//fgBLUE
    }
    break;
    case 2:
    {
        *a=9;//fgBLUE
        *b=14;//fgYELLOW
    }
    break;
    case 3:
    {
        *a=14;//fgYELLOW
        *b=11;//fgCYAN
    }
    break;
    case 4:
    {
        *a=13;//fgPINK
        *b=9;//fgBLUE
    }
    break;
    case 5:
    {
        *a=15;//fgWHITE
        *b=14;//fgYELLOW
    }
    break;
    }
}


void graph(char s)//print the graph
{
    //int s=rand()%26;
    //char alpha='A'+s;//knowing what alpha is
    char alpha=s;
    char str[20]= {alpha}; //store the alpha in str[0]
    strcat(str,".txt");//create .txt file
    char arr[20];//make the space to the file
    sprintf(arr,"%s\\%s","alphabat",str);//create path to the file
    FILE *fp=fopen(arr,"r");
    if(fp==0)
    {
        printf("error\n");
    }

    int tem=(s-'A')%6,a=0,b=0;
    color(tem,&a,&b);
    char c=fgetc(fp);//check one word of the file
    int i=10;
    gotoxy(35, i);
    while(c!=EOF)//when the file is not end,keep doing
    {

        if(c=='1')
        {
            setcolor(a, bgBLACK);
            printf("%c",alpha);
        }
        else if(c=='2')
        {
            setcolor(b, bgBLACK);
            printf("!");
        }
        else if(c=='3')
        {
            setcolor(a, bgBLACK);
            printf("$");
        }
        else if(c=='0')
        {
            setcolor(fgBLACK, bgBLACK);
            printf(" ");
        }
        else if(c=='\n')
        {
            printf("\n");
            i+=1;
            gotoxy(35, i);

        }

        c=fgetc(fp);


    }
    fclose(fp);



}

void menu(int x,int y,int chap)
{
    char arr[30]= {};
    if(chap==0)//lisa
    {
        strcpy(arr,"storyline\\lisa.txt");
        setcolor(fgYELLOW, bgBLACK);
    }
    else //if(chap==1)  //gameover
    {
        system("color 4F");
        strcpy(arr,"storyline\\gameover.txt");
    }
    FILE *fp=fopen(arr,"r");
    if(fp==0)
    {
        printf("error\n");
    }
    gotoxy(x,y);//(10,4)
    char c=fgetc(fp);
    while(c!=EOF)//when the file is not end,keep doing
    {
        if(c=='\n')
        {
            printf("\n");
            y+=1;
            gotoxy(x, y);

        }
        else
        {
            printf("%c",c);
        }

        c=fgetc(fp);


    }


    fclose(fp);


}
