/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <adammour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:52:27 by adammour          #+#    #+#             */
/*   Updated: 2025/05/22 18:53:57 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void	send_string(pid_t pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
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

	if (ac == 3)
	{
		i = 0;
		pid = atoi(av[1]);
		str = av[2];
		while (str[i])
		{
			send_string(pid, str[i]);
			i++;
		}
		send_string(pid, '\0');
		return (0);
	}
	write(1, "Error arguments missing\n", 25);
	return (1);
}
