/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hero.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 10:26:07 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/31 10:26:09 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HERO_H
# define HERO_H

# include "Unit.h"

typedef struct s_unit	t_unit;
typedef struct s_sragon	t_dragon;

typedef struct	s_hero
{
	int			fire;
	int			water;
	int			earth;
	int			air;
	void		(*slogan)(struct s_hero *self);
	void		(*communicate)(struct s_hero *self, t_unit *);
	void		(*del)(struct s_hero *self);
	char		*name;
	void		(*heal)(struct s_hero *self, struct s_hero *);
	void		(*damage)(struct s_hero *self, t_dragon *);
}				t_hero;

void	hero_del(t_hero *self);

#endif
