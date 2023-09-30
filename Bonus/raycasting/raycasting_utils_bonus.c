/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 10:33:48 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/29 10:53:28 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

float	adjust_angle(float ray_angle)
{
	float	new_angle;

	new_angle = remainder(ray_angle, 2 * M_PI);
	if (new_angle < 0)
		new_angle += (2 * M_PI);
	return (new_angle);
}

static int	horz_increment(t_data *data, t_ray *ray, bool *flag_door, int k)
{
	if (hit_door_horz(data, ray, flag_door, k) == 2)
		return (2);
	ray->y_horz_int += ray->y_step;
	ray->x_horz_int += ray->x_step;
	return (0);
}

void	check_horz_intersection(t_data *data, float ray_angle, bool *flag_door)
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
	ray->x_step = ray->y_step / tan(ray_angle);
	while (ray->x_horz_int >= 0 && ray->x_horz_int <= data->map_width
		* SCALE_SIZE && ray->y_horz_int - k > 0 && ray->y_horz_int - k
		< data->map_height * SCALE_SIZE && data->map[(int)(ray->y_horz_int - k)
		/ SCALE_SIZE][(int)(ray->x_horz_int) / SCALE_SIZE] != '1')
		if (horz_increment(data, ray, flag_door, k) == 2)
			break ;
	ray->horz_dist = sqrt(pow(data->player->x - ray->x_horz_int, 2)
			+ pow(data->player->y - ray->y_horz_int, 2));
}

static int	vert_increment(t_data *data, t_ray *ray, bool *flag_door, int k)
{
	if (hit_door_vert(data, ray, flag_door, k) == 2)
		return (2);
	ray->x_vert_int += ray->x_step;
	ray->y_vert_int += ray->y_step;
	return (0);
}

void	check_vert_intersection(t_data *data, float ray_angle, bool *flag_door)
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
	ray->y_step = ray->x_step * tan(ray_angle);
	while (ray->x_vert_int - k > 0 && ray->x_vert_int - k < data->map_width
		* SCALE_SIZE && ray->y_vert_int >= 0 && ray->y_vert_int
		<= data->map_height * SCALE_SIZE && data->map[(int)ray->y_vert_int 
			/ SCALE_SIZE][(int)(ray->x_vert_int - k) / SCALE_SIZE] != '1')
		if (vert_increment(data, ray, flag_door, k) == 2)
			break ;
	ray->vert_dist = sqrt(pow(data->player->x - ray->x_vert_int, 2)
			+ pow(data->player->y - ray->y_vert_int, 2));
}
