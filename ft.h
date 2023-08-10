/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 00:01:11 by ibertran          #+#    #+#             */
/*   Updated: 2023/08/10 22:24:56 by ibertran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>

/* FUNCTIONS */
int		sudoko_rules(int grid[9][9], int row, int col, int to_solve[9][9]);
int		try_digit(int grid[9][9], int row, int col, int to_solve[9][9]);
int		next_step(int grid[9][9], int row, int col, int to_solve[9][9]);
int		ask_input(int to_solve[9][9]);
int		solve_command(char str[5]);
int		place_command(char str[5]);
void	init_grid(int grid[9][9], int init);
void	print_grid(int grid[9][9], int solved, int to_solve[9][9]);
void	print_tosolve(int grid[9][9]);
void	print_line(int line[9], int highlight[9]);
void	ft_putchar(char c);
void	ft_putstr(char *str);

#endif
