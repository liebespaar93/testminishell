/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exe.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:56:36 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/16 16:05:06 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXE_H
# define FT_EXE_H

# include <ft_cmd.h>

void	ft_exe(t_cmd *cmd, int flag, int last_exe);
int		ft_execute(char *argv[]);
#endif