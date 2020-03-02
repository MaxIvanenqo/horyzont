#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

#include <iostream>
#include <stdexcept>

// typ danych przechowywanych w drzewie BST
typedef int TYPE;

// wezel drzewa BST
class Node {
    Node *left, *right; // lewe i prawe poddrzewo
    TYPE value; // wartosc pamietana w wezle
    enum direction                              {dirroot, dirleft, dirright                             };
public:
    Node(TYPE x): value(x)                      {this->left = this->right = nullptr;                    };
    Node(Node &nd)           = delete;
    Node& operator=(Node &nd)= delete;
    inline TYPE valueof()               const   {return value;                                          };
    int size()                          const;
    const Node* search(TYPE x)          const;
    const Node* min()                   const;
    const Node* max()                   const;
    int height()                        const;
    int width()                         const;
    void print(int lev = 0, int mask = 0, direction dir = dirroot) const;
    void clear();
    void insert(Node *&nd, const TYPE x);
    Node* remove_min();
    Node* remove_max();
    Node* remove(TYPE x);
    friend std::ostream& operator<<(std::ostream &out, const Node *nd);
};

// drzewo BST
class Bst {
    Node *root; // korzen
public:
    Bst() : root(nullptr)                       {                                                       };
    ~Bst()                                      {if (root) root->clear(), root = nullptr;               };
    inline bool empty()                         {return root == nullptr;                                };
    inline int size()                           {return empty() ? 0 : root->size();                     };
    inline bool search(TYPE x)                  {return empty() ? false : root->search(x) != nullptr;   };
    inline int height()                 const   {return root->height();                                 };
    inline int width()                  const   {return root->width();                                  };
    Bst(Bst &t)              = delete;
    Bst& operator=(Bst &t)   = delete;
    inline TYPE min();
    inline TYPE max();
    inline void insert(const TYPE x);
    inline void remove_min();
    inline void remove_max();
    inline void remove(TYPE x);
    inline void print();
    friend std::ostream& operator<< (std::ostream &out, const Bst &t);
};

#endif // BST_H_INCLUDED