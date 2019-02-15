#include <map>
#include <istream>
#include<string>
using namespace std;

bool need_decode(const char *in)
{
	// number
	if (*in >= '0' && *in <= '9')
		return false;

	if (*in >= 'A' && *in <= 'Z' || *in >= 'a' && *in <= 'z')
			return false;

	if (*in == '-' || *in == '_' || *in == '.' || *in == '~' || *in == '&')
			return false;

	return true;
}

static std::string
url_encode(const char *in)
{
		const char *s;
		char *d;
		int out_len = 0;
		char *out;

		for (s = in; *s != '\0'; s++) {
				//if (*s < 33 || *s > 126 || *s == '%' || *s == '=')
				//if ((*s >= 33 && *s <= 126) || *s == '-' || *s == '_' || *s == '.' || *s == '~')
				if (need_decode(s))
						out_len += 3;
				else
						out_len++;
		}

		out = (char *)malloc(out_len + 1);
		if (out == NULL)
				return (NULL);

		for (s = in, d = out; *s != '\0'; s++) {
				/* encode any non-printable ASCII character or '%' or '=' */
				//if ((*s >= 33 && *s <= 126) || *s == '-' || *s == '_' || *s == '.' || *s == '~') {
				if (need_decode(s))
				{
						/* URL encoding is '%' followed by two hex digits */
						*d++ = '%';
						*d++ = "0123456789ABCDEF"[0x0f & (*s >> 4)];
						*d++ = "0123456789ABCDEF"[0x0f & *s];
				} else {
						*d++ = *s;
				}
		}
		*d = '\0';
		std::string str(out);
		free(out);
		return str;
}

int main()
{
	std::map<std::string, std::string> mymap = {
			{"bbb","123"},
			{"ddd","456"},
			{"aaa","555"}
	};

	std::string s;
	for (auto it = mymap.begin(); it != mymap.end(); ++it)
	{
		s += "&" + it->first + "=" + it->second;
//		cout << it->first << ":" << it->second;
	}

	cout << "s*************:" << endl << s << endl;
	string result = url_encode(s.c_str());
	cout << result << endl;


	string input =  "GET&/*& AccessKeyId=TestId&Action=QueryMetricList&Dimensions={instanceId:'i-abcdefgh123456'}&Format=JSON&Metric=cpu_idle&SignatureNonce=aeb03861-611f-43c6-9c07-b752fad3dc06";
	string output = url_encode(input.c_str());
	cout << input<< endl;
	cout << output<< endl;
	cout << url_encode("/")<< endl;
	return 0;
}
