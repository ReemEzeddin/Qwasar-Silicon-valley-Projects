
#include "my_ls.h"

void 		my_ls(char **files, char **dirs, char *flag)
{
    int t;
    int a;
    int i;
    
    t = 0;
    a = 0;
    i = 0;
    if (flag[1] == 'T')
       t = 1;
    if (flag[0] == 'A')
        a = 1;
    if(files[0])
        print_files(files, a, t);
   if (dirs[0] && files[0])
        printf("\n");
	else if (!dirs[0])
		print_dirs(".", a, t);
    while (dirs[i])
    {
       if (dirs[1] || files[0])
            printf("%s\n",dirs[i]);
        print_dirs(dirs[i], a, t);
        if(dirs[i + 1])
            printf("\n");
        i++;
    }
    
}

int main(int ac, char **av)
{
    char    *flags;
    char    **files;
    char    **dirs;
    int     ok;

    ok = 0;
    if (ac == 1)
    {
        print_dirs(".",0 ,0);
        return (1);
    }
    if (my_strcmp(av[0], "./my_ls") != 0)
        {
            printf("wrong command !\n");
            return (0);
        }
    files = (char **)malloc(100 * sizeof(char *));
    dirs = (char **)malloc(100 * sizeof(char *));
    ok = get_files_dirs(files, dirs, av + 1);
    if (ok == 0)
		return (0);
    flags = store_flags(ac, av);
    my_ls(files, dirs, flags);
    free(flags);
    free(files);
    free(dirs);
    return (1);
}
