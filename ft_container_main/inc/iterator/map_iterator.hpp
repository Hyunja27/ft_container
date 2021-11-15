#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include "../tools.hpp"
#include "../pair.hpp"


namespace ft
{
    template <typename Key, typename Val, typename Compare>
    class mapIterator;

    template <typename Key, typename Val, typename Compare>
    class mapConstIterator;

    template <typename Key, typename Val, typename Compare>
    class mapReverseIterator;

    template <typename Key, typename Val, typename Compare>
    class mapReverseConstIterator;

    template <typename Key, typename Val, typename Compare = ft::less<Key> >
    class mapIterator
    {
        private :
            node<Key, Val, Compare>* ptr;


        public :
            //=========================default==========================
            mapIterator(node<Key, Val, Compare>* ptr = NULL) : ptr(ptr)
            {
            }

            //===========================copy===========================
            mapIterator(const mapIterator<Key, Val, Compare> &origin) : ptr(origin.ptr)
            {
            }

            //===========================operator= ======================
            mapIterator<Key, Val, Compare>& operator=(const mapIterator<Key, Val, Compare> &origin)
            {
                ptr = origin.ptr;
                return (*this);
            }

            //=========================== destruct ======================
            ~mapIterator ()
            {

            }

            node<Key, Val, Compare>*  getPtr() const
            {
                return (this->ptr);
            }

            node<Key, Val, Compare>*  getPrev() const
            {
                if (ptr->getleft() != NULL)
                    return (ptr->getRightest(ptr->getLeft()));
                node<Key, Val, Compare>* tmp = ptr->getParent();
                while (tmp != NULL && com(ptr->set.first, tmp->set.first))
                    tmp = tmp->getParent();

                return (tmp);
            }

            node<Key, Val, Compare>*  getNext() const
            {
                if (ptr->getRight() != NULL)
                    return (ptr->getLeftest((ptr->getRight())));
                node<Key, Val, Compare>* tmp = ptr->getParent();
                while (tmp != NULL && com(tmp->set.first, ptr->set.first))
                    tmp = tmp->getParent();

                return (tmp);
            }

            pair<const Key, Val>& operator*(void) const
            {
                return (ptr->set);
            }

            pair<const Key, Val>* operator->(void) const
            {
                return (&(this->operator*()));
            }

			mapIterator<Key, Val, Compare>& operator++(void)
			{
                this->ptr = getNext();
				return (*this);
			}

			mapIterator<Key, Val, Compare> operator++(int)
			{
				mapIterator<Key, Val, Compare> temp(*this);
				this->ptr = getNext();
				return (temp);
			}

			mapIterator<Key, Val, Compare>& operator--(void)
			{
				this->ptr = getPrev();
				return (*this);
			}

			mapIterator<Key, Val, Compare> operator--(int)
			{
				mapIterator<Key, Val, Compare> temp(*this);
			    this->ptr = getPrev();
				return (temp);
			}

            bool operator==(const mapIterator<Key, Val, Compare>& original) const
            {
                return (ptr == original.getPtr());
            }

            bool operator==(const mapConstIterator<Key, Val, Compare>& original) const
            {
                return (ptr == original.getPtr());
            }

            bool operator!=(const mapIterator<Key, Val, Compare>& original) const
            {
                return (!operator==(original));
            }

            bool operator!=(const mapConstIterator<Key, Val, Compare>& original) const
            {
                return (!operator==(original));
            }


    };

    template<typename T>
    mapIterator<Key, Val, Compare> operator+(unsigned int n, mapIterator<Key, Val, Compare>& k)
    {
        return (k + n);
    }

    template<typename T>
    class mapConstIterator
    {
        private :
            node<Key, Val, Compare>*  ptr;
        public :
            //=========================default==========================
            mapConstIterator(node<Key, Val, Compare>* ptr = NULL) : ptr(ptr)
            {

            }

            //===========================copy===========================
            mapConstIterator(const mapConstIterator<Key, Val, Compare> &origin) : ptr(origin.ptr)
            {

            }

