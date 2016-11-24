/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:55:12 by msrun             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/11/24 13:38:00 by msrun            ###   ########.fr       */
=======
/*   Updated: 2016/11/24 13:11:19 by ajouanna         ###   ########.fr       */
>>>>>>> 65a5ed0dfa791969b22f1f5771fb43847c01c295
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

/*
** alloue dynamiquement une liste de t_tetra. La fin de liste est signalee par
** le positionnement de isvalid a zero
** un tetrimino occupe 4*4 caracteres, auquels il faut ajouter 4 retours a la
** et il y a un caractere retour a la ligne entre chaque tetrimino
*/

t_tetri		*ft_alloc(t_tetri *lst, char *buf)
{
	int n;
	int i;

	n = (ft_strlen(buf) + 1) / 21;
	i = 0;
	lst = malloc(sizeof(t_tetri) * (n + 1));
	if (lst == 0)
		return (0);
	while (i < n)
	{
		lst[i].isvalid = 1;
		++i;
	}
	lst[i].isvalid = 0;
	return (lst);
}

/*
** Remplie la liste des tetriminos passee en parametre
** AJ : expliquer la logique
*/

void		ft_fill(t_tetri *lst, char *buf)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (buf[i])
	{
		lst[nb].tab[(i - nb) % 20 / 5][(i - nb) % 5] = buf[i];
		if ((i - nb) % 5 == 4)
			lst[nb].tab[(i - nb) % 20 / 5][(i - nb) % 5] = 0;
		++i;
		if ((i - nb) % 20 == 0)
		{
			++i;
			++nb;
		}
	}
}

/*
** cree la liste de tretriminos vide puis la remplie
*/

t_tetri		*ft_fill_lst(char *buf)
{
	t_tetri	*lst;

	lst = NULL;
	lst = ft_alloc(lst, buf);
	if (lst == 0)
		return (NULL);
	ft_fill(lst, buf);
	return (lst);
}
