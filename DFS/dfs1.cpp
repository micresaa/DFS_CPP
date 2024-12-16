//走迷宫
#include <iostream>
using namespace std;
#include <string>

int size_x_fun, size_y_fun;
string maze_fun[110];
bool vis_fun[110][110];
bool inMaze(int x, int y) {
    return x >= 0 && x < size_x_fun && y >= 0 && y < size_y_fun;
}
bool Maze(int x, int y) {
    if(maze_fun[x][y] == 'T') {vis_fun[x][y] = 1; return 1;}
    vis_fun[x][y] = 1;
    if(maze_fun[x][y] != 'S') {maze_fun[x][y] = '+';}
    int up_x = x-1, up_y = y;
    if(inMaze(up_x, up_y) && maze_fun[up_x][up_y] != '*' && !vis_fun[up_x][up_y]) {
        if(Maze(up_x, up_y)) return 1;
    }
    int left_x = x, left_y = y-1;
    if(inMaze(left_x, left_y) && maze_fun[left_x][left_y] != '*' && !vis_fun[left_x][left_y]) {
        if(Maze(left_x, left_y)) return 1;
    }
    int down_x = x+1, down_y = y;
    if(inMaze(down_x, down_y) && maze_fun[down_x][down_y] != '*' && !vis_fun[down_x][down_y]) {
        if(Maze(down_x, down_y)) return 1;
    }
    int right_x = x, right_y = y+1;
    if(inMaze(right_x, right_y) && maze_fun[right_x][right_y] != '*' && !vis_fun[right_x][right_y]) {
        if(Maze(right_x, right_y)) return 1;
    }
    vis_fun[x][y] = 0;
    maze_fun[x][y] = '.';
    return 0;
}
void fun() { 
    cin >> size_x_fun >> size_y_fun;
    for(int i = 0; i < size_x_fun; i++) {cin >> maze_fun[i];}
    int x, y;
    for(int i = 0; i < size_x_fun; i++) {
        for(int j = 0; j < size_y_fun; j++) {
            if(maze_fun[i][j] == 'S') {x = i; y = j;}
        }
    }
    if(Maze(x, y)) {cout << "YES" << endl;}
    else {cout << "NO" << endl;}
    for(int i = 0; i < size_x_fun; i++) {
        for(int j = 0; j < size_y_fun; j++) {
            cout << maze_fun[i][j];
        } cout << endl;
    }
}

int main() {
    fun();
    system("pause");
    return 0;
}