            mapConstIterator(const mapIterator<Key, Val, Compare> &origin) : ptr(origin.getPtr())
            {

            }

            //===========================operator= ======================
            mapConstIterator<Key, Val, Compare>& operator=(const mapConstIterator<Key, Val, Compare> &origin)
            {
                this->ptr = origin.ptr;
                return (*this);
            }

            mapConstIterator<Key, Val, Compare>& operator=(const mapIterator<Key, Val, Compare> &origin)
            {
                this->ptr = origin.getPtr();
                return (*this);
            }


            //=========================== destruct ======================
            ~mapConstIterator ()
            {

            }

            node<Key, Val, Compare>* getPtr() const
            {
                return (this->ptr);
            }

            const node<Key, Val, Compare>& operator*(void) const
            {
                return (*ptr);
            }

            const node<Key, Val, Compare>* operator->(void)
            {
                return (&(this->operator*()));
            }

            mapConstIterator<Key, Val, Compare>& operator++(void)
            {
                this->ptr++;
                return (*this);
            }

            mapConstIterator<Key, Val, Compare> operator++(int)
            {
                mapConstIterator<Key, Val, Compare> temp(*this);
                this->ptr++;
                return (temp);
            }

            mapConstIterator<Key, Val, Compare>& operator--(void)
            {
                this->ptr--;
                return (*this);
            }

            mapConstIterator<Key, Val, Compare> operator--(int)
            {
                mapConstIterator<Key, Val, Compare> temp(*this);
                this->ptr--;
                return (temp);
            }

            mapConstIterator<Key, Val, Compare> operator+(unsigned int n) const
            {
                return (mapConstIterator<Key, Val, Compare>(this->ptr + n));
            }

            unsigned int operator+(const mapConstIterator<Key, Val, Compare>target) const
            {
                return (this->ptr + target.getPtr());
            }

            unsigned int operator+(const mapIterator<Key, Val, Compare>target) const
            {
                return (this->ptr + target.getPtr());
            }

            mapConstIterator<Key, Val, Compare> operator-(unsigned int n) const
            {
                return (mapConstIterator<Key, Val, Compare>(this->ptr - n));
            }

            int operator-(const mapConstIterator<Key, Val, Compare>target) const
            {
                return (this->ptr - target.getPtr());
            }

            int operator-(const mapIterator<Key, Val, Compare>target) const
            {
                return (this->ptr - target.getPtr());
            }

            mapConstIterator<Key, Val, Compare>& operator+=(unsigned int n)
            {
                this->ptr += n;
                return (*this);
            }

            mapConstIterator<Key, Val, Compare>& operator-=(unsigned int n)
            {
                this->ptr -= n;
                return (*this);
            }

            const node<Key, Val, Compare>&  operator[](unsigned int n) const
            {
                return (*(operator+(n)));
            }

            bool operator==(const mapConstIterator<Key, Val, Compare>& original) const
            {
                return (this->ptr == original.getPtr());
            }

            bool operator==(const mapIterator<Key, Val, Compare>& original) const
            {
                return (this->ptr == original.getPtr());
            }

            bool operator!=(const mapConstIterator<Key, Val, Compare>& original) const
            {
                return (!operator==(original));
            }

            bool operator!=(const mapIterator<Key, Val, Compare>& original) const
            {
                return (!operator==(original));
            }

            bool operator<(const mapConstIterator<Key, Val, Compare>& original) const
            {
                return (this->ptr < original.getPtr());
            }

            bool operator<(const mapIterator<Key, Val, Compare>& original) const
            {
                return (this->ptr < original.getPtr());
            }

            bool operator<=(const mapConstIterator<Key, Val, Compare>& original) const
            {
                return (operator<(original) || operator==(original));
            }

            bool operator<=(const mapIterator<Key, Val, Compare>& original) const
            {
                return (operator<(original) || operator==(original));
            }

            bool operator>(const mapConstIterator<Key, Val, Compare>& original) const
            {
                return (!operator<=(original));
            }

