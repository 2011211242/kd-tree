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
#include <config.h>
#include <data_stream.h>
#include <stop_watch.h>

using namespace kdtree;

int main(){
    std::vector<double> p = {-1, 0, 1, 2};
    std::vector<double> l = {0, 1, 2, 3};
    std::vector<double> h = {4, 5, 6, 7};

    std::string row_file_name = config::data_dir + std::string("/compressed_row.bin");
    std::string col_file_name = config::data_dir + std::string("/compressed_col.bin");
    std::string data_file_name = config::data_dir + std::string("/compressed_data.bin");

    StopWatch watch;
    watch.Start();

    std::vector<std::vector<double>> data = read_data(row_file_name, 
            col_file_name, data_file_name);
    printf("%.3fs.\n", watch.ElapsedSeconds());
    printf("%lu %lu\n", data.size(), data[0].size());
}
