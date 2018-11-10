#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ioctrl.h"
#include "level.h"
#pragma comment(lib,"Winmm.lib")
#include <mmsystem.h>
#include "graph.h"
#include "func.h"
int main()
{

    system("title LISA");
    menu(10,4,0);//lisa
    char c;
    menuCheck(&c);
    sndPlaySound("sucess.wav",SND_ASYNC| SND_LOOP);
    int level=0,hp=20,choice=0;
    if(c==' ')//a new game
    {
        SkipMenu(&choice);
        if(choice==3||choice==0)
        {
          openFile("storyline\\startStoryPlot.txt");
        }
    }
    else//start from last record
    {
        FILE *fp=fopen("record.txt","r");
        fscanf(fp,"%d %d %d",&level,&hp,&choice);
        fclose(fp);
    }


    //PlaySound(NULL,NULL,SND_FILENAME);
    if(level<=1)
    {
        level1(&hp,choice);
        if(!hpCheck(hp))
        {
            return 0;
        }
        writeRecord(&level,hp,choice);
    }
    if(level<=2)
    {
        level2(&hp,choice);
        if(!hpCheck(hp))
        {
            return 0;
        }
        writeRecord(&level,hp,choice);
    }
    if(level<=3)
    {
        level3(&hp,choice);
        if(!hpCheck(hp))
        {
            return 0;
        }
        writeRecord(&level,hp,choice);
    }
    if(level<=4)
    {
        level4(&hp,choice);
        if(!hpCheck(hp))
        {
            return 0;
        }
        writeRecord(&level,hp,choice);
    }
    if(level<=5)
    {
        level5(&hp,choice);
        if(!hpCheck(hp))
        {
            return 0;
        }
        writeRecord(&level,hp,choice);
    }
    ending();

}


