/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 10:00:03 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/31 10:00:10 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "Hero.h"
#include "Dragon.h"
#include "Battlefield.h"
#include <stdio.h>

t_list	*heroes_list_create(void)
{
	t_list	*heroes;

	heroes = ft_lstnew(warrior_new(10, 20, 50, 35, "Dragonborn"));
//	ft_lstadd_front(&heroes, ft_lstnew(warrior_new(90, 20, 3, 35, "Fireman")));
	ft_lstadd_front(&heroes, ft_lstnew(berserk_new(80, 1, 2, 10, "Borris")));
	printf("The heroes team is assembled!\n\n");
	return (heroes);
}

t_list	*dragons_list_create(void)
{
	t_list	*dragons;

	dragons = ft_lstnew(icedragon_new(1, 60, 20, 24));
	ft_lstadd_front(&dragons, ft_lstnew(icedragon_new(10, 90, 1, 30)));
	ft_lstadd_front(&dragons, ft_lstnew(firedragon_new(80, 1, 20, 1)));
//	ft_lstadd_front(&1dragons, ft_lstnew(firedragon_new(10, 10, 78, 60)));
	printf("The dragon team is assembled!\n\n");
	return (dragons);
}

int		main(void)
{
	t_list			*dragons;
	t_list			*heroes;
	t_battlefield	*battlefield;

	dragons = dragons_list_create();
	heroes = heroes_list_create();
	battlefield = battlefield_new(dragons, heroes);
	battlefield->fight(battlefield);
	battlefield->end(battlefield);
	battlefield->del(battlefield);
	return (0);
}
