#include "integerSet.h"
#include<iostream>

using namespace std;

integerSet::bad_integerSet::bad_integerSet(int n)
{
  errnum = n;
}

integerSet::integerSet(int p)
{
  k = p;
 if(k<1)
  {
    throw bad_integerSet(1);
  }
}

integerSet::integerSet(const integerSet & integerSetObj)
{
  for(len = 0; len < integerSetObj.len;len++)
  {
    elems[len] = integerSetObj.elems[len];
  }

}
bool integerSet::isMember(int n) const
{
  for (int i = 0;i<len;i++)
  {if(elems[i] == n) return 1;}
  return false;
}

int integerSet::isMemberof(int n) const
{
  for (int i = 0;i<len;i++)
  {if(elems[i] == n)
  return i+1;}
  return -1;
}

void integerSet::print() const
{

  for(int i = 0;i <len;i++)
  cout<<elems[i]<<" ";


}

int integerSet::size() const
{
  return len;
}

unsigned int integerSet::capacity() const
{
  return k;
}

bool integerSet::isEmpty() const
{
  return len==0;
}

bool integerSet::insert(int n)
{

  if(isMember(n));
  else elems[len++] = n;
  if(len>=capacity())
  {
    throw bad_integerSet(2);
  }
  return 1;
}

bool integerSet::erase(int n)
{
  int l = isMemberof(n);
  if(isEmpty() || (l == -1)) return 0;
  for(int i = l;i<len;i++)
  {elems[i-1] = elems[i];}
  len -- ;
  return 1;
}

bool integerSet::isSubset(const integerSet &B)
{
  for(int i = 0;i<len;i++)
  {
    for(int j = 0;j<B.len;j++)
    {if (elems[i] != B.elems[j]) return 0;}

  }
  return 1;
}



integerSet integerSet::setunion(const integerSet & B)
{
  integerSet C(len+B.size());
  for(int i=0;i<len;i++)
  C.insert(elems[i]);
  return C;
}

integerSet integerSet::setintsection(const integerSet & B)
{
  integerSet C(len+B.size());
  for(int i=0;i<len;i++)
  {for(int j=0;j<B.len;j++)
  {if(elems[i]==B.elems[j]) C.insert(elems[i]);}}
  return C;
}

integerSet integerSet::setdifference(const integerSet & B)
  {integerSet C(len+B.size());

  for(int j = 0;j<len;j++)
  if(!B.isMember(elems[j])) C.insert(elems[j]) ;

  return C;
}

integerSet integerSet::setsymmetricdifference(const integerSet &B)
{
  integerSet C(len),D(len+B.size());
  for(int i=0;i<len;i++)
  {for(int j=0;j<B.len;j++)
  {if(elems[i]==B.elems[j]) C.insert(elems[i]);}}

  for(int i0 = 0;i0 < len;i0++)
  {if(!C.isMember(elems[i0])) D.insert(elems[i0]);}
  for(int j0 = 0;j0<B.size();j0++)
  {if(!C.isMember(B.elems[j0])) D.insert(B.elems[j0]);}

  return D;
}


void integerSet::clear()
{
  while(len>0)
  {
    erase(elems[0]);
  }
}
