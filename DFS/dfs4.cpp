//求迷宫有多少种解法
#include <iostream>
using namespace std;
#include <string>

int num_fun4 = 0;
int size_x_fun4, size_y_fun4;
string maze_fun4[11];
bool vis_fun4[11][11];
bool inMaze2(int x, int y) {
    return x>=0 && x<size_x_fun4 && y>=0 && y<size_y_fun4 && !vis_fun4[x][y] && maze_fun4[x][y]!='#';
}
void Maze2(int x, int y) {
    if(!inMaze2(x, y)) return;
    if(maze_fun4[x][y] == 'T') {num_fun4++; return;}
    vis_fun4[x][y] = 1;
    Maze2(x-1, y); Maze2(x, y-1);
    Maze2(x+1, y); Maze2(x, y+1);
    vis_fun4[x][y] = 0;
}
void fun4() { 
    cin >> size_x_fun4 >> size_y_fun4;
    for(int i = 0; i < size_x_fun4; i++) {cin >> maze_fun4[i];}
    for(int i = 0; i < size_x_fun4; i++) {
        for(int j = 0; j < size_y_fun4; j++) {
            if(maze_fun4[i][j] == 'S') {
                Maze2(i, j);
                break;
            }
        }
    }
    cout << num_fun4 << endl;
}

int main() {
    fun4();
    system("pause");
    return 0;
}