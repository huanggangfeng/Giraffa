#include <iostream>
#include <vector>

static int MAX_VECTOR_LENGTH = 10;

void print_vec(const std::vector<int> v)
{
	for (auto &e: v)
		std::cout << e << " ";
	std::cout << '\n';
}

void merge(std::vector<int> &v, int start, int middle, int end)
{
	std::vector<int> v1;
	std::vector<int> v2;
	for (int i = start; i <= middle; i++)
		v1.push_back(v[i]);
	for (int i = middle + 1; i <= end; i++)
		v2.push_back(v[i]);

	int i = 0, j = 0;
	int k = start;
	while(i < v1.size() && j < v2.size()) {
		if (v1[i] <= v2[j]) {
			v[k] = v1[i];
			i++;
		} else {
			v[k] = v2[j];
			j++;
		}
		k++;
	}

	while (i < v1.size()) {
		v[k] = v1[i];
		k++;
		i++;
	}

	while (j < v2.size()) {
		v[k] = v2[j];
		k++;
		j++;
	}
}

void merge_sort(std::vector<int> &v, int start, int end) {
	if(start < end) {
		int middle = (start + end)/2;
		merge_sort(v, start, middle);
		merge_sort(v, middle + 1, end);
		merge(v, start, middle, end);
	}
}

int main(int argc, char const *argv[]) {
	std::vector<int> v;
	srand(time(NULL));
	for (size_t i = 0; i < MAX_VECTOR_LENGTH; i++) {
		v.push_back(random()%100);
	}

	print_vec(v);
	merge_sort(v, 0, v.size()-1);
	print_vec(v);
	return 0;
}
