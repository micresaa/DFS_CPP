//计算直系亲属数
#include <iostream>
using namespace std;
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
void fun5() { 
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
