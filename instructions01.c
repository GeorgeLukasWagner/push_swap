/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 20:55:59 by gwagner           #+#    #+#             */
/*   Updated: 2024/08/02 15:10:14 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap(t_list **stack)
{
	t_list	*head;
	t_list	*next;
	int		tmp_data;
	int		tmp_distance;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	next = head->next;
	if (!head && !next)
		return (-1);
	tmp_data = head->data;
	tmp_distance = head->distance;
	head->data = next->data;
	head->distance = next->distance;
	next->data = tmp_data;
	next->distance = tmp_distance;
	return (0);
}

int	sa(t_list **stack_a)
{
	if (swap(stack_a) == -1)
		return (-1);
	ft_printf("sa\n");
	return (0);
}

int	sb(t_list **stack_b)
{
	if (swap(stack_b) == -1)
		return (-1);
	ft_printf("sb\n");
	return (0);
}

int	ss(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	if (swap(stack_a) == -1 || swap(stack_b) == -1)
		return (-1);
	ft_printf("ss\n");
	return (0);
}
