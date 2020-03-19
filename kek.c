#include "libft.h"

typedef unsigned char HashIndexType;
unsigned char Rand8[256];
# define HashTableSize 65536

HashIndexType Hash(char *str) {
    HashIndexType h;
    unsigned char h1, h2;

    if (*str == 0) return 0;
    h1 = *str; h2 = *str + 1;
    str++;
    while (*str) {
        h1 = Rand8[h1 ^ *str];
        h2 = Rand8[h2 ^ *str];
        str++;
    }
  
    /* h is in range 0..65535 */
    h = ((HashIndexType)h1 << 8)|(HashIndexType)h2;
    /* use division method to scale */
    return h % HashTableSize;
}

int main(int argc, char **argv)
{
    char **split = ft_strsplit(argv[0], '/');
    for (int i = 0; i < 2; i++)
        ft_printf("%s\n", split[i]);
    ft_free((void**)split, 2);
    // ft_putnbr(Hash("1"));
    // ft_putnbr(Hash("2"));
}