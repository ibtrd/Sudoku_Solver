/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sukoku_rules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 00:27:48 by ibertran          #+#    #+#             */
/*   Updated: 2023/08/09 15:15:27 by ibertran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static int	sudoku_row(int grid[9][9], int row, int col, int to_solve[9][9]);
static int	sudoku_col(int grid[9][9], int row, int col, int to_solve[9][9]);
static int	sudoku_box(int grid[9][9], int row, int col, int to_solve[9][9]);
static int	define_box(int nb);

int	sudoko_rules(int grid[9][9], int row, int col, int to_solve[9][9])
{
	if (grid[col][row] == 0)
		return (0);
	if (!sudoku_row(grid, row, col, to_solve))
		return (0);
	if (!sudoku_col(grid, row, col, to_solve))
		return (0);
	if (!sudoku_box(grid, row, col, to_solve))
		return (0);
	return (1);
}

static int	sudoku_row(int grid[9][9], int row, int col, int to_solve[9][9])
{
	int	i;

	i = 0;
	while (i < 9)
	{
		if (grid[col][row] == grid[col][i] && i != row)
			return (0);
		if (grid[col][row] == to_solve[col][i] && i != row)
			return (0);
		i++;
	}
	return (1);
}

static int	sudoku_col(int grid[9][9], int row, int col, int to_solve[9][9])
{
	int	i;

	i = 0;
	while (i < 9)
	{
		if (grid[col][row] == grid [i][row] && i != col)
			return (0);
		if (grid[col][row] == to_solve[i][row] && i != col)
			return (0);
		i++;
	}
	return (1);
}

static int	sudoku_box(int grid[9][9], int row, int col, int to_solve[9][9])
{
	int	x;
	int	y;

	y = define_box(col);
	while (y <= define_box(col) + 2)
	{
		x = define_box(row);
		while (x <= (define_box(row) + 2))
		{
			if (grid[y][x] == grid[col][row] && (y != col && x != row))
				return (0);
			if (to_solve[y][x] == grid[col][row] && (y != col && x != row))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static int	define_box(int nb)
{
	if (nb >= 0 && nb <= 2)
		return (0);
	if (nb >= 3 && nb <= 5)
		return (3);
	if (nb >= 6 && nb <= 8) 
		return (6);
	return (-1);
}
