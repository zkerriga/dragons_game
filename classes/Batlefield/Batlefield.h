/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Batlefield.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 10:21:11 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/31 10:21:13 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BATLEFIELD_H
# define BATLEFIELD_H

# include "Unit.h"

# define LOOP_OUT 5000

typedef struct	s_battlefield
{
	int			dragons_counter;
	int			heroes_counter;
	int			size;
	t_unit		**units_array;
	void		(*fight)(struct s_battlefield *self);
	void		(*end)(struct s_battlefield *self);
	void		(*del)(struct s_battlefield *self);
}				t_battlefield;

t_battlefield	*battlefield_new(t_list *dragons, t_list *heroes);
void			battlefield_del(t_battlefield *self);
void			battlefield_fight(t_battlefield *self);
void			battlefield_end(t_battlefield *self);

#endif
