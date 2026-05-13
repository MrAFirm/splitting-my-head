/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:10:16 by lkhye-ya          #+#    #+#             */
/*   Updated: 2026/05/13 18:15:33 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
// #include <stdio.h>

int	word_count(const char *str);

char	**ft_split(const char *str)
{
	int		i;
	int		countwords;
	char	**buffer;
	int		start;
	int		end;
	int		strlen;
	int		count;
	int		len;

	i = 0;
	countwords = word_count(str);
	count = 0;
	buffer = malloc(sizeof(char *) * (countwords + 1));
	if (buffer == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;
		start = i; // after skipping space then index will definitely be first char.
		while (str[i] != '\0' && str[i] != ' ')
			i++;
		end = i;
		strlen = end - start;
		buffer[count] = malloc(sizeof(char) * (strlen + 1));
		if (buffer[count] == NULL)
			return (NULL);
		len = 0;
		while (len < strlen)
		{
			buffer[count][len] = str[start];
			len++;
			start++;
		}
		buffer[count][len] = '\0';
		count++;
	}
	buffer[count] = NULL;
	return (buffer);
}

int	word_count(const char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str != NULL)
	{
		while (str[i] != '\0')
		{
			if (str[i + 1] == '\0' || str[i + 1] == ' ')
				count++;
			i++;
		}
	}
	return (count);
}

/*
char	*malloc_word(int start, int end)
{
	int	len;
	
	
	len = end - start;
	

}

int	word_len(const char *word)
{
	int	i;

	i = 0;
	while (word[i] != '\0')
	i++;
	return (i);
}
*/

/*
int	main()
{
	printf("%d\n", word_count(" Hello World!"));
	char	**buffer = ft_split("Hello World!");
	int		i = 0;
	
	while (buffer[i])
	{
		printf("%s\n", buffer[i]);
		i++;
	}
	free(buffer);
}
*/
