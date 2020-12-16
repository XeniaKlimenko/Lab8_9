#pragma once

#include "List.h"
#include <iostream>

using namespace std;

template <class T>
class TQueueList
{
protected:
  TList<T> list;
public:
  TQueueList();
  TQueueList(TQueueList<T>& _v);
  ~TQueueList();

  TQueueList<T>& operator =(TQueueList<T>& _v);

  bool IsEmpty(void) const;
  bool IsFull(void) const;
  void Push(T d);
  T Get();

  template <class T1>
  friend ostream& operator<< (ostream& ostr, const TQueueList<T1>& A);
  template <class T1>
  friend istream& operator >> (istream& istr, TQueueList<T1>& A);

  T Min_elem();
  T Max_elem();
  int GetCount();
};

template <class T1>
ostream& operator<< (ostream& ostr, const TQueueList<T1>& A) {
  return ostr << A.list;
}

template <class T1>
istream& operator >> (istream& istr, TQueueList<T1>& A) {
  return istr >> A.list;
}

template<class T>
inline TQueueList<T>::TQueueList()
{
  list.count = 0;
  list.end = 0;
  list.root = 0;
}

template<class T>
inline TQueueList<T>::TQueueList(TQueueList<T>& _v)
{
  list = _v.list;
}

template<class T>
inline TQueueList<T>::~TQueueList()
{
}

template<class T>
inline TQueueList<T>& TQueueList<T>::operator=(TQueueList<T>& _v)
{
  if (this == &_v)
    return *this;
  list = _v.list;
  return *this;
}

template<class T>
inline bool TQueueList<T>::IsEmpty(void) const
{
  return list.IsEmpty();
}

template<class T>
inline bool TQueueList<T>::IsFull(void) const
{
  return list.IsFull();
}

template<class T>
inline void TQueueList<T>::Push(T d)
{
  list.InsLast(d);
}

template<class T>
inline T TQueueList<T>::Get()
{
  if(list.IsEmpty())
    throw logic_error("Error");
  T tmp = list.GetFirst()->GetData();
  list.DelFirst();
  return tmp;
}

template<class T>
inline T TQueueList<T>::Min_elem()
{
  if (list.GetCount() < 1)
    throw logic_error("Error");
  TListElem<T>* tmp = list.GetFirst();
  T min = tmp->GetData();
  tmp = tmp->GetNext();
  while (tmp != NULL)
  {
    T elem = tmp->GetData();
    if (elem < min)
      min = elem;
    tmp = tmp->GetNext();
  }
  return min;
}

template<class T>
inline T TQueueList<T>::Max_elem()
{
  if (list.GetCount() < 1)
    throw logic_error("Error");
  TListElem<T>* tmp = list.GetFirst();
  T max = tmp->GetData();
  tmp = tmp->GetNext();
  while (tmp != NULL)
  {
    T elem = tmp->GetData();
    if (elem > max)
      max = elem;
    tmp = tmp->GetNext();
  }
  return max;
}

template<class T>
inline int TQueueList<T>::GetCount()
{
  return list.GetCount();
}
