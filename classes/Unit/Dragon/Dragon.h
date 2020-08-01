/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dragon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 10:21:48 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/31 10:21:51 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAGON_H
# define DRAGON_H

# include "Unit.h"

typedef struct s_unit	t_unit;

typedef struct	s_dragon
{
	int			hp;
	t_stats		stats;
	const char	*(*slogan)(struct s_dragon *self);
	void		(*communicate)(struct s_dragon *self, t_unit *);
	void		(*del)(struct s_dragon *self);
	void		(*damage)(struct s_dragon *self, t_unit *);
}				t_dragon;

void			dragon_del(t_dragon *self);
const char		*dragon_slogan(t_dragon *self);
void			dragon_communicate(t_dragon *self, t_unit *unit);

#endif
