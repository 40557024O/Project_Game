#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "ioctrl.h"
#include "func.h"
#include "graph.h"

void level5(int *lb,const int choice)
{
    system("color 0F");
    if(choice==3||choice==0)
    {
        openFile("storyline\\level1StoryPlot.txt");
    }

    printf("\n不知道盒子有甚麼機關，要開盒子嗎???\n");
    Sleep(1000);
    printf("\"要(按1)\" \"不要(按2)\" ");
    int hp=0;
    hp=*lb;
    char c;
    c=getch();
    while(c!='1'&&c!='2')
    {
        Sleep(500);
        c=getch();
    }
    system("cls");
    if(c=='2')
    {
        hp-=20;
        openFile("storyline\\level5OpenTheBox.txt");
    }
    else
    {
        printf("\n請輸入4位數密碼(不須分開)，輸入完畢請按Enter\n\n");
        Sleep(1000);
        int code=0;
        scanf("%d",&code);
        if(code!=1221)
        {
            hp-=20;
            openFile("storyline\\level5CodeFailed.txt");
        }
        else
        {
            printf("\n盒子..打開了");
            Sleep(2000);

        }
        system("cls");

        if(hp>0)
        {
            openFile("storyline\\level5Finish.txt");
        }


    }
    *lb=hp;
    Sleep(500);
    system("cls");

}






