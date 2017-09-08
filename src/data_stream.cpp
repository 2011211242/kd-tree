/****************************************
* File Name:                                 
* Created Time: 2017-07-23 21:35:21
* Author: yanxianlong                        
* Mail: xianlongyan@foxmail.com              
* Github: https://github.com/2011211242       
****************************************/

#include <data_stream.h>
#include <iostream>
#include <vector>
#include <assert.h>

namespace kdtree{
    std::vector<uint32_t> read_index(std::string file_name){
        uint32_t size = 0;
        std::ifstream in;
        in.open(file_name, std::ios::binary);
        in.seekg(0, std::ios::end);   
        size = in.tellg() / sizeof(uint32_t);

        uint32_t* buf = new uint32_t[size];
        in.seekg(0, std::ios::beg);
        in.read(reinterpret_cast<char*>(buf), size * sizeof(uint32_t));

        std::vector<uint32_t> idx(size);
        for(uint32_t i = 0; i < size; i++){
            idx[i] = buf[i];
        }

        delete [] buf;
        return idx;
    }

    std::vector<float> read_val(std::string file_name){
        uint32_t size = 0;
        std::ifstream in;
        in.open(file_name, std::ios::binary);
        in.seekg(0, std::ios::end);   

        size = in.tellg() / sizeof(double);
        double* buf = new double[size];

        in.seekg(0, std::ios::beg);
        in.read(reinterpret_cast<char*>(buf), size * sizeof(double));

        std::vector<float> idx(size);
        for(uint32_t i = 0; i < size; i++){
            idx[i] = buf[i];
        }
        delete [] buf;
        return idx;
    }

    std::vector<std::vector<float>> read_data(std::string row_file_name, 
            std::string col_file_name, std::string data_file_name){

        std::vector<uint32_t> row = read_index(row_file_name);
        std::vector<uint32_t> col = read_index(col_file_name);
        std::vector<float> data = read_val(data_file_name);
        assert(row.size() == col.size() && col.size() == data.size());

        uint32_t row_size = 0;
        uint32_t col_size = 0;
        for(uint32_t i = 0; i < row.size(); i++){
            row_size = std::max(row_size, row[i]);
            col_size = std::max(col_size, col[i]);
        }
        std::vector<std::vector<float>> ret(row_size + 1, std::vector<float>(col_size + 1));
        for(uint32_t i = 0; i < row.size(); i++){
            ret[row[i]][col[i]] = data[i];
        }
        return ret;
    }

    void write(int32_t * buf, std::string file_name, uint32_t size){

    }
};
