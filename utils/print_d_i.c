/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneshev <sneshev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:48:38 by sneshev           #+#    #+#             */
/*   Updated: 2024/12/02 11:20:11 by sneshev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_nbr(int n, int *count)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		*count += 11;
	}
	else
	{
		if (n < 0)
		{
			n *= -1;
			write(1, "-", 1);
			*count += 1;
		}
		if (n > 9)
			print_nbr(n / 10, count);
		c = (n % 10) + '0';
		write (1, &c, 1);
		*count += 1;
	}
}
