/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:50:55 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/14 13:30:40 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DIR_H
# define FT_DIR_H

void ft_dir_view(char *name);
struct dirent	*ft_readdir_get_file(char *dir_name, char *file_name);

#endif