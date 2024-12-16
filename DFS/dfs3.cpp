//地图中寻找连续区域的个数并求最大连续区域的面积
#include <iostream>
using namespace std;
#include <string>

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
void fun3() { 
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

int main() {
    fun3();
    system("pause");
    return 0;
}