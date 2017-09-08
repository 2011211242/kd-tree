/****************************************
* File Name:                                 
* Created Time: 2017-07-23 21:00:24
* Author: yanxianlong                        
* Mail: xianlongyan@foxmail.com              
* Github: https://github.com/2011211242       
****************************************/
#ifndef DATA_STREAM
#define DATA_STREAM

#include <string>
#include <fstream>
#include <vector>

namespace kdtree{
    std::vector<uint32_t> read_index(std::string file_name);
    std::vector<float> read_val(std::string file_name);

    std::vector<std::vector<float>> read_data(std::string row_file_name, 
            std::string col_file_name, std::string data_file_name);

    void write(int32_t * buf, std::string file_name, uint32_t size);
};
    
#endif
