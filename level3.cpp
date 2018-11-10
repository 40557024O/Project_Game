#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "ioctrl.h"
#include "func.h"
#include "graph.h"
#include <ctype.h>

void level3(int *lb,const int choice)
{

    system("color 0F");
    if(choice==3||choice==0)
    {
        openFile("storyline\\level3StoryPlot.txt");
    }
    if(choice==2||choice==0)
    {
        openFile("storyline\\level3GameExplain.txt");
        enter();
    }

    int hp=*lb,num=0,color[26]= {2,7,8,6,5,1,9,0,2,6,4,3,4,2,1,3,9,6,5,8,1,6,5,5,7,3};
    srand(time(0));
    for(int i=0; i<41; i++)//遊戲
    {
        if(i==15||i==33)
        {
            graph('N');//print 圖案 N
            setcolor(fgYELLOW, bgBLACK);
            gotoxyprint(hp);
            char c={};
            timer(&c);
            c=toupper(c);
            Beep(784,1500);
            seeif(c,&hp);
            gotoxyprint(hp);
        }
        else
        {

            num=rand()%26;
            char b;
            b='A'+num;
            if(b=='N')//不要出現 N 換成別的號碼
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
            graph(b);//print 圖案
            setcolor(fgYELLOW, bgBLACK);
            gotoxyprint(hp);
            char c={};
            timer(&c);
            if((c-48==color['A'-'A']&&b=='A')||(c-48==color['I'-'A']&&b=='I')||(c-48==color['V'-'A']&&b=='V')||(c-48==color['H'-'A']&&b=='H')||(c-48==color['S'-'A']&&b=='S')||(c-48==color['U'-'A']&&b=='U'))//判斷
            {
                system("color F");
                hp-=5;

            }
            else if((c==' '&&b=='A')||(c==' '&&b=='I')||(c==' '&&b=='V')||(c==' '&&b=='S')||(c==' '&&b=='H')||(c==' '&&b=='U'))
            {
                hp-=0;
                setcolor(fgWHITE, bgBLACK);

            }
            else if(c-48==color[b-'A'])
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


