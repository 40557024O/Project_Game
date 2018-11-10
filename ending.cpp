#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include "func.h"



void ending()
{
    Sleep(1000);
    openFile("storyline\\ending.txt");
    PlaySound(NULL,NULL,SND_FILENAME);
    printf("LISA，祝妳生日快樂喔!\n\n");
    Sleep(1500);


    unsigned FREQUENCY[25] = {392,392,440,392,523,494,
                              392,392,440,392,587,523,
                              392,392,784,659,523,494,440,
                              698,698,659,523,587,523
                             };

    unsigned DELAY[25] = {375,125,500,500,500,1000,
                          375,125,500,500,500,1000,
                          375,125,500,500,500,500,1000,
                          375,125,1000,1000,1500,2000
                         };


    for (int i = 0; i < 25; i++)
    {
        Beep(FREQUENCY[i], DELAY[i]);
    }

    Sleep(1000);
    printf("全 劇 終 。");
    Sleep(2000);



}

