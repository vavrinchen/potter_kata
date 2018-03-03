#include "pch.h"
#include "../PotterKata/PotterKata.h"
#include <gtest/gtest.h>
#include <stdlib.h>
#include <vector>


#define COUNT_OF(array) (sizeof(array) / sizeof(array[0]))
using namespace std;

TEST(PRICE, no_book_get_0) {
	ShoppingCart sc;
	int books[] = { 0, 0, 0, 0, 0 };
	vector<int> shopping_list(books, books + sizeof(books) / sizeof(int));
	EXPECT_EQ(0, sc.checkout(shopping_list));
}


TEST(PRICE, one_no_discount_get_100) {
	ShoppingCart sc;
	int books[] = { 0, 0, 0, 0, 1 };
	vector<int> shopping_list(books, books + sizeof(books) / sizeof(int));
	EXPECT_EQ(100, sc.checkout(shopping_list));
}

TEST(PRICE, one_5_percent_get_190) {
	ShoppingCart sc;
	int books[] = { 1, 1, 0, 0, 0 };
	vector<int> shopping_list(books, books + sizeof(books) / sizeof(int));
	EXPECT_EQ(190, sc.checkout(shopping_list));
}

TEST(PRICE, one_10_percent_get_270) {
	ShoppingCart sc;
	int books[] = { 1, 1, 1, 0, 0 };
	vector<int> shopping_list(books, books + sizeof(books) / sizeof(int));
	EXPECT_EQ(270, sc.checkout(shopping_list));
}

TEST(PRICE, one_20_percent_get_320) {
	ShoppingCart sc;
	int books[] = { 1, 1, 1, 1, 0 };
	vector<int> shopping_list(books, books + sizeof(books) / sizeof(int));
	EXPECT_EQ(320, sc.checkout(shopping_list));
}

TEST(PRICE, one_25_percent_get_375) {
	ShoppingCart sc;
	int books[] = { 1, 1, 1, 1, 1 };
	vector<int> shopping_list(books, books + sizeof(books) / sizeof(int));
	EXPECT_EQ(375, sc.checkout(shopping_list));
}

TEST(PRICE, one_10_percent_one_no_discount_get_370) {
	ShoppingCart sc;
	int books[] = { 1, 1, 2, 0, 0 };
	vector<int> shopping_list(books, books + sizeof(books) / sizeof(int));
	EXPECT_EQ(370, sc.checkout(shopping_list));
}

TEST(PRICE, one_10_percent_one_5_percent_get_460) {
	ShoppingCart sc;
	int books[] = { 1, 2, 2, 0, 0 };
	vector<int> shopping_list(books, books + sizeof(books) / sizeof(int));
	EXPECT_EQ(460, sc.checkout(shopping_list));
}

TEST(PRICE, one_25_percent_three_no_discount_get_675) {
	ShoppingCart sc;
	int books[] = { 1, 1, 1, 1, 4 };
	vector<int> shopping_list(books, books + sizeof(books) / sizeof(int));
	EXPECT_EQ(675, sc.checkout(shopping_list));
}

TEST(PRICE, two_20_percent_get_640) {
	ShoppingCart sc;
	int books[] = { 1, 1, 2, 2, 2 };
	vector<int> shopping_list(books, books + sizeof(books) / sizeof(int));
	EXPECT_EQ(640, sc.checkout(shopping_list));
}

TEST(PRICE, one_20_percent_one_25_percent_get_695) {
	ShoppingCart sc;
	int books[] = { 1, 2, 2, 2, 2 };
	vector<int> shopping_list(books, books + sizeof(books) / sizeof(int));
	EXPECT_EQ(695, sc.checkout(shopping_list));
}

TEST(PRICE, two_20_percent_one_no_discount_get_740) {
	ShoppingCart sc;
	int books[] = { 1, 1, 2, 2, 3 };
	vector<int> shopping_list(books, books + sizeof(books) / sizeof(int));
	EXPECT_EQ(740, sc.checkout(shopping_list));
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}