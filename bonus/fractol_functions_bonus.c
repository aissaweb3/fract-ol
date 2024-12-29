/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_functions_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:09:33 by ioulkhir          #+#    #+#             */
/*   Updated: 2024/12/29 11:09:34 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	mandelbrot_julia_func(t_complex *z, void *params)
{
	t_complex	*c;

	c = (t_complex *)params;
	*z = (add(mul(*z, *z), *c));
}

void	burningship_func(t_complex *z, void *params)
{
	t_complex	abs_zn;
	t_complex	c;

	c = *(t_complex *)params;
	abs_zn.real = fabs(z->real);
	abs_zn.im = fabs(z->im);
	*z = add(mul(abs_zn, abs_zn), c);
}

void	tricon_func(t_complex *z, void *params)
{
	t_complex	*c;

	c = (t_complex *)params;
	*z = (add(mul(conjugate(*z), conjugate(*z)), *c));
}
