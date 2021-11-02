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
            //=========================default==========================
            vectorConstIterator(T* ptr = NULL) : ptr(ptr)
            {

            }

            //===========================copy===========================
            vectorConstIterator(const vectorConstIterator<T> &origin) : ptr(origin.ptr)
            {

            }

            vectorConstIterator(const vectorIterator<T> &origin) : ptr(origin.getPtr())
            {

            }

            //===========================operator= ======================
            vectorConstIterator<T>& operator=(const vectorConstIterator<T> &origin)
            {
                this->ptr = origin.ptr;
                return (*this);
            }

            vectorConstIterator<T>& operator=(const vectorIterator<T> &origin)
            {
                this->ptr = origin.getPtr();
                return (*this);
            }


            //=========================== destruct ======================
            ~vectorConstIterator ()
            {

            }

            T* getPtr() const
            {
                return (this->ptr);
            }

            const T& operator*(void) const
            {
                return (*ptr);
            }

            const T* operator->(void)
            {
                return (&(this->operator*()));
            }

            vectorConstIterator<T>& operator++(void)
            {
                this->ptr++;
                return (*this);
            }

            vectorConstIterator<T> operator++(int)
            {
                vectorConstIterator<T> temp(*this);
                this->ptr++;
                return (temp);
            }

            vectorConstIterator<T>& operator--(void)
            {
                this->ptr--;
                return (*this);
            }

            vectorConstIterator<T> operator--(int)
            {
                vectorConstIterator<T> temp(*this);
                this->ptr--;
                return (temp);
            }

            vectorConstIterator<T> operator+(unsigned int n) const
            {
                return (vectorConstIterator<T>(this->ptr + n));
            }

            unsigned int operator+(const vectorConstIterator<T>target) const
            {
                return (this->ptr + target.getPtr());
            }

            unsigned int operator+(const vectorIterator<target>) const
            {
                return (this->ptr + target.getPtr());
            }

            vectorConstIterator<T> operator-(unsigned int n) const
            {
                return (vectorConstIterator<T>(this->ptr - n));
            }

            int opertator -(const vectorIterator<T>target) const
            {
                return (this->ptr - target.getPtr());
            }

            int opertator -(const vectorConstIterator<T>target) const
            {
                return (this->ptr - target.getPtr());
            }

            vectorConstIterator<T>& operator+=(unsigned int n)
            {
                this->ptr += n;
                return (*this);
            }

            vectorConstIterator<T>& operator-=(unsigned int n)
            {
                this->ptr -= n;
                return (*this);
            }

            const T&  operator[](unsigned int n) const
            {
                return (*(operator+(n)));
            }

            bool operator==(const vectorConstIterator<T>& original) const
            {
                return (this->ptr == original.getPtr());
            }

            bool operator==(const vectorIterator<T>& original) const
            {
                return (this->ptr == original.getPtr());
            }

            bool operator!=(const vectorConstIterator<T>& original) const
            {
                return (!operator==(origin));
            }

            bool operator!=(const vectorIterator<T>& original) const
            {
                return (!operator==(origin));
            }

            bool operator<(const vectorConstIterator<T>& original) const
            {
                return (this->ptr < original.getPtr());
            }

            bool operator<(const vectorIterator<T>& original) const
            {
                return (this->ptr < original.getPtr());
            }

            bool operator<=(const vectorConstIterator<T>& original) const
            {
                return (operator<(origin) || operator==(origin));
            }

            bool operator<=(const vectorIterator<T>& original) const
            {
                return (operator<(origin) || operator==(origin));
            }

            bool operator>(const vectorConstIterator<T>& original) const
            {
                return (!operator<=(original));
            }

            bool operator>(const vectorIterator<T>& original) const
            {
                return (!operator<=(original));
            }

            bool operator>=(const vectorConstIterator<T>& original) const
            {
                return (operator>(original) || operator==(original));
            }

            bool operator>=(const vectorIterator<T>& original) const
            {
                return (operator>(original) || operator==(original));
            }
    };

    template<typename T>
    vectorConstIterator<T> operator+(unsigned int n, vectorConstIterator<T>& k)
    {
        return (&(*k) + n);
    }

    template<typename T>
    class vectorReverseIterator
    {
        private :
            T*  ptr;
        public :
            //=========================default==========================
            vectorReverseIterator(T* ptr = NULL) : ptr(ptr)
            {

            }

            //===========================copy===========================
            vectorReverseIterator(const vectorReverseIterator<T> &origin) : ptr(origin.ptr)
            {

            }

            vectorReverseIterator(const vectorIterator<T> &origin) : ptr(origin.getPtr() - 1)
            {

            }

            //===========================operator= ======================
            vectorReverseIterator<T>& operator=(const vectorReverseIterator<T> &origin)
            {
                this->ptr = origin.ptr;
                return (*this);
            }

            ~vectorReverseIterator()
            {

            }

            T* getPtr() const
            {
                return (this->ptr);
            }

            vectorIterator<T> base()
            {
                return (vectorIterator<T>(this->ptr + 1));
            }
            
            T& operator*(void) const
            {
                return (*ptr);
            }

            T* operator->(void)
            {
                return (&(this->operator*()));
            }

            vectorReverseIterator<T>& operator++(void)
            {
                this->ptr--;
                return (*this);
            }

            vectorReverseIterator<T> operator++(int)
            {
                vectorReverseIterator<T> temp(*this);
                this->ptr--;
                return (temp);
            }

            vectorReverseIterator<T>& operator--(void)
            {
                this->ptr++;
                return (*this);
            }

            vectorReverseIterator<T> operator--(int)
            {
                vectorReverseIterator<T> temp(*this);
                this->ptr++;
                return (temp);
            }

            vectorReverseIterator<T> operator+(unsigned int n) const
            {
                return (vectorReverseIterator<T>(this->ptr - n));
            }

            unsigned int operator+(const vectorReverseIterator<T>target) const
            {
                return (this->ptr - target.getPtr());
            }

            unsigned int operator+(const vectorReverseConstIterator<T>target) const
            {
                return (this->ptr - target.getPtr());
            }

            vectorReverseIterator<T> operator-(unsigned int n) const
            {
                return (vectorReverseIterator<T>(this->ptr + n));
            }

            //@if_error 하위 부분이 그냥 int여야 하는가?    

            unsigned int operator-(const vectorReverseIterator<T>target) const
            {
                return (this->ptr + target.getPtr());
            }

            unsigned int operator-(const vectorReverseConstIterator<T>target) const
            {
                return (this->ptr + target.getPtr());
            }

            vectorReverseIterator<T>& operator+=(unsigned int n)
            {
                this->ptr -= n;
                return (*this);
            }

            vectorReverseIterator<T>& operator-=(unsigned int n)
            {
                this->ptr += n;
                return (*this);
            }

            T& operator[](unsigned int n)
            {
                return (*(operator+(n)));
            }

            bool operator==(const vectorConstReverseIterator<T>& original) const
            {
                return (this->ptr == original.getPtr());
            }

            // 연산자 오버로딩 작업필요 





    }
}

#endif
