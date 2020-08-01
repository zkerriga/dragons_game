/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warrior_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 10:30:33 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/31 10:30:35 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hero.h"

void	warrior_heal(t_hero *self, t_hero *bro);
void	warrior_damage(t_hero *self, t_dragon *dragon);

t_hero	*warrior_new(int fire, int water, int earth, int air, const char *name)
{
	t_hero	*warrior;

	if (!(warrior = (t_hero *)malloc_gc(sizeof(t_hero))))
		exit(1);
	warrior->hp = MAX_HP;
	warrior->stats.fire = fire;
	warrior->stats.water = water;
	warrior->stats.earth = earth;
	warrior->stats.air = air;
	if (!(warrior->name = ft_strdup(name)))
	{
		free_gc(NULL);
		exit(1);
	}
	unit_normalize(warrior);
	warrior->del = hero_del;
	warrior->slogan = hero_slogan;
	warrior->communicate = hero_communicate;
	warrior->heal = warrior_heal;
	warrior->damage = warrior_damage;
	return (warrior);
}
