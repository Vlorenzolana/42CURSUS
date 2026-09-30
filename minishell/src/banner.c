/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   banner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:42:20 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/09/23 18:43:51 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "banner.h"
#include "libft.h"

static const char	**get_mini_ascii(void)
{
	static const char	*a[5] = {C_ORG " ##   ##  ###  ##   ##  ###" C_RST,
		C_ORG " ### ###   #   ###  ##   #" C_RST,
		C_ORG " ## # ##   #   #### ##   #" C_RST,
		C_ORG " ##   ##   #   ## ####   #" C_RST,
		C_ORG " ##   ##  ###  ##   ##  ###" C_RST};

	return (a);
}

static const char	**get_shell_ascii(void)
{
	static const char	*a[5] = {C_CYAN " █████  █   █  █████  █      █" C_RST,
		C_CYAN " █      █   █  █      █      █     " C_RST,
		C_CYAN " █████  █████  █████  █      █     " C_RST,
		C_CYAN "     █  █   █  █      █      █     " C_RST,
		C_CYAN " █████  █   █  █████  █████  █████ " C_RST};

	return (a);
}

static const char	**get_flame(int side)
{
	static const char	*f[2][5] = {{C_LAV " )" C_RST, C_CYAN "( " C_RST,
		C_WHT " )" C_RST, C_YEL "( " C_RST, C_ORG " )" C_RST},
	{C_ORG "( " C_RST, C_YEL " )" C_RST, C_PINK "( " C_RST,
		C_LAV " )" C_RST, C_WHT "( " C_RST}};

	if (side != 1)
		side = 0;
	return (f[side]);
}

void	print_mini42_banner(void)
{
	int			i;
	const char	**mini;
	const char	**fl1;
	const char	**fl2;

	mini = get_mini_ascii();
	fl1 = get_flame(0);
	fl2 = get_flame(1);
	ft_putstr((char *)"\n");
	i = 0;
	while (i < 5)
	{
		ft_putstr((char *)fl1[i]);
		ft_putstr((char *)" ");
		ft_putstr((char *)mini[i]);
		ft_putstr((char *)" ");
		ft_putstr((char *)fl2[i]);
		ft_putstr((char *)"\n");
		i++;
	}
}

void	print_shell_banner(void)
{
	int			i;
	const char	**shell;
	const char	**fl1;
	const char	**fl2;

	shell = get_shell_ascii();
	fl1 = get_flame(0);
	fl2 = get_flame(1);
	ft_putstr((char *)"\n");
	i = 0;
	while (i < 5)
	{
		ft_putstr((char *)fl1[i]);
		ft_putstr((char *)" ");
		ft_putstr((char *)shell[i]);
		ft_putstr((char *)" ");
		ft_putstr((char *)fl2[i]);
		ft_putstr((char *)"\n");
		i++;
	}
}
