
#include "my_ls.h"


int		my_list_size(t_file *begin_list)
{
	t_file	*probe;
	int		size;

	size = 0;
	probe = begin_list;
	while (probe)
	{
		size++;
		probe = probe->next;
	}
	return (size);
}

void    time_sorting(t_file *start)
{
	int		size;
	int		i;
	long	ret;
    char    *name;
	struct  stat	temp;
	t_file	*probe;

	if (start)
	{
		size = my_list_size(start);
		while (size)
		{
			i = 0;
			probe = start;
			while (++i < size)
			{
				ret = probe->info.st_mtim.tv_sec - probe->next->info.st_mtim.tv_sec;
				if (ret == 0)
					ret = probe->info.st_mtim.tv_nsec - probe->next->info.st_mtim.tv_nsec;
				if (ret < 0)
				{
					temp = probe->info;
					probe->info = probe->next->info;
					probe->next->info = temp;

                    name = probe->name;
					probe->name = probe->next->name;
					probe->next->name = name;
				}
				probe = probe->next;
			}
			size--;
		}
	}
    size = my_list_size(start);
    while (--size)
    {
        printf("%s  ",start->name);
        start = start->next;
    }
    printf("\n");
}

void    name_sorting(t_file *start, int t)
{
	int		size;
	int		i;
    char    *name;
	struct  stat	temp;
	t_file	*probe;
	if (start)
	{
		size = my_list_size(start);
		while (size)
		{
			i = 0;
			probe = start;
			while (++i < size)
			{
                if (my_strcmp(probe->name, probe->next->name) > 0 && probe->name && probe->next->name)
				{
					temp = probe->info;
					probe->info = probe->next->info;
					probe->next->info = temp;

                    name = probe->name;
					probe->name = probe->next->name;
					probe->next->name = name;
				}
				probe = probe->next;
			}
			size--;
		}
	}
    if (t == 0)
    {
        size = my_list_size(start);
        start = start->next;
        while (--size)
        {
            printf("%s  ",start->name);
            start = start->next;
        }
        printf("\n");
    }
}
