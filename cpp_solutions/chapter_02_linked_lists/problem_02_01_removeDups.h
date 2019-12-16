#pragma once
#include "Node.h"
#include <unordered_map>

namespace chapter_02{
    template <typename T>
    void removeDups(std::shared_ptr<SinglyLinkedNode<T>> head){
        auto slowRunner = head;
        if (slowRunner == nullptr || slowRunner->getNext() == nullptr) return;  // a list of length 0 or 1 cannot have dups
        auto fastRunner = slowRunner->getNext();
        std::unordered_map<T, bool> hashTable;
        hashTable[slowRunner->getValue()] = true;
        while (fastRunner != nullptr){
            if (hashTable.count(fastRunner->getValue())){
                slowRunner->setNext(fastRunner->getNext());
                fastRunner->setNext(nullptr);
                fastRunner = slowRunner->getNext();
            } else {
                hashTable[fastRunner->getValue()] = true;
                slowRunner = fastRunner;
                fastRunner = fastRunner->getNext();
            }
        }
    }
}
