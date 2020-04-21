#include <array>
#include <cassert>

/**
 * this is demo of Nontype template.
 */

template <typename T, std::size_t Maxsize>
class Stack {
 private:
  std::array<T, Maxsize> elems;
  std::size_t numElems;

 public:
  Stack();
  ~Stack();

  void push(T const& elem);
  void pop();
  T const& top() const;
  bool empty() { return numElems == 0; }
  std::size_t size() { return numElems; }
};

template <typename T, std::size_t Maxsize>
Stack<T, Maxsize>::Stack() : numElems(0) {}

template <typename T, std::size_t Maxsize>
Stack<T, Maxsize>::~Stack() {}

template <typename T, std::size_t Maxsize>
void Stack<T, Maxsize>::push(T const& elem) {
  assert(numElems < Maxsize);
  elems[numElems] = elem;
  ++numElems;
}

template <typename T, std::size_t Maxsize>
void Stack<T, Maxsize>::pop() {
  assert(!elems.empty());
  --numElems;
}

template <typename T, std::size_t Maxsize>
T const& Stack<T, Maxsize>::top() const {
  assert(!elems.empty());

  return elems[numElems - 1];
}
