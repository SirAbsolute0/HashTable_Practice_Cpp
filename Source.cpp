#include <iostream>
#include <cstring>
#include <list>

using namespace std;

// Implementing a hash table 
class hashTable {
private:
	static int const hashGroup = 10;
	list <pair<int, string>> table[hashGroup];

public:
	bool isEmpty();
	int hashFunction(int);
	void insertItem(int, string);
	string searchItem(int);
	void deleteItem(int);
	void printTable();

};

// A quick function to see if the hash table is empty through counting the size of each pair in one index
bool hashTable::isEmpty() {
	int sumSize = 0;
	for (int i = 0; i < hashGroup; i++) {
		sumSize += table[i].size();
	}

	if (!sumSize) {
		return true;
	}
	else {
		return false;
	}
}

// Hash function for the hash table
int hashTable::hashFunction(int key) {
	return (key % 10);
}
// A function to insert new item into the hash table
void hashTable::insertItem(int key, string value) {
	int hashKey = hashFunction(key);
	//auto& cell = table[hashKey];
	auto iter = begin(table[hashKey]);
	bool itemExisted = false;

	for (; iter != end(table[hashKey]); iter++) {
		if (iter->first == key) {
			itemExisted = true;
			iter->second = value;
			cout << "Value exitst and is replaced." << endl;
			break;
		}
	}

	if (!itemExisted) {
		table[hashKey].emplace_back(key, value);
	}


}

// Function to search through the hash table, or specifically getting the column and search the item in the column using the key
string hashTable::searchItem(int key) {
	int hashKey = hashFunction(key);
	auto iter = begin(table[hashKey]);
	string autoAnswer = "Value not found";
	for (; iter != end(table[hashKey]); iter++) {
		if (iter->first == key) {
			return iter->second;
		}
	}
	return autoAnswer;
}

// Function to delete an item from the hash table
void hashTable::deleteItem(int key) {
	int hashKey = hashFunction(key);
	auto iter = begin(table[hashKey]);
	auto& cell = table[hashKey];

	for (; iter != end(table[hashKey]); iter++) {
		if (iter->first == key) {
			cell.erase(iter);
			cout << "The value was found and has been deleted." << endl;
			return;
		}
	}

	cout << "The value was not found.";
}

void hashTable::printTable() {
	for (int i = 0; i < hashGroup; i++) {
		//if (table[i].size() == 0) continue;
		for (auto iter = begin(table[i]); iter != end(table[i]); iter++) {
			cout << "[Info]: " << "Key-" << iter->first << " Value-" << iter->second << endl;
		}
	}
}

int main() {
	hashTable HT;
	if (HT.isEmpty()) {
		cout << "the table is empty." << endl;
	}
	else {
		cout << "wrong.";
	}

	HT.insertItem(000, "A");
	HT.insertItem(111, "B");
	HT.insertItem(222, "C");
	HT.insertItem(333, "D");
	HT.insertItem(444, "E");
	HT.insertItem(555, "F");
	HT.insertItem(666, "G");
	HT.insertItem(777, "H");
	HT.insertItem(888, "I");
	HT.insertItem(999, "J");


	HT.insertItem(212, "C2");
	HT.printTable();
	cout << HT.searchItem(212) << endl;
	HT.deleteItem(212);
	cout << HT.searchItem(212) << endl;

	if (HT.isEmpty()) {
		cout << "the table is empty." << endl;
	}
	else {
		cout << "right.";
	}
}
