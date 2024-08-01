/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:15:47 by gwagner           #+#    #+#             */
/*   Updated: 2024/07/18 16:40:57 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push(t_list **stack_to, t_list **stack_from)
{
	t_list	*from;
	t_list	*to;
	t_list	*tmp;

	if (ft_lstsize(*stack_from) == 0)
		return (-1);
	to = *stack_to;
	from = *stack_from;
	tmp = from;
	from = from->next;
	*stack_from = from;
	if (!to)
	{
		to = tmp;
		to->next = NULL;
		*stack_to = to;
	}
	else
	{
		tmp->next = to;
		*stack_to = tmp;
	}
	return (0);
}

int	pa(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	ft_printf("pa\n");
	return (0);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	ft_printf("pb\n");
	return (0);
}
