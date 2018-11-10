#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "ioctrl.h"
#include "func.h"
#include "graph.h"
#include <ctype.h>

void level2(int *lb,const int choice)
{
    system("color 0F");
    if(choice==3||choice==0)
    {
        openFile("storyline\\level2StoryPlot.txt");
    }
    if(choice==2||choice==0)
    {
        openFile("storyline\\level2GameExplain.txt");
        enter();
    }

    int num=0,hp=*lb,color[26]= {18,7,2,25,16,23,18,7,2,25,16,23,18,7,2,25,16,23,18,7,2,25,16,23,18,7};
    srand(time(0));
    for(int i=0; i<39; i++)//遊戲
    {
        if(i==11||i==30)
        {
            graph('S');//print 圖案 S
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
            if(b=='S')//不要出現 S 換成別的號碼
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
            c=toupper(c);
            if((c-'A'+1==color['A'-'A']&&b=='A')||(c-'A'+1==color['I'-'A']&&b=='I')||(c-'A'+1==color['V'-'A']&&b=='V')||(c-'A'+1==color['H'-'A']&&b=='H')||(c-'A'+1==color['N'-'A']&&b=='N')||(c-'A'+1==color['U'-'A']&&b=='U'))//判斷
            {
                system("color F");
                hp-=5;
            }
            else if((c==' '&&b=='A')||(c==' '&&b=='I')||(c==' '&&b=='V')||(c==' '&&b=='H')||(c==' '&&b=='N')||(c==' '&&b=='U'))
            {
                hp-=0;
                setcolor(fgWHITE, bgBLACK);
            }
            else if(c==color[b-'A']+'A'-1)
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

