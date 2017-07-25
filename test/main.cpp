/****************************************
* File Name: main.cpp
* Created Time: 2017-07-25 22:55:23
* Author: yanxianlong                        
* Mail: xianlongyan@foxmail.com              
* Github: https://github.com/2011211242       
****************************************/
#include <ctime>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include "stop_watch.h"

using namespace std;
using namespace kdtree;

const int LENGTH = 200000000;
int main(){
    vector<vector<int>> a(2, vector<int>(LENGTH));
    vector<int *> b(LENGTH);
    

    int * c = new int[LENGTH * 2];
    for(int i = 0; i < LENGTH; i++){
        b[i] = c + i * 2;

        a[0][i] = rand();
        a[1][i] = rand();


        b[i][0] = rand();
        b[i][1] = rand();
    }

    int * d = new int[LENGTH];


    StopWatch watch;

    for(int i = 0; i < LENGTH; i++){
        d[i] = b[i][1] * b[i][0];
    }
    printf("b elapsed %.6f seconds\n", watch.ElapsedSeconds());

    for(int i = 0; i < LENGTH; i++){
        d[i] = a[0][i] * a[1][i];
    }

    printf("a elapsed %.6f seconds\n", watch.ElapsedSeconds());
}
