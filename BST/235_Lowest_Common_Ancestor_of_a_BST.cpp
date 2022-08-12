TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
        return NULL;
    TreeNode *cur = root;
    while (cur)
    {
        if (p->val < cur->val && q->val < cur->val)
            cur = cur->left;
        else if (p->val > cur->val && q->val > cur->val)
            cur = cur->right;
        else
            break;
    }
    return cur;
}

/*
if both p & q are smaller than the root node that means both lies on the left side of the root node.
else if both p & q are greater than the root node that means both lies on the right side of the root node.
The moment we cant say the position of both the nodes from the current node is our required answer.
*/