            bool operator>(const mapIterator<Key, Val, Compare>& original) const
            {
                return (!operator<=(original));
            }

            bool operator>=(const mapConstIterator<Key, Val, Compare>& original) const
            {
                return (operator>(original) || operator==(original));
            }

            bool operator>=(const mapIterator<Key, Val, Compare>& original) const
            {
                return (operator>(original) || operator==(original));
            }

            mapConstIterator<Key, Val, Compare> operator+(unsigned int n)
            {
                return (mapIterator<Key, Val, Compare>(this->ptr + n));
            }
    };

    template<typename T>
    mapConstIterator<Key, Val, Compare> operator+(unsigned int n, mapConstIterator<Key, Val, Compare>& k)
    {
        return (k + n);
    }

    template<typename T>
    class mapReverseIterator
    {
        private :
            node<Key, Val, Compare>*  ptr;
        public :
            //=========================default==========================
            mapReverseIterator(node<Key, Val, Compare>* ptr = NULL) : ptr(ptr)
            {

            }

            //===========================copy===========================
            mapReverseIterator(const mapReverseIterator<Key, Val, Compare> &origin) : ptr(origin.ptr)
            {

            }

            //@question
            mapReverseIterator(const mapConstIterator<Key, Val, Compare> &origin) : ptr(origin.getPtr() - 1)
            {

            }

            //===========================operator= ======================
            mapReverseIterator<Key, Val, Compare>& operator=(const mapReverseIterator<Key, Val, Compare> &origin)
            {
                this->ptr = origin.ptr;
                return (*this);
            }

            ~mapReverseIterator()
            {
            }

            node<Key, Val, Compare>* getPtr() const
            {
                return (this->ptr);
            }

            mapIterator<Key, Val, Compare> base()
            {
                return (mapIterator<Key, Val, Compare>(this->ptr + 1));
            }

            node<Key, Val, Compare>& operator*(void) const
            {
                return (*ptr);
            }

            node<Key, Val, Compare>* operator->(void)
            {
                return (&(this->operator*()));
            }

            mapReverseIterator<Key, Val, Compare>& operator++(void)
            {
                this->ptr--;
                return (*this);
            }

            mapReverseIterator<Key, Val, Compare> operator++(int)
            {
                mapReverseIterator<Key, Val, Compare> temp(*this);
                this->ptr--;
                return (temp);
            }

            mapReverseIterator<Key, Val, Compare>& operator--(void)
            {
                this->ptr++;
                return (*this);
            }

            mapReverseIterator<Key, Val, Compare> operator--(int)
            {
                mapReverseIterator<Key, Val, Compare> temp(*this);
                this->ptr++;
                return (temp);
            }

            mapReverseIterator<Key, Val, Compare> operator+(unsigned int n) const
            {
                return (mapReverseIterator<Key, Val, Compare>(this->ptr - n));
            }

            int operator+(const mapReverseConstIterator<Key, Val, Compare>target) const
            {
                return (this->ptr - target.getPtr());
            }

            int operator+(const mapReverseIterator<Key, Val, Compare>target) const
            {
                return (this->ptr - target.getPtr());
            }

            mapReverseIterator<Key, Val, Compare> operator-(unsigned int n) const
            {
                return (mapReverseIterator<Key, Val, Compare>(this->ptr + n));
            }

            int operator-(const mapReverseConstIterator<Key, Val, Compare>target) const
            {
                return (this->ptr + target.getPtr());
            }   

            int operator-(const mapReverseIterator<Key, Val, Compare>target) const
            {
                return (this->ptr + target.getPtr());
            }

            mapReverseIterator<Key, Val, Compare>& operator+=(unsigned int n)
            {
                this->ptr -= n;
                return (*this);
            }
            
            mapReverseIterator<Key, Val, Compare>& operator-=(unsigned int n)
            {
                this->ptr += n;
                return (*this);
            }

            node<Key, Val, Compare>& operator[](unsigned int n)
            {
                return (*(operator+(n)));
            }

