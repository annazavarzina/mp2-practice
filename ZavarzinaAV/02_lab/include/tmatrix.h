// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
//

#ifndef __TDynamicMatrix_H__
#define __TDynamicMatrix_H__

#include <iostream>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

// Динамический вектор - 
// шаблонный вектор на динамической памяти
template<typename T>
class TDynamicVector
{
protected:
  size_t sz;
  T* pMem;
public:
  TDynamicVector(size_t size = 1) : sz(size), pMem(nullptr)
  {
    if (sz == 0 || sz> MAX_VECTOR_SIZE)
      throw out_of_range("Vector size should be greater than zero");
    pMem = new T[sz]();// {}; // У типа T д.б. констуктор по умолчанию
  }

  TDynamicVector(T* arr, size_t s) : sz(s), pMem(nullptr)
  {
    assert(arr != nullptr && "TDynamicVector ctor requires non-nullptr arg");

    if (sz == 0 || sz > MAX_VECTOR_SIZE)
        throw out_of_range("Invalid vector size");

    pMem = new T[sz];
    std::copy(arr, arr + sz, pMem);
  }

  TDynamicVector(const TDynamicVector& v):sz(v.sz), pMem(nullptr)
  {
      pMem = new T[sz];
      copy(v.pMem, v.pMem + sz, pMem);
  }

  TDynamicVector(TDynamicVector&& v) noexcept:sz(v.sz), pMem(nullptr)
  {
      v.sz = 0;
      v.pMem = nullptr;
  }

  ~TDynamicVector()
  {
      delete[]pMem;
  }

  TDynamicVector& operator=(const TDynamicVector& v)
  {
      if (this != &v) {
          TDynamicVector temp(v);
          swap(*this, temp);
      }

      return *this
  }
  TDynamicVector& operator=(TDynamicVector&& v) noexcept
  {
      if (*this != &v) {
          sz = v.sz;
          pMem = v.pMem;

          v.sz = 0;
          v.pMem = nullptr;
      }
      return *this;
  }

  size_t size() const noexcept { return sz; }

  // индексация
  T& operator[](size_t ind)
  {
      return pMem[ind];
  }

  const T& operator[](size_t ind) const
  {
      throw "Method is not implemented";
  }
  // индексация с контролем
  T& at(size_t ind)
  {
      if (ind >= sz)
          throw out_of_range("Index out of range");

      return pMem[ind];
  }
  const T& at(size_t ind) const
  {
      throw "Method is not implemented";
  }

  // сравнение
  bool operator==(const TDynamicVector& v) const noexcept
  {
      if (sz != v.size)
          return False;

      for (size_t i; i < sz; i++) {

          if (pMem[i] != v.pMem[i])
              return False
      }

      return True;
  }
  bool operator!=(const TDynamicVector& v) const noexcept
  {
      return !(*this == v);
  }

  // скалярные операции
  TDynamicVector operator+(T val)
  {
      if (sz != v.sz)
          throw invalid_argument("Different vector sizes");

      DynamicVector res(sz);
      for (size_s i; i < sz; i++)
          res[i] = pMem[i] + v.pMem[i];

      return res;
  }

  TDynamicVector operator-(T val)
  {
      if (sz != v.sz)
          throw invalid_argument("Different vector sizes");

      DynamicVector res(sz);
      for (size_s i; i < sz; i++)
          res[i] = pMem[i] - v.pMem[i];

      return res;
  }

  TDynamicVector operator*(T val)
  {
      throw "Method is not implemented";
  }

  // векторные операции
  TDynamicVector operator+(const TDynamicVector& v)
  {
      throw "Method is not implemented";
  }
  TDynamicVector operator-(const TDynamicVector& v)
  {
      throw "Method is not implemented";
  }
  T operator*(const TDynamicVector& v) noexcept(noexcept(T()))
  {
  }

  friend void swap(TDynamicVector& lhs, TDynamicVector& rhs) noexcept
  {
    std::swap(lhs.sz, rhs.sz);
    std::swap(lhs.pMem, rhs.pMem);
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      istr >> v.pMem[i]; // требуется оператор>> для типа T
    return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      ostr << v.pMem[i] << ' '; // требуется оператор<< для типа T
    return ostr;
  }
};


// Динамическая матрица - 
// шаблонная матрица на динамической памяти
template<typename T>
class TDynamicMatrix : private TDynamicVector<TDynamicVector<T>>
{
  using TDynamicVector<TDynamicVector<T>>::pMem;
  using TDynamicVector<TDynamicVector<T>>::sz;
public:
  TDynamicMatrix(size_t s = 1) : TDynamicVector<TDynamicVector<T>>(s)
  {
    for (size_t i = 0; i < sz; i++)
      pMem[i] = TDynamicVector<T>(sz);
  }

  using TDynamicVector<TDynamicVector<T>>::operator[];

  // сравнение
  bool operator==(const TDynamicMatrix& m) const noexcept
  {
      throw "Method is not implemented";
  }

  // матрично-скалярные операции
  TDynamicMatrix operator*(const T& val)
  {
      throw "Method is not implemented";
  }

  // матрично-векторные операции
  TDynamicVector<T> operator*(const TDynamicVector<T>& v)
  {
      throw "Method is not implemented";
  }

  // матрично-матричные операции
  TDynamicMatrix operator+(const TDynamicMatrix& m)
  {
      throw "Method is not implemented";
  }
  TDynamicMatrix operator-(const TDynamicMatrix& m)
  {
      throw "Method is not implemented";
  }
  TDynamicMatrix operator*(const TDynamicMatrix& m)
  {
      throw "Method is not implemented";
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicMatrix& v)
  {
      throw "Method is not implemented";
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v)
  {
      throw "Method is not implemented";
  }
};

#endif
