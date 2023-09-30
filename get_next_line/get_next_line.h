/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:04:03 by aben-nei          #+#    #+#             */
/*   Updated: 2022/11/15 21:37:34 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	10
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
/* ------------------- Prototype Function -------------------*/

char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strchr_gnl(char *s, char c);
size_t	ft_strlen_gnl(char *str, char c);
char	*ft_strdup_gnl(char *s);
char	*ft_substr_gnl(char *s, unsigned int start, size_t len);
#endif
