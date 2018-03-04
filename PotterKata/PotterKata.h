#pragma once

#include <map>
#include <vector>
using namespace std;


class ShoppingCart
{
private:
	map<int, int> get_checkout_sequence_by_most_episodes(vector<int> &shopping_list);
	bool check_exist_bunch_5_episodes_and_bunch_3_episodes(map<int, int> &checkout_sequence);
	void replace_bunch_5_episodes_and_bunch_3_episodes_to_bunch_4_episodes(map<int, int> &checkout_sequence);
	map<int, int> produce_more_bunch_4_episodes_sequences(map<int, int> &checkout_sequence);
	map<int, int> get_cheapest_checkout_sequence(vector<int> &shopping_list);

public:
	int checkout(vector<int> &shopping_list);

	ShoppingCart() = default;
	~ShoppingCart() = default;
};
