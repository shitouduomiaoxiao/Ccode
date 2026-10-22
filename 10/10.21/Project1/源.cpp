#define  _CRT_SECURE_NO_WARNINGS
Definition for singly - linked list.
 struct ListNode {
    int val;
    struct ListNode* next;
    
};

struct ListNode* addTwo(struct ListNode* l1, struct ListNode* l2, int carry) {
    if (l1 == NULL && l2 == NULL && carry == 0) {
        return NULL;
    }
    int s = carry;
    if (l1) {
        s += l1->val;
        l1 = l1->next;
    }
    if (l2) {
        s += l2->val;
        l2 = l2->next;

    }
    struct ListNode* node = malloc(sizeof(struct ListNode));
    node->val = s % 10;
    node->next = addTwo(l1, l2, s / 10);
    return node;




}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    return addTwo(l1, l2, 0);
}