#include <iostream>
#include "bst.h"

// usunięcie z pamięci całego drzewa
void Node::clear() {
    if (left) left->clear();
    if (right) right->clear();
    delete this;
}

// zwraca liczbe wezlow w calym drzewie BST
int Node::size() const {
    int a = left ? left->size(): 0;
    int b = right ? right->size() : 0;
    return a + 1 + b;
}

// zwraca wskaznik do wezla z wartoscia x w drzewie BST
const Node* Node::search(TYPE x) const {
    if (x < value){
        if (left) return left->search(x);
        else return nullptr;
    }
    else if (value < x){
         if (right) return right->search(x);
         else return nullptr;
    }
    else return this;
}

// zwraca wskaznik do wezla z wartoscia minimalna w drzewie BST
const Node* Node::min() const {
    if (left) return left->min();
    else return this;
}

// zwraca wskaznik do wezla z wartoscia maksymalna w drzewie BST
const Node* Node::max() const {
    if (right) return right->max();
    else return this;
}

// funkcja wstawia nowa wartosc do drzewa BST (albo aktualizuje)
void Node::insert(Node *&nd, const TYPE x) {
    if (nd == nullptr) 
        nd = new Node(x);
    else if (x < nd->valueof())
        insert(nd->left, x);
    else
        insert(nd->right, x);
}

Node* Node::remove_max() {
    if (left) {
        left = left->remove_max();
        return this;
    }
    else {
        Node *res = right;
        delete this;
        return res;
    }
}

Node* Node::remove_min() {
    if (right) {
        right = right->remove_min();
        return this;
    }
    else {
        Node *res = left;
        delete this;
        return res;
    }
}

Node* Node::remove(TYPE x) {
    if (x < value) {
        if (left) left = left->remove(x);
        return this;
    }
    else if (value < x) {
        if (right) right = right->remove(x);
        return this;
    }
    else if (!left && !right) {
        delete this;
        return nullptr;
    }
    else if (!left) {
        Node *res = right;
        delete this;
        return res;
    }
    else if (!right) {
        Node *res = left;
        delete this;
        return res;
    }
    else {
        value = left->max()->valueof();
        left = left->remove_max();
        return this;
    }
}

void Node::print(int lev, int mask, direction dir) const {
    if (left != nullptr){
        if (dir != dirright) left->print(lev+1, mask, dirleft);
        else left->print(lev+1, mask | (1 << lev), dirleft);
    }
    for(int i = 0; i < lev; ++i)
        if (mask & (1 << i)) std::cerr << "|    ";
        else std::cerr<< "     ";
    std::cerr<<"+--->"<<value<<std::endl;
    if (right != nullptr){
        if (dir != dirleft) right->print(lev+1, mask, dirright);
        else right->print(lev + 1, mask | (1 << lev), dirright); 
    }
}

inline void Bst::insert(TYPE x) {
    this->root->insert(root, x);
}

inline TYPE Bst::min() {
    if (empty()) throw std::domain_error("Empty BST");
    else return root->min()->valueof();
}

inline TYPE Bst::max() {
    if (empty()) throw std::domain_error("Empty BST");
    else return root->min()->valueof();
}

inline void Bst::remove_min() {
    if (empty()) throw std::domain_error("Empty BST");
    else root = root->remove_min();
}
inline void Bst::remove_max() {
    if (empty()) throw std::domain_error("Empty BST");
    else root = root->remove_max();
}
inline void Bst::remove(TYPE x) {
    if (!empty()) root = root->remove(x);
}
inline void Bst::print() {
    if (!empty()) root->print();
}

int Node::height() const{
    int maxLeft = this->left ? this->left->height(): 0;
    int maxRight = this->right ? this->right->height() : 0;
    return maxLeft + maxRight + 1;
}

int Node::width() const{
    int a = left ? left->width(): 0;
    int b = right ? right->width() : 0;
    if (a > b)  return a + 1;
    else        return b + 1;
}

std::ostream& operator << (std::ostream &out, const Bst &t) {
    out << "(";
    if (t.root != nullptr) out << t.root;
    out << ")";
    return out;
}

std::ostream& operator << (std::ostream &out, const Node *nd) {
    if (nd->left) out << nd->left << ", ";
    out << nd->value;
    if (nd->right) out << ", " << nd->right;
    return out;
}