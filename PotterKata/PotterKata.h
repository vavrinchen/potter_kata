#include <map>
#include <vector>
using namespace std;

class ShoppingCart
{
private:
	int get_num_of_left_book(vector<int> shopping_list);
	map<int, int> get_checkout_sequence_by_most_episodes(vector<int> shopping_list);
	bool check_exist_bunch_25_percent_and_bunch_10_percent(map<int, int> &checkout_sequence);
	void replace_bunch_25_percent_and_bunch_10_percent_to_bunch_20_percent(map<int, int> &checkout_sequence);
	map<int, int> produce_more_20_percent_off_sequences(map<int, int> &checkout_sequence);
	map<int, int> get_cheapest_checkout_sequence(vector<int> shopping_list);

public:
	int checkout(vector<int> shopping_list);

	ShoppingCart() = default;
	~ShoppingCart() = default;
};
#pragma once
