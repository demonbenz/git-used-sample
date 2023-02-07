#include<stdio.h>
#include<stdlib.h>


int	ft_wordlen(char *str)
{
	int i = 0;

	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		++i;
	return (i);
} 

int count_w(char  *word)
{
  int i;
  int tik;
  int count;
  
  count = 0;
  tik = 0;
  i = 0;
  while(word[i] != '\0')
  {
    if (word[i] == '\n' || word[i] == '\t' || word[i] == ' ')
    {
      tik = 0;
      }
      else if(tik == 0)
      {
        count++;
        tik = 1;
        }
    i++;
    }
    return (count);
  }


char    *word_dupe(char *str)
{
    int i = 0;
    int len = ft_wordlen(str);
    char *word = malloc(sizeof(char) * (len + 1));
    
    word[len] = '\0';
    while (i < len)
    {
        word[i] = str[i];
        ++i;
    }
    return (word);
}

void    fill_words(char **array, char *str)
{
    int word_index = 0;
    
    while (*str == ' ' || *str == '\t' || *str == '\n')
        ++str;
    while (*str != '\0')
    {
        array[word_index] = word_dupe(str);
        ++word_index;
        while (*str != '\0' && *str != ' ' && *str != '\t' && *str != '\n')
            ++str;
        while (*str == ' ' || *str == '\t' || *str == '\n')
            ++str;
    }
}

char    **ft_split(char *str)
{
    char  **tmp;
    int w_count;
    
    w_count = count_w(str);
    tmp = (char **)malloc(sizeof(char *) * (w_count + 1));
    tmp[w_count] = 0;
    
    fill_words(tmp, str);
    return(tmp);
  }
  
int main() {
  char  *line;
  char  **words;
  int i;

  line = "\nthis is a long long word could be split by\t\nnewline.\n";
  words = ft_split(line);
  
  i = 0;
  while(words[i])
  {
    printf("%s\n", words[i]);
    i++;
    }
    
  return 0;
}