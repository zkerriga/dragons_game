/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Unit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 10:21:30 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/31 10:21:32 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_H
# define UNIT_H

# include "libft.h"

typedef struct	s_unit
{
	int			fire;
	int			water;
	int			earth;
	int			air;
	void		(*slogan)(struct s_unit *self);
	void		(*communicate)(struct s_unit *self, struct s_unit *);
	void		(*del)(struct s_unit *self);
}				t_unit;

void			unit_normalize(t_unit *unit);

#endif
