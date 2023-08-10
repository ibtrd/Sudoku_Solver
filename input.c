/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:10:22 by ibertran          #+#    #+#             */
/*   Updated: 2023/08/10 22:11:20 by ibertran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ask_input(int to_solve[9][9])
{
	char	buff[5];

	ft_putstr("command 'XYZ↵'\n  place ");
	ft_putstr("\033[33mZ\033[39m on \033[91mX→\033[39m,\033[92mY↓");
	ft_putstr("\033[39m position\n\n");
	ft_putstr("command 'solve↵'\n  solve the puzzle\n\n");
	read(0, buff, 5);
	if (solve_command(buff))
		return (-2);
	else if (place_command(buff))
	{
		to_solve[buff[1] - 49][buff[0] - 49] = buff[2] - 48;
		if (buff[2] == '0')
			return (1);
		if (!sudoko_rules(to_solve, buff[0] - 49, buff[1] - 49, to_solve))
		{
			ft_putstr("\033[93m  /!\\ CONFLICTING INPUT /!\\\033[39m\n");
			to_solve[buff[1] - 49][buff[0] - 49] = 0;
		}
	}
	else
		ft_putstr("\033[93m   /!\\ INVALID COMMAND /!\\\033[39m\n");
	return (1);
}

int	solve_command(char str[5])
{
	if (str[0] != 's')
		return (0);
	if (str[1] != 'o')
		return (0);
	if (str[2] != 'l')
		return (0);
	if (str[3] != 'v')
		return (0);
	if (str[4] != 'e')
		return (0);
	return (1);
}

int	place_command(char str[5])
{
	if (str[0] < '1' || str[0] > '9')
		return (0);
	if (str[1] < '1' || str[0] > '9')
		return (0);
	if (str[2] < '0' || str[0] > '9')
		return (0);
	if (str[3] != '\n')
		return (0);
	return (1);
}
