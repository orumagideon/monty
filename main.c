#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

ssize_t getline(char **lineptr, size_t *n, FILE *stream);

mlist_t gs;

/**
 * mlist_destroy - Closes file descriptor and frees buffer.
 */
void mlist_destroy(void)
{
    while (gs.size > 0)
        mlist_remove(gs.tail);
    
    if (gs.fd != NULL)
        fclose(gs.fd);
    
    if (gs.buffer != NULL)
        free(gs.buffer);
}

/**
 * main - Monty bytecode interpreter
 * @ac: Argument count
 * @av: Argument variables entered from the command line
 * Return: 0 on success
 */
int main(int ac, char **av)
{
    FILE *FD;
    char *buffer = NULL;
    ssize_t glcount = 0;
    size_t bufflen = 0;

    mlist_init();
    
    if (ac != 2)
        myexit(-1, NULL);
    
    FD = fopen(av[1], "r");
    if (FD == NULL)
        myexit(-2, av[1]);
    
    gs.fd = FD;
    
    while (glcount != -1)
    {
        gs.ln++;
        glcount = getline(&buffer, &bufflen, FD);
        if (glcount == -1)
            break;
        
        gs.buffer = buffer;
        run_opcode(buffer);
    }
    
    mlist_destroy();
    return (EXIT_SUCCESS);
}
