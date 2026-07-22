/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakalkan <hakalkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:35:57 by hakalkan          #+#    #+#             */
/*   Updated: 2025/07/13 16:44:15 by hakalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
#define GET_NEXT_LINE_BONUS_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 15
#endif
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>



char *get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*read_file(int fd, char *backup);
char	*get_line(char *backup);
char	*update_backup(char *backup);



#endif
