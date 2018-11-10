#include <stdio.h>
#include <windows.h>
#include "func.h"
#include "ioctrl.h"
#include "graph.h"
#include "conio.h"
#include <time.h>

void openline(FILE *fp)
{
    char arr[400]= {};
    int num=0;
    while(fgets(arr,400,fp))
    {
        char tem[400]= {};
        sscanf(arr,"%s%d",tem,&num);

        if(!strcmp("color",tem))
        {
            system(arr);
            Sleep(250);
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

void openFile(char s[])
{
    FILE *fp=fopen(s,"r");
    openline(fp);
    fclose(fp);
}

void enter()
{
    char c;//按\"*\"開始
    c=getch();
    while(c!='*')
    {
        Sleep(500);
        c=getch();
    }
    system("cls");
}

void menuCheck(char *v)
{
    setcolor(fgWHITE, bgBLACK);
    gotoxy(45,24);
    printf("PRESS \"SPACE\" TO START\n");
    gotoxy(44,25);
    printf("PRESS \" * \" TO CONTINUE THE GAME\n");
    gotoxy(27,27);
    printf("*建議先將鍵盤切換為英文模式，視窗大小120*30  *有背景音樂喲");
    char c;
    c=getch();
    while(c!=' '&&c!='*')
    {
        Sleep(100);
        c=getch();
    }
    *v=c;
    system("cls");


}

void SkipMenu(int *num)
{
    printf("\n(1)跳過所有故事和遊戲規則\n"
           "\n(2)只跳過故事\n"
           "\n(3)只跳過遊戲規則\n"
           "\n(4)都不跳過\n"
           "\n請選擇.......\n");
    scanf("%d",num);
    *num=*num%4;//prevent someone select incorrect one.
    system("cls");
}

bool hpCheck(int hp)
{
    if(!hp)
    {
        PlaySound(NULL,NULL,SND_FILENAME);
        menu(25,2,1);//gameover
        Sleep(2000);
        return false;
    }
    system("cls");
    return true;
}

void writeRecord(int *level,int hp,int choice)
{
    FILE *f=fopen("record.txt","w");
    *level+=1;
    fprintf(f,"%d %d %d",*level,hp,choice);
}

void gotoxyprint(int hp)
{
    gotoxy(0,0);
    printf("HP = %d  ",hp);
}

void seeif(char c,int *hp)
{
    if(c==' ')//判斷
    {
        *hp-=0;
        setcolor(fgWHITE, bgBLACK);
    }
    else
    {
        system("color F");
        *hp-=5;
    }
}

bool timer(char *c)
{
    time_t begin, end;
    bool flag = true;
    begin = time(NULL);
    double tem=0;
    int countdown=5;
    while(flag)
    {
        if(kbhit())
        {
            *c = getch();
            return true;
        }
        end=time(NULL);

        if(difftime(end, begin)>tem)
        {
            gotoxy(0,3);
            printf("倒數 : %.f  ",countdown-tem);
            tem+=1;
        }
        if(difftime(end, begin)> countdown)//NEEDED_TIME_IN_SECONDS)
        {
            flag = false;//The user didn't enter it in within the wanted period of time
            return false;
        }


    }
}
