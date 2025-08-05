#include "bits/stdc++.h"
using namespace std;


//문제 : tail칸을 추가하면 cursor를 지우는 것이 왼쪽 애를 지우도록 해야하는데
// 그렇게 해버리면
typedef struct Node {
    char c;
    struct Node* left; // 이 구조체 자체를 가리키는 포인터이므로 struct으로 선언
    struct Node* right;
} node;

string s;
node* head, *tail;
node* cursor;

void init() {
    head = new node;
    tail = new node;
    head->c = NULL;
    head->left = NULL;
    head->right = tail;
    tail->c = '\0';
    tail->left = head;
    tail->right = NULL;
    cursor = head;

}
void insert(char c) {
    node* newNode = new node;
    newNode->c = c;

    node* prevNode = cursor;
    node* nextNode = cursor->right;
    prevNode->right = newNode;
    newNode->left = prevNode;
    newNode->right = nextNode;
    nextNode->left = newNode;
    cursor = newNode;
}

void stringToNode(string str) {
    for(int i=0; i<s.length(); i++) {
        insert(str[i]);
    }
}

void L() {
    if(cursor!=head)
        cursor = cursor->left;
}
void D() {
    if(cursor->right != tail)
        cursor = cursor->right;
}
void B() {
    node* toDelete = cursor;
    if(toDelete->c != '\0') {
        toDelete->left->right = cursor->right;
        cursor->right->left = toDelete->left;

        if(cursor->left = head) cursor = cursor->right;
        else cursor = toDelete->left;
        delete toDelete;
        cursor = cursor->left;
    }

}
void P(char ch) {
    node* prevNode = cursor;
    node* nextNode = cursor->right;
    node* newNode = new node;
    newNode->c = ch;
    newNode->left = prevNode;
    prevNode->right = newNode;

    if(nextNode) {
        newNode->right = nextNode;
        nextNode->left = newNode;
    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    char op, ch;
    int n;

    init();
    cin >> s;
    stringToNode(s);
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> op;
        if(op == 'L') L();
        if(op == 'D' ) D();
        if(op == 'P') {
            cin >> ch;
            insert(ch);
        }
        if(op == 'B') B();
    }

    node*ptr = head->right;
    while(ptr->c != '\0') {
        cout << ptr->c;
        ptr = ptr->right;
    }
    cout << "\n";


    return 0;

}

