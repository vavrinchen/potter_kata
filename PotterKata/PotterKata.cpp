#include "PotterKata.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <limits>

using namespace std;

const int PRICE_SINGLE_BOOK = 100;
const int BUNCH_PERCENT_OFF_25 = 5;
const int BUNCH_PERCENT_OFF_20 = 4;
const int BUNCH_PERCENT_OFF_10 = 3;



int ShoppingCart::get_num_of_left_book(vector<int> shopping_list)
{
	int num_of_left_book = 0;
	for (int i = 0; i<shopping_list.size(); i++)
	{
		num_of_left_book += shopping_list[i];
	}
	return num_of_left_book;
}

map<int, int> ShoppingCart::get_checkout_sequence_by_most_episodes(vector<int> shopping_list)
{
	map<int, int> checkout_sequence;
	while (get_num_of_left_book(shopping_list)>0)
	{
		int num_of_most_episodes = 0, num_bunch = 0, min_book_num = INT_MAX;
		for (int i = 0; i < shopping_list.size(); i++)
		{
			if (shopping_list[i] > 0)
			{
				num_of_most_episodes++;
				min_book_num = min(shopping_list[i], min_book_num);
				shopping_list[i] -= min_book_num;
			}
		}

		num_bunch = min_book_num;
		checkout_sequence[num_of_most_episodes] = num_bunch;
	}

	return checkout_sequence;
}


bool ShoppingCart::check_exist_bunch_25_percent_and_bunch_10_percent(map<int, int> &checkout_sequence)
{
	if (checkout_sequence[BUNCH_PERCENT_OFF_25] > 0 && checkout_sequence[BUNCH_PERCENT_OFF_10] > 0)
	{
		return true;
	}

	return false;
}

void ShoppingCart::replace_bunch_25_percent_and_bunch_10_percent_to_bunch_20_percent(map<int, int> &checkout_sequence)
{
	int add_percent_off_20_bunch_num = 0;

	add_percent_off_20_bunch_num = min(checkout_sequence[BUNCH_PERCENT_OFF_25], checkout_sequence[BUNCH_PERCENT_OFF_10]);
	checkout_sequence[BUNCH_PERCENT_OFF_25] -= add_percent_off_20_bunch_num;
	checkout_sequence[BUNCH_PERCENT_OFF_10] -= add_percent_off_20_bunch_num;
	checkout_sequence[BUNCH_PERCENT_OFF_20] += add_percent_off_20_bunch_num * 2;
}


map<int, int> ShoppingCart::produce_more_20_percent_off_sequences(map<int, int> &checkout_sequence)
{
	if (check_exist_bunch_25_percent_and_bunch_10_percent(checkout_sequence))
	{
		replace_bunch_25_percent_and_bunch_10_percent_to_bunch_20_percent(checkout_sequence);
	}

	return checkout_sequence;
}

map<int, int> ShoppingCart::get_cheapest_checkout_sequence(vector<int> shopping_list)
{
	map<int, int> checkout_sequence = get_checkout_sequence_by_most_episodes(shopping_list);
	map<int, int> cheapest_sequence = produce_more_20_percent_off_sequences(checkout_sequence);
	return cheapest_sequence;
}

int ShoppingCart::checkout(vector<int> shopping_list)
{

	float discount_type[] = { 1, 0.95, 0.9, 0.8, 0.75 };
	float amount = 0;

	map<int, int> cheapest_sequence = get_cheapest_checkout_sequence(shopping_list);

	for (map<int, int>::iterator it = cheapest_sequence.begin(); it != cheapest_sequence.end(); ++it)
	{
		amount += PRICE_SINGLE_BOOK * it->first* it->second * discount_type[it->first - 1];
	}

	return amount;

}
