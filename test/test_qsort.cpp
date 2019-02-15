#include <vector>
#include <iostream>
#include <algorithm>

int partition(std::vector<int> &v, int start, int end) {
	int flag = v[start];
	int s1 = start, s2 = end;
	int temp;
	while(s1 < s2) {
		while (v[s2] >= flag && s2 > s1) {
			s2--;
		}
		// Swap
		// temp = v[s2];
		// v[s2] = v[s1];
		// v[s1] = temp;
		std::swap(v[s1], v[s2]);

		while (v[s1] <= flag && s2 > s1) {
			s1++;
		}
		// Swap
		std::swap(v[s1], v[s2]);
		// temp = v[s2];
		// v[s2] = v[s1];
		// v[s1] = temp;
	}

	std::cout << "Start is: " << start << " End is: " << end << '\n';
	std::cout << "after split, s1 is " << s1 << '\n';
	for (auto &e: v)
		std::cout << e << '\t';
	std::cout << '\n';
	return s1;
}

void qucik_sort(std::vector<int> &v, int start, int end) {
	if (start >= end)
		return;
	int partition_point = partition(v, start, end);
	qucik_sort(v, start, partition_point - 1);
	qucik_sort(v, partition_point + 1, end);
}

int main(int argc, char const *argv[]) {
	std::vector<int> v;
	srand(time(NULL));
	for (size_t i = 0; i < 10; i++) {
		v.emplace_back(random()%100);
	}

	for (auto &e : v)
		std::cout << e << '\t';
	std::cout << '\n';

  qucik_sort(v, 0, v.size()-1);

	for (auto &e : v)
		std::cout << e << '\t';
	std::cout << '\n';
	return 0;
}
