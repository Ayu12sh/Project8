#ifndef BST_H
#define BST_H

template <class T>
class BST {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(T d) : data(d), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // helpers
    Node* insert(Node* r, const T& item) {
        if (!r) return new Node(item);
        if (item < r->data) r->left = insert(r->left, item);
        else if (item > r->data) r->right = insert(r->right, item);
        return r;
    }

    Node* findMin(Node* r) {
        while (r->left) r = r->left;
        return r;
    }

    Node* remove(Node* r, const T& item) {
        if (!r) return nullptr;

        if (item < r->data) r->left = remove(r->left, item);
        else if (item > r->data) r->right = remove(r->right, item);
        else {
            if (!r->left && !r->right) {
                delete r;
                return nullptr;
            }
            else if (!r->left) {
                Node* temp = r->right;
                delete r;
                return temp;
            }
            else if (!r->right) {
                Node* temp = r->left;
                delete r;
                return temp;
            }
            else {
                Node* temp = findMin(r->right);
                r->data = temp->data;
                r->right = remove(r->right, temp->data);
            }
        }
        return r;
    }

    bool search(Node* r, const T& item, T& result) {
        if (!r) return false;
        if (item == r->data) { result = r->data; return true; }
        if (item < r->data) return search(r->left, item, result);
        return search(r->right, item, result);
    }

    void preorder(Node* r, void (*visit)(T&)) {
        if (!r) return;
        visit(r->data);
        preorder(r->left, visit);
        preorder(r->right, visit);
    }

    void inorder(Node* r, void (*visit)(T&)) {
        if (!r) return;
        inorder(r->left, visit);
        visit(r->data);
        inorder(r->right, visit);
    }

public:
    BST() : root(nullptr) {}

    void insert(const T& item) { root = insert(root, item); }
    void remove(const T& item) { root = remove(root, item); }

    bool search(const T& item, T& result) {
        return search(root, item, result);
    }

    void preorder(void (*visit)(T&)) { preorder(root, visit); }
    void inorder(void (*visit)(T&)) { inorder(root, visit); }
};

#endif
