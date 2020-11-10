
#ifndef MY_LS_H
# define MY_LS_H

# include <sys/stat.h>
# include <sys/types.h>
# include <dirent.h>
# include <time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

//#undef  st_atime
//#define st_mtime st_mtim->tv_sec

typedef struct	s_file
{
	char            *name;
	struct  stat    info;
    struct  s_file  *next;
}   t_file;

//*******************  **   Tools 1  **  *****************

int     my_strcmp(char *s1, char *s2);
char	*my_strdup(char *src);
int     my_strlen(char *s);
void	*my_memset(void *str, int c, int n);

//*******************  **   Tools 2  **  *****************

char    *get_path(char *path, char *name);
int     print_dirs(char *path, int a, int t);
int     print_files(char **files, int a, int t);
char    *store_flags(int ac, char **av);

//*******************  **   Sorting  **  *****************

void    time_sorting(t_file *start);
void    name_sorting(t_file *start, int t);
int		my_list_size(t_file *begin_list);

//*******************  **   F_or_D  **  *****************

int     is_dir(char *path);
int     fileexists(char *name);
int     get_files_dirs(char **files,char **dirs, char **av);

//*******************  **   My_ls  **  *******************

void 	my_ls(char **files,char **dirs,char *flag);


#endif
