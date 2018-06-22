#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct link_s {
    struct link_s *next;
} link_t;

typedef struct link_head_s {
    link_t  *head;
    link_t  *tail;
} link_head_t;

link_head_t*
link_join(link_head_t* head1, link_head_t* head2)
{
    if (head1 == NULL) {
        return NULL;
    }

    if (head2 == NULL) {
        return head1;
    }

    head1->tail->next = head2->head;
    head1->tail = head2->tail;

    return head1;
}


link_t*
link_rm(link_head_t* head, link_t* del_node)
{
    link_t** chg_node = &head->head;
    link_t* node = head->head;

    while(node != del_node) {
        chg_node = &((*chg_node)->next);
        node = node->next;
    }

    if (node == NULL) {
        // Add assert;
        return NULL;
    }

    *chg_node = node->next;
    if (del_node == head->tail) {
        head->tail = node->next;
    }

    assert(del_node == node);
    return del_node;
}

void
link_add_end(link_head_t* head_link, link_t* node)
{
    if (head_link->head == NULL) {
        assert(head_link->tail == NULL);
        head_link->head = head_link->tail = node;
        return;
    }

    head_link->tail->next = node;
    head_link->tail = node;
}

int
link_init_head(link_head_t* head_link, link_t* first_link)
{
    if (head_link == NULL) {
        return -1;
    }

    if (first_link == NULL) {
        return -1;
    }
    link_add_end(head_link, first_link);
    return 0;
}

link_t*
create_new_link()
{
    link_t* link = (link_t*) malloc(sizeof(link_t));

    if (link == NULL) {
        // Return ENOMEM;
        return NULL;
    }

    link->next = NULL;
    
    return link;
}

link_t*
get_midlink(link_head_t* link_head)
{
    link_t* dlink;
    link_t* slink;

    while(dlink && dlink->next && dlink->next->next) {
        slink = slink->next;
        dlink = dlink->next->next;
    }

    return slink;
}

