#pragma once

#include <iostream>

inline constexpr int STACK_MAX_SIZE{512000}; // 512K

template <typename T> class Stack {
public:
        /**
         * @brief Initialises an empty stack.
         */
        Stack() { index = 0; };

        /**
         * @brief Default destructor
         */
        ~Stack() = default;

        /**
         * @brief *Moves* the provided item to the stack. If the stack is
         *        filled, an item will be popped to make room for the new one
         * @param item The item to be pushed to the stack
         * @returns A constant reference to the item from the stack.
         */
        const T& push(T& item);

        /**
         * @brief Removes the last item.
         * @returns The removed item.
         */
        const T& pop();

        /**
         * @param index The index of the required element
         * @returns The element at the provided index.
         */
        T& at(int index);

        /**
         * @returns The number of elements in the stack (current index).
         */
        int size();

        /**
         * @returns Is the stack empty or not.
         */
        bool empty();

        /**
         * @returns The first element of the stack
         */
        T& top();

private:
        // The stack.
        T stack[STACK_MAX_SIZE];

        // Current amount of items in the stack
        int_fast32_t index;
};

template <typename T> const T& Stack<T>::push(T& item) {
        int prev_index = this->index - 1;
        index = (this->index < STACK_MAX_SIZE) * index +
                (this->index >= STACK_MAX_SIZE) * prev_index;

        this->stack[this->index] = item;
        index++;

        return this->stack[this->index - 1];
};

template <typename T> const T& Stack<T>::pop() {
        // TODO: Check if this is a good idea
        index--;
        return this->index;
};

template <typename T> T& Stack<T>::at(int index) { return this->stack[index]; }

template <typename T> T& Stack<T>::top() { return this->at(this->index); }

template <typename T> int Stack<T>::size() { return this->index; }

template <typename T> bool Stack<T>::empty() { return (this->index <= 0); }
