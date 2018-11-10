#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "ioctrl.h"
#include "func.h"
#include "graph.h"
#include <ctype.h>
void level4(int *lb,const int choice)
{
    system("color 0F");
    if(choice==3||choice==0)
    {
        openFile("storyline\\level4StoryPlot.txt");
    }
    if(choice==2||choice==0)
    {
        openFile("storyline\\level4GameExplain.txt");
        enter();
    }

    int num=0,hp=*lb;
    char b;
    srand(time(0));
    for(int i=0; i<50; i++)//遊戲
    {
        if(i==15)
        {
            int num2=0;
            num2=rand()%3;
            system("color 0F");
            if(num2==2)//第一種
            {
                printf("\n輸入字母\n");
            }
            else if (num2==1)
            {
                printf("\n輸入相對顏色\n");
            }
            else if(num2==0)
            {
                printf("\n找出有幾個\"$\"\n");
            }

            graph('U');//print 圖案 U
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
            b='A'+num;
            if(b=='U')//不要出現 U 換成別的號碼
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

            int num2=0;
            num2=rand()%3;
            system("color 0F");
            if(num2==0)//第一種
            {
                printf("\n輸入字母\n");
                graph(b);//print 圖案
                setcolor(fgYELLOW, bgBLACK);
                gotoxyprint(hp);
                char c={};
                timer(&c);
                c=toupper(c);


                if((c=='A'&&b=='A')||(c=='I'&&b=='I')||(c=='V'&&b=='V')||(c=='S'&&b=='S')||(c=='N'&&b=='N')||(c=='H'&&b=='H'))//判斷
                {
                    system("color F");
                    hp-=5;
                }
                else if((c==' '&&b=='A')||(c==' '&&b=='I')||(c==' '&&b=='V')||(c==' '&&b=='S')||(c==' '&&b=='N')||(c==' '&&b=='H'))
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
            else if(num2==1)//第二種
            {
                printf("\n輸入相對顏色\n");
                graph(b);//print 圖案
                setcolor(fgYELLOW, bgBLACK);
                gotoxyprint(hp);
                char c={};
                timer(&c);
                c=toupper(c);

                int color[26]= {18,7,2,25,16,23,18,7,2,25,16,23,18,7,2,25,16,23,18,7,2,25,16,23,18,7};



                if((c-'A'+1==color['A'-'A']&&b=='A')||(c-'A'+1==color['I'-'A']&&b=='I')||(c-'A'+1==color['V'-'A']&&b=='V')||(c-'A'+1==color['H'-'A']&&b=='H')||(c-'A'+1==color['N'-'A']&&b=='N')||(c-'A'+1==color['S'-'A']&&b=='S'))//判斷
                {
                    system("color F");
                    hp-=5;
                }
                else if((c==' '&&b=='A')||(c==' '&&b=='I')||(c==' '&&b=='V')||(c==' '&&b=='H')||(c==' '&&b=='N')||(c==' '&&b=='S'))
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
            else //第三種
            {
                printf("\n找出有幾個\"$\"\n");
                graph(b);//print 圖案
                setcolor(fgYELLOW, bgBLACK);
                gotoxyprint(hp);
                char c={};
                timer(&c);

                int color[26]= {2,7,8,6,5,1,9,0,2,6,4,3,4,2,1,3,9,6,5,8,1,6,5,5,7,3};
                if((c-48==color['A'-'A']&&b=='A')||(c-48==color['I'-'A']&&b=='I')||(c-48==color['V'-'A']&&b=='V')||(c-48==color['H'-'A']&&b=='H')||(c-48==color['S'-'A']&&b=='S')||(c-48==color['N'-'A']&&b=='N'))//判斷
                {
                    system("color F");
                    hp-=5;
                }
                else if((c==' '&&b=='A')||(c==' '&&b=='I')||(c==' '&&b=='V')||(c==' '&&b=='S')||(c==' '&&b=='H')||(c==' '&&b=='N'))
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


