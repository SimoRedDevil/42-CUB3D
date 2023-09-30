/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 10:33:48 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/28 20:31:25 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float	adjust_angle(float ray_angle)
{
	float	new_angle;

	new_angle = remainder(ray_angle, 2 * M_PI);
	if (new_angle < 0)
		new_angle += (2 * M_PI);
	return (new_angle);
}

static void	horz_increment(t_ray *ray)
{
	ray->y_horz_int += ray->y_step;
	if (ray->ray_looking_right && ray->x_step < 0)
		ray->x_step *= -1;
	else if (!ray->ray_looking_right && ray->x_step > 0)
		ray->x_step *= -1;
	ray->x_horz_int += ray->x_step;
}

void	check_horz_intersection(t_data *data, float ray_angle)
{
	t_ray	*ray;
	int		k;

	ray = data->ray;
	k = 0;
	ray->y_horz_int = floor(data->player->y / SCALE_SIZE) * SCALE_SIZE;
	if (ray->ray_looking_down)
		ray->y_horz_int += SCALE_SIZE;
	else
		k = 1;
	ray->x_horz_int = data->player->x
		+ (ray->y_horz_int - data->player->y) / tan(ray_angle);
	ray->y_step = SCALE_SIZE;
	if (!ray->ray_looking_down)
		ray->y_step *= -1;
	ray->x_step = SCALE_SIZE / tan(ray_angle);
	while (ray->x_horz_int > 0 && ray->x_horz_int < data->map_width
		* SCALE_SIZE && ray->y_horz_int - k > 0 && ray->y_horz_int - k
		< data->map_height * SCALE_SIZE && data->map[(int)(ray->y_horz_int - k)
		/ SCALE_SIZE][(int)(ray->x_horz_int) / SCALE_SIZE] != '1')
		horz_increment(ray);
	ray->horz_dist = sqrt(pow(data->player->x - ray->x_horz_int, 2)
			+ pow(data->player->y - ray->y_horz_int, 2));
}

static void	vert_increment(t_ray *ray)
{
	ray->x_vert_int += ray->x_step;
	if (ray->ray_looking_down && ray->y_step < 0)
		ray->y_step *= -1;
	else if (!ray->ray_looking_down && ray->y_step > 0)
		ray->y_step *= -1;
	ray->y_vert_int += ray->y_step;
}

void	check_vert_intersection(t_data *data, float ray_angle)
{
	t_ray	*ray;
	int		k;

	ray = data->ray;
	k = 0;
	ray->x_vert_int = floor(data->player->x / SCALE_SIZE) * SCALE_SIZE;
	if (ray->ray_looking_right)
		ray->x_vert_int += SCALE_SIZE;
	else
		k = 1;
	ray->y_vert_int = data->player->y
		+ (ray->x_vert_int - data->player->x) * tan(ray_angle);
	ray->x_step = SCALE_SIZE;
	if (!ray->ray_looking_right)
		ray->x_step *= -1;
	ray->y_step = SCALE_SIZE * tan(ray_angle);
	while (ray->x_vert_int - k > 0 && ray->x_vert_int - k < data->map_width
		* SCALE_SIZE && ray->y_vert_int >= 0
		&& ray->y_vert_int <= data->map_height * SCALE_SIZE
		&& data->map[(int)ray->y_vert_int / SCALE_SIZE]
		[(int)(ray->x_vert_int - k) / SCALE_SIZE] != '1')
		vert_increment(ray);
	ray->vert_dist = sqrt(pow(data->player->x - ray->x_vert_int, 2)
			+ pow(data->player->y - ray->y_vert_int, 2));
}
