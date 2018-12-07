/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:18:19 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/12/07 16:23:53 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MLX_H
# define LIBFT_MLX_H

# include <mlx.h>

# define X_KEYPRESS 2
# define X_KEYRELEASE 3
# define X_MOTIONNOTIFY 6
# define X_KEYPRESSMASK (1L<<0)
# define X_KEYRELEASEMASK (1L<<1)
# define X_BUTTON3MOTIONMASK (1L<<10)
# define X_BUTTON4MOTIONMASK (1L<<11)
# define X_BUTTON5MOTIONMASK (1L<<12)
# define X_BUTTONMOTIONMASK (1L<<13)
# define X_KEYMAPSTATEMASK (1L<<14)
# define X_EXPOSUREMASK (1L<<15)
# define X_VISIBILITYCHANGEMASK (1L<<16)
# define X_STRUCTURENOTIFYMASK (1L<<17)
# define X_RESIZEREDIRECTMASK (1L<<18)
# define X_SUBSTRUCTURENOTIFYMASK (1L<<19)
# define X_BUTTONPRESSMASK (1L<<2)
# define X_SUBSTRUCTUREREDIRECTMASK (1L<<20)
# define X_FOCUSCHANGEMASK (1L<<21)
# define X_PROPERTYCHANGEMASK (1L<<22)
# define X_COLORMAPCHANGEMASK (1L<<23)
# define X_BUTTONRELEASEMASK (1L<<3)
# define X_ENTERWINDOWMASK (1L<<4)
# define X_LEAVEWINDOWMASK (1L<<5)
# define X_POINTERMOTIONMASK (1L<<6)
# define X_POINTERMOTIONHINTMASK (1L<<7)
# define X_BUTTON1MOTIONMASK (1L<<8)
# define X_BUTTON2MOTIONMASK (1L<<9)

# define X_KEY_A 0
# define X_KEY_S 1
# define X_KEY_D 2
# define X_KEY_F 3
# define X_KEY_H 4
# define X_KEY_G 5
# define X_KEY_Z 6
# define X_KEY_X 7
# define X_KEY_C 8
# define X_KEY_V 9
# define X_KEY_B 11
# define X_KEY_Q 12
# define X_KEY_W 13
# define X_KEY_E 14
# define X_KEY_R 15
# define X_KEY_Y 16
# define X_KEY_T 17
# define X_KEY_1 18
# define X_KEY_2 19
# define X_KEY_3 20
# define X_KEY_4 21
# define X_KEY_6 22
# define X_KEY_5 23
# define X_KEY_9 25
# define X_KEY_7 26
# define X_KEY_8 28
# define X_KEY_0 29
# define X_KEY_BRACE_R 30
# define X_KEY_O 31
# define X_KEY_U 32
# define X_KEY_BRACE_L 33
# define X_KEY_I 34
# define X_KEY_P 35
# define X_KEY_L 37
# define X_KEY_J 38
# define X_KEY_K 40
# define X_KEY_SEMI 41
# define X_KEY_N 45
# define X_KEY_M 46
# define X_KEY_TAB 48
# define X_KEY_PLUS 69
# define X_KEY_MINUS 78
# define X_KEY_NUM_1 83
# define X_KEY_NUM_2 84
# define X_KEY_NUM_3 85
# define X_KEY_LEFT 123
# define X_KEY_RIGHT 124
# define X_KEY_DOWN 125
# define X_KEY_UP 126
# define X_KEY_ESC 53

#endif
