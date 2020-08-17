#include<vector>
#include<algorithm>
#include<string>
#include<iostream>


using namespace std;
class MyHashSet {
private:
	int num_buckets = 10000;
	vector<vector<int>> buckets;

	int HashFunc(int key) {
		return key % num_buckets;
	}

public:
	MyHashSet() {
		buckets = vector<vector<int>>(num_buckets, vector<int>());
	}

	void add(int key)
	{
		int hash = HashFunc(key);

		if (find(buckets[hash].begin(), buckets[hash].end(), key) == buckets[hash].end()) {
			buckets[hash].push_back(key);
		}
	}

	void remove(int key) {
		int hash = HashFunc(key);

		vector<int>::iterator it = find(buckets[hash].begin(), buckets[hash].end(), key);
		if (it != buckets[hash].end()) buckets[hash].erase(it);

	}

	bool contains(int key) {
		int hash = HashFunc(key);
		return find(buckets[hash].begin(), buckets[hash].end(), key) != buckets[hash].end();
	}

};
//
//int main() {
//
//	MyHashSet* hashset = new MyHashSet();
//	hashset->add(1);
//	hashset->add(2);
//	cout << hashset->contains(1) << endl;
//	cout << hashset->contains(3) << endl;
//	hashset->add(2);
//	cout << hashset->contains(2) << endl;
//	hashset->remove(2);
//	cout << hashset->contains(2) << endl;
//
//	return 1;
//}