/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        Node *ans= new Node(head->val);
        Node *a=ans,*b=head,*crnt;
        int i=1;
        while(b)
        {
            if (b->next)
                a->next = new Node(b->next->val);
            else{
            a->next = nullptr;}
            a=a->next;
            b->val=i++;
            b=b->next;
        }
        b=head;
        crnt=ans;
        int j=1;
        while(b)
        {   a=ans;
            if(b->random)
            {
                int t=b->random->val;
                j=1;
                while(j<t)
                {
                    a=a->next;
                    j++;
                }
                crnt->random=a;
                b=b->next;
                crnt=crnt->next;
            }
            else
            {
               while(a){a=a->next;}
                crnt->random=a;
                b=b->next;
                crnt=crnt->next;
            }
        }
        return ans;
    }
};
