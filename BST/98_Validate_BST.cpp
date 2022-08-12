/*Recursion with number limits*/
//TC: O(N)
//SC: O(N)
bool help(TreeNode *root, int mini, int maxi)
{
    if (root == NULL)
        return true;
    if (root->val >= maxi || root->val <= mini)
        return false;

    return help(root->left, mini, root->val) && help(root->right, root->val, maxi);
}

bool isValidBST(TreeNode *root)
{
    if (root == NULL)
        return true;

    return help(root, INT32_MIN, INT32_MAX);
}

/*Recursion with previous node*/
/*Inorder traversal of BST is a monotonically increasing sequence*/
//TC: O(N)
//SC: O(N)
bool help(TreeNode *node, TreeNode *&prev)
{
    if (node == NULL)
        return true;
    if (!help(node->left, prev))
        return false;
    if (prev != NULL && prev->val >= node->val)
        return false;
    prev = node;
    return help(node->right, prev);
}

bool isValidBST(TreeNode *root)
{
    TreeNode *prev = NULL;
    return help(root, prev);
}

/*Iterative with previous node*/
/*Inorder traversal of BST is a monotonically increasing sequence*/
//TC: O(N)
//SC: O(N)
bool isValidBST(TreeNode *root)
{
    stack<TreeNode *> st;

    TreeNode *prev = nullptr;

    while (true)
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }

        if (empty(st))
            break;
        root = st.top();
        st.pop();

        // Visit.
        if (prev && prev->val >= root->val)
            return false;
        prev = root;

        root = root->right;
    }

    return true;
}