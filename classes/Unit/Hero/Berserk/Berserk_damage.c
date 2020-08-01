/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Berserk_damage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 09:50:01 by zkerriga          #+#    #+#             */
/*   Updated: 2020/08/01 09:50:03 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hero.h"

void	berserk_damage(t_hero *self, t_dragon *dragon)
{
	if (self->stats.fire > dragon->stats.fire / 2)
	{
		dragon->hp -= 10 + (self->hp < 10 ? 4 : 0);
	}
	if (self->stats.earth + self->stats.air + self->stats.water / 2
		> dragon->stats.air)
	{
		dragon->hp -= 3 + (self->hp < 10 ? 4 : 0);
	}
}
