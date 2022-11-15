/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 22:58:44 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/15 13:24:14 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GLOBAL_H
# define FT_GLOBAL_H

typedef struct s_global
{
	const char	**export_ptr;
	const char	**origin_envp_ptr;
	const char	**origin_envp;
}	t_global;

t_global	g_global;

void	ft_global_init(const char **envp);
int		ft_find_origin_envp(void **ptr);

#endif