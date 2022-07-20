/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkernbac <fkernbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:34:10 by fkernbac          #+#    #+#             */
/*   Updated: 2022/03/30 17:23:35 by fkernbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//scans for the first occurence of character in string and returns pointer
char	*ft_strchr(const char *string, int character)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == (char)character)
			return ((char *)&string[i]);
		i++;
	}
	if (character == '\0')
		return ((char *)&string[i]);
	return (0);
}
