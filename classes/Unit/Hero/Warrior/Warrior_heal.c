/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warrior_heal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 09:32:24 by zkerriga          #+#    #+#             */
/*   Updated: 2020/08/01 09:32:25 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hero.h"

static void	hp_increase(int plus_hp, t_hero *bro)
{
	if (bro->hp + plus_hp > MAX_HP)
		bro->hp = MAX_HP;
	else
		bro->hp += plus_hp;
}

void		warrior_heal(t_hero *self, t_hero *bro)
{
	if (self->stats.water > bro->stats.water)
	{
		hp_increase(10, bro);
	}
	else
	{
		hp_increase(5, bro);
	}
}