            bool operator==(const mapReverseIterator<Key, Val, Compare>& original) const
            {
                return (ptr == original.getPtr());
            }

            bool operator==(const mapReverseConstIterator<Key, Val, Compare>& original) const
            {
                return (ptr == original.getPtr());
            }


            bool operator!=(const mapReverseIterator<Key, Val, Compare>& original) const
            {
                return (!operator==(original));
            }

            bool operator!=(const mapReverseConstIterator<Key, Val, Compare>& original) const
            {
                return (!operator==(original));
            }

            bool operator<(const mapReverseIterator<Key, Val, Compare>& original) const
            {
                return (ptr > original.getPtr());
            }
            
            bool operator<(const mapReverseConstIterator<Key, Val, Compare>& original) const
            {
                return (ptr > original.getPtr());
            }

            bool operator<=(const mapReverseIterator<Key, Val, Compare>& original) const
            {
                return (operator<(original) || operator==(original));
            }

            bool operator<=(const mapReverseConstIterator<Key, Val, Compare>& original) const
            {
                return (operator<(original) || operator==(original));
            }

            bool operator>(const mapReverseIterator<Key, Val, Compare>& original) const
            {
                return (!operator<=(original));
            }

            bool operator>(const mapReverseConstIterator<Key, Val, Compare>& original) const
            {
                return (!operator<=(original));
            }

            bool operator>=(const mapReverseIterator<Key, Val, Compare>& original) const
            {
                return (operator>(original) || operator==(original));
            }

            bool operator>=(const mapReverseConstIterator<Key, Val, Compare>& original) const
            {
                return (operator>(original) || operator==(original));
            }

    };

    template<typename T>
    mapReverseIterator<Key, Val, Compare> operator+(unsigned int n, mapReverseIterator<Key, Val, Compare>& k)
    {
        return (&(*k) - n);
    }

    template <typename Key, typename Val, typename Compare>
	class mapReverseConstIterator
	{
		private	:
			node<Key, Val, Compare>* ptr;

		public	:
			//default
			mapReverseConstIterator(node<Key, Val, Compare>* ptr = NULL) : ptr(ptr)
			{
				
			}
			//copy
			mapReverseConstIterator(const mapReverseConstIterator<Key, Val, Compare> &origin) : ptr(origin.ptr)
			{
				
			}

			mapReverseConstIterator(const mapReverseIterator<Key, Val, Compare> &origin) : ptr(origin.getPtr())
			{
				
			}

			mapReverseConstIterator(const mapIterator<Key, Val, Compare> &origin) : ptr(origin.getPtr() - 1)
			{
				
			}

			mapReverseConstIterator(const mapConstIterator<Key, Val, Compare> &origin) : ptr(origin.getPtr() -1)
			{
				
			}
			//operator=
			mapReverseConstIterator<Key, Val, Compare>& operator=(const mapReverseConstIterator<Key, Val, Compare> &origin)
			{
				this->ptr = origin.ptr;
				return (*this);
			}
			
			mapReverseConstIterator<Key, Val, Compare>& operator=(const mapReverseIterator<Key, Val, Compare> &origin)
			{
				this->ptr = origin.getPtr();
				return (*this);
			}

			~mapReverseConstIterator()
			{
				
			}

			node<Key, Val, Compare>*	getPtr() const
			{
				return (ptr);
			}

			mapConstIterator<Key, Val, Compare> base()
			{
				return (mapConstIterator<Key, Val, Compare>(this->ptr + 1));
			}

			const node<Key, Val, Compare>& operator*(void) const
			{
				return (*ptr);
			}

