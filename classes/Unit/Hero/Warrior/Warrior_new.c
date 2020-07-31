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

t_hero	*Warrior_new(int fire, int water, int earth, int air, const char *name)
{
	t_hero	*warrior;

	if (!(warrior = (t_hero *)malloc_gc(sizeof(t_hero))))
		exit(1);
	warrior->fire = fire;
	warrior->water = water;
	warrior->earth = earth;
	warrior->air = air;
	warrior->name = ft_strdup(name);
	unit_normalize(warrior);
	warrior->del = hero_del;
	return (warrior);
}
