#pragma once

#include <map>
#include <vector>


class ShoppingCart
{

private:
	std::map<int, int> get_checkout_sequence_by_most_episodes(std::vector<int> &shopping_list);
	bool check_exist_bunch_5_episodes_and_bunch_3_episodes(std::map<int, int> &checkout_sequence);
	void replace_bunch_5_episodes_and_bunch_3_episodes_to_bunch_4_episodes(std::map<int, int> &checkout_sequence);
	std::map<int, int> produce_more_bunch_4_episodes_sequences(std::map<int, int> &checkout_sequence);
	std::map<int, int> get_cheapest_checkout_sequence(std::vector<int> &shopping_list);

public:
	int checkout(std::vector<int> &shopping_list);

	ShoppingCart() = default;
	~ShoppingCart() = default;
};