			const node<Key, Val, Compare>* operator->(void)
			{
				return (&(this->operator*()));
			}
			//전위 - 미리 증가시키고 보낸다.
			mapReverseConstIterator<Key, Val, Compare>& operator++(void)
			{
				this->ptr--;
				return (*this);
			}
			//후위 - 보내고 증가 시킨다.
			mapReverseConstIterator<Key, Val, Compare> operator++(int)
			{
				mapReverseConstIterator<Key, Val, Compare> temp(*this);
				this->ptr--;
				return (temp);
			}
			//전위 - 미리 증가시키고 보낸다.
			mapReverseConstIterator<Key, Val, Compare>& operator--(void)
			{
				this->ptr++;
				return (*this);
			}
			//후위 - 보내고 증가
			mapReverseConstIterator<Key, Val, Compare> operator--(int)
			{
				mapReverseConstIterator<Key, Val, Compare> temp(*this);
				this->ptr++;
				return (temp);
			}

			mapReverseConstIterator<Key, Val, Compare> operator+(unsigned int n) const
			{
				return (mapReverseConstIterator<Key, Val, Compare>(this->ptr - n));
			}

			unsigned int operator+(const mapReverseIterator<Key, Val, Compare>target) const
			{
				return (this->ptr - target.getPtr());
			}

			unsigned int operator+(const mapReverseConstIterator<Key, Val, Compare>target) const
			{
				return (this->ptr - target.getPtr());
			}

			mapReverseConstIterator<Key, Val, Compare> operator-(unsigned int n) const
			{
				return (mapReverseConstIterator<Key, Val, Compare>(this->ptr + n));
			}

			int operator-(const mapReverseIterator<Key, Val, Compare>target) const
			{
				return (target.getPtr() - this->ptr);
			}

			int operator-(const mapReverseConstIterator<Key, Val, Compare>target) const
			{
				return (target.getPtr() - this->ptr);
			}

			mapReverseConstIterator<Key, Val, Compare>& operator+=(unsigned int n)
			{
				this->ptr -= n;
				return (*this);
			}

			mapReverseConstIterator<Key, Val, Compare>& operator-=(unsigned int n)
			{
				this->ptr += n;
				return (*this);
			}

			node<Key, Val, Compare>&				operator[](unsigned int n)
			{
				return (*(operator+(n)));
			}

			bool		  operator==(const mapReverseConstIterator<Key, Val, Compare> &origin) const
			{
				return (ptr == origin.getPtr());
			}

			bool		  operator==(const mapReverseIterator<Key, Val, Compare> &origin) const
			{
				return (ptr == origin.getPtr());
			}

			bool		  operator!=(const mapReverseConstIterator<Key, Val, Compare> &origin) const
			{
				return (!operator==(origin));
			}

			bool		  operator!=(const mapReverseIterator<Key, Val, Compare> &origin) const
			{
				return (!operator==(origin));
			}

			bool		  operator<(const mapReverseConstIterator<Key, Val, Compare> &origin) const
			{
				return (ptr > origin.getPtr());
			}

			bool		  operator<(const mapReverseIterator<Key, Val, Compare> &origin) const
			{
				return (ptr > origin.getPtr());
			}

			bool		  operator<=(const mapReverseConstIterator<Key, Val, Compare> &origin) const
			{
				return ( operator==(origin) || operator<(origin) );
			}

			bool		  operator<=(const mapReverseIterator<Key, Val, Compare> &origin) const
			{
				return ( operator==(origin) || operator<(origin) );
			}

			bool		  operator>(const mapReverseConstIterator<Key, Val, Compare> &origin) const
			{
				return (!operator<=(origin));
			}

			bool		  operator>(const mapReverseIterator<Key, Val, Compare> &origin) const
			{
				return (!operator<=(origin));
			}

			bool		  operator>=(const mapReverseConstIterator<Key, Val, Compare> &origin) const
			{
				return (operator>(origin) || operator==(origin));
			}

			bool		  operator>=(const mapReverseIterator<Key, Val, Compare> &origin) const
			{
				return (operator>(origin) || operator==(origin));
			}
	};

	template<typename T>
    mapReverseConstIterator<Key, Val, Compare> operator+(unsigned int n, mapReverseConstIterator<Key, Val, Compare>& rai)
    {
            return (&(*rai) - n);
    }

}
    

#endif
