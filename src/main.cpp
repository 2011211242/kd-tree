/****************************************
* File Name: main.cpp
* Created Time: 2017-07-22 23:10:18
* Author: yanxianlong                        
* Mail: xianlongyan@foxmail.com              
* Github: https://github.com/2011211242       
****************************************/

#include <utils.h>
#include <vector>
#include <cstdio>
using namespace std;

int main(){
    vector<double> p = {-1, 0, 1, 2};
    vector<double> l = {0, 1, 2, 3};
    vector<double> h = {4, 5, 6, 7};
    printf("%.12f\n", distOfPoint2cube(p, l, h));
}
