/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:13:49 by ioulkhir          #+#    #+#             */
/*   Updated: 2024/12/29 11:13:45 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_julia_func(t_complex *z, void *params)
{
	t_complex	*c;

	c = (t_complex *)params;
	*z = (add(mul(*z, *z), *c));
}
