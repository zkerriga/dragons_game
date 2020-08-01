/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IceDragon_damage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 10:03:30 by zkerriga          #+#    #+#             */
/*   Updated: 2020/08/01 10:03:32 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dragon.h"

void	icedragon_damage(t_dragon *self, t_unit *unit)
{
	if (self->stats.water > unit->stats.water / 3 * 2)
	{
		unit->hp -= 16;
	}
	else
	{
		unit->hp -= 6;
	}
}
