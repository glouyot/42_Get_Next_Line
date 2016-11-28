#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int		ft_bn(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (0);
		if (*str == '\0')
			return (1);
		str++;
	}
}

int	get_next_line(const int fd, char **line)
{
	int		o;
	static char *reste;
	char *str;

	o = 1;
	if (!reste)
		reste = malloc(sizeof(char*) * BUFF_SIZE + 1);
	str = malloc(sizeof(char*) * BUFF_SIZE + 1);
	while (o)
	{
		read(fd, str, BUFF_SIZE);
		*line = ft_split(str, reste);
		o = 0;
	}
	return (0);
}

char	*ft_split(char *str, char *reste)
{
	char	*new;
	size_t	i;
	size_t	ok;

	ok = 0;
	i = 0;
	while (str[i] != '\n')
		i++;
	new = NULL;
	new = malloc(sizeof(char *) * i + 1);
	while (ok < i)
	{
		new[ok] = str[ok];
		ok++;
	}
	new[ok] = '\0';
	while (*str)
		*reste++ = *str++;
	*reste = '\0';
	return (new);
}

int main(void)
{
	char *str[50];
	int fd;

	fd = open("test.txt", O_RDONLY);
	get_next_line(fd, str);
	printf("%s", *str);
}
