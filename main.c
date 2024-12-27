/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ioulkhir <ioulkhir@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/12/27 22:15:24 by ioulkhir		  #+#	#+#			 */
/*   Updated: 2024/12/27 22:16:47 by ioulkhir		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "fractol.h"

static void	throw_usage(void)
{
	write(2, "Bad usage !\n\nUsage :\n\t./fractol <FRACTAL_NAME>", 47);
	write(2, "\n\n\t<FRACTAL_NAME>:", 19);
	write(2, "\n\t\tMandelbrot", 14);
	write(2, "\n\t\tJulia", 9);
	write(2, "\n\t\tBurningship", 15);
	write(2, "\n\t\tTricon\n", 11);
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
