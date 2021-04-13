/*
 * Bebas disini bisa masukin apa aja.
 * Misal mau testing atau debugging sendiri.
 *
 */

#include <iostream>

#include "queue.hpp"

using namespace strukdat::priority_queue;

int main()
{
  auto q = new_queue<int>();
  enqueue(q, 1, 5);
  enqueue(q, 2, 3);
  enqueue(q, 3, 7);
  enqueue(q, 4, 5);
  enqueue(q, 5, 1);

  dequeue(q);
  std :: cout << top(q);

  dequeue(q);
  std :: cout << top(q);

  dequeue(q);
  std :: cout << top(q);

  dequeue(q);
  std :: cout << top(q);
}
