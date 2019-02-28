#include "lc.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head)
        {
            return head;
        }
        ListNode *ln1 = head;
        if (!ln1->next)
        {
            return ln1;
        }
        head = ln1->next;
        ListNode *pre = NULL;
        while (ln1 && ln1->next)
        {
            ListNode *ln2 = ln1->next;
            ln1->next = ln2->next;
            ln2->next = ln1;
            if (pre)
            {
                pre->next = ln2;
            }
            pre = ln1;
            ln1 = ln1->next;
        }
        return head;
    }
};

//auxiliary functions copied from leetcode website
ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main(int argc, char *argv[])
{
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        
        ListNode* ret = Solution().swapPairs(head);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}