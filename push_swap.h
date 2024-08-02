/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:50:44 by gwagner           #+#    #+#             */
/*   Updated: 2024/08/02 15:17:31 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include "./printf/ft_printf.h"
# include "./printf/libft/libft.h"

typedef struct s_list
{
	int				data;
	int				distance;
	struct s_list	*next;
}	t_list;

void	ft_err_check(char *msg, char **to_free, int argc);
void	ft_check_args(int argc, char **argv);
int		sa(t_list **stack_a);
int		sb(t_list **stack_b);
int		ss(t_list **stack_a, t_list **stack_b);
int		pa(t_list **stack_a, t_list **stack_b);
int		pb(t_list **stack_a, t_list **stack_b);
int		ra(t_list **stack_a);
int		rb(t_list **stack_b);
int		rr(t_list **stack_a, t_list **stack_b);
int		rra(t_list **stack_a);
int		rrb(t_list **stack_b);
int		rrr(t_list **stack_a, t_list **stack_b);
t_list	*ft_lstnew(int data);
void	ft_lstadd_front(t_list **stack, t_list *new);
t_list	*ft_lstlast(t_list *head);
void	ft_lstadd_back(t_list **stack, t_list *new);
int		ft_lstsize(t_list *head);
void	ft_printlst(t_list *head);
void	free_stack(t_list	**stack);
int		is_sorted(t_list **stack);
void	simple_sort(t_list **stack_a, t_list **stack_b);
int		find_min(t_list *stack_a);
void	sort_3(t_list **stack_a);
void	radixsort(t_list **stack_a, t_list **stack_b);
void	ft_free(char **str);
void	distance_stack(t_list **stack);

#endif