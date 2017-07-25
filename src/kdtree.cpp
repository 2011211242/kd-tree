/****************************************
* File Name:                                 
* Created Time: 2017-07-25 21:50:08
* Author: yanxianlong                        
* Mail: xianlongyan@foxmail.com              
* Github: https://github.com/2011211242       
****************************************/

#include <kdtree.h>
#include <data_stream.h>

namespace kdtree{

    void node::init(const uint32_t leaf_size){

    }

    void node::search_knear(uint32_t id, const std::vector<uint32_t> &point,
            uint32_t k, std::vector<std::vector<uint32_t>> &res){
    }

    node::~node(){

    }

    void node::split(){

    }

    KDTree::KDTree(const uint32_t leaf_size){

    }

    KDTree::~KDTree(){

    }

    void KDTree::search_knear(const std::vector<std::vector<uint32_t>> &points,
            uint32_t k, std::vector<std::vector<uint32_t>> &res){

    }

}
