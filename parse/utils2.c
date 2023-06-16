/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:43:48 by ccestini          #+#    #+#             */
/*   Updated: 2023/04/10 15:44:14 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	ft_count_words(char const *s, char c);
static char	*ft_word_cpy(char const *s, int first, int last);
static void	ft_write_split(char const *s, char **split, char c);

char	**ft_split2(char const *s, char c)
{
	char	**split;

	if (!s)
		return (0);
	split = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!split)
		return (0);
	ft_write_split(s, split, c);
	return (split);
}

static void	ft_write_split(char const *s, char **split, char c)
{
	size_t	i;
	size_t	j;
	int		index;

	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && s[i] != ' ' && s[i] != '\t' && index < 0)
			index = i;
		else if ((s[i] == c || s[i] == ' ' || s[i] == '\t' \
				|| i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = ft_word_cpy(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
}

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] == c || s[i] == ' ' || s[i] == '\t')
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && s[i] != c && s[i] != ' ' && s[i] != '\t')
			i++;
	}
	return (count);
}

static char	*ft_word_cpy(char const *s, int first, int last)
{
	char	*word;
	int		i;

	i = 0;
	if (!s)
		return (0);
	word = malloc((last - first + 1) * sizeof(char));
	if (!word)
		return (0);
	while (first < last)
		word[i++] = s[first++];
	if (word[i - 1] == '\n')
		i--;
	word[i] = '\0';
	return (word);
}
