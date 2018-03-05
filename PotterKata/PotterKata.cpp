#include "PotterKata.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <limits>


const int PRICE_SINGLE_BOOK = 100;
const int MAX_EPISODE_NUM = 5;

const int BUNCH_THREE_EPISODES = 3;
const int BUNCH_FOUR_EPISODES = 4;
const int BUNCH_FIVE_EPISODES = 5;




std::map<int, int> ShoppingCart::get_checkout_sequence_by_most_episodes(std::vector<int> &shopping_list)
{
	std::map<int, int> checkout_sequence;
	sort(shopping_list.begin(), shopping_list.end());
	int min_book_num = 0;

	for (int i = 0; i < shopping_list.size(); i++)
	{
		if (shopping_list[i] > 0)
		{
			checkout_sequence[MAX_EPISODE_NUM - i] = shopping_list[i] - min_book_num;
			min_book_num = shopping_list[i];
		}
	}
	
	return checkout_sequence;
}


bool ShoppingCart::check_exist_bunch_5_episodes_and_bunch_3_episodes(std::map<int, int> &checkout_sequence)
{
	if (checkout_sequence[BUNCH_FIVE_EPISODES] > 0 && checkout_sequence[BUNCH_THREE_EPISODES] > 0)
	{
		return true;
	}

	return false;
}

void ShoppingCart::replace_bunch_5_episodes_and_bunch_3_episodes_to_bunch_4_episodes(std::map<int, int> &checkout_sequence)
{
	int add_to_bunch_four_num = 0;

	add_to_bunch_four_num = std::min(checkout_sequence[BUNCH_FIVE_EPISODES], checkout_sequence[BUNCH_THREE_EPISODES]);
	checkout_sequence[BUNCH_FIVE_EPISODES] -= add_to_bunch_four_num;
	checkout_sequence[BUNCH_THREE_EPISODES] -= add_to_bunch_four_num;
	checkout_sequence[BUNCH_FOUR_EPISODES] += add_to_bunch_four_num * 2;
}


std::map<int, int> ShoppingCart::produce_more_bunch_4_episodes_sequences(std::map<int, int> &checkout_sequence)
{
	if (check_exist_bunch_5_episodes_and_bunch_3_episodes(checkout_sequence))
	{
		replace_bunch_5_episodes_and_bunch_3_episodes_to_bunch_4_episodes(checkout_sequence);
	}

	return checkout_sequence;
}

std::map<int, int> ShoppingCart::get_cheapest_checkout_sequence(std::vector<int> &shopping_list)
{
	std::map<int, int> checkout_sequence = get_checkout_sequence_by_most_episodes(shopping_list);
	std::map<int, int> cheapest_sequence = produce_more_bunch_4_episodes_sequences(checkout_sequence);
	return cheapest_sequence;
}

float ShoppingCart::get_discount_of_episode(int episode)
{
	float discount_type[] = { 1, 0.95, 0.9, 0.8, 0.75 };
	return discount_type[episode - 1];
}

int ShoppingCart::checkout(std::vector<int> &shopping_list)
{	
	int total_price = 0;

	std::map<int, int> cheapest_sequence = get_cheapest_checkout_sequence(shopping_list);

	for (std::map<int, int>::iterator it = cheapest_sequence.begin(); it != cheapest_sequence.end(); ++it)
	{
		total_price += PRICE_SINGLE_BOOK * it->first* it->second *get_discount_of_episode(it->first);
	}

	return total_price;

}
