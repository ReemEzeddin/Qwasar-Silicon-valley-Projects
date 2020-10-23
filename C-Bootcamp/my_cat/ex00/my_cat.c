#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#define BUF_SIZE 1000

void	my_cat(int f, char *s)
{
	int		r;
	char	buffer[BUF_SIZE];

	while ((r = read(f, buffer, BUF_SIZE)))
	{
		if (r == -1)
		{
			printf("ERROR..!!");
			return ;
		}
		buffer[r] = '\0';
		printf("%s",buffer);
	}
}
int		main(int argc, char **argv)
{
	int	i;
	int	file;

	i = 0;
	while (++i < argc)
	{
		if ((file = open(argv[i], O_RDONLY)) == -1)
			printf("ERROR..!!");
		if (file != -1)
			my_cat(file, argv[i]);
		close(file);
	}
	return (0);
}
