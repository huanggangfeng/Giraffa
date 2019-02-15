#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>


using namespace std;
class object_stream
{
public:
	object_stream(int len);
	void write(void *buff, size_t len);
	void output_vec();
private:
	std::string local_buf;
	size_t pos;
};

object_stream::object_stream(int len):
		pos(0)
{
		local_buf.reserve(len);
		std::cout << "Constructure:" << local_buf.size() << endl;
}

void
object_stream::write(void * buff, size_t len)
{
	local_buf.append((char *)buff, len);
}

void
object_stream::output_vec()
{
	std::cout << "cout all vector:" << local_buf.data();
	std::cout << "position:" << pos << "\n";
}


int main()
{
	char test1[]="123456789";
	char test2[]="abcdefg";
	object_stream stream(200);
	stream.write(test1, sizeof(test2));
	stream.write(test2, sizeof(test2));
	stream.output_vec();

	std::vector<int> v;
	for (size_t i = 0; i < 10; i++) {
		v.emplace_back(i);
	}

	std::vector<int> v1(v.begin()+1, v.begin()+5);
	std::vector<int> v2(v.begin()+5, v.begin()+9);
	for (auto &e: v1)
		std::cout << e << ' ';
	std::cout  << '\n';
	for (auto &e: v2)
		std::cout << e << ' ';

	std::cout << "\nv1 size: " << v1.size() << '\n';
	std::cout << "v2 size: " << v2.size() << '\n';
}
