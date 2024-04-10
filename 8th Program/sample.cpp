#include<iostream>
#include<queue>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* insertInBinaryTree(Node *&head, int val) {
    if (head == nullptr) {
        return new Node(val);
    }

    if (val < head->data) {
        head->left = insertInBinaryTree(head->left, val);
    } else {
        head->right = insertInBinaryTree(head->right, val);
    }

    return head;
}

void inOrder(Node *head) {
    if (head == nullptr) return;
    inOrder(head->left);
    cout << head->data << " ";
    inOrder(head->right);
}

void preOrder(Node *head) {
    if (head == nullptr) return;
    cout << head->data << " ";
    preOrder(head->left);
    preOrder(head->right);
}

void postOrder(Node *head) {
    if (head == nullptr) return;
    postOrder(head->left);
    postOrder(head->right);
    cout << head->data << " ";
}

Node* findMin(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

Node* deleteNode(Node *&head, int val) {
    if (head == nullptr) {
        return head;
    }

    if (val < head->data) {
        head->left = deleteNode(head->left, val);
    } else if (val > head->data) {
        head->right = deleteNode(head->right, val);
    } else {
        if (head->left == nullptr) {
            Node *temp = head->right;
            delete head;
            return temp;
        } else if (head->right == nullptr) {
            Node *temp = head->left;
            delete head;
            return temp;
        }

        // Node with two children
        Node* temp = findMin(head->right);
        head->data = temp->data;
        head->right = deleteNode(head->right, temp->data);
    }

    return head;
}

void levelOrder(Node *head) {
    if (head == nullptr) return;

    queue<Node*> q;
    q.push(head);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";

        if (temp->left != nullptr) {
            q.push(temp->left);
        }
        if (temp->right != nullptr) {
            q.push(temp->right);
        }
    }
}

int main() {
    Node *head = nullptr;

    while (true) {
        cout << "Enter 1 to insert, 2 for inorder, 3 for preorder, 4 for postorder, 5 to delete, 6 for level order, 7 to exit: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter number of elements to insert: ";
                int n;
                cin >> n;
                cout << "Enter elements: ";
                for (int i = 0; i < n; i++) {
                    int x;
                    cin >> x;
                    head = insertInBinaryTree(head, x);
                }
                break;
            case 2:
                cout << "Inorder Traversal: ";
                inOrder(head);
                cout << endl;
                break;
            case 3:
                cout << "Preorder Traversal: ";
                preOrder(head);
                cout << endl;
                break;
            case 4:
                cout << "Postorder Traversal: ";
                postOrder(head);
                cout << endl;
                break;
            case 5:
                cout << "Enter value to delete: ";
                int val;
                cin >> val;
                head = deleteNode(head, val);
                break;
            case 6:
                cout << "Level Order Traversal: ";
                levelOrder(head);
                cout << endl;
                break;
            case 7:
                cout << "Exiting..." << endl;
                exit(0);
            default:
                cout << "Invalid choice." << endl;
        }
    }

    return 0;
}
