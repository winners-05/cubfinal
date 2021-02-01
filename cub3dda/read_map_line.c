#include "cub3d.h"
#include <stdio.h>
void read_map_line(char *str)
{
    if (str[0] != '\0' && !g_map_st)
        g_map_st = 1; 
    if (g_map_st && (str[0] != '\0'))
        g_map = ft_strjoin_line(g_map, str);
    if (g_map_st && str[0] == '\0')
    {
        ft_putstr("new lline");
        exit(0);
    }
}

void check_map_arrays(char *str)
{
    int i;
    i = 0;
    if (str[i] == '\0')
    {
        ft_putstr("map doesnt exist");
        exit(0);
    }
    while (str[i] != '\0')
    {
        if ((str[i] != '1' && str[i] != '0' && str[i] != ' ' && str[i] != '2' && 
        str[i] != 'N' && str[i] !='S' && str[i] != 'E' && str[i]!= 'W' )
         && str[i] != '\n' )
        {
            ft_putstr("ERROR \n Check your MAP");
            exit(0);
        }
        i++;
    }
  
}

void split_map(void)
{
    g_allmap = ft_split(g_map, '\n'); 
}

void fill_map(char **str)
{
    int i;
    int j;
    int x;
    int y;
    i = 1;
    j = 1;
    x = 0;
    y = 0;
    while (x < g_mheight)
    {
        while (y < g_mwidth)
        {
            if (y < ft_strlen(g_allmap[x]))
                str[i][j] = g_allmap[x][y];
            else
                str[i][j] = ' ';
            y++;
            j++;            
        }
        i++;
        x++;
        j = 1;
        y = 0;
    }
}
void check_arrays()
{

 int i;
 int j;
 int x;
 i = 0;
 j = 0;
 x = 0;
 while (g_allmap[i])
 {
     while (g_allmap[i][j] != '\0')
        j++;
    i++;
    if (j > x)
        x = j;
    j = 0;
 }
  g_mwidth = x;  
}
void check_width()
{
    int i;
    i = 0;
    while (g_allmap[i])
        i++;
    g_mheight = i;
}
void fill_spaces(char **str)
{
    int i;
    int j;
    i = 0;
    j = 0;
    while (str[i])
    {
        while (j < g_mwidth + 2)
            j++;
        str[i][j] = '\0';
        i++;
        j = 0;
    }
    i = 0;
    j = 0;
    while (i < g_mheight + 2)
    {  
        j = 0;
        while ( j < g_mwidth + 2)
        {
            str[i][j] = ' ';
            j++;
        }
        i++;
       
    }

}


int check (int i , char c)
{
    if (i == 0)
    {
        if (c != 1 && c != '0' && c != 2 && c != 'N' && c != 'W' && c != 'E' && c != 'S' && c != 'S' && c != ' ')
            return (1);
        return (0);
    }
    return (0);
}
void check_close(char **str)
{
    int i;
    int j;

    i =     0;
    while (i <= g_mheight )
    {  
        j = 0;
        while (j <= g_mwidth)
        {
                 if (str[i][j] != ' ' && str[i][j] != '1')
                      {
                      if ((str[i - 1][j] == ' ') || (str[i+1][j] == ' ') || (str[i][j-1] == ' ') || (str[i][j+1] == ' '))
                        {
                        ft_putstr("map isnt closed");
                        exit(0);
                       }
                }
            
            j++;
        }
        i++;
    }
 //   fill_map_with_one(str);
}
void fill_map_with_one(char **str)
{
    int i;
    int j;
    i = 0;
    j = 0;
    while (str[i])
    {  
        j = 0;
        while (str[i][j])
        {
            if (str[i][j] == ' ')
                str[i][j] = '1';
            j++;
        }
        i++;
    }
}

void check_player(char **str)
{
	int i;
	int j;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'N' || str[i][j] == 'E' || str[i][j] == 'S' || str[i][j]== 'W')
			{
                init_player(str[i][j], j , i );
			}
			
			j++;
		}
		i++;
	}
}
void init_player(char x,int i, int j)
{
    if (g_p)
    {
        ft_putstr("more than one player");
        exit(0);
    }
    else 
    {
         player.x = (i * TILE_SIZE) + (TILE_SIZE / 2);
        player.y = (j * TILE_SIZE) + (TILE_SIZE / 2);
         g_p = 1;
        if (x == 'N')
            player.rtang =270 * (M_PI / 180);
        else if (x == 'S')
            player.rtang =  90 * (M_PI / 180);
        else if (x == 'E')
            player.rtang = 0;
        else if (x == 'W')
            player.rtang = M_PI;
        player.FOV = 60 * (M_PI / 180);
		player.turnDirection = 0;
		player.walkDirection = 0;
		player.MoveSpeed = 10;
		player.rotationSpeed= 4 * (M_PI / 180);     
    }
    
}
void check_play_exist()
{
    if (player.x == -1 || player.y == -1)
    {
        ft_putstr("Player not FOUND");
         exit(0);
    }
}
void fill_g_allmap()
{
    char **str;
    int i;
    i = 0;
    str = (char **)malloc((g_mheight + 3) * sizeof(char*));
    while (i < g_mheight + 2)
    {
        str[i] = (char *)malloc((g_mwidth + 3) * sizeof(char));
        i++;
    }
    str[i] = NULL;
    fill_spaces(str);
    fill_map(str);
    check_close(str);
    fill_map_with_one(str);
    check_player(str);
    check_play_exist();
    g_allmap_with_spaces = str;
    free_memory(g_allmap);
    
    
}
