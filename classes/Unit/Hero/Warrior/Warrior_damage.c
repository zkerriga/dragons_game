/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warrior_damage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 09:32:15 by zkerriga          #+#    #+#             */
/*   Updated: 2020/08/01 09:32:16 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hero.h"

void	warrior_damage(t_hero *self, t_dragon *dragon)
{
	if (self->stats.fire > dragon->stats.fire)
	{
		dragon->hp -= 5;
	}
	if (self->stats.earth + self->stats.air > dragon->stats.air)
	{
		dragon->hp -= 6;
	}
}
