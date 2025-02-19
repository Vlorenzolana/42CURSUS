#include <unistd.h>
#include <stdlib.h>
#define BUFFER_SIZE 1000

typedef struct s_buff
{
	char buff[BUFFER_SIZE + 1];
	char *current;
}	t_buff;

char *strNlChr(char *s)
{
	while (*s && *s != '\n')
		++s;
	return (s);
}

int strNlLen(char *s)
{
	int i = 0;
	if (!s)
		return (0);
	while(s[i] && s[i] != '\n')
		++i;
	if (s[i] == '\n')
		++i;
	return (i);
}

char *strNlJoin(char *s1, char *s2)
{
	char *ret = malloc((strNlLen(s1) + strNlLen(s2) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	int i = 0;
	if (s1)
		while (*s1)
			ret[i++] = *(s1++);
	if (s2)
		while (*s2 && *s2 != '\n')
			ret[i++] = *(s2++);
	if ((s2 && *s2 == '\n') || (s1 && *s1 == '\n'))
		ret[i++] = '\n';
	ret[i] = 0;
	return (ret);
}

char *get_next_line(int fd)
{
	if (BUFFER_SIZE < 1)
		return (NULL);
	static t_buff buffer;
	char *nlIndex;
	char *tmp;
	char *ret = NULL;
	int rd;
	while (1)
	{
		if (!buffer.current || !*buffer.current)
		{
			rd = read(fd, buffer.buff, BUFFER_SIZE);
			if (rd >= 0)
				buffer.buff[rd] = 0;
			buffer.current = buffer.buff;
			if (rd < 1)
				return (ret);
		}
		nlIndex = strNlChr(buffer.current);
		if (*nlIndex)
		{
			tmp = ret;
			ret = strNlJoin(tmp, buffer.current);
			if (tmp)
				free(tmp);
			buffer.current = nlIndex + 1;
			return (ret);
		} else {
			tmp = ret;
			ret = strNlJoin(tmp, buffer.current);
			if (tmp)
				free(tmp);
			buffer.current = nlIndex;
		}
	}
	return (ret);
}

/*--------------------------TEST--------------------------*/

#include <fcntl.h>
#include <stdio.h>
int main(void)
{
	int fd = open("test", O_RDONLY);
	char *retStr = NULL;
	if (fd < 1)
		write(1, "\033[31m!!! Le fichier ne c'est pas ouvert !!!", 39);
	//
	//
	write(1, "!!! GNL GO !!!\n", 15);
        while (1)
        {
                retStr = get_next_line(fd);
                printf("%s", retStr);
                if (retStr)
                        free(retStr);
                else    
                        break;
        }    
	close(fd);
	return (0);
}
