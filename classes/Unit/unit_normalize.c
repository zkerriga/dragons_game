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
	int	sum;
	int	diff;

	sum = unit->air + unit->earth + unit->fire + unit->water;
	diff = sum / 100;
	unit->air /= diff;
	unit->earth /= diff;
	unit->fire /= diff;
	unit->water /= diff;
}
