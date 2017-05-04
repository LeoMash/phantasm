#pragma once
#ifndef _SCENE_HPP_
#define _SCENE_HPP_


template <typename SCENE_ITERATOR_TYPE>
SCENE_ITERATOR<SCENE_ITERATOR_TYPE>::SCENE_ITERATOR (typename std::vector<SCENE_ITERATOR_TYPE>::iterator iterator, std::vector<SCENE_ITERATOR_TYPE> * objects) : it(iterator), obj(objects)
{
}


template <typename SCENE_ITERATOR_TYPE>
SCENE_ITERATOR<SCENE_ITERATOR_TYPE>::SCENE_ITERATOR (const SCENE_ITERATOR & iter) : it(iter.it), objects(iter.objects)
{
}


template <typename SCENE_ITERATOR_TYPE>
SCENE_ITERATOR<SCENE_ITERATOR_TYPE>::~SCENE_ITERATOR (void)
{
}


template <typename SCENE_ITERATOR_TYPE>
SCENE_ITERATOR_TYPE SCENE_ITERATOR<SCENE_ITERATOR_TYPE>::operator* (void)
{
   return *it;
}


template <typename SCENE_ITERATOR_TYPE>
SCENE_ITERATOR<SCENE_ITERATOR_TYPE> & SCENE_ITERATOR<SCENE_ITERATOR_TYPE>::operator++ (void)
{
   ++it;

   return *this;
}


template <typename SCENE_ITERATOR_TYPE>
SCENE_ITERATOR<SCENE_ITERATOR_TYPE> SCENE_ITERATOR<SCENE_ITERATOR_TYPE>::operator++ (int)
{
   SCENE_ITERATOR temp = *this;

   ++it;

   return temp;
}


template <typename SCENE_ITERATOR_TYPE>
bool SCENE_ITERATOR<SCENE_ITERATOR_TYPE>::operator== (const SCENE_ITERATOR & iter) const
{
   if (iter.it == it && iter.obj == obj) {
      return true;
   }

   return false;
}


template <typename SCENE_ITERATOR_TYPE>
bool SCENE_ITERATOR<SCENE_ITERATOR_TYPE>::operator!= (const SCENE_ITERATOR & iter) const
{
   if (iter.it != it || iter.obj != obj) {
      return true;
   }

   return false;
}





template <typename SCENE_ITERATOR_TYPE>
SCENE_CONST_ITERATOR<SCENE_ITERATOR_TYPE>::SCENE_CONST_ITERATOR (typename std::vector<SCENE_ITERATOR_TYPE>::const_iterator iterator, const std::vector<SCENE_ITERATOR_TYPE> * objects) : it(iterator), obj(objects)
{
}


template <typename SCENE_ITERATOR_TYPE>
SCENE_CONST_ITERATOR<SCENE_ITERATOR_TYPE>::SCENE_CONST_ITERATOR (const SCENE_CONST_ITERATOR & iter) : it(iter.it), objects(iter.objects)
{
}


template <typename SCENE_ITERATOR_TYPE>
SCENE_CONST_ITERATOR<SCENE_ITERATOR_TYPE>::~SCENE_CONST_ITERATOR (void)
{
}


template <typename SCENE_ITERATOR_TYPE>
const SCENE_ITERATOR_TYPE SCENE_CONST_ITERATOR<SCENE_ITERATOR_TYPE>::operator* (void) const
{
   return *it;
}


template <typename SCENE_ITERATOR_TYPE>
SCENE_CONST_ITERATOR<SCENE_ITERATOR_TYPE> & SCENE_CONST_ITERATOR<SCENE_ITERATOR_TYPE>::operator++ (void)
{
   ++it;

   return (*this);
}


template <typename SCENE_ITERATOR_TYPE>
SCENE_CONST_ITERATOR<SCENE_ITERATOR_TYPE> SCENE_CONST_ITERATOR<SCENE_ITERATOR_TYPE>::operator++ (int)
{
   SCENE_CONST_ITERATOR temp = *this;

   ++it;

   return temp;
}


template <typename SCENE_ITERATOR_TYPE>
bool SCENE_CONST_ITERATOR<SCENE_ITERATOR_TYPE>::operator== (const SCENE_CONST_ITERATOR & iter) const
{
   if (iter.it == it && iter.obj == obj) {
      return true;
   }

   return false;
}


template <typename SCENE_ITERATOR_TYPE>
bool SCENE_CONST_ITERATOR<SCENE_ITERATOR_TYPE>::operator!= (const SCENE_CONST_ITERATOR & iter) const
{
   if (iter.it != it || iter.obj != obj) {
      return true;
   }

   return false;
}


#endif // _SCENE_HPP_
