#ifndef KD_TREE
#define KD_TREE
/****************************************
* File Name:                                 
* Created Time: 2017-07-25 21:21:35
* Author: yanxianlong                        
* Mail: xianlongyan@foxmail.com              
* Github: https://github.com/2011211242       
****************************************/


#include <cstdint>
#include <vector>
#include <thread>
#include <queue>

using std::vector;
using std::thread;
using std::queue;

namespace kdtree{
    struct kdres{
        double dist;
        unsigned int idx;
    };

    class node{
        public:
            node(node * father, std::vector<uint32_t> idx, uint32_t leaf_size);
            void split();
        private:
            std::vector<uint32_t> idx;
            node *left, *right, *father;
            uint32_t leaf_size;
    };

    void split();
    class KDTree{
        public:
            KDTree(const uint32_t leaf_size);
            KDTree(const vector<vector<float>> &data, const uint32_t leaf_size, uint32_t n_jobs=4);

            ~KDTree();
            vector<kdres>  search_knear(uint32_t k);
            const vector<vector<float>> & input;

        private:
            node * root;
    };
}

#endif

