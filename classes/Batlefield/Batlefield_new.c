/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Batlefield_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 10:24:25 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/31 10:24:27 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Batlefield.h"
#include "Unit.h"

static void		init_array(t_battlefield *self, t_list *dragons, t_list *heroes)
{
	int		i;
	t_list	*tmp;

	if (!(self->units_array = (t_unit **)calloc_gc(sizeof(t_unit *),
													self->size)))
		exit(1);
	i = 0;
	while (dragons)
	{
		self->units_array[i++] = dragons->content;
		tmp = dragons;
		dragons = dragons->next;
		free(tmp);
	}
	while (heroes)
	{
		self->units_array[i++] = heroes->content;
		tmp = heroes;
		heroes = heroes->next;
		free(tmp);
	}
}

static void		shuffle_array(t_unit **array, int size)
{
	int		first_i;
	int		second_i;
	int		counter;
	t_unit	*for_swap;

	srand(42);
	counter = 0;
	while (counter++ < size)
	{
		first_i = rand() % size;
		second_i = rand() % size;
		for_swap = array[first_i];
		array[first_i] = array[second_i];
		array[second_i] = for_swap;
	}
}

t_battlefield	*battlefield_new(t_list *dragons, t_list *heroes)
{
	t_battlefield	*field;

	if (!(field = (t_battlefield *)malloc_gc(sizeof(t_battlefield))))
		exit(1);
	field->dragons_counter = ft_lstsize(dragons);
	field->heroes_counter = ft_lstsize(heroes);
	field->size = field->dragons_counter + field->heroes_counter;
	init_array(field, dragons, heroes);
	shuffle_array(field->units_array, field->size);
	field->fight = battlefield_fight;
	field->end = battlefield_end;
	field->del = battlefield_del;
	return (field);
}
