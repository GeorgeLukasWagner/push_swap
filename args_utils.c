/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 20:46:03 by gwagner           #+#    #+#             */
/*   Updated: 2024/08/01 17:57:25 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_contains(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_err(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}

void	ft_check_args(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;	

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!ft_isnum(args[i]))
			ft_err("Error");
		if (ft_contains(tmp, args, i))
			ft_err("Error");
		if (tmp < -2147483648 || tmp > 2147483647)
			ft_err("Error");
		i++;
	}
	if (argc == 2)
		ft_free(args);
}

// void	get_data(int ac, char **av, t_list **stack_a)
// {
// 	size_t	i;
// 	int		value;
// 	t_list	*tmp;
// 	char	**args;

// 	i = 0;
// 	if (ac == 2)
// 		args = ft_split(av[1], ' ');
// 	else
// 	{
// 		i = 1;
// 		args = av;
// 	}
// 	ft_check_args(ac, args, i);
// 	while (i < argslen(args))
// 	{
// 		value = ft_atoi(args[i]);
// 		tmp = ft_lstnew(value, i);
// 		if (!tmp)
// 			ft_err("Error");
// 		ft_lstadd_back(stack_a, tmp);
// 		ft_printf("%s\n", args[i]);
// 		i++;
// 	}
// }
