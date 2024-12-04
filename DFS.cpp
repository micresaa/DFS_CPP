//深度优先搜索(dfs),用递归方法枚举所有可能情况
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
void fun() { //走迷宫
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
void fun2() { //10X9棋谱中马走迷宫
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

int area_fun3;
int size_x_fun3, size_y_fun3;
string map_fun3[101];
bool vis_fun3[101][101];
void Map(int x, int y) {
    if(x<0||y<0||x>=size_x_fun3||y>=size_y_fun3||vis_fun3[x][y]||map_fun3[x][y]=='.') {return;}
    vis_fun3[x][y] = 1;
    area_fun3++;
    Map(x+1, y); Map(x-1, y);
    Map(x, y+1); Map(x, y-1);
}
void fun3() { //地图中寻找连续区域的个数并求最大连续区域的面积
    int num = 0, ans = 0;
    cin >> size_x_fun3 >> size_y_fun3;
    for(int i = 0; i < size_x_fun3; i++) {cin >> map_fun3[i];}
    for(int i = 0; i < size_x_fun3; i++) {
        for(int j = 0; j < size_y_fun3; j++) {
            if(map_fun3[i][j] == '#' && !vis_fun3[i][j]) {
                area_fun3 = 0;
                Map(i, j);
                ans = max(area_fun3, ans);
                num++;
            }
        }
    }
    cout << num <<  " " << ans << endl;
}

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
void fun4() { //求迷宫有多少种解法
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

#include <vector>
vector<int> son_fun5[100001];
bool vis_fun5[100001];
int ans_fun5[100001];
int Family(int a) {
    int son = 0;
    for(int i = 0; i < son_fun5[a].size(); i++) {
        son += Family(son_fun5[a][i]);
    }
    ans_fun5[a] = son;
    return son+1;
}
void fun5() { //计算直系亲属数
    int num, x, y; cin >> num;
    for(int i = 0; i < num-1; i++) {
        cin >> x >> y;
        son_fun5[x].push_back(y);
        vis_fun5[y] = 1;
    }
    for(int i = 1; i <= num; i++) {
        if(!vis_fun5[i]) {
            Family(i);
            break;
        }
    }
    for(int i = 1; i <= num; i++) {
        cout << ans_fun5[i] << endl;
    }
}

int main() {
    fun5();
    system("pause");
    return 0;
}