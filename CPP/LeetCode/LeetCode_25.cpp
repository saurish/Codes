/*  Author          :   Sauresh Bhowmick
 *  Problem Link    :   https://leetcode.com/problems/reverse-nodes-in-k-group/ 
 *  Comment         :   O(N) algorithm, beat 96.23% 
 */

#include "../all_cpp_header.hpp"

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}

     void push_node(ListNode* node)
     {
         if(next == NULL){
             next = node;
             return;
         }

         ListNode* nxt = next;
         while(nxt->next != NULL)
            nxt = nxt->next;
        
        nxt->next = node;
     }
     
};
 
class Solution {
public:
    
    ListNode* getKThNode(ListNode* head, int k, bool& hasKNodes)
    {
        ListNode* temp = head;
        
        while(temp){
            temp = temp->next;
            k--;
            if(k == 1)
                break;
        }
        
        if (k == 1 && temp){
            
            hasKNodes = true;
            return temp;
        }
        
        return NULL;
    }
    
    ListNode* reverseLinkedList(ListNode* head){
        
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* nextNode = head->next;
        head->next = NULL;
        
        ListNode* listHead = reverseLinkedList(nextNode);
        nextNode->next = head;
        
        return listHead;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        // Base cases
        if(!head)
            return NULL;
        
        if(k == 1)
            return head;
        
        ListNode    *currentHead    = head;
        ListNode    *newListHead    = NULL, *prevListTail   = NULL;
        
        while(currentHead){
            
            bool    hasKNodes     = false; 
            ListNode* currentTail = getKThNode(currentHead, k, hasKNodes);
            
            if(!hasKNodes)
                break;
            
            ListNode* KthPlusOneNode = currentTail->next;
            currentTail->next        = NULL;    // deatch current k-list
            
            ListNode* reversedListHead  =   reverseLinkedList(currentHead);
            if(!newListHead)
                newListHead = reversedListHead;
            
            if(prevListTail)
                prevListTail->next = reversedListHead;
            
            prevListTail        = currentHead;
            currentHead->next   = KthPlusOneNode;   // reverted list tail points to the beginning of next list
                                                    // if next list has < k nodes this assignment will be updated with
                                                    // assigment on line 80
            currentHead         = KthPlusOneNode;   // shift current head.
        }
        
        return newListHead == NULL? head : newListHead;
    }
};

int main()
{
    ListNode* head = new ListNode(1);

    ListNode* new_node = new ListNode(2);
    head->push_node(new_node);
    new_node = new ListNode(3);
    head->push_node(new_node);
    new_node = new ListNode(4);
    head->push_node(new_node);
    new_node = new ListNode(5);
    head->push_node(new_node);

    Solution sln;

    ListNode* reversed_list_head = sln.reverseKGroup(head, 2);

    cout << "Original List : ";
    new_node = head;
    while(new_node){
        cout << new_node->val << " ";
        new_node = new_node->next;
    }
    cout << endl << "Reversed List : ";
    while(reversed_list_head){
        cout << reversed_list_head->val << " ";
        reversed_list_head = reversed_list_head->next;
    }
    cout << endl;
    return 1;
}