#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

void print_vec(std::vector<int> v);
// Using multiset
std::vector<int> find_k_largest_element(int k, std::vector<int> v) {
	std::multiset<int> s{v.begin(), v.begin() +k};
	int i = k;
	while(i < v.size()) {
		if (v[i] > *s.begin()) {
			s.erase(s.begin());
			s.insert(v[i]);
		}
		i++;
	}

	return std::vector<int>(s.begin(),s.end()) ;
}

void heap_adjust(std::vector<int> &v, int position)
{
	int left = position * 2 + 1;
	int right = position * 2 + 2;
	int smallest_positon = position;

	if (left < v.size() && v[position] > v[left])
		smallest_positon = left;

	if (right < v.size() && v[smallest_positon] > v[right])
		smallest_positon = right;

	if (smallest_positon != position) {
		int temp = v[position];
		v[position] = v[smallest_positon];
		v[smallest_positon] = temp;
		heap_adjust(v, smallest_positon);
	}
}

void print_vec(std::vector<int> v)
{
	for (auto &e : v)
		std::cout << e << ' ';
	std::cout << '\n';
}

std::vector<int> find_k_largest_element_heap(int k, std::vector<int> v) {
	std::vector<int> heap(v.begin(), v.begin() + k);
	// std::cout << "find the largetst " << heap.size() << "\n";
	int i = (k-1)/2 + 1;
	for (; i >= 0; i--)
		heap_adjust(heap, i);

	for (i = k; i < v.size(); i++) {
		if (v[i] > heap[0]) {
			heap[0] = v[i];
			heap_adjust(heap, 0);
		}
	}
	return heap;
}

std::vector<int> find_k_largest_element_stl(int k, std::vector<int> v) {
	std::vector<int> heap(v.begin(), v.begin() + k);
	std::make_heap(heap.begin(), heap.end(),
	    [](int first, int second){return first > second? true : false;});

	for (int i = k; i< v.size(); i++) {
		if (v[i] > heap[0]) {
			heap[0] = v[i];
			std::make_heap(heap.begin(), heap.end(),
		    [](int first, int second) {return first > second? true : false;});
		}
	}
	return heap;
}

int main(int argc, char const *argv[]) {
	// std::vector<int> v{82, 70, 84, 11, 72, 32, 80, 5, 7, 32};
	std::vector<int> v;
	srand(time(NULL));
	for (size_t i = 0; i < 10; i++)
		v.push_back(random()%100);
	print_vec(v);

	// Solution 1: using multiset
	std::vector<int> result = find_k_largest_element(5, v);

	std::cout << "\nThe largest k element of solution 1:";
	for(auto &e: result)
		std::cout << e << " ";
	std::cout << "\n";

	//Solution 2: using heap
	result = find_k_largest_element_heap(5, v);

	std::cout << "\nThe largest k element of solution 2:";
	print_vec(result);

	// Solution 3 : Stl algorithm to build heap
	result = find_k_largest_element_stl(5, v);
	std::cout << "\nThe largest k element of solution 3:";
	print_vec(result);
	return 0;
}
