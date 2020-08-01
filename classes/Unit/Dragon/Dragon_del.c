/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dragon_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 11:28:28 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/31 11:28:30 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dragon.h"
#include <stdio.h>

void	dragon_del(t_dragon *self)
{
//	printf("The dragon died!\n");
	free_gc(self);
}
