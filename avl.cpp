#include<bits/stdc++.h>

class AVLTree {
private:
    struct Node {
        int key;
        int height;
        Node* left;
        Node* right;

        explicit Node(int k)
            : key(k), height(1), left(nullptr), right(nullptr) {}
    };

    Node* root = nullptr;

    int getHeight(Node* node) const {
        if (node == nullptr) {
            return 0;
        }
        return node->height;
    }

    void updateHeight(Node* node) {
        node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
    }

    int getBalance(Node* node) const {
        if (node == nullptr) {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* t2 = x->right;

        x->right = y;
        y->left = t2;

        updateHeight(y);
        updateHeight(x);
        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* t2 = y->left;

        y->left = x;
        x->right = t2;

        updateHeight(x);
        updateHeight(y);
        return y;
    }

    Node* insert(Node* node, int key) {
        if (node == nullptr) {
            return new Node(key);
        }

        if (key < node->key) {
            node->left = insert(node->left, key);
        } else if (key > node->key) {
            node->right = insert(node->right, key);
        } else {
            return node;
        }

        updateHeight(node);
        int balance = getBalance(node);

        if (balance > 1 && key < node->left->key) {
            return rightRotate(node);
        }

        if (balance < -1 && key > node->right->key) {
            return leftRotate(node);
        }

        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node* minValueNode(Node* node) const {
        if (node->left) {
            return minValueNode(node->left);
        }
        return node;
    }

    Node* deleteNode(Node* node, int key) {
        if (node == nullptr) {
            return node;
        }

        if (key < node->key) {
            node->left = deleteNode(node->left, key);
        } else if (key > node->key) {
            node->right = deleteNode(node->right, key);
        } else {
            if (node->left == nullptr || node->right == nullptr) {
                Node* child = (node->left != nullptr) ? node->left : node->right;
                delete node;
                return child;
            }

            Node* t = minValueNode(node->right);
            node->key = t->key;
            node->right = deleteNode(node->right, t->key);
        }

        updateHeight(node);
        int balance = getBalance(node);

        if (balance > 1 && getBalance(node->left) >= 0) {
            return rightRotate(node);
        }

        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && getBalance(node->right) <= 0) {
            return leftRotate(node);
        }

        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    bool contains(Node* node, int key) const {
        if (node == nullptr) {
            return false;
        }
        if (key == node->key) {
            return true;
        }
        if (key < node->key) {
            return contains(node->left, key);
        }
        return contains(node->right, key);
    }

    void preorder(Node* node) const {
        if (node == nullptr) {
            return;
        }
        std::cout << node->key << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node* node) const {
        if (node == nullptr) {
            return;
        }
        inorder(node->left);
        std::cout << node->key << " ";
        inorder(node->right);
    }

    void destroy(Node* node) {
        if (node == nullptr) {
            return;
        }
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    ~AVLTree() {
        destroy(root);
    }

    void insert(int key) {
        root = insert(root, key);
    }

    void erase(int key) {
        root = deleteNode(root, key);
    }

    bool contains(int key) const {
        return contains(root, key);
    }

    void preorder() const {
        preorder(root);
    }

    void inorder() const {
        inorder(root);
    }
};

int main() {
    AVLTree tree;
    int insertValues[] = {20, 10, 30, 5, 15, 25, 40, 3, 8, 13, 18, 23, 28, 35, 50};
    for (int x : insertValues) {
        tree.insert(x);
    }

    std::cout << "initial preorder: ";
    tree.preorder();
    std::cout << "\n";

    std::cout << "initial inorder: ";
    tree.inorder();
    std::cout << "\n\n";

    std::cout << "contains 25: " << (tree.contains(25) ? "true" : "false") << "\n";
    std::cout << "contains 99: " << (tree.contains(99) ? "true" : "false") << "\n\n";

    int deleteValues[] = {3, 5, 10, 20, 30, 40, 50};
    for (int x : deleteValues) {
        tree.erase(x);
        std::cout << "after delete " << x << " preorder: ";
        tree.preorder();
        std::cout << "\n";

        std::cout << "after delete " << x << " inorder: ";
        tree.inorder();
        std::cout << "\n\n";
    }

    return 0;
}
