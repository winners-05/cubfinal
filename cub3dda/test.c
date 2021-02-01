#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int ft_strlen(char *str)
{
	int i;
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
char	*ft_strjoin(char  *s1, char  *s2)

{
int		i;
	int		len1;
	int		len2;
	char	*str;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		str = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
		if (str == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			str[len1] = s2[i];
			len1++;
		}
		//str[i] = '\n';
		str[len1] = '\0';
		free(str);
		return (str);
	}
	return (NULL);
}

int main()
{
	char *str = "1111n1111111";
	int i;
	i = 0;
	while (str[i] != '\0')
	{
		
	}

}

