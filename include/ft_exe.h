/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exe.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:56:36 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/15 14:19:26 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXE_H
# define FT_EXE_H

# include <ft_cmd.h>

void	ft_exe(t_cmd *cmd, int flag);
int		ft_execute(char *argv[]);
#endif