/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_print_grid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 03:00:26 by ibertran          #+#    #+#             */
/*   Updated: 2023/08/10 22:12:19 by ibertran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	init_grid(int grid[9][9], int init)
{
	int	x;
	int	y;

	y = 0;
	while (y < 9)
	{
		x = 0;
		while (x < 9)
		{
			grid[y][x] = init;
			x++;
		}
		y++;
	}
}

void	print_grid(int grid[9][9], int solved, int to_solve[9][9])
{
	int	y;

	if (solved)
		ft_putstr("\n\033[92m   Sudoku has been solved!\033[39m\n");
	else
		ft_putstr("\n\033[91m      No solution found\033[39m\n");
	ft_putstr("  +-------+-------+-------+\n");
	y = 0;
	while (y < 9)
	{
		ft_putstr("  ");
		print_line(grid[y], to_solve[y]);
		y++;
		ft_putchar(10);
		if (y == 3 || y == 6)
			ft_putstr("  +-------+-------+-------+\n");
	}
	ft_putstr("  +-------+-------+-------+\n\n");
}

void	print_tosolve(int grid[9][9])
{
	int	y;

	ft_putstr("\033[91m");
	ft_putstr("\n    1 2 3   4 5 6   7 8 9  \n");
	ft_putstr("\033[39m");
	ft_putstr("  +-------+-------+-------+\n");
	y = 0;
	while (y < 9)
	{
		ft_putstr("\033[92m");
		ft_putchar(y + 49);
		ft_putchar(32);
		ft_putstr("\033[39m");
		print_line(grid[y], grid[y]);
		y++;
		ft_putchar(10);
		if (y == 3 || y == 6)
			ft_putstr("  +-------+-------+-------+\n");
	}
	ft_putstr("  +-------+-------+-------+\n\n");
}

void	print_line(int line[9], int highlight[9])
{
	int	x;

	ft_putchar('|');
	ft_putchar(32);
	x = 0;
	while (x < 9)
	{
		if (line[x] >= 1 && line[x] <= 9)
		{
			if (highlight[x] != 0)
				ft_putstr("\033[33m");
			ft_putchar(line[x] + 48);
			ft_putstr("\033[39m");
		}
		else if (line[x] == 0)
			ft_putchar('.');
		else
			ft_putchar('X');
		ft_putchar(32);
		x++;
		if (x == 3 || x == 6)
			ft_putstr("| ");
	}
	ft_putchar('|');
}
