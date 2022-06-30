/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 23:19:46 by sgerace           #+#    #+#             */
/*   Updated: 2022/06/30 19:00:22 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include "./libft/includes/libft.h"
# include "./libft/includes/ft_printf.h"
# include "./libft/includes/get_next_line.h"
# include "mlx.h"

void	*initialize_window(void	*mlx_ptr);
void	*initialize_pointer();
void	draw_line(void	*mlx_ptr, void	*win_ptr, int startX, \
				int startY, int endX, int endY, int color);
void	insert_image(void	*mlx_ptr, void	*win_ptr, int image_posX, \
					int image_posY);
void	moves_counter(void	*mlx_ptr, void	*win_ptr);

#endif
