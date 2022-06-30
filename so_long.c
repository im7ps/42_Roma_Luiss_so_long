/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:33:26 by sgerace           #+#    #+#             */
/*   Updated: 2022/06/30 22:04:24 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_errors(char	**map, int rows_num)
{
	int	tmp;
	int	i;
	int	j;

	tmp = 0;
	i = 0;
	j = i + 1;
	while (i < rows_num)
	{
		tmp = ft_strlen(map[i]);
		tmp2 = ft_strlen(map[i]);
		i++;
	}
	return (0);
}

char	**create_matrix(rows_num)
{
	int 	fd;
	char	**map;
	int 	i;

	i = 0;
	fd = open("./maps/map1.ber", O_RDONLY);
	map = (char **) malloc (sizeof(char *) * (rows_num + 1));
	while (rows_num--)
	{
		map[i] = get_next_line(fd, 1);
		i++;
	}
	return (map);
}

int count_rows()
{
	char	*row;
	int		fd;
	int		counter;

	counter = 0;
	fd = open("./maps/map1.ber", O_RDONLY);
	row = get_next_line(fd, 1);
	while (row != 0)
	{
		row = get_next_line(fd, 1);
		counter++;
	}
	return (counter);
}

void handle_map()
{
	int		rows_num;
	char	**map;

	rows_num = count_rows();
	map = create_matrix(rows_num);
	check_map_errors(map, rows_num);
}

void	moves_counter(void	*mlx_ptr, void	*win_ptr)
{
	int x = 30;
	int y = 30;
	int color = 0x11FFAA;
	char *string = "moves counter";
	int wtf;

	wtf = mlx_string_put(mlx_ptr, win_ptr, x, y, color, string);
	printf("non so cosa sia ma mlx_string_put vale: %d\n", wtf);
}

void	insert_image(void	*mlx_ptr, void	*win_ptr, int image_posX, \
					int image_posY)
{
	void	*img_ptr;
	int w = 256;
	int h = 256;
	int	*width = &w;
	int	*height = &h;
	char *file_path = "./images/one_piece_img.xpm";

	img_ptr = mlx_xpm_file_to_image(mlx_ptr, file_path, width, height); //crea un'ímmagine in memoria, ritorna void* (l indirizzo in memoria) per poter essere manipolata
	if (img_ptr ==	(void *)0)
	{
		printf("errore nella creazione dell'immagine");
		exit (3);
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, image_posX, image_posY); //visualizza l immagine sul display secondo le coordinate desiderate (x e y)
}

void	draw_line(void	*mlx_ptr, void	*win_ptr, int startX, \
				int startY, int endX, int endY, int color)
{
	double	deltaX = endX - startX;
	double	deltaY = endY - startY;
	double	pixelX = startX;
	double	pixelY = startY;
	int		pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));

	deltaX = deltaX / pixels;
	deltaY /= pixels;
	while (pixels)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, pixelX, pixelY,  color);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
}

void	*initialize_window(void	*mlx_ptr)
{
	void	*win_ptr;
	int		size_x = 1000;
	int		size_y = 1000;
	char	*title = "Hello!";

	win_ptr = mlx_new_window(mlx_ptr, size_x, size_y, title); //crea un nuovo display
	if (win_ptr == (void *)0)
	{
		free(win_ptr);
		printf("errore nella creazione della finestra");
		exit (2);
	}
	return (win_ptr);
}

void	*initialize_pointer()
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init(); //mlx_init ritorna un puntatore che contiene l indirizzo (è void *) del nostro display, lo si usa per manipolarlo, ritorna NULL se qualcosa va storto
	if (mlx_ptr == (void *)0) //come scritto nella guida, il puntatore ritorna (void *)0 in caso di fallimento
	{
		printf("errore di inizializzazione");
		exit (1);
	}
	return (mlx_ptr);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = initialize_pointer();
	win_ptr = initialize_window(mlx_ptr);
	draw_line(mlx_ptr, win_ptr, 0, 0, 1000, 700, 0xFFAAAA);
	insert_image(mlx_ptr, win_ptr, 250, 250);
	moves_counter(mlx_ptr, win_ptr);
	handle_map();
	mlx_loop(mlx_ptr);
	mlx_destroy_window(mlx_ptr, win_ptr);
}
