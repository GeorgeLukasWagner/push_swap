/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 20:21:32 by gwagner           #+#    #+#             */
/*   Updated: 2024/08/01 19:34:34 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printlst(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp)
	{
		ft_printf("%d/%d\n", tmp->data, tmp->distance);
		tmp = tmp->next;
	}
}

void	free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}

int	is_sorted(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->data > head->next->data)
			return (0);
		head = head->next;
	}
	return (1);
}
