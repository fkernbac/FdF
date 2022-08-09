/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:01:59 by fkernbac          #+#    #+#             */
/*   Updated: 2022/08/09 19:05:40 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	print_coordinates(t_map *map)
{
	t_vert	*current;

	current = map->first;
	while (current != NULL)
	{
		if (current->right == NULL)
			ft_printf("%i ", current->z);
		current = current->next;
	}
}
