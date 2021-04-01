
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
char		*ft_strjoin_line(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s2)
		return (s1);
	if (!s1)
		return (s2);
	str = (char*)malloc(strlen(s1) + strlen(s2) + 2);
	i = -1;
	while (s1[++i])
	{
		str[i] = s1[i];
	}
	j = -1;
	while (s2[++j])
	{
		str[i] = s2[j];
		i++;
	}
	str[i] = '\n';
	str[i + 1] = '\0';
	//free(s1);
	return (str);
}
char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *new;
    size_t  j;
    if (s1 == NULL || s2 == NULL)
        return (0);
    if (!(new = (char *)malloc(sizeof(char) *
                ((strlen(s1)) + (strlen(s2)) + 1))))
        return (0);
    j = strlen(s1);
    strcpy(new, s1);
    strcpy(new + j, s2);
    new[j] = '\0';
    return (new);
}
int main ()
{
    char *str = "test";
    char *str1 = "souhaik";

    printf("%s",ft_strjoin_line(str,str1));
    printf("\n%s",ft_strjoin(str,str1));
    return (0);
}