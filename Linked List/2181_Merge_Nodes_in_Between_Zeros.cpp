
void del(ListNode *node)
{
    if (node->next == NULL)
    {
        node = NULL;
        return;
    }
    ListNode *toDel = node->next;
    node->next = toDel->next;
    delete toDel;
}

ListNode *mergeNodes(ListNode *head)
{
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    temp = dummy;
    while (temp != NULL)
    {
        if (temp->val == 0 || temp->next->val == 0)
        {
            temp = temp->next;
        }
        else
        {
            temp->val += temp->next->val;
            del(temp);
        }
    }

    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    temp = dummy;
    while (temp != NULL)
    {
        if (temp->next->val == 0)
        {
            del(temp);
        }
        temp = temp->next;
    }
    return dummy->next;
}
