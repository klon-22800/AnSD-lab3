#include <gtest/gtest.h>
#include <algorithm/algorithm.h>
using namespace std;
using namespace alg;

TEST(FunctionsTest, bubble_sort) {
	std::vector<int> a{10,9,8,7,6,5,4,3,2,1};
	std::vector<int> c{ 100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1 };
	stats b = bubble_sort(c);
	cout << b.comparison_count << endl;
	cout << b.copy_count<< endl;
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << endl;
	}
}
TEST(FunctionsTest, shell_sort) {
	std::vector<int> a{10,9,8,7,6,5,4,3,2,1};
	std::vector<int> c{ 100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1 };
	stats b = shell_sort(c);
	cout << b.comparison_count << endl;
	cout << b.copy_count;
}
TEST(FunctionsTest, heap_sort) {
	std::vector<int> a{ 10,9,8,7,6,5,4,3,2,1};
	std::vector<int> c{ 100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1 };

	stats stat = heap_sort(c);
	cout << stat.comparison_count << endl;
	cout << stat.copy_count << endl;
}
TEST(FunctionsTest, bubble_sort_diap) {
	std::vector<int> a{ 100,9,8,7,6,5,4,3,2,100 };
	stats b = bubble_sort_diap(a, 1, 8);
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << endl;
	}
}
TEST(FunctionsTest, shell_sort_diap) {
	std::vector<int> a{ 100,9,8,7,6,5,4,3,2,100 };
	std::vector<int> c{ 100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1 };
	stats b = shell_sort_diap(a, 1, 8);
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << endl;
	}
}
TEST(FunctionsTest, heap_sort_diap) {
	std::vector<int> a{ 100,9,8,7,6,5,4,3,2,100 };
	std::vector<int> c{ 100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1 };
	heap_sort_diap(a,1,8);
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << endl;
	}
}
TEST(FunctionTest, vector_generator) {
	std::vector<int> a = random(0, 100, 15);
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << endl;
	}
	heap_sort(a);
	cout << a;
}
TEST(FunctionTest, test_for_bubble_sort_generator) {
	stats res = get_stat(1000, 1, 1);
	cout << res.comparison_count<<endl;
	cout << res.copy_count;
}