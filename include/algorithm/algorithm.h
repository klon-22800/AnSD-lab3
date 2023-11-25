#pragma once
#include<iostream>
#include <random>

using namespace std; 
namespace alg {
	struct stats {
		size_t comparison_count = 0;
		size_t copy_count = 0;
	};

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
	
	void heapify(std::vector<int>& arr, int n, int i) {
		int largest = i; 
		int left = 2 * i + 1; 
		int right = 2 * i + 2; 

		if (left < n && arr[left] > arr[largest])
			largest = left;

		if (right < n && arr[right] > arr[largest])
			largest = right;

		if (largest != i) {
			swap(arr[i], arr[largest]);
			
			heapify(arr, n, largest);
		}
	}

	
	void heap_sort(std::vector<int>& arr) {
		int n = arr.size();

		for (int i = n / 2 - 1; i >= 0; i--)
			heapify(arr, n, i);

		for (int i = n - 1; i > 0; i--) {
			
			swap(arr[0], arr[i]);
			
			heapify(arr, i, 0);
		}
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

	int sum(const int a, const int b) {
		return a + b;
	}
}
