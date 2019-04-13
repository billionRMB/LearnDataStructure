/*************************************************************************
	> File Name: test.cpp
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年04月13日 星期六 18时32分39秒
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define MAX_M 10000
#define MAX_N 1000
#define MAX_k 19

struct Ede{
    int to,next;
}g[MAX_M + 5];
int head[MAX_N + 5],cnt = 0;
int gas[MAX_N + 5][MAX_k + 5] = {0},deep[MAX_N + 5] = {0};
int father[MAX_N + 5] = {0};
int val[MAX_N + 5] = {0};

// 神奇就是自定义了一个地址
// 这个可以和链表一起学
inline void add(int a,int b){
    g[++cnt].to = b;
    g[cnt].next = head[a];
    head[a] = cnt;
}

void dfs1(int fa,int ind){
    father[ind] = fa;
    // 深度优先遍历
    for(int i = 1;i <= MAX_k;i ++){
        gas[ind][i] = gas[gas[ind][i - 1]][i - 1];
    }
    for(int i = head[ind];i;i = g[i].next){
        if(g[i].to == fa)continue;
        int to = g[i].to;
        deep[to] = deep[ind] + 1;
        gas[to][0] = ind;
        dfs1(ind,to);
    }
    return ;
}

int lca(int x,int y){
    if(deep[x] < deep[y])swap(x,y);
    // 跳到对齐
    for(int i = MAX_k;i >= 0;i --){
        if(deep[gas[x][i]] < deep[y])continue;
        x = gas[x][i];
    }
    // 如果y 是ｘ的祖先
    if(x == y)return x;
    for(int i = MAX_k;i >= 0;i --){
        if(gas[x][i]==gas[y][i])continue;
        x = gas[x][i],y = gas[y][i];
    }
    return gas[x][0];
}

int query(int ind){
    int ans = 0;
    for(int i = head[ind];i ;i = g[i].next){
        if(g[i].to == father[ind])continue;
        ans += query(g[i].to);
    }
    ans += val[ind];
    return ans;
}

int main(){
    int n,m,s;
    cin >> n >> m >> s;
    for(int i = 0;i < m;i ++){
        int a,b;
        cin >> a >> b;
        add(a,b);
        add(b,a);
    }
    deep[0] = -1;
    dfs1(0,s);
    for(int i = 0;i < m;i ++){
        int a,b,c,d,temp;
        cin >> a;
        switch(a){
            case 1:
                cin>>b>>c >>d;
                val[b] += d;
                val[c] += d;
                temp = lca(b,c);
                val[temp] -= d;
                val[father[temp]] -= d;
            break;
            case 2:
                cin >> b;
                cout << query(b) << endl;
            break;
        }
    }
    for(int i = 0;i <= n;i ++){
        cout << val[i] << endl;
    }
    return 0;
}
