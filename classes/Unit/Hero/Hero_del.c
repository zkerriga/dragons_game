/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hero_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 11:27:25 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/31 11:27:26 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hero.h"
#include <stdio.h>

void	hero_del(t_hero *self)
{
//	printf("The hero %s died!\n", self->name);
	free(self->name);
	free_gc(self);
}
