#include <list>
#include <unordered_map>
#include <assert.h>
#include <iostream>

using namespace  std;

template <class key_t, class value_t> class LruCache{
	private:

	list<pair<key_t, value_t>> item_list;
	unordered_map<key_t, decltype(item_list.begin())> item_map;
	size_t size;

	void clean(){
		while(item_map.size() > size){

		}
	};

	public:
	
	void put(const key_t &key, const value_t &value){
		auto it = item_map.find(key);
		if (it != item_map.end()){
			auto it2 = it->second;
			item_list.erase(it2);
			item_map.erase(it);
		}
		item_list.push_front(make_pair(key,value));
		item_map.insert(make_pair(key, item_list.begin()));
	};

	bool exists(const key_t &key){
		return item_map.count(key);
	};

	value_t get(const key_t& key){
		assert(exists(key));
                auto it = item_map.find(key);
                item_list.splice(item_list.begin(), item_list, it->second);
		cout << "key found:: " << key << ", value:: " << it->second->second << "\n\n";
		return it->second->second;
	};

	void printCache(){
		cout << "\n\n Cache:: \n\n";
		for(auto it = item_list.begin(); 
			 it != item_list.end();
			 it++){
			cout << it->second << " --> ";
		}
		cout <<"\n\n";
	};
};

int main(){
	LruCache <string, int> cache;

	cache.put("key1", 1);
	cache.put("key2", 2);
	cache.put("key3", 3);

	cache.printCache();

	cache.get("key1");

	cache.printCache();

	cache.get("key2");

	cache.printCache();

	return 0;

}


