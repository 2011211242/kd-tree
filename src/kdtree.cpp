/****************************************
* File Name:                                 
* Created Time: 2017-07-25 21:50:08
* Author: yanxianlong                        
* Mail: xianlongyan@foxmail.com              
* Github: https://github.com/2011211242       
****************************************/

#include <kdtree.h>
#include <data_stream.h>
#include <thread>
#include <mutex>
#include <atomic>
#include <condition_variable>
#include <iostream>
using std::mutex;
using std::condition_variable;
using std::condition_variable_any;
using std::cout;
using std::endl;

namespace kdtree{
    static queue <node*> buffer;
    static uint32_t threads_num;

    static mutex lockBuffer;
    volatile bool ArretDemande = false;
    condition_variable_any cndNotifierConsommateurs; //condition variable
    condition_variable_any cndNotifierProducteur;
    condition_variable consume;
    std::atomic<long> interlock;

    void node::split(){
        long element = interlock.fetch_add(1);//【1】
        lockBuffer.lock ();
        printf("111\n");
        while(buffer.size()==10 && ArretDemande ==false){
            cndNotifierProducteur.wait(lockBuffer);//【2】
        }

        if (ArretDemande == true){                   
            lockBuffer.unlock();
            cndNotifierConsommateurs.notify_one ();//【3】
            ArretDemande=true;
            exit(0);
        }

        printf("222\n");
        //buffer.push();
        cout << "Production unlement :" << element << " size :" << buffer.size() << endl;
        lockBuffer.unlock ();
        cndNotifierConsommateurs.notify_one ();
        printf("%u %lu\n", this->leaf_size, this->idx.size());
        printf("333\n");
        ArretDemande=true;
    }


    void split(){
        interlock = 5;
        while(true){
            lockBuffer.lock();
            printf("444\n");
            while(buffer.empty () && ArretDemande==false){                   
                cndNotifierConsommateurs.wait(lockBuffer);
            }

            if (ArretDemande==true && buffer.empty ()){
                lockBuffer.unlock();
                cndNotifierProducteur.notify_one ();
                //lockBuffer.unlock ();
                //cndNotifierProducteur.notify_one ();


                ArretDemande=true;
                printf("break\n");
                break;
            }

            printf("555\n");
            node * root = buffer.front();
            buffer.pop();
            lockBuffer.unlock ();
            cndNotifierProducteur.notify_one ();

            printf("666\n");
            root -> split();
        }
    }



    KDTree::KDTree(const vector<vector<float>> &data, const uint32_t leaf_size, uint32_t n_jobs): input(data){
        vector<uint32_t> ids;
        for(uint32_t i = 0; i < data.size(); i++){
            ids.push_back(i);
        }

        root = new node(NULL, ids, leaf_size);
        threads_num = n_jobs;

        vector<thread> threads(threads_num);
        for(uint32_t i = 0; i < threads_num; i++){
            threads[i] = thread(split);
        }

        buffer.push(root);
        for(uint32_t i = 0; i < threads_num; i++){
            threads[i].join();
        }
    }

    KDTree::~KDTree(){}
        node::node(node * father, std::vector<uint32_t> idx, uint32_t leaf_size){
        this -> father = father;
        this -> idx = idx;
        this -> leaf_size = leaf_size;
    }

}
