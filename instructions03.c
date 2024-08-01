/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions03.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:32:38 by gwagner           #+#    #+#             */
/*   Updated: 2024/07/15 19:46:36 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

int	ra(t_list **stack_a)
{
	if (rotate(stack_a) == -1)
		return (-1);
	ft_printf("ra\n");
	return (0);
}

int	rb(t_list **stack_b)
{
	if (rotate(stack_b) == -1)
		return (-1);
	ft_printf("rb\n");
	return (0);
}

int	rr(t_list **stack_a, t_list **stack_b)
{
	if (rotate(stack_b) == -1 || rotate(stack_a) == -1)
		return (-1);
	ft_printf("rr\n");
	return (0);
}
