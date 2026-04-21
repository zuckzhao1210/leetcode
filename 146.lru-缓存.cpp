// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <list>
#include "commoncppproblem146.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
class LRUCache {
    using iter = std::list<int>::iterator;
public:

    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
    }
    
    int get(int key) {
        if (cache_map.find(key) != cache_map.end()) {
            // 调整链表顺序
            visit(key);
            return cache_map[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache_map.find(key) == cache_map.end()) {
            ++size;
            // 超出容量
            if (size > capacity) {
                int todel = cache_list.front();
                cache_list.pop_front();
                std::unordered_map<int, int>::iterator it = cache_map.find(todel);
                cache_map.erase(it);  
                --size;
            }
            cache_list.push_back(key);
        }
        else {
            visit(key);
        }
        cache_map[key] = value;
    }

    // 访问key，调整链表中的顺序
    void visit(int key) {
        for(iter it = cache_list.begin(); it != cache_list.end(); ++it) {
            if (*it == key) {
                cache_list.erase(it);
                break;
            }
        }
        cache_list.push_back(key);
    }

private:
    int capacity;
    int size;
    std::list<int> cache_list;
    std::unordered_map<int, int> cache_map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

