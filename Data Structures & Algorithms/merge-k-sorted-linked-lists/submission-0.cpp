class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;

        ListNode* dummy = new ListNode(0);
        ListNode* ans = dummy;

        while(true) {
            int mi = INT_MAX, idx = -1;

            for(int i = 0; i < lists.size(); i++) {
                if(lists[i] && lists[i]->val < mi) {
                    mi = lists[i]->val;
                    idx = i;
                }
            }

            if(idx == -1) break;

            ans->next = new ListNode(lists[idx]->val);
            ans = ans->next;

            lists[idx] = lists[idx]->next;
        }

        return dummy->next;
    }
};