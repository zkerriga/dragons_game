/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hero_communicate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 09:19:28 by zkerriga          #+#    #+#             */
/*   Updated: 2020/08/01 09:19:30 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hero.h"

/*
** During communication, the hero uses the slogan to determine who he is facing.
** He treats heroes, but beats dragons.
*/

void	hero_communicate(t_hero *self, t_unit *unit)
{
	if (ft_memcmp(unit->slogan(unit), "I'm a hero!", 11))
	{
		self->damage(self, unit);
	}
	else
	{
		self->heal(self, unit);
	}
}
