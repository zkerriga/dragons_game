/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Batlefield_del.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 10:24:35 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/31 10:24:36 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Batlefield.h"

static void	clear_array(t_unit **array, int size)
{
	int	i_unit;

	i_unit = 0;
	while (i_unit < size)
	{
		if (array[i_unit] != NULL)
			array[i_unit]->del(array[i_unit]);
		++i_unit;
	}
}

void	battlefield_del(t_battlefield *self)
{
	clear_array(self->units_array, self->size);
	free_gc(self->units_array);
	free_gc(self);
}
