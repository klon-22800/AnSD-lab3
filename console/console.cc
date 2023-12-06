#include<iostream>
#include<algorithm/algorithm.h>

using namespace std;
using namespace alg;

int main(){
	vector<int> a{9, 8, 7, 6, 5, 4, 3, 2, 1};
	vector<int> b{ 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	vector<int> c{ 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	shell_sort_diap(a, 2, 6);
	bubble_sort_diap(b, 2, 6);
	heap_sort_diap(c, 2, 6);
	cout << a<<endl;
	cout << b<<endl;
	cout << c;

	/*vector<int> test = random(-1000, 1000, 1000);
	stats a = shell_sort(test);
	cout << a;
	return 0;*/

}