/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:05:03 by gwagner           #+#    #+#             */
/*   Updated: 2024/08/01 19:14:51 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_list *stack_a)
{
	t_list	*tmp;
	int		min;
	int		i;
	int		ret;

	ret = 1;
	i = 1;
	tmp = stack_a;
	min = tmp->data;
	while (tmp->next)
	{
		i++;
		tmp = tmp->next;
		if (tmp->data < min)
		{
			min = tmp->data;
			ret = i;
		}
	}
	return (ret);
}

void	sort_3(t_list **stack_a)
{
	if (is_sorted(stack_a) == 1)
		return ;
	if (find_min(*stack_a) == 1)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (find_min(*stack_a) == 2)
	{
		if ((*stack_a)->data < (*stack_a)->next->next->data)
			sa(stack_a);
		else
			ra(stack_a);
	}
	else
	{
		if ((*stack_a)->data < (*stack_a)->next->data)
			rra(stack_a);
		else
		{
			ra(stack_a);
			sa(stack_a);
		}
	}
}

void	sort_4(t_list **stack_a, t_list **stack_b)
{
	if (find_min(*stack_a) == 2)
		ra(stack_a);
	else if (find_min(*stack_a) == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (find_min(*stack_a) == 4)
		rra(stack_a);
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	if (find_min(*stack_a) == 2)
		ra(stack_a);
	else if (find_min(*stack_a) == 3)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (find_min(*stack_a) == 4)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (find_min(*stack_a) == 5)
		rra(stack_a);
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	simple_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_a;
	if (is_sorted(stack_a) == 1)
		return ;
	if (ft_lstsize(*stack_a) == 2 && tmp->data > tmp->next->data)
		sa(stack_a);
	else if (ft_lstsize(*stack_a) == 3)
		sort_3(stack_a);
	else if (ft_lstsize(*stack_a) == 4)
		sort_4(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 5)
		sort_5(stack_a, stack_b);
}
