#include <iostream>
#include <random>
#include <set>
#include <vector>

#include "AVLTree.h"

int main()
{
    AVLTree avl;
    std::set<int> stdSet;

    std::random_device rd;
    std::default_random_engine gen(rd());
    std::uniform_int_distribution<int> dist(0, 10000);

    const int treeSize = 10000;
    const int removeSize = 10000;

    for (int i = 0; i < treeSize; i++)
    {
        int rndInt = dist(gen);
        avl.Insert(rndInt);
        stdSet.insert(rndInt);
    }
    std::vector<int> treeValues = avl.GetVector();
    bool isEqual = std::equal(treeValues.cbegin(), treeValues.cend(), stdSet.cbegin());
    std::cout << "Insertion. Are values equal?: " << (isEqual ? "yes" : "no") << '\n';

    
    for (int i = 0; i < removeSize; i++)
    {
        int rndInt = dist(gen);
        avl.Remove(rndInt);
        stdSet.erase(rndInt);
    }
    treeValues = avl.GetVector();
    isEqual = std::equal(treeValues.cbegin(), treeValues.cend(), stdSet.cbegin());
    std::cout << "Removing. Are values equal?: " << (isEqual ? "yes" : "no") << '\n';
}