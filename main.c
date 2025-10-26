#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int    uint_t;

/*
This macro defines the interval of the jumps between each steps of the cipher.
*/
#define INTERVAL 1

/*
void    encode (char *data, char *key);

DESCRIPTION
    The encode function swaps a value with others. It applies the swaps relative
    to the next position of the value.
*/
void    encode (char *data, char *key)
{
    uint_t  last, next, d_index, k_index, d_size, k_size;
    char    tmp;

    last = 0;
    next = 0;
    d_size = strlen (data);
    k_size = strlen (key);
    tmp = 0;

    for (d_index = 0; d_index < d_size; d_index += INTERVAL)
    {
        last = d_index;
        for (k_index = 0; k_index < k_size; k_index++)
        {
            next = (last + (key[k_index] - 48)) % d_size;
            tmp = data[last % d_size];
            data[last % d_size] = data[next];
            data[next] = tmp;
            last = next;
        }
    }
}

/*
void    decode (char *data, char *key);

DESCRIPTION
    This function decode a ciphertext. By the way, this might be useless.
*/
void    decode (char *data, char *key)
{
    int     d_index, k_index, tmp, last, next, d_size, k_size;

    d_size = strlen (data);
    k_size = strlen (key);
    tmp = 0;
    last = 0;
    next = 0;
    for (d_index = 0; d_index < d_size; d_index++)
        d_index += INTERVAL;
    if (d_index > d_size)
        d_index -= INTERVAL;
    k_index = 0;

    for (; d_index >= 0; d_index -= INTERVAL)
    {
        last = d_index;
        for (k_index = 0; k_index < k_size; k_index++)
        {
            next = (last + (key[k_index] - 48)) % d_size;
            tmp = data[last % d_size];
            data[last % d_size] = data[next];
            data[next] = tmp;
            last = next;
        }
    }
}

/*
void    strrev (char *str);

DESCRIPTION
    strrev reverse the elements of a char pointer.
*/
void    strrev (char *str)
{
    char   *start, *end;
    uint_t  tmp;

    start = str;
    end = str + strlen(str) - 1;
    while (start < end)
    {
        tmp = *start;
        *start++ = *end;
        *end-- = tmp;
    }
    
    return;
}

int    main (int argc, char **argv)
{
    char    *data, *key;

    if (argc != 3)
    {
        printf ("Usage:\tbento [PLAINTEXT] [KEY]\n");
        return (1);
    }
    data = argv[1];
    key = argv[2];
    if (!data || !key)
        return (1);
    printf ("Plaintext:\t'%s'\tKey:\t'%s'\n", data, key);
    encode (data, key);
    printf ("Encoded:\t'%s'\n", data);
    strrev (key);
    encode (data, key);
    printf ("Decoded:\t'%s'\tKey:\t'%s'\n", data, key);

    return (0);
}
