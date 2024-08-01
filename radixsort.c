/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radixsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:13:43 by gwagner           #+#    #+#             */
/*   Updated: 2024/08/01 19:44:09 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_list **stack)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->distance;
	max_bits = 0;
	while (head)
	{
		if (head->distance > max)
			max = head->distance;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	push_to_a(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_b) != 0)
		pa(stack_a, stack_b);
}

void	radixsort(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		digit;
	int		j;
	int		size;
	t_list	*tmp;

	size = ft_lstsize(*stack_a);
	i = 0;
	tmp = *stack_a;
	digit = get_max_bits(stack_a);
	while (i < digit)
	{
		j = 0;
		while (j++ < size)
		{
			tmp = *stack_a;
			if ((tmp->distance >> i & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
		}
		push_to_a(stack_a, stack_b);
		i++;
	}
}
