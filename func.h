#ifndef FUNC__
#define FUNC__
void openline(FILE *fp);
void enter();
void menuCheck(char *v);
void SkipMenu(int *num);
bool hpCheck(int hp);
void writeRecord(int *level,int hp,int choice);
void gotoxyprint(int hp);
void openFile(char s[]);
void seeif(char c,int *hp);
bool timer(char *c);
#endif // FUNC__
