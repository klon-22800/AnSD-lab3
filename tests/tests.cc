#include <gtest/gtest.h>
#include <algorithm/algorithm.h>
using namespace std;
using namespace alg;

TEST(FunctionsTest, sum) {
	int a = 5;
	int b = 7;
	int res = sum(a, b);
	EXPECT_EQ(res, 12);
}