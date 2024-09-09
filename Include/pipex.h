/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:32:37 by almarico          #+#    #+#             */
/*   Updated: 2024/09/09 20:01:47 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft-complete/libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
// # include <sys/types.h>
// # include <sys/stat.h>
# include <fcntl.h>

# define SUCCESS			0
# define FAIL				1

/* error define */

# define ERR_ARGC			"the number of argument is different from five "
# define ERR_PIPE			"error during pipe creation "
# define ERR_FORK			"an error occur during the fork "
# define ERR_INFILE			"an error occur while opening the entry file "
# define ERR_DUP2			"an error occur while trying to duplicate the fd "
# define ERR_OUTFILE		"an error occur while opening the exit file or \
creating it "
# define ERR_EXECVE			"an error occur during execve "
# define ERR_PATH			"no path where found "
# define PATH				"PATH="

/* utils.c */

void	error(char *msg);
void	free_essential(char **s1, char *s2);
void	free_all(char **s1, char **s2, char *s3);

#endif
