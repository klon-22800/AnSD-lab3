#pragma once
#include<iostream>
#include <random>

using namespace std; 
namespace alg {
	struct stats {
		double comparison_count = 0;
		double copy_count = 0;
		stats& operator+=(const stats& rhs) {
			comparison_count += rhs.comparison_count;
			copy_count += rhs.copy_count;
			return *this;
		}
		stats& operator/(const int rhs) {
			comparison_count /= rhs;
			copy_count /= rhs;
			return *this;
		}
	};
	std::vector<int> random(int a, int b, int n) {
		std::vector<int> res;
		std::random_device random_device;
		std::mt19937 generator(random_device()); 
		std::uniform_int_distribution<> distribution(a, b); 
		for (int i = 0; i < n; i++) {
			int x = distribution(generator);
			res.push_back(x);
		}
		return res;
	}
	std::vector<int> ordered_vector(int n) {
		std::vector<int> res;
		for (int i = 0; i < n; i++) {
			res.push_back(i);
		}
		return res;
	}
	std::vector<int> reversed_ordered_vector(int n) {
		std::vector<int> res;
		for (int i = n; i > 0; i--) {
			res.push_back(i);
		}
		return res;
	}
	stats bubble_sort(std::vector<int> &data) {
		stats stat;
		int n = data.size();
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				stat.comparison_count += 1;
				if (data[j] > data[j + 1]) {
					stat.copy_count += 1;
					std::swap(data[j], data[j + 1]);
				}
			}
		}
		return stat;
	}
	stats bubble_sort_diap(std::vector<int> &data, size_t min, size_t max) {
		stats stat;
		for (int i = min; i < max; i++) {
			for (int j = min; j < max; j++) {
				stat.comparison_count += 1;
				if (data[j] > data[j + 1]) {
					stat.copy_count += 1;
					std::swap(data[j], data[j + 1]);
				}
			}
		}
		return stat;
	}
	stats shell_sort(std::vector<int> &data) {
		stats stat;
		int n = data.size();
		for (int s = n / 2; s > 0; s /= 2) {
			for (int i = s; i < n; ++i) {
				stat.comparison_count += 1;
				for (int j = i - s; j >= 0 && data[j] > data[j + s]; j -= s) {
					stat.comparison_count += 1;
					stat.copy_count += 1;
					std::swap(data[j], data[j + s]);
				}
			}
		}
		return stat;
	}
	stats shell_sort_diap(std::vector<int>& data, size_t min, size_t max) {
		stats stat;
		int n = max - min;
		for (int s = n / 2; s > 0; s /= 2) {
			for (int i = s; i < max; ++i) {
				stat.comparison_count += 1;
				for (int j = i - s+min; (j >= min) && (j<=max) && (data[j] > data[j + s]); j -= s) {
					stat.copy_count += 1;
					std::swap(data[j], data[j + s]);
				}
			}
		}
		return stat;
	}
	
	void heapify(std::vector<int>& arr, int n, int i, stats& stat) {
		int largest = i; 
		int left = 2 * i + 1; 
		int right = 2 * i + 2; 

		stat.comparison_count += 1;
		if (left < n && arr[left] > arr[largest]) {
			largest = left;
			stat.copy_count += 1;
		}
		stat.comparison_count += 1;
		if (right < n && arr[right] > arr[largest]) {
			largest = right;
			stat.copy_count += 1;
		}

		if (largest != i) {
			swap(arr[i], arr[largest]);
			stat.copy_count += 1;
			
			heapify(arr, n, largest, stat);
		}
	}

	stats heap_sort(std::vector<int>& arr) {
		int n = arr.size();
		stats stat;
		for (int i = n / 2 - 1; i >= 0; i--)
			heapify(arr, n, i, stat);

		for (int i = n - 1; i > 0; i--) {
			stat.copy_count += 1;
			swap(arr[0], arr[i]);
			heapify(arr, i, 0, stat);
		}
		return stat;
	}

	void heapify_diap(vector<int>& arr, int n, int i, int min) {
		int largest = i;
		int l = 2 * i + 1;
		int r = 2 * i + 2;

		if (l < n && arr[l + min] > arr[largest + min])
			largest = l;

		if (r < n && arr[r + min] > arr[largest + min])
			largest = r;

		if (largest != i) {
			swap(arr[i + min], arr[largest + min]);
			heapify_diap(arr, n, largest, min);
		}
	}
		
	void heap_sort_diap(vector<int>& arr, int min, int max) {
		int n = max - min + 1;

		for (int i = n / 2 - 1; i >= 0; i--) {
			heapify_diap(arr, n, i, min);
		}

		for (int i = max; i > min; i--) {
			swap(arr[min], arr[i]);
			heapify_diap(arr, i - min, 0, min);
		}
	}
	stats get_stat(int vect_len, int trial_count, int sort_choice) {
		stats stat;
		for (int i = 0; i < trial_count; i++) {
			std::vector<int> test = random(-1000, 1000, vect_len);
			switch (sort_choice) {
			case 1:
				stat += bubble_sort(test);
				break;
			case 2:
				stat += shell_sort(test);
				break;
			case 3:
				stat += heap_sort(test);
				break;
			}
		}
		stat = stat / trial_count;
		return stat;
	}
}

template<typename T>
std::ostream& operator << (std::ostream& os, const std::vector<T> a)
{
	cout << "{ ";
	for (int i = 0; i < a.size(); i++) {
		if (i < a.size()-1)
			cout << a[i] << ", ";
		else {
			cout << a[i] << " }";
		}
	}
	return os;
}
