#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "stddef.h"

typedef struct path_node
{
    char *dir;
    struct path_node *next;
} path_node;

path_node *build_path_list(void)
{
    char *path = getenv("PATH");
    if (!path)
        return (NULL);

    char *path_copy = strdup(path);
    if (!path_copy)
        return (NULL);

    char *token = strtok(path_copy, ":");
    path_node *head = NULL, *tail = NULL;

    while (token)
    {
        // create a new node
        path_node *new_node = malloc(sizeof(path_node));
        if (!new_node)
        {
            perror("malloc failed");
            break;
        }

        new_node->dir = strdup(token); // copy the path_dir to new node
        new_node->next = NULL; // new_node is not linked yet

        // add to thee list
        if (!head)
        {
            head = new_node;
            tail = new_node; // become first and only node in the list
        }
        else // if the list already has nodes
        {
            tail->next = new_node; // link new_node to the end of list
            tail = new_node; // add new_node to the end by updating the tail to be new_node
        }

        token = strtok(NULL, ":");
    }

    free(path_copy);
    return (head);
}

void print_path_list(path_node *head)
{
    while (head)
    {
        printf("%s\n", head->dir);
        head = head->next;
    }
}

void free_path_list(path_node *head)
{
    path_node *tmp;
    while (head)
    {
        tmp = head; // hold current node
        head = head->next; // move to the next node
        free(tmp->dir);
        free(tmp); // free the current one
    }
}

int main(void)
{
    path_node *list = build_path_list();

    print_path_list(list);
    free_path_list(list);

    return (0);
}