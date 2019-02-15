#include <string>
#include <iostream>
using namespace std;

int main()
{
//	string s = "{\"BucketName" + ":" + "container_name" + "}";
	string ss = "{\"BucketName\" :   \"your_bucket_name\"}";
			cout << ss << "\n";

	string head = "t4atawtatwat";
	string content = head + "123456789";
	cout << content.substr(head.size(), string::npos);
	return 0;
}
