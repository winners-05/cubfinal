#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int get_next_line(char **line)
{
    int i = 0; int ret =0; static char *str; char *buff; char *tmp;
    *line = ft_stock(NULL,"",0);
    if (str)
    {
        i = ft_count(str);
        *line = ft_stock(*line, str, i);
        if (str[i] == '\n')
        {
            tmp = str;
            str = ft_stock(0, str + i + 1, ft_strlen(str) - i - 1);
            free(tmp); tmp = NULL;
            return(1);
        }
        free(str); str=NULL;
    }
    buff = malloc(BUFFER_SIZE + 1);
    while ((ret = (read(0, buff, BUFFER_SIZE))))
    {
        if (ret == -1)
            return (-1);
        if (buff[ret] != -1)
            buff[ret] = '\0';
        i = ft_count(buff);
        *line = ft_stock(*line, buff,i);
        if (buff[i] == '\n')
        {
            str = ft_stock(str, buff + i + 1, ret -i-1);
            free(buff); buff = NULL;
            return(1);
        }
    }
    free(buff); buff = NULL;
    return(0);
}
int get_next_line(char **line)
{
    int i = 0;
    int ret = 0;
     static char *str;
     char *tmp;
     char *buff;
     *line = ft_stock(NUll,"",0);
     if(str)
     {
         i = ft_count(str);
         *line = ft_stock(*line,str,i);
         if (str == '\n')
         {
             tmp = str;
             str = ft_stock(0,str + i + 1 , ft_strlen(str) - 1 - i);
             free(tmp);
            tmp = NULL;
            return (1);
         }
     }
}