//10X9棋盘中马走迷宫问题
#include <iostream>
using namespace std;
#include <string>

string chess_manual_fun2[11];
bool vis_fun2[11][10];
char ch_fun2 = 'a';
bool inChessManual(int x, int y) {
    return x >= 0 && x < 10 && y >= 0 && y < 9;
}
bool chessManual(int x, int y) {
    if(chess_manual_fun2[x][y] == 'T') {vis_fun2[x][y] = 1; return true;}
    vis_fun2[x][y] = 1;
    if(chess_manual_fun2[x][y] != 'S') {chess_manual_fun2[x][y]= ch_fun2++;}
    int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int dir2[8][2] = {{-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {-1, 2}, {1, 2}};
    for(int i = 0; i < 4; i++) {
        if(inChessManual(x+dir[i][0], y+dir[i][1]) && chess_manual_fun2[x+dir[i][0]][y+dir[i][1]] != '#') {
            for(int j = 2*i; j < 2*i+2; j++) {
                if(inChessManual(x+dir2[j][0], y+dir2[j][1]) && !vis_fun2[x+dir2[j][0]][y+dir2[j][1]] &&           chess_manual_fun2[x+dir2[j][0]][y+dir2[j][1]] != '#') {
                    if(chessManual(x+dir2[j][0], y+dir2[j][1])) return true;
                }
            }
        }
    }
    vis_fun2[x][y] = 0;
    chess_manual_fun2[x][y] = '.';
    ch_fun2--;
    return 0;
}
void fun2() { 
    for(int i = 0; i < 10; i++) {cin >> chess_manual_fun2[i];}
    int x, y;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 9; j++) {
            if(chess_manual_fun2[i][j] == 'S') {x = i, y = j;}
        }
    }
    if(chessManual(x, y)) {cout << "YES" << endl;}
    else {cout << "NO" << endl;}
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 9; j++) {
            cout << chess_manual_fun2[i][j];
        } cout << endl;
    }
}

int main() {
    fun2();
    system("pause");
    return 0;
}
