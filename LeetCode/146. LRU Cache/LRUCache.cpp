#include <bits/stdc++.h>
using namespace std;
class LRUCache {
private:
    unordered_map<int, list<int>::iterator> keyMap;
    list<int> cacheQueue;
    int capacity;
public:
    LRUCache(int capacity) : capacity(capacity) {
        // Don't need to do anything special
        // other than initialize the capacity
    }
    
    int get(int key) {
        cout << "get(" << key << ");";
        if (keyMap.count(key) > 0) {
            int val = *keyMap[key];
            cout << " got here" << endl;
            cacheQueue.erase(keyMap[key]);
            cacheQueue.push_front(val);
            keyMap[key] = cacheQueue.begin();
            val = *keyMap[key];
            return val;
        } else {
            cout << "null case" << endl;
            return -1;
        }
    }
    
    void put(int key, int value) {
        cout << "put(" << key << ", " << value << ")" << endl;
        // New key values pushed to front of queue and added to map
        if (!keyMap.count(key)) {
            capacity--;
        } else {
            cacheQueue.erase(keyMap[key]);
        }
        
        cacheQueue.push_front(value);
        keyMap[key] = cacheQueue.begin();
        
        // When capacity is exceeded oldest element removed
        if (capacity < 0) {
            int toRemove = cacheQueue.back();
            cout << "^erasing: " << cacheQueue.back() << "... ";
            keyMap.erase(cacheQueue.back());
            cacheQueue.pop_back();
            if (!keyMap.count(toRemove)) {
                cout << "erased." << endl;
            }
            capacity++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
  LRUCache* obj = new LRUCache(2);
  obj->put(1, 0);
  obj->put(2, 2);
  obj->get(1);
  obj->put(3, 3);
  obj->get(2);
  obj->put(4, 4);
  obj->get(1);
  obj->get(3);
  obj->get(4);
}