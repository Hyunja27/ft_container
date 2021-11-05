#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP


namespace ft
{
    template <typename T>
    class vectorIterator;

    // template <typename T>
    // class vectorIterator;

    template <typename T>
    class ReverseIterator;

    // template <typename T>
    // class ReverseIterator;

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
                ptr = origin.ptr;
                return (*this);
            }

            //=========================== destruct ======================
            ~vectorIterator ()
            {

            }

            T*  getPtr() const
            {
                return (ptr);
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
				ptr++;
				return (*this);
			}

			vectorIterator<T> operator++(int)
			{
				vectorIterator<T> temp(*this);
				ptr++;
				return (temp);
			}

			vectorIterator<T>& operator--(void)
			{
				ptr--;
				return (*this);
			}

			vectorIterator<T> operator--(int)
			{
				vectorIterator<T> temp(*this);
			    ptr--;
				return (temp);
			}

            vectorIterator<T> operator+(unsigned int n) const
            {
                return (vectorIterator<T>(ptr + n));
            }

            unsigned int operator+(const vectorIterator<T>target) const
            {
                return (ptr + target.getPtr());
            }

            vectorIterator<T> operator-(unsigned int n) const
            {
                return (vectorIterator<T>(ptr - n));
            }

            unsigned int operator-(const vectorIterator<T>target) const
            {
                return (ptr - target.getPtr());
            }

            vectorIterator<T>& operator+=(unsigned int n)
            {
                ptr += n;
                return (*this);
            }

            vectorIterator<T>& operator-=(unsigned int n)
            {
                ptr -= n;
                return (*this);
            }

            T&  operator[](unsigned int n)
            {
                return (*(operator+(n)));
            }

            bool operator==(const vectorIterator<T>& original) const
            {
                return (ptr == original.getPtr());
            }

            bool operator!=(const vectorIterator<T>& original) const
            {
                return (ptr != original.getPtr());
            }

            bool operator<(const vectorIterator<T>& original) const
            {
                return (ptr < original.getPtr());
            }

            bool operator<=(const vectorIterator<T>& original) const
            {
                return (operator<(original) || operator==(original));
            }

            bool operator>(const vectorIterator<T>& original) const
            {
                return (ptr > original.getPtr());
            }

            bool operator>=(const vectorIterator<T>& original) const
            {
                return (ptr > original.getPtr() || ptr == original.getPtr());
            }

            vectorIterator<T> operator+(unsigned int n)
            {
                return (vectorIterator<T> (this->ptr + n));
            }
    };

    template<typename T>
    vectorIterator<T> operator+(unsigned int n, vectorIterator<T>& k)
    {
        return (k + n);
    }

    // template<typename T>
    // class vectorIterator
    // {
    //     private :
    //         T*  ptr;
    //     public :
    //         //=========================default==========================
    //         vectorIterator(T* ptr = NULL) : ptr(ptr)
    //         {

    //         }

    //         //===========================copy===========================
    //         vectorIterator(const vectorIterator<T> &origin) : ptr(origin.ptr)
    //         {

    //         }

    //         vectorIterator(const vectorIterator<T> &origin) : ptr(origin.getPtr())
    //         {

    //         }

    //         //===========================operator= ======================
    //         vectorIterator<T>& operator=(const vectorIterator<T> &origin)
    //         {
    //             this->ptr = origin.ptr;
    //             return (*this);
    //         }

    //         vectorIterator<T>& operator=(const vectorIterator<T> &origin)
    //         {
    //             this->ptr = origin.getPtr();
    //             return (*this);
    //         }


    //         //=========================== destruct ======================
    //         ~vectorIterator ()
    //         {

    //         }

    //         T* getPtr() const
    //         {
    //             return (this->ptr);
    //         }

    //         const T& operator*(void) const
    //         {
    //             return (*ptr);
    //         }

    //         const T* operator->(void)
    //         {
    //             return (&(this->operator*()));
    //         }

    //         vectorIterator<T>& operator++(void)
    //         {
    //             this->ptr++;
    //             return (*this);
    //         }

    //         vectorIterator<T> operator++(int)
    //         {
    //             vectorIterator<T> temp(*this);
    //             this->ptr++;
    //             return (temp);
    //         }

    //         vectorIterator<T>& operator--(void)
    //         {
    //             this->ptr--;
    //             return (*this);
    //         }

    //         vectorIterator<T> operator--(int)
    //         {
    //             vectorIterator<T> temp(*this);
    //             this->ptr--;
    //             return (temp);
    //         }

    //         vectorIterator<T> operator+(unsigned int n) const
    //         {
    //             return (vectorIterator<T>(this->ptr + n));
    //         }

    //         unsigned int operator+(const vectorIterator<T>target) const
    //         {
    //             return (this->ptr + target.getPtr());
    //         }

    //         unsigned int operator+(const vectorIterator<T>target) const
    //         {
    //             return (this->ptr + target.getPtr());
    //         }

    //         vectorIterator<T> operator-(unsigned int n) const
    //         {
    //             return (vectorIterator<T>(this->ptr - n));
    //         }

    //         int operator-(const vectorIterator<T>target) const
    //         {
    //             return (this->ptr - target.getPtr());
    //         }

    //         int operator-(const vectorIterator<T>target) const
    //         {
    //             return (this->ptr - target.getPtr());
    //         }

    //         vectorIterator<T>& operator+=(unsigned int n)
    //         {
    //             this->ptr += n;
    //             return (*this);
    //         }

    //         vectorIterator<T>& operator-=(unsigned int n)
    //         {
    //             this->ptr -= n;
    //             return (*this);
    //         }

    //         const T&  operator[](unsigned int n) const
    //         {
    //             return (*(operator+(n)));
    //         }

    //         bool operator==(const vectorIterator<T>& original) const
    //         {
    //             return (this->ptr == original.getPtr());
    //         }

    //         bool operator==(const vectorIterator<T>& original) const
    //         {
    //             return (this->ptr == original.getPtr());
    //         }

    //         bool operator!=(const vectorIterator<T>& original) const
    //         {
    //             return (!operator==(original));
    //         }

    //         bool operator!=(const vectorIterator<T>& original) const
    //         {
    //             return (!operator==(original));
    //         }

    //         bool operator<(const vectorIterator<T>& original) const
    //         {
    //             return (this->ptr < original.getPtr());
    //         }

    //         bool operator<(const vectorIterator<T>& original) const
    //         {
    //             return (this->ptr < original.getPtr());
    //         }

    //         bool operator<=(const vectorIterator<T>& original) const
    //         {
    //             return (operator<(original) || operator==(original));
    //         }

    //         bool operator<=(const vectorIterator<T>& original) const
    //         {
    //             return (operator<(original) || operator==(original));
    //         }

    //         bool operator>(const vectorIterator<T>& original) const
    //         {
    //             return (!operator<=(original));
    //         }

    //         bool operator>(const vectorIterator<T>& original) const
    //         {
    //             return (!operator<=(original));
    //         }

    //         bool operator>=(const vectorIterator<T>& original) const
    //         {
    //             return (operator>(original) || operator==(original));
    //         }

    //         bool operator>=(const vectorIterator<T>& original) const
    //         {
    //             return (operator>(original) || operator==(original));
    //         }

    //         vectorIterator<T> operator+(unsigned int n)
    //         {
    //             return (vectorIterator<T>(this->ptr + n));
    //         }
    // };

    // template<typename T>
    // vectorIterator<T> operator+(unsigned int n, vectorIterator<T>& k)
    // {
    //     return (k + n);
    // }

    template<typename T>
    class ReverseIterator
    {
        private :
            T*  ptr;
        public :
            //=========================default==========================
            ReverseIterator(T* ptr = NULL) : ptr(ptr)
            {

            }

            //===========================copy===========================
            ReverseIterator(const ReverseIterator<T> &origin) : ptr(origin.ptr)
            {

            }

            ReverseIterator(const vectorIterator<T> &origin) : ptr(origin.getPtr() - 1)
            {

            }

            //===========================operator= ======================
            ReverseIterator<T>& operator=(const ReverseIterator<T> &origin)
            {
                this->ptr = origin.ptr;
                return (*this);
            }

            ~ReverseIterator()
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

            ReverseIterator<T>& operator++(void)
            {
                this->ptr--;
                return (*this);
            }

            ReverseIterator<T> operator++(int)
            {
                ReverseIterator<T> temp(*this);
                this->ptr--;
                return (temp);
            }

            ReverseIterator<T>& operator--(void)
            {
                this->ptr++;
                return (*this);
            }

            ReverseIterator<T> operator--(int)
            {
                ReverseIterator<T> temp(*this);
                this->ptr++;
                return (temp);
            }

            ReverseIterator<T> operator+(unsigned int n) const
            {
                return (ReverseIterator<T>(this->ptr - n));
            }

            unsigned int operator+(const ReverseIterator<T>target) const
            {
                return (this->ptr - target.getPtr());
            }

            ReverseIterator<T> operator-(unsigned int n) const
            {
                return (ReverseIterator<T>(this->ptr + n));
            }

            //@if_error 하위 부분이 그냥 int여야 하는가?    

            unsigned int operator-(const ReverseIterator<T>target) const
            {
                return (this->ptr + target.getPtr());
            }

            ReverseIterator<T>& operator+=(unsigned int n)
            {
                this->ptr -= n;
                return (*this);
            }

            ReverseIterator<T>& operator-=(unsigned int n)
            {
                this->ptr += n;
                return (*this);
            }

            T& operator[](unsigned int n)
            {
                return (*(operator+(n)));
            }

            bool operator==(const ReverseIterator<T>& original) const
            {
                return (this->ptr == original.getPtr());
            }

            bool operator!=(const ReverseIterator<T>& original) const
            {
                return (!operator==(original));
            }

            bool operator<(const ReverseIterator<T>& original) const
            {
                return (this->ptr > original.getPtr());
            }

            bool operator<=(const ReverseIterator<T>& original) const
            {
                return (operator>(original) || operator==(original));
            }

            bool operator>(const ReverseIterator<T>& original) const
            {
                return (!operator>(original));
            }

            bool operator>=(const ReverseIterator<T>& original) const
            {
                return (operator<(original) || operator==(original));
            }

            ReverseIterator<T> operator+(unsigned int n)
            {
                return (ReverseIterator<T>(this->ptr - n));
            }
    };

    template<typename T>
    ReverseIterator<T> operator+(unsigned int n, ReverseIterator<T>& k)
    {
        return (k - n);
    }
}
    

#endif
