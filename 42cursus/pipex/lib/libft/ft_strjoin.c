/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 22:11:09 by hannkim           #+#    #+#             */
/*   Updated: 2022/03/09 18:39:16 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../../includes/pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	int		len;
	int		idx;
	int		p_idx;

	if (!s1 || !s2)
		exit_msg("libft : strjoin");
	idx = ft_strlen(s1);
	len = idx + ft_strlen(s2);
	p_idx = 0;
	strjoin = (char *)ft_calloc(len + 1, sizeof(char));
	ft_memcpy(strjoin, s1, ft_strlen(s1));
	ft_memcpy(strjoin + ft_strlen(s1), s2, ft_strlen(s2));
	return (strjoin);
}
