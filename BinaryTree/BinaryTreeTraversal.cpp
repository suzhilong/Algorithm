#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct BinaryTree{
    int val;
    BinaryTree *lc;
    BinaryTree *rc;
    BinaryTree(int x) : val(x), lc(nullptr), rc(nullptr){};
};

void preOrder_recursion(BinaryTree *root){
    if(root==nullptr)
        return;
    cout << root->val << " ";
    preOrder_recursion(root->lc);
    preOrder_recursion(root->rc);
}

void inOrder_recursion(BinaryTree *root){
    if(root==nullptr)
        return;
    inOrder_recursion(root->lc);
    cout << root->val << " ";
    inOrder_recursion(root->rc);
}

void posOrder_recursion(BinaryTree *root){
    if(root==nullptr)
        return;
    posOrder_recursion(root->lc);
    posOrder_recursion(root->rc);
    cout << root->val << " ";
}

void preOrder_non_recursion(BinaryTree *root){
    stack<BinaryTree *> st;

    while(root!=nullptr || !st.empty()){
        if(root!=nullptr){
            cout << root->val << " ";
            st.push(root);
            root = root->lc;
        }else{
            root = st.top();
            st.pop();
            root = root->rc;
        }
    }
}

void inOrder_non_recursion(BinaryTree *root){
    stack<BinaryTree *> st;

    while(root!=nullptr || !st.empty()){
        if(root!=nullptr){
            st.push(root);
            root = root->lc;
        }else{
            root = st.top();
            st.pop();
            cout << root->val << " ";
            root = root->rc;
        }
    }
}

void posOrder_non_recursion(BinaryTree *root){
    stack<BinaryTree *> st;
    BinaryTree *lastVisited = root;

    while(root!=nullptr || !st.empty()){
        if(root!=nullptr){
            st.push(root);
            root = root->lc;
        }else{
            root = st.top();
            if(root->lc == nullptr || root->rc == lastVisited){
                cout << root->val << " ";
                st.pop();
                lastVisited = root;
                root = nullptr;
            }else{
                root = root->rc;
            }
        }
    }
}

void levelOrder(BinaryTree *root){
    queue<BinaryTree *> que;
    que.push(root);

    while(!que.empty()){
        BinaryTree *curNode = que.front();
        cout << curNode->val << " ";
        que.pop();
        if(curNode->lc!=nullptr)
            que.push(curNode->lc);
        if(curNode->rc!=nullptr)
            que.push(curNode->rc);
    }
}

int main(){
    /*
        4
       /  \
      2    6
     /\    /\
    1  3  5  7
    */
    BinaryTree *root = new BinaryTree(4);
    root->lc = new BinaryTree(2);
    root->rc = new BinaryTree(6);
    root->lc->lc = new BinaryTree(1);
    root->lc->rc = new BinaryTree(3);
    root->rc->lc = new BinaryTree(5);
    root->rc->rc = new BinaryTree(7);

    cout << "pre_recur: ";
    preOrder_recursion(root);
    cout << endl;
    cout << "pre_non_recur: ";
    preOrder_non_recursion(root);
    cout << endl;

    cout << "in_recur: ";
    inOrder_recursion(root);
    cout << endl;
    cout << "in_non_recur: ";
    inOrder_non_recursion(root);
    cout << endl;
    
    cout << "pos_recur: ";
    posOrder_recursion(root);
    cout << endl;
    cout << "pos_non_recur: ";
    posOrder_non_recursion(root);
    cout << endl;

    cout << "levelOrder: ";
    levelOrder(root);
    cout << endl;


    return 0;
}