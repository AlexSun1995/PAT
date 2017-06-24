#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
template <typename Comparable>
class BinarySearchTree{
    public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree & rhs);
    ~BinarySearchTree();
    const & findMin() const;
    const & findMax() const;   // what's the diff between const ahead and behind?
    void makeEmpty();
    void insert(const Comparable & x);
    void remove(const Comparable & x);
    private:
    struct BinaryNode
    {
        Comparable element;
        BinaryNode *left;
        BinaryNode *right;
        BinaryNode(const Comparable & theElement,BinaryNode *lt,BinaryNode *rt)
        : element{theElement},left{lt},right{rt} { }   
    };
   void insert(const Comparable & x,BinaryNode* & t);
   void remove(const Comparable & x,BinaryNode* & t);
   BinaryNode * findMin(BinaryNode *t) const;
   BinaryNode * findMax(BinaryNode *t) const;
   bool contains(const Comparable & x,BinaryNode * t) const;
   void makeEmpty(BinaryNode *& t);
   void printTree(BinaryNode *t,ostream & out) const;
   BinaryNode * clone(BinaryNode * t )const; 
};
int main(){

} 