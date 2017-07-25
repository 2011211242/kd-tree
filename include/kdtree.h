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


namespace kdtree{
    class node{
        public:
            void static init(const uint32_t leaf_size);
            node(std::vector<uint32_t> _idx) :idx(_idx){}

            void search_knear(uint32_t id, const std::vector<uint32_t> &point,
                    uint32_t k, std::vector<std::vector<uint32_t>> &res);

            ~node();
            void split();

        private:
            std::vector<uint32_t> idx;
            node *left, *right;
            static std::vector<std::vector<double>> data_set;
            static uint32_t leaf_size;
    };

    class KDTree{
        public:
            KDTree(const uint32_t leaf_size);
            ~KDTree();

            void search_knear(const std::vector<std::vector<uint32_t>> &points,
                    uint32_t k, std::vector<std::vector<uint32_t>> &res);

        private:
            node * root;
    };
}

#endif

