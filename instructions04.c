/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions04.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:38:07 by gwagner           #+#    #+#             */
/*   Updated: 2024/07/15 20:53:55 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	return (0);
}

int	rra(t_list **stack_a)
{
	if (reverse_rotate(stack_a) == -1)
		return (-1);
	ft_printf("rra\n");
	return (0);
}

int	rrb(t_list **stack_b)
{
	if (reverse_rotate(stack_b) == -1)
		return (-1);
	ft_printf("rrb\n");
	return (0);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if (reverse_rotate(stack_b) == -1 || reverse_rotate(stack_a) == -1)
		return (-1);
	ft_printf("rrr\n");
	return (0);
}
