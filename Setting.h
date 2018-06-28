#ifndef SETTING_H_INCLUDED
#define SETTING_H_INCLUDED

#define MAP_X 20
#define MAP_Y 30
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

struct Block
{
    char direction; // 상하좌우 1234
    int type; // 0 : 빈공간, 1 : 스네이크 몸통 , 2 : 스네이크 헤드, 3: : 아이템, -1 : 막힌 공간
} map[MAP_X + 3][MAP_Y + 3];

struct Snake_head
{
    int x, y;
    int length;
} head;

#endif // SETTING_H_INCLUDED
