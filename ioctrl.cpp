#include <windows.h>
#include <conio.h>

void setcolor(int fg, int bg)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,fg+bg);
}
// ---------------------------------------------------------
void setcursor(bool visible)
{
    CONSOLE_CURSOR_INFO info;
    info.bVisible = visible;
    //info.dwSize = 1;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}
// ---------------------------------------------------------
void gotoxy(int xpos, int ypos)
{
    COORD scrn;
    scrn.X = xpos;
    scrn.Y = ypos;

    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOuput,scrn);
}
// ---------------------------------------------------------

int getcha()
{
    char c = getch();
    if (c<0) c = getch();
    return c;
}
// ---------------------------------------------------------


