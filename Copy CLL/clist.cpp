#include "clist.h"

int list :: copy_special(list & new_list)
{
    node * stop = rear;

    node *& new_head = new_list.rear;

    return copy_special(new_head, new_list.rear, rear, stop);
    
}

int list :: copy_special(node *& new_copy, node *& to_link, node * original, node * stop)
{
    if(original->next == stop)
    {
        if(original->data %2 == 0)
        {
            new_copy = new node;
            new_copy->data = original->data;
            new_copy->next = to_link;
            return 1;
        }
        new_copy->next = to_link;
        return 0;
    }
    if(original->data %2 == 0)
    {
        new_copy = new node;
        new_copy->data = original->data;
        new_copy->next = NULL;
        return copy_special(new_copy->next, to_link, original->next, stop)+1;
    }
    return copy_special(new_copy, to_link, original->next, stop);
}




























void list :: display_all()
{
    node * sign = rear;
    node * head = rear->next;
    return display_all(head,sign);
}

void list :: display_all(node * head, node * sign)
{
    if(head == sign)
        return;
    cout<<" "<<head->data<<" ->";
    return display_all(head->next,sign);
}
