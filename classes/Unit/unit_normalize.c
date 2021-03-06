/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_normalize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 11:35:44 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/31 11:35:45 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Unit.h"

void	unit_normalize(t_unit *unit)
{
	int		sum;
	float	diff;

	sum = unit->stats.air + unit->stats.earth + unit->stats.fire
			+ unit->stats.water;
	diff = (float)sum / 100.f;
	unit->stats.air = (int)((float)unit->stats.air / diff);
	unit->stats.earth = (int)((float)unit->stats.earth / diff);
	unit->stats.fire = (int)((float)unit->stats.fire / diff);
	unit->stats.water = (int)((float)unit->stats.water / diff);
}
