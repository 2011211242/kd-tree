/****************************************
* File Name: utils.cpp
* Created Time: 2017-07-22 22:14:29
* Author: yanxianlong                        
* Mail: xianlongyan@foxmail.com              
* Github: https://github.com/2011211242       
****************************************/

#include <utils.h>
#include <vector>
#include <assert.h>
#include <algorithm>
#include <cmath>
#include <cstdint>

double distOfPoint2cube(const std::vector<double> &p,
        const std::vector<double> &l, const std::vector<double> &h)
{
    double dist = 0.0f;
    assert(p.size() == l.size() && l.size() == h.size());

    for(uint32_t i = 0; i < l.size(); i++)
    {
        int sign = !(p[i] >= l[i] && p[i] <= h[i]);
        double tmp = std::min(std::abs(p[i] - l[i]), std::abs(p[i] - h[i]));
        dist += sign * tmp * tmp;
    }
    return sqrt(dist);
}

