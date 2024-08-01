/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distonce.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 18:03:21 by gwagner           #+#    #+#             */
/*   Updated: 2024/08/01 18:08:56 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*get_next_min(t_list **stack)
{
	t_list	*head;
	t_list	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->distance == -1) && (!has_min || head->data < min->data))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	distance_stack(t_list **stack)
{
	t_list	*head;
	int		distance;

	distance = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->distance = distance++;
		head = get_next_min(stack);
	}
}
