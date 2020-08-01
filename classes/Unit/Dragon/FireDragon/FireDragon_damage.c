/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FireDragon_damage.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 10:03:17 by zkerriga          #+#    #+#             */
/*   Updated: 2020/08/01 10:03:19 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dragon.h"

void	firedragon_damage(t_dragon *self, t_unit *unit)
{
	if (self->stats.fire > unit->stats.water)
	{
		if (self->stats.fire > unit->stats.fire / 2)
		{
			unit->hp -= 19;
		}
		else
		{
			unit->hp -= 14;
		}
	}
	else
	{
		unit->hp -= 7;
	}
}
