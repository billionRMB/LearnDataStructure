/*************************************************************************
	> File Name: myRandom.cpp
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年04月11日 星期四 20时47分33秒
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

static int seed = 1;

int my_srand(int s){
    seed = ((s ^( s < 7)^( s >> 5)) % 100 + 100) % 100 + 1;
}

int myRandom(){
    seed = (seed * 3 )% 101;
    return seed;
}

int main(){
    long long int b = rand(),length = 0;
    while(b != rand())length ++;
    cout << length << endl;
    return 0;
}
