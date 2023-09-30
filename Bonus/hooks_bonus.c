/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:14:52 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/29 10:53:28 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	hide_show_mouse(t_data *data)
{
	if (data->flags->hide_mouse == false)
	{
		mlx_mouse_hide();
		data->flags->hide_mouse = true;
	}
	else
	{
		mlx_mouse_show();
		data->flags->hide_mouse = false;
	}
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		close_game(data);
	else if (keycode == KEY_W)
		data->flags->move_up = true;
	else if (keycode == KEY_S)
		data->flags->move_down = true;
	else if (keycode == KEY_A)
		data->flags->move_left = true;
	else if (keycode == KEY_D)
		data->flags->move_right = true;
	else if (keycode == KEY_LEFT)
		data->flags->rotate_left = true;
	else if (keycode == KEY_RIGHT)
		data->flags->rotate_right = true;
	else if (keycode == KEY_Q)
		hide_show_mouse(data);
	else if (keycode == KEY_R && (data->player->weapon == PISTOL
			|| data->player->weapon == SNIPER) && data->player->ammo < AMMO_MAX)
	{
		play_sound("./sound/reload.wav");
		data->player->ammo = AMMO_MAX;
		data->flags->reload_pistol = true;
	}
	open_door(keycode, data);
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		close_game(data);
	if (keycode == KEY_W)
		data->flags->move_up = false;
	if (keycode == KEY_S)
		data->flags->move_down = false;
	if (keycode == KEY_A)
		data->flags->move_left = false;
	if (keycode == KEY_D)
		data->flags->move_right = false;
	if (keycode == KEY_LEFT)
		data->flags->rotate_left = false;
	if (keycode == KEY_RIGHT)
		data->flags->rotate_right = false;
	return (0);
}

static void	switch_weapon(t_data *data, int keycode)
{
	if (keycode == 2)
	{
		data->flags->switch_weapon = true;
		if (data->player->weapon == SNIPER)
			data->player->weapon = PISTOL;
		else if (data->player->weapon == PISTOL)
			data->player->weapon = SNIPER;
	}
	else if (keycode == 3)
	{
		data->flags->switch_weapon = true;
		if (data->player->weapon == KNIFE)
			data->player->weapon = PISTOL;
		else
			data->player->weapon = KNIFE;
	}
}

int	mouse_hook(int keycode, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (keycode == 1)
	{
		if (data->player->weapon == KNIFE)
		{
			data->flags->knife_shoot = true;
			play_sound("sound/knifehit.wav");
		}
		else
		{
			if (data->player->weapon == PISTOL && data->player->ammo > 0)
				data->flags->pistol_shoot = true;
			if (data->player->weapon == SNIPER && data->player->ammo > 0)
				play_sound("./sound/sniper.wav");
			if (data->player->ammo > 0)
				data->player->ammo--;
			else
				play_sound("./sound/emptygun.wav");
		}
	}
	switch_weapon(data, keycode);
	return (0);
}
