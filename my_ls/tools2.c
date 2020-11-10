
#include "my_ls.h"


char *store_flags(int ac, char **av)
{
    char *flag = malloc(sizeof(char) * (2 + 1));

    if (!flag)
        return NULL;
    for (int i = 0; i < 2; i++)
        flag[i] = ' ';
    flag[2] = '\0';
    
    for (int i = 1; i < ac; i++) {
        if (av[i][0] == '-') {
            for (int j = 1; av[i][j]; j++)
            {
                (av[i][j] == 'a') ? flag[0] = 'A': 0;
                (av[i][j] == 't') ? flag[1] = 'T': 0;
                if (flag[0] == 'A' && av[i][j + 1] == 't')
                    {
                        flag[1] = 'T';
                        return (flag);
                    }
                if (flag[1] == 'T' && av[i][j + 1] == 'a')
                    {
                        flag[0] = 'A';
                        return (flag);
                    }
            }
        }
    }
    return flag;
}

char	*get_path(char *path, char *name)
{
    int i = 0;
    char *str = malloc(sizeof(char) * (my_strlen(path) + my_strlen(name)));

    if (!str)
        return NULL;
    if (name[0] == '/')
    {
        str = my_strdup(name);
        return (str);
    }
    for (; path[i]; i++)
        str[i] = path[i];
    str[i] = '/';
    i++;
    for (int j = 0; name[j]; i++, j++)
        str[i] = name[j];
    str[i] = '\0';
    return (str);
}

int print_files(char **files, int a, int t)
{
    t_file          *list;
    t_file          *start;
    struct  stat    st;
    int             i;

    list = (t_file *)malloc(sizeof(t_file) * 100);
    start = list;
    i = 0;
    while (files[i])
    {
        if (stat(files[i], &st) == -1)
            return (0);
        if (*files[0] == '.' && a == 0)
        {
            free(list->name);
            free(list->next);
            continue;
        }
        list->name = my_strdup(files[i]);
        stat(files[i], &st);
        list->info = st;
        list->next = (t_file *)malloc(sizeof(t_file) * 100);
        list->next->name = (char *)malloc(100);
        list = list->next;
        i++;
    }
    free(list->next);
    name_sorting(start, t);
    if(t == 1)
        time_sorting(start);
    return (1);
}

int print_dirs(char *path, int a, int t)
{
    DIR             *fs_dir;
    struct dirent   *dir;
    t_file          *list;
    t_file          *start;
    char            *content_name;
    struct  stat    st;
    char            *path_name;

    fs_dir = opendir(path);
    dir = readdir(fs_dir);
    list = (t_file *)malloc(sizeof(t_file) * 100);
    start = list;
    for (; dir; dir = readdir(fs_dir))
    {
        content_name = dir->d_name;
        if (content_name[0] == '.' && a == 0)
        {
            free(list->name);
            free(list->next);
            continue;
        }
        path_name = get_path(path, content_name);
        if (stat(path_name, &st) == -1)
            return (0);
        list->name = my_strdup(content_name);
        stat(path_name, &st);
        list->info = st;
        list->next = (t_file *)malloc(sizeof(t_file) * 100);
        list->next->name = (char *)malloc(100);
        list = list->next;
        free(path_name);
    }
    free(list->next);
    free(list->name);
    name_sorting(start, t);
    if(t == 1)
        time_sorting(start);
    closedir(fs_dir);
    return (1);
}

