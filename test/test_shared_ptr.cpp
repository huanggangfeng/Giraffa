#include <iostream>
#include <memory>
#include <string>

using namespace std;
const static int MAX_STREAM_SIZE = 100;

class stream {
public:
	stream() {}
	virtual ~stream() {}
	virtual size_t write(void *buff, size_t len) = 0;
	virtual void print_buff() {};
private:
	stream(const stream &);
	stream& operator = (const stream &);
};

class data_stream : public stream {
private:
	string local_buff;
public:
	data_stream () {};
	virtual ~data_stream (){};
	size_t write(void *buff, size_t len) {
		std::cout << "data_stream write\n";
		local_buff.append((char*)buff, len);
		return len;
	}
	virtual void print_buff() {
		std::cout << "Buffer:" << local_buff << endl;
	}
};

class checksum_filter: public stream {
public:
	checksum_filter (stream &input_stream) :s(input_stream) {}
	virtual ~checksum_filter () {};
	size_t write(void *buff, size_t len) {
		std::cout << "checksum_filter write\n";
		s.write(buff, len);
		return len;
	}
	virtual void print_buff() {
		// std::cout << "Buffer:" << local_buff << endl;
	}
private:
	stream &s;
};

class encrypt_filter: public stream {
public:
	encrypt_filter (stream &input_stream):s(input_stream) {}
	virtual ~encrypt_filter () {};
	size_t write(void *buff, size_t len) {
		std::cout << "encrypt_filter write\n";
		s.write(buff, len);
		return len;
	}
	virtual void print_buff() {
		// std::cout << "Buffer:" << local_buff << endl;
	}
private:
	stream &s;
};

class compress_filter: public stream {
public:
	compress_filter (stream &input_stream) : s(input_stream) {}
	virtual ~compress_filter () {};
	size_t write(void *buff, size_t len) {
		std::cout << "compress_filter write\n";
		s.write(buff, len);
		return len;
	}
private:
	stream &s;
};

int main()
{
	data_stream data;
	stream *p_stream = &data;
	shared_ptr<checksum_filter> ck_filter;
	shared_ptr<encrypt_filter> enc_filter;
	shared_ptr<compress_filter> cp_filter;

	ck_filter.reset(new checksum_filter(*p_stream));
	p_stream = ck_filter.get();
	enc_filter.reset(new encrypt_filter(*p_stream));
	p_stream = enc_filter.get();
	cp_filter.reset(new compress_filter(*p_stream));
	p_stream = cp_filter.get();
	string input_str("hello world!");
	p_stream->write((char *)input_str.c_str(), input_str.size());
	data.print_buff();

	return 0;
}
