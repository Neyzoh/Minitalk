/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <adammour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:52:27 by adammour          #+#    #+#             */
/*   Updated: 2025/05/29 15:24:56 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Printf/ft_printf.h"
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	correct_pid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	send_string(pid_t pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (pid == 0 || kill(pid, 0) == -1)
		{
			ft_printf("Error invalid PID\n");
			exit(EXIT_FAILURE);
		}
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(10);
		i++;
	}
}

int	main(int ac, char **av)
{
	int		i;
	pid_t	pid;
	char	*str;

	if (ac != 3)
	{
		write(1, "Error arguments missing\n", 25);
		return (EXIT_FAILURE);
	}
	i = 0;
	pid = atoi(av[1]);
	str = av[2];
	if (!correct_pid(av[1]))
	{
		ft_printf("Error invalid PID\n");
		return (EXIT_FAILURE);
	}
	while (str[i])
		send_string(pid, str[i++]);
	send_string(pid, '\0');
	return (EXIT_SUCCESS);
}
