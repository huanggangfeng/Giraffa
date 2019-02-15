#include <iostream>
#include <cstdint>

using namespace std;

typedef struct btree_key {
	uint64_t key[2];
} btree_key_t;

struct b_flag {
	uint8_t flags: 3;
	uint8_t ignore: 5;
};


struct sbt_entry {
	btree_key_t key;
	struct b_flag flags;
	uint32_t size_out;
	char buf[];
};


int main()
{
	struct sbt_entry test;
//	char buff[];
	std::cout << "Size of struct stb entry:" << sizeof(struct sbt_entry) << endl;
	std::cout << "Size of struct 1:" << sizeof(btree_key_t) << endl;
	std::cout << "Size of struct 2:" << sizeof(struct b_flag) << endl;
	std::cout << "Size of struct 2:" << sizeof(uint32_t) << endl;
//	std::cout << "Size of struct 2:" << sizeof(buff) << endl;
	std::cout << "Size of struct 2:" << sizeof(test.buf) << endl;
}
	
