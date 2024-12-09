#pragma once

template <class T> class Singleton
{
public:
  Singleton() = default;
  Singleton(const Singleton &) = delete;
  Singleton(Singleton &&) = delete;
  Singleton &operator=(const Singleton &) = delete;
  Singleton &operator=(Singleton &&) = delete;
  ~Singleton() = default;

  static T *get_instance();
};
