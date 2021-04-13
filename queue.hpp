#pragma once

namespace strukdat {

namespace priority_queue {

/**
 * @brief Implementasi struct untuk elemen, harus ada isi dan prioritas elemen.
 */
template <typename T>
struct Element {
  T isi;
  int pri;
  Element<T> *next;
};

template <typename T>
using ElementPtr = Element<T> *;

/**
 * @brief implemetasi struct untuk queue.
 */
template <typename T>
struct Queue {
  ElementPtr<T> head;
  ElementPtr<T> last;
};

/**
 * @brief membuat queue baru
 *
 * @return  queue kosong
 */
template <typename T>
Queue<T> new_queue() {
  Queue<T> q;
  q.head = nullptr;
  q.last = nullptr;
  return q;
}

/**
 * @brief memasukan data sesuai priority elemen.
 *
 * @param q         queue yang dipakai.
 * @param value     isi dari elemen.
 * @param priority  prioritas elemen yang menentukan urutan.
 */
template <typename T>
void enqueue(Queue<T> &q, const T &value, int priority) {
  ElementPtr<T> newElement;
  newElement = new Element<T>;
  newElement->isi = value;
  newElement->pri = priority;
  if(q.head == nullptr && q.last == nullptr){
    q.head = newElement;
    q.last = newElement;
  }else{
    ElementPtr<int> prev = nullptr;
    ElementPtr<int> temp = q.head;
    while(newElement->pri <= temp->pri){
      if (temp->next == nullptr)
        break;
      prev = temp;
      temp = temp->next;
    }
    if(temp == q.head && newElement->pri > temp->pri){
      newElement->next = temp;
      q.head = newElement;
    }else if(temp == q.last && newElement->pri < temp->pri){
      temp->next = newElement;
      q.last = newElement;
    }else{
      prev->next = newElement;
      newElement->next = temp;
    }
  }
}

/**
 * @brief mengembalikan isi dari elemen head.
 *
 * @param q   queue yang dipakai.
 * @return    isi dari elemen head.
 */
template <typename T>
T top(const Queue<T> &q) {
  return q.head->isi;
}

/**
 * @brief menghapus elemen head queue (First in first out).
 *
 * @param q   queue yang dipakai.
 */
template <typename T>
void dequeue(Queue<T> &q) {
  ElementPtr<T> del;
  if(q.head == nullptr && q.last == nullptr){
    del = nullptr;
  }else if(q.head->next == nullptr){
    del = q.head;
    q.head = nullptr;
    q.last = nullptr;
  }else{
    del = q.head;
    q.head = q.head->next;
    del->next = nullptr;
  }
}

}  // namespace priority_queue

}  // namespace strukdat
