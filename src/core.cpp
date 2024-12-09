#include "core.h"

template <class T>
T *Singleton<T>::get_instance()
{
  static T instance;
  return &instance;
}
