#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        auto hashit = _hashmap.find(key);
        if(hashit != _hashmap.end()){
            auto listit = hashit->second;
            pair<int, int> kv = *listit;
            _list.erase(listit);
            _list.push_front(kv);
            _hashmap[key] = _list.begin();
            return kv.second;
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        auto hashit = _hashmap.find(key);
        if(hashit == _hashmap.end()){
            if(_list.size() >= _capacity){
                _hashmap.erase(_list.back().first);
                _list.pop_back();
            }
            _list.push_front(make_pair(key, value));
            _hashmap[key] = _list.begin();
        }
        else{
            auto listit = hashit->second;
            _list.erase(listit);
            _list.push_front(make_pair(key, value));
            _hashmap[key] = _list.begin();
        }
    }
private:
    size_t _capacity;
    list<pair<int, int>> _list;
    unordered_map<int, list<pair<int, int>>::iterator> _hashmap;
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

