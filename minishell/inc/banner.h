/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   banner.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:26:32 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/09/23 21:28:11 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BANNER_H
# define BANNER_H

//////////////////////////////////
// COLOURS
//////////////////////////////////
# define C_RST "\033[0m"
# define C_YEL "\033[38;5;226m"
# define C_ORG "\033[38;5;214m"
# define C_RED "\033[38;5;196m"
# define C_GRY "\033[38;5;245m"
# define C_WHT "\033[1;38;5;231m"
# define C_CYAN "\033[38;5;51m"
# define C_PINK "\033[38;5;218m"
# define C_LAV "\033[38;5;183m"
# define C_TTL "\033[1;38;5;231m"

//////////////////////////////////
// PRINT BANNER
//////////////////////////////////
void	print_mini42_banner(void);
void	print_shell_banner(void);

#endif