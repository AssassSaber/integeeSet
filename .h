#ifndef INTEGERSET_H
#define INTEGERSET_H

class integerSet
{
private:
  int len = 0,k;
  int elems[5000];

public:
  integerSet(int p);
  integerSet(const integerSet & integerSetObj);
  int size() const;
  bool isEmpty() const;
  bool insert(int n);
  bool erase(int n);
  bool isMember(int n);
  unsigned int capacity() const;
  int isMemberof(int n) const;
  void clear();
  bool isSubset(const integerSet &B);
  integerSet setunion(const integerSet &B);
  integerSet setintsection(const integerSet &B);
  integerSet setdifference(const integerSet &B);
  integerSet setsymmetricdifference(const integerSet &B);
  void print() const;
  class bad_integerSet
  {
  public:
    bad_integerSet(int n);
    int errnum;
  };

};
#endif
