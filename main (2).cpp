#include <cstdio>
#include <ctime>
#include <iostream>
#include <stdlib.h>
using namespace std;

class Container {
public:
  virtual void print() = 0;
};

class Vector : public Container {
  int *vec;
  int n;

public:
  Vector(int _n = 0, int *arr = nullptr) {
    n = _n;
    vec = new int[n];
    if (arr == nullptr)
      return;
    for (int i = 0; i < n; i++) {
      vec[i] = arr[i];
    }
  }

  void add_elem(int el) {
    int *new_vec = new int[n + 1];
    for (int i = 0; i < n; i++) {
      new_vec[i] = vec[i];
    }
    n++;
    new_vec[n - 1] = el;
    vec = new int[n];
    for (int i = 0; i < n; i++) {
      vec[i] = new_vec[i];
    }
  }

  void print() {
    cout << "[ ";
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        cout << vec[i];
      } else
        cout << ", " << vec[i];
    }
    cout << " ] " << endl;
    ;
  }

  int &operator[](int i) { return vec[i]; }
  ~Vector() { delete[] vec; }
};

class Set : public Container {
  int *set;
  int n;

public:
  Set(int _n = 0, int *arr = nullptr) {
    n = _n;
    if (arr == nullptr)
      return;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i != j) {
          if (arr[i] == arr[j]) {
            swap(arr[n - 1], arr[j]);
            n--;
          }
        }
      }
    }
    set = new int[n];
    for (int i = 0; i < n; i++) {
      set[i] = arr[i];
    }
  }
  int &operator[](int i) { return set[i]; }
  void add_elem(int el) {
    int *new_arr = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
      new_arr[i] = set[i];
    }
    for (int i = 0; i < n; i++) {
      if (set[i] == el) {
        return;
      }
    }
    n++;
    new_arr = (int *)realloc(new_arr, n * sizeof(int));
    new_arr[n - 1] = el;
    set = new int[n];
    for (int i = 0; i < n; i++) {
      set[i] = new_arr[i];
    }
  }

  void print() {
    cout << "[ ";
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        cout << set[i];
      } else
        cout << ", " << set[i];
    }
    cout << " ] " << endl;
    ;
  }
  ~Set() { delete[] set; }
};
class Dictionary : Container {
private:
  string *keys;
  int *values;
  int n;

public:
  Dictionary(int _n) {
    n = _n;
    keys = new string[n];
    values = new int[n];
  }
  ~Dictionary() {
    delete[] keys;
    delete[] values;
  }

  void add(string key, int value) {
    for (int i = 0; i < n; i++) {
      if (keys[i] == "") {
        keys[i] = key;
        values[i] = value;
        break;
      }
    }
  }

  void print() {
    for (int i = 0; i < n; i++) {
      if (keys[i] != "") {
        cout << keys[i] << ": " << values[i] << endl;
      }
    }
  }

  int &operator[](string key) {
    for (int i = 0; i < n; i++) {
      if (keys[i] == key) {
        return values[i];
      }
    }
  }
};
int main() {
  cout << "Введите количество элементов в векторе: ";
  int n;
  cin >> n;
  int *arr = new int[n];
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 10 + 1;
  }

  Vector v(n, arr);
  cout << "Реализация print for vector: ";
  v.print();
  cout << "Реализация add for vector: ";
  v.add_elem(10);
  v.print();
  cout << "Реализация  [ ] for vector: " << v[5] << endl << endl;
  cout << "Введите количество элементов в множестве: ";
  int t;
  cin >> t;
  int *mas = new int[t];
  for (int i = 0; i < t; i++) {
    mas[i] = rand() % 10;
    cout << (mas[i]) << " ";
  }

  Set s(t, mas);
  cout << endl << "Реализация print for set: ";
  s.print();
  cout << "Реализация add for set: ";
  s.add_elem(8);
  s.print();
  cout << "Реализация  [ ] for set: " << s[5] << endl << endl;

  Dictionary dict(5);
  dict.add("apple", 1);
  dict.add("banana", 2);
  dict.add("cherry", 3);
  cout << "Реализация print и add for dict: " << endl;
  dict.print();
  cout << "Реализация [ ] for dict: ";
  cout << dict["cherry"] << endl;

  return 0;
}