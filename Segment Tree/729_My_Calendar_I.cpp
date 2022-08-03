/*Brute force*/
//TC: O(N*N)
//SC O(N) 
class MyCalendar
{
public:
    vector<pair<int, int>> arr;
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            int sa = arr[i].first;
            int ea = arr[i].second;
            if ((start >= sa && start < ea) || (sa >= start && sa < end))
                return false;
        }
        arr.push_back({start, end});
        return true;
    }
};


/*Sets*/
//TC: O(NlogN)
//SC O(N) 
class MyCalendar
{
public:
    set<pair<int, int>> st;
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        auto it = st.upper_bound({start, start});
        if (next != st.end() && (*next->second < end))
            return false;
        st.insert({end, start});
        return true;
    }
};


/*Segment Trees*/
//TC: O(NlogN)
//SC O(4*N)  [maybe]
class Node
{
public:
    int startDate, endDate;
    Node *left;
    Node *right;
    Node(int startDate, int endDate)
    {
        this->startDate = startDate;
        this->endDate = endDate;
        this->left = NULL;
        this->right = NULL;
    }
};
class MyCalendar
{
private:
    Node *root;
    bool _book(Node *node, int start, int end)
    {
        if (!node)
        {
            return true;
        }
        else if (node->endDate <= start)
        {
            if (!node->right)
            {
                return true;
            }
            else
            {
                return this->_book(node->right, start, end);
            }
        }
        else if (node->startDate >= end)
        {
            if (!node->left)
            {
                return true;
            }
            else
            {
                return this->_book(node->left, start, end);
            }
        }
        else
        {
            return false;
        }
    }
    Node *_update(Node *node, int start, int end)
    {
        if (!node)
        {
            node = new Node(start, end);
            return node;
        }
        else
        {
            if (node->endDate <= start)
            {
                node->right = this->_update(node->right, start, end);
            }
            else
            {
                node->left = this->_update(node->left, start, end);
            }
            return node;
        }
    }

public:
    MyCalendar()
    {
        this->root = NULL;
    }

    bool book(int start, int end)
    {
        bool ans = this->_book(this->root, start, end);
        if (ans)
        {
            this->root = this->_update(this->root, start, end);
        }
        return ans;
    }
};
