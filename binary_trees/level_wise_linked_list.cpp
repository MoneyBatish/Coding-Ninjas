#include <iostream>
#include <queue>
#include <vector>

template <typename T>
class Node {
   public:
    T data;
    Node<T> *next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
#include<vector>
#include<queue>


vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here
    queue<BinaryTreeNode<int>*> pending;
    vector<Node<int>*> levels;
    if(root==NULL){
        return levels;
    }
    pending.push(root);
    pending.push(NULL);
    Node<int> *head = NULL;//new Node<int>(root->data);
    Node<int> *tmp = head;
    while(!pending.empty()){
        if(pending.size()==1 && pending.front()==NULL){
            pending.pop();
            break;
        }
        else if(pending.front()==NULL){
            pending.push(NULL);
            pending.pop();
            head = NULL;
            tmp = NULL;
        }
        BinaryTreeNode<int>* curr = pending.front();
        pending.pop();
        if(head==NULL){
            head = new Node<int>(curr->data);
            tmp = head;
            levels.push_back(head);
        }
        else{
            tmp->next = new Node<int>(curr->data);
            tmp = tmp->next;
        }
        if(curr->left!=NULL){
            pending.push(curr->left);
        }
        if(curr->right!=NULL){
            pending.push(curr->right);
        }
    }
    return levels;
}

BinaryTreeNode<int> *takeInput() {
    int rootData;
    
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void print(Node<int> *head) {
    Node<int> *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    vector<Node<int> *> ans = constructLinkedListForEachLevel(root);

    for (int i = 0; i < ans.size(); i++) {
        print(ans[i]);
    }
}