/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 07:31:00 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/14 09:48:38 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CMD_H
# define FT_CMD_H

typedef struct s_cmd
{
	char	**argv;
	int		fd_in;
	int		fd_out;
}	t_cmd;

int		ft_cmd(char *str);

char	**ft_argv_add(t_cmd *cmd, char *str);
void	ft_argv_free(t_cmd *cmd);

char	*ft_redirect(t_cmd *cmd, char *str);
#endif