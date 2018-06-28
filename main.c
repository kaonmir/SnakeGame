#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include "Setting.h"

void title(void);
void ending(void);
void map_setting(void);
void print_map(void);
int gameover(void);
void gane(void);
void move(char dir);
int oppose(int dir);
int move_dir(int *x, int *y, char dir);
void random_make(void);

void remove_cursor()
{
    CONSOLE_CURSOR_INFO curInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    curInfo.bVisible = 0;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

int main()
{
    remove_cursor();

    title();
    getch();
    map_setting();

    while(1) {
        game();
        if(gameover()) break;
        print_map();
        Sleep(500);
    }
    ending();
    getch();
}

void title(void)
{
    system("cls");

    printf("\n\n\n       ");
    for(int i = 0; i <= MAP_Y + 1; i++) printf("¡á");
    printf("\n       ¡á                                                            ¡á");
    printf("\n       ¡á                 +¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡  - ¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡+               ¡á");
    printf("\n       ¡á                          SNAKE GAME                        ¡á");
    printf("\n       ¡á                 +¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡  - ¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡+               ¡á");
    printf("\n       ¡á                                                            ¡á");
    printf("\n       ¡á                   <PRESS ANY KEY TO START>                 ¡á");
    printf("\n       ¡á                                                            ¡á");
    printf("\n       ¡á                                                            ¡á");
    printf("\n       ¡á                   ¡Þ w, a, s, d : MOVE                     ¡á");
    printf("\n       ¡á                   ¡Þ P : PAUSE                             ¡á");
    printf("\n       ¡á                   ¡Þ ESC : Quit                            ¡á");
    printf("\n       ¡á                                                            ¡á");
    printf("\n       ¡á                                                            ¡á");
    printf("\n       ¡á                                                            ¡á");
    printf("\n       ¡á                      MADE BY : KAONMIR                     ¡á");
    printf("\n       ¡á                                                            ¡á");
    printf("\n       ¡á             CHUNGANG UNIV. DEPARTMENT OF SOFTWARE          ¡á");
    printf("\n       ¡á                                                            ¡á");
    printf("\n       ¡á                                                            ¡á");
    printf("\n       ¡á                                                            ¡á");
    printf("\n       ");
    for(int i = 0; i <= MAP_Y + 1; i++) printf("¡á");
    printf("\n\n");

}
void ending(void)
{
    system("cls");

    printf("\n\n\n       ");
    for(int i = 0; i <= MAP_Y + 1; i++) printf("¡á");
    printf("\n       ¡á                                                            ¡á");
    printf("\n       ¡á                 +¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡  - ¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡+               ¡á");
    printf("\n       ¡á                          SNAKE GAME                        ¡á");
    printf("\n       ¡á                 +¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡  - ¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡+               ¡á");
    printf("\n       ¡á                                                            ¡á");
    printf("\n       ¡á                                                            ¡á");
    printf("\n       ¡á                                                            ¡á");
    printf("\n       ¡á                          YOU DIED!!!                       ¡á");
    printf("\n       ¡á                                                            ¡á");
    printf("\n       ¡á               THANK YOU FOR ENJOYING THIS GAME             ¡á");
    printf("\n       ¡á                                                            ¡á");
    printf("\n       ¡á                                                            ¡á");
    printf("\n       ¡á                                                            ¡á");
    printf("\n       ¡á                                                            ¡á");
    printf("\n       ¡á                      MADE BY : KAONMIR                     ¡á");
    printf("\n       ¡á                                                            ¡á");
    printf("\n       ¡á             CHUNGANG UNIV. DEPARTMENT OF SOFTWARE          ¡á");
    printf("\n       ¡á                                                            ¡á");
    printf("\n       ¡á                                                            ¡á");
    printf("\n       ¡á                                                            ¡á");
    printf("\n       ");
    for(int i = 0; i <= MAP_Y + 1; i++) printf("¡á");
    printf("\n\n");
}
void random_make(void)
{
    int rand_x = 0 , rand_y = 0;

    while(map[rand_x][rand_y].type != 0) {
        rand_x = rand() % MAP_X + 1;
        rand_y = rand() % MAP_Y + 1;
    }
    map[rand_x][rand_y].type = 3;
}

void map_setting(void)
{
    for(int i = 0; i <= MAP_X + 1; i++)
    {
        if(i == 0 || i == MAP_X + 1) for(int j = 0; j <= MAP_Y + 1; j++) map[i][j].type = -1;
        else {
            map[i][0].type = map[i][MAP_Y+1].type = -1;
            for(int j = 1; j <= MAP_Y; j++) map[i][j].type = 0;
        }
    }

    map[5][5].type = 2;
    map[6][5].type = map[6][4].type = 1;
    map[5][5].direction = DOWN;
    map[6][5].direction = LEFT;
    map[6][4].direction = LEFT;

    random_make();

    head.length = 3;
    head.x = head.y = 5;

    print_map();
}

void print_map(void)
{
    system("cls");
    printf("\n\n");
    for(int i = 0; i <= MAP_X + 1; i++)
    {
        printf("\n       ");
        for(int j = 0; j <= MAP_Y + 1; j++)
        {
            if(map[i][j].type == -1) printf("¡á");
            else if(map[i][j].type == 0) printf("  ");
            else if(map[i][j].type == 1) printf("¡Û");
            else if(map[i][j].type == 2) printf("¡Ý");
            else if(map[i][j].type == 3) printf("£À");
        }
    }
}

int gameover(void)
{
    if(map[head.x][head.y].type == -1 || map[head.x][head.y].type == 1) return 1;
    else return 0;
}


int oppose(int dir)
{
    if(dir == UP) return DOWN;
    else if(dir == DOWN) return UP;
    else if(dir == LEFT) return RIGHT;
    else if(dir == RIGHT) return LEFT;
    else return 0;
}
int move_dir(int *x, int *y, char dir)
{
    if(dir == UP) *x -=1;
    else if(dir == DOWN) *x +=1;
    else if(dir == LEFT) *y -=1;
    else if(dir == RIGHT) *y +=1;
    else return 1;

    return 0;
}
void move(char dir)
{
    if(map[head.x][head.y].direction == dir) return;
    if(move_dir(&head.x, &head.y, dir)) return;

    int x = head.x, y = head.y;

    if(map[x][y].type == 3){
        head.length ++;
        map[x][y].type = 0;
        random_make();
    }

    if(map[x][y].type != 0) return;

    map[x][y].direction = oppose(dir);

    map[x][y].type = 2;
    move_dir(&x, &y, map[x][y].direction);
    map[x][y].type = 1;
    for(int i = 1; i <=head.length - 1; i++) move_dir(&x, &y, map[x][y].direction);
    map[x][y].direction = 0;
    map[x][y].type = 0;

}
void game(void)
{
    char dir;
    if(kbhit()) dir = getch();
    else dir = oppose(map[head.x][head.y].direction);

    move(dir);
}
//¡á ¡à £À ¡Þ ¡ß ¡Ý ¡Û
