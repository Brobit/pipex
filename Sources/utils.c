/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:54:16 by almarico          #+#    #+#             */
/*   Updated: 2024/09/09 20:14:45 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/pipex.h"

void	error(char *msg)
{
	perror(msg);
	exit(FAIL);
}

void	free_essential(char **s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
		free(s1[i++]);
	free(s1);
	free(s2);
}

void	free_all(char **s1, char **s2, char *s3)
{
	int	i;

	i = 0;
	while (s1[i])
		free(s1[i++]);
	free(s1);
	i = 0;
	while (s2[i])
		free(s2[i++]);
	free(s2);
	free(s3);
}
