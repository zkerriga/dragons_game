/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Berserk_new.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 10:29:56 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/31 10:29:58 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hero.h"

void	berserk_heal(t_hero *self, t_hero *bro);
void	berserk_damage(t_hero *self, t_dragon *dragon);

t_hero	*berserk_new(int fire, int water, int earth, int air, const char *name)
{
	t_hero	*berserk;

	if (!(berserk = (t_hero *)malloc_gc(sizeof(t_hero))))
		exit(1);
	berserk->hp = MAX_HP;
	berserk->stats.fire = fire;
	berserk->stats.water = water;
	berserk->stats.earth = earth;
	berserk->stats.air = air;
	berserk->name = ft_strdup(name);
	unit_normalize(berserk);
	berserk->del = hero_del;
	berserk->slogan = hero_slogan;
	berserk->communicate = hero_communicate;
	berserk->heal = berserk_heal;
	berserk->damage = berserk_damage;
	return (berserk);
}
