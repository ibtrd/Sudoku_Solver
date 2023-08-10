/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 23:50:01 by ibertran          #+#    #+#             */
/*   Updated: 2023/08/10 22:29:30 by ibertran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(void)
{
	int	grid[9][9];
	int	to_solve[9][9];

	init_grid(grid, 0);
	init_grid(to_solve, 0);
	print_tosolve(to_solve);
	while (ask_input(to_solve) != -2)
	{
		print_tosolve(to_solve);
	}
	if (!try_digit(grid, 0, 0, to_solve))
	{
		init_grid(grid, -1);
		print_grid(grid, 0, to_solve);
	}
	return (0);
}

int	try_digit(int grid[9][9], int row, int col, int to_solve[9][9])
{
	while (grid[col][row] <= 9)
	{
		if (to_solve[col][row] != 0)
			grid[col][row] = to_solve[col][row];
		if (sudoko_rules(grid, row, col, to_solve))
		{
			if (next_step(grid, row, col, to_solve))
				return (1);
		}
		if (to_solve[col][row] != 0)
			break ;
		grid[col][row] += 1;
	}
	grid[col][row] = 0;
	return (0);
}

int	next_step(int grid[9][9], int row, int col, int to_solve[9][9])
{
	if (row == 8 && col == 8)
	{
		print_grid(grid, 1, to_solve);
		return (1);
	}
	else if (row == 8 && col != 8)
	{
		if (try_digit(grid, 0, col + 1, to_solve))
			return (1);
	}
	else
		if (try_digit(grid, row + 1, col, to_solve))
			return (1);
	return (0);
}
