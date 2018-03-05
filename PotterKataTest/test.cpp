#include "pch.h"
#include "../PotterKata/PotterKata.h"
#include <gtest/gtest.h>
#include <stdlib.h>
#include <vector>


#define COUNT_OF(array) (sizeof(array) / sizeof(array[0]))


TEST(PRICE, no_book_get_0) {
	ShoppingCart sc;
	int books[] = { 0, 0, 0, 0, 0 };
	std::vector<int> shopping_list(books, books + sizeof(books) / sizeof(int));
	EXPECT_EQ(0, sc.checkout(shopping_list));
}


TEST(PRICE, one_book_get_100) {
	ShoppingCart sc;
	int books[] = { 0, 0, 0, 0, 1 };
	std::vector<int> shopping_list(books, books + sizeof(books) / sizeof(int));
	EXPECT_EQ(100, sc.checkout(shopping_list));
}

TEST(PRICE, two_diff_books_get_190) {
	ShoppingCart sc;
	int books[] = { 1, 1, 0, 0, 0 };
	std::vector<int> shopping_list(books, books + sizeof(books) / sizeof(int));
	EXPECT_EQ(190, sc.checkout(shopping_list));
}

TEST(PRICE, three_diff_books_get_270) {
	ShoppingCart sc;
	int books[] = { 1, 1, 1, 0, 0 };
	std::vector<int> shopping_list(books, books + sizeof(books) / sizeof(int));
	EXPECT_EQ(270, sc.checkout(shopping_list));
}

TEST(PRICE, four_diff_books_get_320) {
	ShoppingCart sc;
	int books[] = { 1, 1, 1, 1, 0 };
	std::vector<int> shopping_list(books, books + sizeof(books) / sizeof(int));
	EXPECT_EQ(320, sc.checkout(shopping_list));
}

TEST(PRICE, five_diff_books_get_375) {
	ShoppingCart sc;
	int books[] = { 1, 1, 1, 1, 1 };
	std::vector<int> shopping_list(books, books + sizeof(books) / sizeof(int));
	EXPECT_EQ(375, sc.checkout(shopping_list));
}

TEST(PRICE, three_diff_books_and_one_book_get_370) {
	ShoppingCart sc;
	int books[] = { 1, 1, 2, 0, 0 };
	std::vector<int> shopping_list(books, books + sizeof(books) / sizeof(int));
	EXPECT_EQ(370, sc.checkout(shopping_list));
}

TEST(PRICE, three_diff_books_and_two_diff_books_get_460) {
	ShoppingCart sc;
	int books[] = { 1, 2, 2, 0, 0 };
	std::vector<int> shopping_list(books, books + sizeof(books) / sizeof(int));
	EXPECT_EQ(460, sc.checkout(shopping_list));
}

TEST(PRICE, five_diff_books_and_three_same_books_get_675) {
	ShoppingCart sc;
	int books[] = { 1, 1, 1, 1, 4 };
	std::vector<int> shopping_list(books, books + sizeof(books) / sizeof(int));
	EXPECT_EQ(675, sc.checkout(shopping_list));
}

TEST(PRICE, two_bunch_four_diff_books_get_640) {
	ShoppingCart sc;
	int books[] = { 1, 1, 2, 2, 2 };
	std::vector<int> shopping_list(books, books + sizeof(books) / sizeof(int));
	EXPECT_EQ(640, sc.checkout(shopping_list));
}

TEST(PRICE, five_diff_books_and_four_diff_books_get_695) {
	ShoppingCart sc;
	int books[] = { 1, 2, 2, 2, 2 };
	std::vector<int> shopping_list(books, books + sizeof(books) / sizeof(int));
	EXPECT_EQ(695, sc.checkout(shopping_list));
}

TEST(PRICE, two_bunch_four_diff_books_and_one_book_get_740) {
	ShoppingCart sc;
	int books[] = { 1, 1, 2, 2, 3 };
	std::vector<int> shopping_list(books, books + sizeof(books) / sizeof(int));
	EXPECT_EQ(740, sc.checkout(shopping_list));
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}