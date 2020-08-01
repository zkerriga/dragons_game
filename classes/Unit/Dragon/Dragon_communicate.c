/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dragon_communicate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 09:59:26 by zkerriga          #+#    #+#             */
/*   Updated: 2020/08/01 09:59:28 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dragon.h"

/*
** Dragons are stupid and beat everyone they meet.
*/

void	dragon_communicate(t_dragon *self, t_unit *unit)
{
	self->damage(self, unit);
}

