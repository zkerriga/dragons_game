/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hero_slogan.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 09:05:09 by zkerriga          #+#    #+#             */
/*   Updated: 2020/08/01 09:06:08 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hero.h"
#include <stdio.h>

const char	*hero_slogan(t_hero *self)
{
	const char	*slogan = "I'm a hero!";
//	printf("%s My name is %s\n", slogan, self->name);
	return (slogan);
}
