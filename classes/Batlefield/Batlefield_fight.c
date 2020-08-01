/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Batlefield_fight.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 15:48:10 by zkerriga          #+#    #+#             */
/*   Updated: 2020/08/01 15:48:12 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Batlefield.h"
#include "stdio.h"

void	battle(t_battlefield *self, int i1, int i2)
{
	t_unit	*unit1;
	t_unit	*unit2;

	unit1 = self->units_array[i1];
	unit2 = self->units_array[i2];
	printf("Battle: %s vs %s\n", unit1->slogan(unit1), unit2->slogan(unit2));
	unit1->communicate(unit1, unit2);
	if (unit2->hp < MIN_HP)
	{
		if (ft_memcmp("I'm a hero!", unit2->slogan(unit2), 11))
			--self->dragons_counter;
		else
			--self->heroes_counter;
		unit2->del(unit2);
		self->units_array[i2] = NULL;
		return ;
	}
	unit2->communicate(unit2, unit1);
	if (unit1->hp < MIN_HP)
	{
		if (ft_memcmp("I'm a hero!", unit1->slogan(unit1), 11))
			--self->dragons_counter;
		else
			--self->heroes_counter;
		unit1->del(unit1);
		self->units_array[i1] = NULL;
	}
}

void	find_units(t_battlefield *self, int *unit1, int *unit2)
{
	static int	unit0 = 0;
	int			next_unit;

	while (unit0 < self->size && self->units_array[unit0] == NULL)
		++unit0;
	if (unit0 == self->size)
	{
		unit0 = 0;
		while (unit0 < self->size && self->units_array[unit0] == NULL)
			++unit0;
	}
	next_unit = unit0 + 1;
	while (next_unit < self->size && self->units_array[next_unit] == NULL)
		++next_unit;
	if (next_unit == self->size)
	{
		next_unit = 0;
		while (next_unit < self->size && self->units_array[next_unit] == NULL)
			++next_unit;
	}
	*unit1 = unit0;
	*unit2 = next_unit;
	++unit0;
}

void	batlefield_fight(t_battlefield *self)
{
	int		unit1;
	int		unit2;
	int		loop_j;

	loop_j = 0;
	while (loop_j++ < LOOP_OUT && self->heroes_counter > 0
			&& self->dragons_counter > 0)
	{
		find_units(self, &unit1, &unit2);
		battle(self, unit1, unit2);
	}
}
