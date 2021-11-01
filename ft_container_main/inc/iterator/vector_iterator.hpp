#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP


namespace ft
{
    template <typename T>
    class vectorIterator;

    template <typename T>
    class vectorConstIterator;

    template <typename T>
    class vectorReverseIterator;

    template <typename T>
    class vectorConstReverseIterator;

    template <typename T>
    class vectorIterator
    {
        private :
            T* ptr;

        public :
            //=========================default==========================
            vectorIterator(T* ptr = NULL) : ptr(ptr)
            {

            }

            //===========================copy===========================
            vectorIterator(const vectorIterator<T> &origin) : ptr(origin.ptr)
            {

            }

            //===========================operator= ======================
            vectorIterator<T>& operator=(const vectorIterator<T> &origin)
            {
                this->ptr = origin.ptr;
                return (*this);
            }

            //=========================== destruct ======================
            ~vectorIterator ()
            {

            }

            T*  getPtr() const
            {
                return (this->ptr);
            }

            T& operator*(void) const
            {
                return (*ptr);
            }

            T* operator->(void)
            {
                return (&(this->operator*()));
            }

			vectorIterator<T>& operator++(void)
			{
				this->ptr++;
				return (*this);
			}

			vectorIterator<T> operator++(int)
			{
				vectorIterator<T> temp(*this);
				this->ptr++;
				return (temp);
			}

			vectorIterator<T>& operator--(void)
			{
				this->ptr--;
				return (*this);
			}

			vectorIterator<T> operator--(int)
			{
				vectorIterator<T> temp(*this);
				this->ptr--;
				return (temp);
			}

            vectorIterator<T> operator+(unsigned int n) const
            {
                return (vectorIterator<T>(this->ptr + n));
            }

            unsigned int operator+(const vectorConstIterator<T>target) const
            {
                return (this->ptr + target.getPtr());
            }

            unsigned int operator+(const vectorIterator<target>) const
            {
                return (this->ptr + target.getPtr());
            }

            vectorIterator<T> operator-(unsigned int n) const
            {
                return (vectorIterator<T>(this->ptr - n));
            }

            unsigned int operator-(const vectorConstIterator<T>target) const
            {
                return (this->ptr - target.getPtr());
            }

            unsigned int operator-(const vectorIterator<target>) const
            {
                return (this->ptr - target.getPtr());
            }

            vectorIterator<T>& operator+=(unsigned int n)
            {
                this->ptr += n;
                return (*this);
            }

            vectorIterator<T>& operator-=(unsigned int n)
            {
                this->ptr -= n;
                return (*this);
            }

            T&  operator[](unsigned int n)
            {
                return (*(operator+(n)));
            }

            bool operator==(const vectorConstIterator<T>& original) const
            {
                return (ptr == original.getPtr());
            }

            bool operator==(const vectorIterator<T>& original) const
            {
                return (ptr == original.getPtr());
            }

            bool operator!=(const vectorConstIterator<T>& original) const
            {
                return (ptr != original.getPtr());
            }

            bool operator!=(const vectorIterator<T>& original) const
            {
                return (ptr != original.getPtr());
            }

            bool operator<(const vectorConstIterator<T>& original) const
            {
                return (ptr < original.getPtr());
            }

            bool operator<(const vectorIterator<T>& original) const
            {
                return (ptr < original.getPtr());
            }

            bool operator<=(const vectorConstIterator<T>& original) const
            {
                return (ptr < original.getPtr() || ptr == original.getPtr());
            }

            bool operator<=(const vectorIterator<T>& original) const
            {
                return (operator<(origin) || operator==(origin));
            }

            bool operator>(const vectorConstIterator<T>& original) const
            {
                return (ptr > original.getPtr());
            }

            bool operator>(const vectorIterator<T>& original) const
            {
                return (ptr > original.getPtr());
            }

            bool operator>=(const vectorConstIterator<T>& original) const
            {
                return (ptr > original.getPtr() || ptr == original.getPtr());
            }

            bool operator>=(const vectorIterator<T>& original) const
            {
                return (ptr > original.getPtr() || ptr == original.getPtr());
            }
    };

    template<typename T>
    vectorIterator<T> operator+(unsigned int n, vectorIterator<T>& k)
    {
        return (&(*k) + n);
    }

    template<typename T>
    class vectorConstIterator
    {
        private :
            T*  ptr;
        public :
            vectorConstIterator

    }

}

#endif
