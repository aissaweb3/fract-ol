/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:09:57 by ioulkhir          #+#    #+#             */
/*   Updated: 2024/12/29 11:09:58 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

t_complex	mul(t_complex a, t_complex b)
{
	t_complex	result;

	result.real = ((a.real * b.real) - (b.im * a.im));
	result.im = ((a.real * b.im) + (b.real * a.im));
	return (result);
}

t_complex	conjugate(t_complex z)
{
	t_complex	z_bar;

	z_bar.real = z.real;
	z_bar.im = -z.im;
	return (z_bar);
}

t_complex	add(t_complex a, t_complex b)
{
	t_complex	result;

	result.real = a.real + b.real;
	result.im = a.im + b.im;
	return (result);
}

t_complex	sub(t_complex a, t_complex b)
{
	t_complex	result;

	result.real = a.real - b.real;
	result.im = a.im - b.im;
	return (result);
}

double	complex_module(t_complex z)
{
	return (sqrt((z.real * z.real) + (z.im * z.im)));
}
