#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* constructBinaryTree(const string& str) {
    if (str.empty())
        return nullptr;

    stack<Node*> st;
    Node* root = nullptr;

    for (char c : str) {
        if (c == '(') {
            st.push(root);
            root = nullptr;
        } else if (isdigit(c)) {
            int num = 0;
            while (isdigit(c)) {
                num = num * 10 + (c - '0');
                c = str[++i];
            }
            Node* newNode = new Node(num);
            if (root == nullptr)
                root = newNode;
            else {
                if (root->left == nullptr)
                    root->left = newNode;
                else
                    root->right = newNode;
            }
        } else if (c == ')') {
            if (!st.empty()) {
                root = st.top();
                st.pop();
            }
        }
    }
    return root;
}

void inorderTraversal(Node* root) {
    if (root == nullptr)
        return;
    
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    string str;
    cout << "Enter the string representation of the binary tree: ";
    cin >> str;

    Node* root = constructBinaryTree(str);

    cout << "Inorder traversal of the constructed binary tree: ";
    inorderTraversal(root);

    return 0;
}
