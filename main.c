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
#include "Unit.h"

t_list	*heroes_list_create(void)
{
	t_list	*heroes;

	heroes = ft_lstnew();
	ft_lstadd_front(&heroes, ft_lstnew());
	ft_lstadd_front(&heroes, ft_lstnew(NULL));
	return (heroes);
}

t_list	*dragons_list_create(void)
{
	t_list	*dragons;

	dragons = ft_lstnew(NULL);
	ft_lstadd_front(&dragons, ft_lstnew(NULL));
	ft_lstadd_front(&dragons, ft_lstnew(NULL));
	ft_lstadd_front(&dragons, ft_lstnew(NULL));
	ft_lstadd_front(&dragons, ft_lstnew(NULL));
	return (dragons);
}

int		main(void)
{
	t_list	*dragons;
	t_list	*heroes;

	dragons = dragons_list_create();
	heroes = heroes_list_create();
	return (0);
}
