#include "../include/Deque.h"

Deque::Deque(std::size_t capacity) : _capacity(capacity) {
  _arr = new int[_capacity];
  _size = 0;
  _front = -1;
  _back = 0;
}

void Deque::push_front(int value) {
  if (is_full()) {
    resize();
  }

  if (_front == -1) // Deque is empty
  {
    _front = 0;
    _back = 0;
  } else if (_front == 0) {
    _front = _capacity - 1; // circular go to end
  } else {
    --_front; // basic case
  }

  _arr[_front] = value;
  ++_size;
}

void Deque::push_back(int value) {
  if (is_full()) {
    resize();
  }

  if (_front == -1) {
    _front = 0;
    _back = 0;
  } else if (_back == _capacity - 1) {
    _back = 0;
  } else {
    ++_back;
  }
  _arr[_back] = value;
  ++_size;
}

void Deque::pop_front() {
  if (is_empty()) {
    std::cout << "Deque Underflow!!\n";
    return;
  }

  if (_front == _back) // Only one element
  {
    _front = -1;
    _back = -1;
  } else if (_front == _capacity - 1) {
    _front = 0;
  } else {
    _front = _front + 1;
  }
  --_size;
}

void Deque::pop_back() {
  if (is_empty()) {
    std::cout << "Deque Underflow\n";
    return;
  }

  if (_front == _back) // Only one element
  {
    _front = -1;
    _back = -1;
  } else if (_back == 0) {
    _back = _capacity - 1;
  } else {
    --_back;
  }
  --_size;
}

int Deque::get_front()
{
  return _arr[_front];
}

int Deque::get_back()
{
  return _arr[_back];
}
std::size_t Deque::get_size() { return _size; }

bool Deque::is_empty() { return _size == 0; }

bool Deque::is_full() { return _size == _capacity; }

void Deque::print() {
  if (is_empty()) {
    std::cout << "Deque is empty\n";
  }

  if (_front <= _back) {
    for (int i = _front; i <= _back; ++i) {
      std::cout << _arr[i] << " ";
    }
  } else {
    for (int i = _front; i < _size; ++i) {
      std::cout << _arr[i] << " ";
    }

    for (int i = 0; i <= _back; ++i) {
      std::cout << _arr[i] << " ";
    }
  }
  std::cout << std::endl;
}


void Deque::resize() {
  std::size_t newCapacity = _capacity * 2;
  int* newArray = new int[newCapacity];

  if(_front <= _back)
  {
    for(int i = 0; i < _size; ++i)
    {
      newArray[i] = _arr[_front + i]; 
    }
  } else 
  {
    for(int i = 0; i < _capacity - _front; ++i)
    {
      newArray[i] = _arr[_front + i];
    }

    for(int i = 0; i <= _back; ++i)
    {
      newArray[_capacity - _front + i] = _arr[i];
    }
  }

  _front = 0;
  _back = _size - 1;
  _capacity = newCapacity;
  delete [] _arr;
  _arr = newArray;
}