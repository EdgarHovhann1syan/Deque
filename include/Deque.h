#ifndef DEQUE_H
#define DEQUE_H
#include <iostream>
class Deque {
public:
  Deque(std::size_t capacity);
  void push_front(int value);
  void push_back(int value);
  void pop_front();
  void pop_back();
  int get_front();
  int get_back();
  std::size_t get_size();
  bool is_empty();
  void print();

private:
  void resize();
  bool is_full();

private:
  int *_arr;
  std::size_t _capacity;
  std::size_t _size;
  int _front;
  int _back;
};
#endif // DEQUE_H