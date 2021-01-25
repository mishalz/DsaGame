//
// Created by Mishal Zulfiqar on 25/01/2021.
//
#include <iostream>
#include "Captives.h"

#ifndef DSAGAME_STACK_H
#define DSAGAME_STACK_H


class Stack {
private:
    //size of the vector
    int size;
    std::vector<Captives*> stackVector;

public:
    //constructor
    Stack(int siz) {
        this->size=siz;
    }
    //method to push the element
    void Push(Captives element) {

        //the process to only work if the stack is not already full
        if (!isFull()) {

            stackVector.push_back(&element);
        }
        else {
            std::cout << "The stack is full" << std::endl;
        }
    }

    //method to pop out the element
    Captives* Pop() {


        //the process to only work if the stack is not already empty
        if (!isEmpty()) {

            Captives* temp = stackVector.back();
            stackVector.pop_back();

            return temp;

        }
        else {
            std::cout << "The stack is empty" << std::endl;
            return nullptr;
        }

    }

    //to check is the stack is empty
    bool isEmpty() {
        return stackVector.empty();
    }

    //to check if the stack is full
    bool isFull() {
        return stackVector.size() == size;
    }

    //to release the memory allocated by stack
    void Clear() {
        for(int i=0; i<this->size ; i++){
            delete stackVector[i];
        }
    }
};


#endif //DSAGAME_STACK_H
