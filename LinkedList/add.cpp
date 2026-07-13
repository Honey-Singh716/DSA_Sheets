#include <iostream>
using namespace std;


class Node{
    public:
    int val;
    Node* next;

    Node(int val){
       this->val = val;
    }
};


Node* add(Node* l1,Node* l2){

    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry != 0)
    {
        int sum = carry;

        if (l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 1000;
        Node* temp = new Node(sum % 1000);
        
    }
}