#define  _CRT_SECURE_NO_WARNINGS
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prve = NULL;
    struct ListNode* cur = head;
    struct ListNode* nxt = NULL;
    while (cur) {
        nxt = cur->next;
        cur->next = prve;
        prve = cur;
        cur = nxt;
    }
    return prve;
}
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    else {
        struct ListNode* newhead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newhead;
    }

}
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* newhead = NULL;
    struct ListNode* newtail = NULL;




    while (head) {
        struct ListNode* prve = NULL;
        struct ListNode* cur = head;
        while (cur->next) {
            prve = cur;
            cur = cur->next;

        }
        struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newnode->val = cur->val;
        newnode->next = NULL;
        if (newhead)
        {
            newtail->next = newnode;
        }
        else
        {
            newhead = newnode;
        }
        newtail = newnode;
        if (prve == NULL) {
            free(head);
            head = NULL;
        }
        else {
            prve->next = NULL;
            free(cur);
        }




    }

    return newhead;


