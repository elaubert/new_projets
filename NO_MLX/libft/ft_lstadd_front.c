/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubert <eaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 12:26:31 by eaubert           #+#    #+#             */
/*   Updated: 2021/04/29 13:36:49 by eaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(void *alst, void *new)
{
	if (alst && new)
	{
		((t_next *)new)->next = *(t_next **)alst;
		*(t_next **)alst = new;
	}
}
