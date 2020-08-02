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

#include "Battlefield.h"
#include "stdio.h"

static void	print_info(t_unit *unit1, t_unit *unit2, t_bool is_start)
{
	if (is_start)
		printf("Battle: ");
	else
		printf("     -> ");
	if (unit1)
		printf("%s(%3d hp) vs ", (ft_memcmp("I'm a hero!",
				unit1->slogan(unit1), 11) ? "dragon" : "hero"), unit1->hp);
	else
		printf("dead vs ");
	if (unit2)
		printf("%s(%3d hp)\n", (ft_memcmp("I'm a hero!",
				unit2->slogan(unit2), 11) ? "dragon" : "hero"), unit2->hp);
	else
		printf("dead\n");
	if (!is_start)
		printf("\n");
}

static void	battle(t_battlefield *self, int i1, int i2)
{
	t_unit	*unit1;
	t_unit	*unit2;

	unit1 = self->units_array[i1];
	unit2 = self->units_array[i2];
	print_info(unit1, unit2, TRUE);
	unit1->communicate(unit1, unit2);
	if (unit2->hp < MIN_HP)
	{
		if (ft_memcmp("I'm a hero!", unit2->slogan(unit2), 11))
			--self->dragons_counter;
		else
			--self->heroes_counter;
		unit2->del(unit2);
		self->units_array[i2] = NULL;
		print_info(self->units_array[i1], self->units_array[i2], FALSE);
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
	print_info(self->units_array[i1], self->units_array[i2], FALSE);
}

static void	find_units(t_battlefield *self, int *unit1, int *unit2)
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

void	battlefield_fight(t_battlefield *self)
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
