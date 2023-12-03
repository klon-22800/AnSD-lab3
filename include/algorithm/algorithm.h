#pragma once
#include<iostream>
#include <random>
#include <string>
#include <fstream>

using namespace std; 
namespace alg {
	class Drink {
	private:
		string _name;
		double _price;
		double _volume;
		double _abv;
	public:
		Drink() {
			_name = "";
			_price = 0;
			_volume = 0;
			_abv = 0;
		}
		Drink(string name, double price, double volume, double abv) {
			_name = name;
			_price = price;
			_volume = volume;
			_abv = abv;
		}
		string get_name() const {
			return _name;
		}
		double get_price() const {
			return _price;
		}
		double get_volume() const {
			return _volume;
		}
		double get_abv() const {
			return _abv;
		}
		double alc_per_price() const {
			double alc = _abv * _volume;
			return alc / _price;
		}

	};
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
	template<typename T>
	stats bubble_sort(std::vector<T>& data) {
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
	template<typename T>
	stats bubble_sort_diap(std::vector<T>& data, size_t min, size_t max) {
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

	template<typename T>
	stats shell_sort(std::vector<T>& data) {
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
	template<typename T>
	stats shell_sort_diap(std::vector<T>& data, size_t min, size_t max) {
		stats stat;
		int n = max - min;
		for (int s = n / 2; s > 0; s /= 2) {
			for (int i = s; i < max; ++i) {
				stat.comparison_count += 1;
				for (int j = i - s + min; (j >= min) && (j <= max) && (data[j] > data[j + s]); j -= s) {
					stat.copy_count += 1;
					std::swap(data[j], data[j + s]);
				}
			}
		}
		return stat;
	}

	template<typename T>
	void heapify(std::vector<T>& arr, int n, int i, stats& stat) {
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

	template<typename T>
	stats heap_sort(std::vector<T>& arr) {
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

	template<typename T>
	void heapify_diap(vector<T>& arr, int n, int i, size_t min) {
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

	template<typename T>
	void heap_sort_diap(vector<T>& arr, size_t min, size_t max) {
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
			cout << "iteration: " << i << endl;
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

	vector<stats> get_full_stat(int sort_choice) {
		vector<stats> stat;
		for (int i = 1; i < 11; i++) {
			stat.push_back(get_stat(i * 1000, 100, sort_choice));
			cout << "len: " << i*1000 << endl;
		}
		cout << "len: " << 25000 << endl;
		stat.push_back(get_stat(25000, 100, sort_choice));
		cout << "len: " << 50000 << endl;
		stat.push_back(get_stat(50000, 100, sort_choice));
		cout << "len: " << 100000 << endl;
		stat.push_back(get_stat(100000, 100, sort_choice));
		return stat;
	}
	void write_stat_file(vector<stats> stat) {
		ofstream fout;
		fout.open("C:\\Users\\Andrew Saydashev\\Desktop\\AnSD-lab3\\stat_inv_heap.txt");
		for (int i = 0; i < stat.size(); i++) {
			fout << stat[i].comparison_count << " " << stat[i].copy_count << endl;
		}
		fout.close();
		return;
	}

	template<typename T>
	std::ostream& operator << (std::ostream& os, const std::vector<T> a)
	{
		cout << "{ ";
		for (int i = 0; i < a.size(); i++) {
			if (i < a.size() - 1)
				cout << a[i] << ", ";
			else {
				cout << a[i] << " }";
			}
		}
		return os;
	}

	bool operator<(const std::string& lhs, const std::string& rhs) {
		return lhs.compare(rhs) < 0;
	}
	bool operator>(const std::string& lhs, const std::string& rhs) {
		return lhs.compare(rhs) > 0;
	}

	bool operator<(const Drink& lhs, const Drink& rhs) {
		return lhs.alc_per_price() < rhs.alc_per_price();
	}
	bool operator>(const Drink& lhs, const Drink& rhs) {
		return lhs.alc_per_price() > rhs.alc_per_price();
	}

	std::ostream& operator <<(std::ostream& os, const Drink a) {
		os << a.get_name() << " " << a.get_volume() << "l " << a.get_abv() << "% " << a.get_price() << "r ";
		return os;
	}
	std::ostream& operator <<(std::ostream& os, const stats a) {
		os << "compasion count: " << a.comparison_count<<" " << "copy count: " << a.copy_count;
		return os;
	}
}