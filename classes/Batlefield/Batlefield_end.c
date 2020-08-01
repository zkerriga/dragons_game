/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Batlefield_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 16:44:14 by zkerriga          #+#    #+#             */
/*   Updated: 2020/08/01 16:44:16 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Batlefield.h"
#include <stdio.h>

void	battlefield_end(t_battlefield *self)
{
	if (self->dragons_counter == 0)
	{
		printf("Heroes win! There are only %d of them left.\n",
				self->heroes_counter);
	}
	else if (self->heroes_counter == 0)
	{
		printf("Dragons win! There are only %d of them left.\n",
				self->heroes_counter);
	}
	else
	{
		printf("The battle dragged on.. There are %d dragons left, and %d heroes left.\n", self->dragons_counter, self->heroes_counter);
	}
}
