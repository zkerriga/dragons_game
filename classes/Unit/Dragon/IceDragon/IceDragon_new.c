/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IceDragon_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 10:24:55 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/31 10:24:56 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dragon.h"

void		icedragon_damage(t_dragon *self, t_unit *unit);

t_dragon	*icedragon_new(int fire, int water, int earth, int air)
{
	t_dragon	*icedragon;

	if (!(icedragon = (t_dragon *)malloc_gc(sizeof(t_dragon))))
		exit(1);
	icedragon->hp = MAX_HP;
	icedragon->stats.fire = fire;
	icedragon->stats.water = water;
	icedragon->stats.earth = earth;
	icedragon->stats.air = air;
	unit_normalize(icedragon);
	icedragon->del = dragon_del;
	icedragon->slogan = dragon_slogan;
	icedragon->communicate = dragon_communicate;
	icedragon->damage = icedragon_damage;
	return (icedragon);
}
