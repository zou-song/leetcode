#include "lc.h"

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1)
            return head;
        ListNode *pre = NULL;
        ListNode *cur = head;
        while (cur)
        {//first, check whether k elements left
            ListNode *node = cur;
            int cnt = 0;
            while (cnt < k)
            {
                if (node == NULL)
                    break;
                node = node->next;
                cnt++;
            }
            if (cnt < k)
            {//no k elements left, no reverse
                if (pre)
                {
                    pre->next = cur;
                }
                break;
            }
            //need reverse
            ListNode *old_head = cur;
            ListNode *slice_pre = NULL;
            for (int i = 0; i < k; ++i)
            {
                ListNode *slice_next = cur->next;
                cur->next = slice_pre;
                slice_pre = cur;
                cur = slice_next;
            }
            if (!pre)
            {
                head = slice_pre;
            }
            else
            {
                pre->next = slice_pre;
            }
            pre = old_head;
        }
        return head;
    }
};

//auxiliary functions from leetcode website
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
        getline(cin, line);
        int k = stringToInteger(line);
        
        ListNode* ret = Solution().reverseKGroup(head, k);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}