#include "deck.h"


/**
 * _strcmp - compares two strings
 * @str1: first string to compare
 * @str2: second string to compare
 *
 * Return: 0 if else 1
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
		{
			return (0);
		}
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

/**
 * deck_len - returns length of list
 * @list: head of list
 *
 * Return: length
 */
size_t deck_len(deck_node_t *list)
{
	size_t x = 0;

	while (list)
	{
		x++;
		list = list->next;
	}
	return (x);
}

/**
 * sort_deck - sorts a deck of card
 * @deck: doubly linked list to sort
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *node;
	size_t len;
	deck_node_t *one, *two, *three, *four;

	len = deck_len(*deck);

	if (!deck || !*deck || len < 2)
		return;

	node = *deck;
	while (node)
	{
		if (node->prev && card_value(node) < card_value(node->prev))
		{
			one = node->prev->prev;
			two = node->prev;
			three = node;
			four = node->next;

			two->next = four;
			if (four)
				four->prev = two;
			three->next = two;
			three->prev = one;
			if (one)
				one->next = three;
			else
				*deck = three;
			two->prev = three;
			node = *deck;
			continue;
		}
		else
			node = node->next;
	}
}

/**
 * card_value - returns the value of a card
 * @node: card in a deck
 *
 * Return: value between 1 and 52
 */
int card_value(deck_node_t *node)
{
	char *val[13] = {"Ace", "2", "3", "4", "5", "6",
		"7", "8", "9", "10", "Jack", "Queen", "King"};
	char *cards[4] = {"SPADE", "HEART", "CLUB", "DIAMOND"};
	int i, card_val = 0;

	for (i = 1; i <= 13; i++)
	{
		if (!_strcmp(node->card->value, val[i - 1]))
			card_val = i;
	}

	for (i = 1; i <= 4; i++)
	{
		if (!_strcmp(cards[node->card->kind], cards[i - 1]))
			card_val = card_val + (13 * i);
	}

	return (card_val);
}
