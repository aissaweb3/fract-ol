/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:09:52 by ioulkhir          #+#    #+#             */
/*   Updated: 2024/12/29 11:09:53 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	throw_usage(void)
{
	write(2, "Bad usage !\n\nUsage :\n\t./fractol <FRACTAL_NAME>", 47);
	write(2, "\n\n\t<FRACTAL_NAME>:", 19);
	write(2, "\n\t\tMandelbrot", 14);
	write(2, "\n\t\tJulia", 9);
	write(2, "\n\t\tBurningship", 15);
	write(2, "\n\t\tTricon\n", 11);
	write(2, "\n\n\tJulia:", 10);
	write(2, "\n\t\t./fractol Julia Re(c) Im(c)\n", 31);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;
	char		error;

	error = fractal_init(&fractal, ac, av);
	if (error)
		return (throw_usage(), 1);
	fill_img(&fractal);
	handle_events(&fractal);
	mlx_loop(fractal.mlx_connection);
}
