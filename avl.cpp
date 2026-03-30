#include<bits/stdc++.h>

class AVLTree {
private:
    struct Node {
        int key;
        int height;
        int size;
        Node* left;
        Node* right;

        explicit Node(int k)
            : key(k), height(1), size(1), left(nullptr), right(nullptr) {}
    };

    Node* root = nullptr;

    int getHeight(Node* node) const {
        if (node == nullptr) {
            return 0;
        }
        return node->height;
    }

    int getSize(Node* node) const {
        if (node == nullptr) {
            return 0;
        }
        return node->size;
    }

    void pull(Node* node) {
        if (node == nullptr) {
            return;
        }
        node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
        node->size = getSize(node->left) + getSize(node->right) + 1;
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

        pull(y);
        pull(x);
        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* t2 = y->left;

        y->left = x;
        x->right = t2;

        pull(x);
        pull(y);
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

        pull(node);
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

        pull(node);
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

    int orderOfKey(Node* node, int key) const {
        if (node == nullptr) {
            return 0;
        }
        if (key <= node->key) {
            return orderOfKey(node->left, key);
        }
        return getSize(node->left) + 1 + orderOfKey(node->right, key);
    }

    Node* findByOrder(Node* node, int k) const {
        if (node == nullptr || k < 0 || k >= getSize(node)) {
            return nullptr;
        }

        int leftSize = getSize(node->left);
        if (k < leftSize) {
            return findByOrder(node->left, k);
        }
        if (k == leftSize) {
            return node;
        }
        return findByOrder(node->right, k - leftSize - 1);
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

    int order_of_key(int key) const {
        return orderOfKey(root, key);
    }

    bool find_by_order(int k, int& result) const {
        Node* node = findByOrder(root, k);
        if (node == nullptr) {
            return false;
        }
        result = node->key;
        return true;
    }

    int size() const {
        return getSize(root);
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

    std::cout << "initial inorder: ";
    tree.inorder();
    std::cout << "\n";

    std::cout << "size: " << tree.size() << "\n";
    std::cout << "contains 25: " << (tree.contains(25) ? "true" : "false") << "\n";
    std::cout << "contains 99: " << (tree.contains(99) ? "true" : "false") << "\n";
    std::cout << "order_of_key(18): " << tree.order_of_key(18) << "\n";
    std::cout << "order_of_key(19): " << tree.order_of_key(19) << "\n";

    for (int k = 0; k < tree.size(); ++k) {
        int value = 0;
        if (tree.find_by_order(k, value)) {
            std::cout << "find_by_order(" << k << "): " << value << "\n";
        }
    }

    tree.erase(20);
    tree.erase(5);
    tree.erase(30);

    std::cout << "\nafter deletions inorder: ";
    tree.inorder();
    std::cout << "\n";
    std::cout << "size: " << tree.size() << "\n";
    std::cout << "order_of_key(28): " << tree.order_of_key(28) << "\n";

    int value = 0;
    if (tree.find_by_order(3, value)) {
        std::cout << "find_by_order(3): " << value << "\n";
    }

    return 0;
}
