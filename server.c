/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <adammour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:52:30 by adammour          #+#    #+#             */
/*   Updated: 2025/05/22 18:53:30 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Printf/ft_printf.h"
#include <signal.h>
#include <unistd.h>

void	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	decode_signal(int sig)
{
	static int	bit = 0;
	static char	c = 0;

	if (sig == SIGUSR1)
		c |= (0 << bit);
	else if (sig == SIGUSR2)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
		{
			write(1, "\n", 1);
			putstr("OK");
			write(1, "\n", 1);
		}
		write(1, &c, 1);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	write(1, "Server PID: ", 12);
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, decode_signal);
	signal(SIGUSR2, decode_signal);
	write(1, "\n", 2);
	while (1)
		;
}
