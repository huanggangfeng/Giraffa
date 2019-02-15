#include <time.h>
#include <istream>
#include <string>
using namespace std;


int main()
{
#if 0
	char buffer[80];
	// YYYY-MM-DDThh:mm:ssZ例如，2017-03-23T06:59:55Z
	time_t rawtime;
	time(&rawtime);
	struct tm *timeinfo = localtime(&rawtime);
	timeinfo->tm_hour -= 3;

	strftime(buffer, 80, "%Y-%m-%dT%H:%M:%SZ", timeinfo);
	//puts(buffer);
	//
	//
	auto now =std::time(nullptr);
	const auto uct_now = *std::gmtime(std::addressof(now));
	struct tm start_time;
	uct_now.tm_hour -= 3;
	std::cout <<  *std:
	
#endif 
	int a =2;
	while(a--)
	{
			cout << "a:" << a << "\n";
	}
	return 0;
}


