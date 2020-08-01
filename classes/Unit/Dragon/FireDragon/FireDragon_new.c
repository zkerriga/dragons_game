/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FireDragon_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 10:25:22 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/31 10:25:24 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dragon.h"

void		firedragon_damage(t_dragon *self, t_unit *unit);

t_dragon	*firedragon_new(int fire, int water, int earth, int air)
{
	t_dragon	*firedragon;

	if (!(firedragon = (t_dragon *)malloc_gc(sizeof(t_dragon))))
		exit(1);
	firedragon->hp = MAX_HP;
	firedragon->stats.fire = fire;
	firedragon->stats.water = water;
	firedragon->stats.earth = earth;
	firedragon->stats.air = air;
	unit_normalize(firedragon);
	firedragon->del = dragon_del;
	firedragon->slogan = dragon_slogan;
	firedragon->communicate = dragon_communicate;
	firedragon->damage = firedragon_damage;
	return (firedragon);
}
