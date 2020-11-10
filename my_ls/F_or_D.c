
#include "my_ls.h"

int is_dir(char* name)
{
    DIR* directory = opendir(name);

    if(directory != NULL)
    {
     closedir(directory);
     return 1;
    }
    return (0);
}

int is_file(char *name)
{
    DIR* directory = opendir(name);

    if(directory != NULL)
    {
     closedir(directory);
     return (0);
    }
    return (1);
}
int fileexists(char *filename){
    struct stat buffer;
    int         exist;
    exist = stat(filename,&buffer);
    if(exist == 0)
        return 1;
    else
        return 0;
}

int     get_files_dirs(char **files,char **dirs, char **av)
{
    int f;
    int d;
    int i;

    f = 0;
    d = 0;
    i = 0;
    while (av[i] != NULL)
    {
        if (av[i][0] == '-')
        {
            i++;
            continue;
        }
        if (is_dir(av[i]))
        {
            dirs[d] = (char *)malloc(100);
            dirs[d++] = my_strdup(av[i]);
        }
        else if (fileexists(av[i]))
        {
            files[f] = (char *)malloc(100); 
            files[f++] = my_strdup(av[i]);
        }
        else
        {
            printf("cannot access '%s': No such file or directory/n", av[i]);
            return (0);
        }
        i++;
    }
    return (1);
}
