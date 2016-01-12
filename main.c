/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 16:15:27 by gahubaul          #+#    #+#             */
/*   Updated: 2015/12/10 16:15:30 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fillit.h"

int			count_tetri(char *buff)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (buff[i])
	{
		if (buff[i] != '\n')
			count++;
		i++;
	}
	count = count / 16;
	return (count);
}

void		ft_error(char *argv)
{
	char	buff[BUFF_SIZE + 1];
	int		file_descriptor;
	int		read_result;

	if ((file_descriptor = open(argv, O_RDONLY)) == -1)
		ft_error_exit("error");
	if ((read_result = read(file_descriptor, buff, BUFF_SIZE)) == -1)
		ft_error_exit("error");
	buff[read_result] = '\0';
	if (close(file_descriptor) == -1)
		ft_error_exit("error1");
	if (ft_count_enter(buff) == 0)
		ft_error_exit("error2");
	if (ft_count_char_tetri(buff) == 0)
		ft_error_exit("error3");
	if (ft_count_sharp(buff) == 1)
		ft_error_exit("error4");
	if (ft_count_char_sharp_line(buff) == 0)
		ft_error_exit("error5");
	if (ft_check_block(buff) < 6)
		ft_error_exit("error6");
	if (ft_tab_buff(buff) == NULL)
		ft_error_exit("error7");
	ft_resolve(ft_tab_buff(buff), count_tetri(buff));
}

int			main(int argc, char **argv)
{
	if (argc == 2)
		ft_error(argv[1]);
	else if (argc != 2)
		ft_error_exit("erreur");
	return (0);
}