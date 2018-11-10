#include <stdio.h>//printf
#include <windows.h>//Sleep
#include <conio.h>//getch
#include <stdlib.h>//systemclean
#include <time.h>//srandtime
#include "ioctrl.h"//color
#include "func.h"
#include "graph.h"
#include <ctype.h>//toupper


void level1(int *lb,const int choice)
{
    system("color 0F");
    if(choice==3||choice==0)//open story plot or not
    {
        openFile("storyline\\level1StoryPlot.txt");
    }
    if(choice==2||choice==0)//open game explain or not
    {
        openFile("storyline\\level1GameExplain.txt");
        enter();
    }


    int num=0,hp=*lb;
    srand(time(0));//randomly
    for(int i=0; i<43; i++)//gamet
    {
        if(i==27)
        {
            graph('H');//print graph H
            setcolor(fgYELLOW, bgBLACK);
            gotoxyprint(hp);
            char c={};
            timer(&c);
            c=toupper(c);
            Beep(784,1500);
            seeif(c,&hp);//see if player put the space or the alphabat
            gotoxyprint(hp);//print hp=%d at (0,0)
        }
        else
        {
            num=rand()%26;
            char b;
            b='A'+num;
            if(b=='H')//don't show H ，turn into another number
            {
                int num1=0;
                num1=rand()%2;
                if(num1)
                {
                    b+=1;
                }
                else
                {
                    b-=1;
                }
            }
            graph(b);//print graph
            setcolor(fgYELLOW, bgBLACK);
            gotoxyprint(hp);
            char c={};
            timer(&c);
            c=toupper(c);


            if((c=='A'&&b=='A')||(c=='I'&&b=='I')||(c=='V'&&b=='V')||(c=='S'&&b=='S')||(c=='N'&&b=='N')||(c=='U'&&b=='U'))//判斷
            {
                system("color F");
                hp-=5;
            }
            else if((c==' '&&b=='A')||(c==' '&&b=='I')||(c==' '&&b=='V')||(c==' '&&b=='S')||(c==' '&&b=='N')||(c==' '&&b=='U'))
            {
                hp-=0;
                setcolor(fgWHITE, bgBLACK);
            }
            else if(c==b)
            {
                hp-=0;
                setcolor(fgWHITE, bgBLACK);
            }
            else
            {
                system("color F");
                hp-=5;
            }
            gotoxyprint(hp);
        }
        Sleep(500);
        system("cls");
        if(hp<=0)
        {
            break;
        }

    }
    *lb=hp;
    system("color F0");
    Sleep(1050);
    system("color 0F");
    Sleep(2000);
}



