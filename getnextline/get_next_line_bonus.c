/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakalkan <hakalkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:35:54 by hakalkan          #+#    #+#             */
/*   Updated: 2025/07/13 17:24:43 by hakalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *read_file(int fd, char *backup)
{
	char	*buff;
	char	*tmp;
	int		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while ((i = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[i] = '\0';
		tmp = backup;
		backup = ft_strjoin(backup, buff);
		free(tmp);
		if (!backup)
			return (free(buff),NULL);
		if (ft_strchr(buff, '\n'))
			break;
	}
	free(buff);
	if (i == -1)
		return (NULL);
	return (backup);
}


char *update_backup(char *backup)
{
	int 	i;
	int 	j;
	char 	*new_backup;

	i = 0;
	j = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (!backup[i])
	{
		free(backup);
		return (NULL);
	}
	i++;
	new_backup = malloc(sizeof(char) * (ft_strlen(backup) - i + 1));
	if (!new_backup)
		return (NULL);
	while (backup[i])
		new_backup[j++] = backup[i++];
	new_backup[j] = '\0';
	free(backup);
	return (new_backup);
}

char *get_line(char *backup)
{
	int i;
	char *line;

	i = 0;	
	if (!backup[i])
		return (NULL);
	while (backup[i] && backup[i] != '\n')
		i++;
	if (backup[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (backup[i] && backup[i] != '\n')
		line[i++] = backup[i];
	if (backup[i] == '\n')
	{
		line[i] = backup[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char *get_next_line(int fd)
{
    static char *backup[1024];
    char *line;

    if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
        return (NULL);

    backup[fd] = read_file(fd, backup[fd]);
    if (!backup[fd])
        return (NULL);

    line = get_line(backup[fd]);
    backup[fd] = update_backup(backup[fd]);

    return (line);
}


