#ifndef SET_ITERATOR_HPP
#define SET_ITERATOR_HPP


namespace ft
{
    template <typename Key, typename Val, typename Compare>
    class setIterator;

    template <typename Key, typename Val, typename Compare>
    class setConstIterator;

    template <typename Key, typename Val, typename Compare>
    class setReverseIterator;

    template <typename Key, typename Val, typename Compare>
    class setReverseConstIterator;

    template <typename Key, typename Val, typename Compare = less<Key> >
    class setIterator
    {
        private :
            node<Key, Val, Compare>*    ptr;
            saver<Key, Val, Compare>*   save;
            Compare                     cmp;

        public :
            //=========================default==========================
            setIterator()
            {
            }

            setIterator(node<Key, Val, Compare>* ptr, saver<Key, Val, Compare>* save) : ptr(ptr), save(save)
            {
            }

            //===========================copy===========================
            setIterator(const setIterator<Key, Val, Compare> &origin) : ptr(origin.getPtr()), save(origin.getSave())
            {
            }

            //===========================operator= ======================
            setIterator<Key, Val, Compare>& operator=(const setIterator<Key, Val, Compare> &origin)
            {
                ptr = origin.getPtr();
                this->save = origin.getSave();
                return (*this);
            }

            //=========================== destruct ======================
            ~setIterator ()
            {

            }

            node<Key, Val, Compare>*  getPtr() const
            {
                return (this->ptr);
            }

            saver<Key, Val, Compare>* getSave() const
            {
                return (this->save);
            }

            node<Key, Val, Compare>*  getPrev() const
            {
                if (ptr == NULL)
                    return (ptr->getRightest(save->root));

                if (ptr->getLeft() != NULL)
                    return (ptr->getRightest(ptr->getLeft()));
                node<Key, Val, Compare>* tmp = ptr->getParent();
                while (tmp != NULL && cmp(ptr->set.first, tmp->set.first))
                    tmp = tmp->getParent();

                return (tmp);
            }

            node<Key, Val, Compare>*  getNext() const
            {
                if (ptr == NULL)
                    return (ptr->getleftest(save->root));

                if (ptr->getRight() != NULL)
                    return (ptr->getleftest((ptr->getRight())));
                node<Key, Val, Compare>* tmp = ptr->getParent();
                while (tmp != NULL && cmp(tmp->set.first, ptr->set.first))
                    tmp = tmp->getParent();

                return (tmp);
            }

            const Key& operator*(void) const
            {
                return (ptr->set.first);
            }

            Key* operator->(void) const
            {
                return (&(this->operator*()));
            }

			setIterator<Key, Val, Compare>& operator++(void)
			{
                this->ptr = getNext();
				return (*this);
			}

			setIterator<Key, Val, Compare> operator++(int)
			{
				setIterator<Key, Val, Compare> temp(*this);
				this->ptr = getNext();
				return (temp);
			}

			setIterator<Key, Val, Compare>& operator--(void)
			{
				this->ptr = getPrev();
				return (*this);
			}

			setIterator<Key, Val, Compare> operator--(int)
			{
				setIterator<Key, Val, Compare> temp(*this);
			    this->ptr = getPrev();
				return (temp);
			}

            bool operator==(const setIterator<Key, Val, Compare>& original) const
            {
                return (ptr == original.getPtr());
            }

            bool operator==(const setConstIterator<Key, Val, Compare>& original) const
            {
                return (ptr == original.getPtr());
            }

            bool operator!=(const setIterator<Key, Val, Compare>& original) const
            {
                return (!operator==(original));
            }

            bool operator!=(const setConstIterator<Key, Val, Compare>& original) const
            {
                return (!operator==(original));
            }

            bool		  operator<(const setConstIterator<Key, Val, Compare> &origin) const
			{
				return (ptr < origin.getPtr());
			}

			bool		  operator<(const setIterator<Key, Val, Compare> &origin) const
			{
				return (ptr < origin.getPtr());
			}

			bool		  operator<=(const setConstIterator<Key, Val, Compare> &origin) const
			{
				return ( operator==(origin) || operator<(origin) );
			}

			bool		  operator<=(const setIterator<Key, Val, Compare> &origin) const
			{
				return ( operator==(origin) || operator<(origin) );
			}

			bool		  operator>(const setConstIterator<Key, Val, Compare> &origin) const
			{
				return (!operator<=(origin));
			}

			bool		  operator>(const setIterator<Key, Val, Compare> &origin) const
			{
				return (!operator<=(origin));
			}

			bool		  operator>=(const setConstIterator<Key, Val, Compare> &origin) const
			{
				return (operator>(origin) || operator==(origin));
			}

			bool		  operator>=(const setIterator<Key, Val, Compare> &origin) const
			{
				return (operator>(origin) || operator==(origin));
			}


    };

    template <typename Key, typename Val, typename Compare = less<Key> >
    class setConstIterator
    {
        private :
            node<Key, Val, Compare>*  ptr;
            saver<Key, Val, Compare>* save;
            Compare                   cmp;

        public :
            //=========================default==========================
            setConstIterator()
            {

            }

            setConstIterator(node<Key, Val, Compare>* ptr, saver<Key, Val, Compare> *save) : ptr(ptr), save(save)
            {

            }

            //===========================copy===========================
            setConstIterator(const setConstIterator<Key, Val, Compare> &origin) : ptr(origin.getPtr()), save(origin.getSave())
            {

            }

            setConstIterator(const setIterator<Key, Val, Compare> &origin) : ptr(origin.getPtr()), save(origin.getSave())
            {

            }

            //===========================operator= ======================
            setConstIterator<Key, Val, Compare>& operator=(const setConstIterator<Key, Val, Compare> &origin)
            {
                this->ptr = origin.getPtr();
                this->save = origin.getSave();
                return (*this);
            }

            setConstIterator<Key, Val, Compare>& operator=(const setIterator<Key, Val, Compare> &origin)
            {
                this->ptr = origin.getPtr();
                this->save = origin.getSave();
                return (*this);
            }


            //=========================== destruct ======================
            ~setConstIterator ()
            {

            }

            node<Key, Val, Compare>*  getPtr() const
            {
                return (this->ptr);
            }

            saver<Key, Val, Compare>* getSave() const
            {
                return (this->save);
            }

            node<Key, Val, Compare>*  getPrev() const
            {
                if (ptr == NULL)
                    return (ptr->getRightest(save->root));

                if (ptr->getLeft() != NULL)
                    return (ptr->getRightest(ptr->getLeft()));
                node<Key, Val, Compare>* tmp = ptr->getParent();
                while (tmp != NULL && cmp(ptr->set.first, tmp->set.first))
                    tmp = tmp->getParent();

                return (tmp);
            }

            node<Key, Val, Compare>*  getNext() const
            {
                // std::cout << std::endl << " getnext's ptr set: " << ptr->set.first << std::endl;

                if (ptr == NULL)
                {
                    // std::cout << std::endl << " case 1" << std::endl;
                    return (ptr->getleftest(save->root));
                }

                if (ptr->getRight() != NULL)
                {
                    // std::cout << std::endl << " ptr->getright's val : " << ptr->getRight()->set.first << std::endl;

                    // std::cout << std::endl << " case 2" << std::endl;
                    return (ptr->getleftest((ptr->getRight())));
                }
                node<Key, Val, Compare>* tmp = ptr->getParent();
                while (tmp != NULL && cmp(tmp->set.first, ptr->set.first))
                    tmp = tmp->getParent();

                return (tmp);
            }

            const Key& operator*(void) const
            {
                return (ptr->set.first);
            }

            const pair<const Key, Val>* operator->(void) const
            {
                return (&(this->operator*()));
            }

            setConstIterator<Key, Val, Compare>& operator++(void)
            {
                this->ptr = getNext();
                return (*this);
            }

            setConstIterator<Key, Val, Compare> operator++(int)
            {
                setConstIterator<Key, Val, Compare> temp(*this);
                this->ptr = getNext();
                return (temp);
            }

            setConstIterator<Key, Val, Compare>& operator--(void)
            {
                this->ptr = getPrev();
                return (*this);
            }

            setConstIterator<Key, Val, Compare> operator--(int)
            {
                setConstIterator<Key, Val, Compare> temp(*this);
                this->ptr = getPrev();
                return (temp);
            }

            bool operator==(const setConstIterator<Key, Val, Compare>& original) const
            {
                return (this->ptr == original.getPtr());
            }

            bool operator==(const setIterator<Key, Val, Compare>& original) const
            {
                return (this->ptr == original.getPtr());
            }

            bool operator!=(const setConstIterator<Key, Val, Compare>& original) const
            {
                return (!operator==(original));
            }

            bool operator!=(const setIterator<Key, Val, Compare>& original) const
            {
                return (!operator==(original));
            }

            bool		  operator<(const setConstIterator<Key, Val, Compare> &origin) const
			{
				return (ptr < origin.getPtr());
			}

			bool		  operator<(const setIterator<Key, Val, Compare> &origin) const
			{
				return (ptr < origin.getPtr());
			}

			bool		  operator<=(const setConstIterator<Key, Val, Compare> &origin) const
			{
				return ( operator==(origin) || operator<(origin) );
			}

			bool		  operator<=(const setIterator<Key, Val, Compare> &origin) const
			{
				return ( operator==(origin) || operator<(origin) );
			}

			bool		  operator>(const setConstIterator<Key, Val, Compare> &origin) const
			{
				return (!operator<=(origin));
			}

			bool		  operator>(const setIterator<Key, Val, Compare> &origin) const
			{
				return (!operator<=(origin));
			}

			bool		  operator>=(const setConstIterator<Key, Val, Compare> &origin) const
			{
				return (operator>(origin) || operator==(origin));
			}

			bool		  operator>=(const setIterator<Key, Val, Compare> &origin) const
			{
				return (operator>(origin) || operator==(origin));
			}
    };
    template <typename Key, typename Val, typename Compare = less<Key> >
    class setReverseIterator
    {
        private :
            node<Key, Val, Compare>*  ptr;
            saver<Key, Val, Compare>*   save;
            Compare                   cmp;
        public :
            //=========================default==========================
            setReverseIterator()
            {

            }

            setReverseIterator(node<Key, Val, Compare>* ptr, saver<Key, Val, Compare>* save) : ptr(ptr), save(save)
            {

            }

            //===========================copy===========================
            setReverseIterator(const setReverseIterator<Key, Val, Compare> &origin) : ptr(origin.getPtr()), save(origin.getSave())
            {

            }

            // setReverseIterator(const setReverseConstIterator<Key, Val, Compare> &origin) : ptr(origin.getPtr()), save(origin.getSave())
            // {

            // }

            //@question
            setReverseIterator(const setIterator<Key, Val, Compare> &origin) : ptr(origin.getPrev()), save(origin.getSave())
            {

            }

            // //@question
            // setReverseIterator(const setConstIterator<Key, Val, Compare> &origin) : ptr(origin.getPtr()), save(origin.getSave())
            // {

            // }

            //===========================operator= ======================
            setReverseIterator<Key, Val, Compare>& operator=(const setReverseIterator<Key, Val, Compare> &origin)
            {
                this->ptr = origin.getPtr();
                this->save = origin.getSave();
                return (*this);
            }

            setReverseIterator<Key, Val, Compare>& operator=(const setIterator<Key, Val, Compare> &origin)
            {
                this->ptr = origin.getPrev();
                this->save = origin.getSave();
                return (*this);
            }

            ~setReverseIterator()
            {
            }

            node<Key, Val, Compare>*  getPtr() const
            {
                return (this->ptr);
            }

            saver<Key, Val, Compare>* getSave() const
            {
                return (this->save);
            }

            node<Key, Val, Compare>*  getPrev() const
            {
                if (ptr == NULL)
                    return (ptr->getleftest(save->root));
    
                if (ptr->getRight() != NULL)
                    return (ptr->getleftest(ptr->getRight()));
                node<Key, Val, Compare>* tmp = ptr->getParent();
                while (tmp != NULL && cmp(tmp->set.first, ptr->set.first))
                    tmp = tmp->getParent();

                return (tmp);
            }

            node<Key, Val, Compare>*  getNext() const
            {
                if (ptr == NULL)
                    return (ptr->getRightest(save->root));

                if (ptr->getLeft() != NULL)
                    return (ptr->getRightest((ptr->getLeft())));
                node<Key, Val, Compare>* tmp = ptr->getParent();
                while (tmp != NULL && cmp(ptr->set.first, tmp->set.first))
                    tmp = tmp->getParent();

                return (tmp);
            }

            Key& operator*(void) const
            {
                return (ptr->set->first);
            }

            pair<const Key, Val>* operator->(void) const
            {
                return (&(this->operator*()));
            }

            setReverseIterator<Key, Val, Compare>& operator++(void)
            {
                this->ptr = getNext();
                return (*this);
            }

            setReverseIterator<Key, Val, Compare> operator++(int)
            {
                setReverseIterator<Key, Val, Compare> temp(*this);
                this->ptr = getNext();
                return (temp);
            }

            setReverseIterator<Key, Val, Compare>& operator--(void)
            {
                this->ptr = getPrev();
                return (*this);
            }

            setReverseIterator<Key, Val, Compare> operator--(int)
            {
                setReverseIterator<Key, Val, Compare> temp(*this);
                this->ptr = getPrev();
                return (temp);
            }

            bool operator==(const setReverseIterator<Key, Val, Compare>& original) const
            {
                return (ptr == original.getPtr());
            }

            bool operator==(const setReverseConstIterator<Key, Val, Compare>& original) const
            {
                return (ptr == original.getPtr());
            }


            bool operator!=(const setReverseIterator<Key, Val, Compare>& original) const
            {
                return (!operator==(original));
            }

            bool operator!=(const setReverseConstIterator<Key, Val, Compare>& original) const
            {
                return (!operator==(original));
            }

			bool		  operator<(const setReverseIterator<Key, Val, Compare> &origin) const
			{
				return (ptr > origin.getPtr());
			}

			bool		  operator<=(const setReverseIterator<Key, Val, Compare> &origin) const
			{
				return ( operator==(origin) || operator<(origin) );
			}

			bool		  operator>(const setReverseIterator<Key, Val, Compare> &origin) const
			{
				return (!operator<=(origin));
			}

			bool		  operator>=(const setReverseIterator<Key, Val, Compare> &origin) const
			{
				return (operator>(origin) || operator==(origin));
			}

            setIterator<Key, Val, Compare> base(void) const
			{
				return (setIterator<Key, Val, Compare>(getPrev(), save));
			}

    };

    template <typename Key, typename Val, typename Compare = less<Key> >
    class setReverseConstIterator
	{
		private	:
			node<Key, Val, Compare>* ptr;
            saver<Key, Val, Compare>*   save;
            Compare                  cmp;

		public	:
			//default
            setReverseConstIterator()
			{
			}

			setReverseConstIterator(node<Key, Val, Compare>* ptr, saver<Key, Val, Compare>* save) : ptr(ptr), save(save)
			{
			}

			//copy
			setReverseConstIterator(const setReverseConstIterator<Key, Val, Compare> &origin) : ptr(origin.getPtr()), save(origin.getSave())
			{
				
			}

			setReverseConstIterator(const setReverseIterator<Key, Val, Compare> &origin) : ptr(origin.getPtr()), save(origin.getSave())
			{
				
			}

			setReverseConstIterator(const setIterator<Key, Val, Compare> &origin) : ptr(origin.getPrev()), save(origin.getSave())
			{
				
			}

			setReverseConstIterator(const setConstIterator<Key, Val, Compare> &origin) : ptr(origin.getPrev()), save(origin.getSave())
			{
				
			}
			//operator=
			setReverseConstIterator<Key, Val, Compare>& operator=(const setReverseConstIterator<Key, Val, Compare> &origin)
			{
				this->ptr = origin.getPtr();
                this->save = origin.getSave();
				return (*this);
			}
			
			setReverseConstIterator<Key, Val, Compare>& operator=(const setReverseIterator<Key, Val, Compare> &origin)
			{
				this->ptr = origin.getPtr();
                this->save = origin.getSave();
				return (*this);
			}

            setReverseConstIterator<Key, Val, Compare>& operator=(const setConstIterator<Key, Val, Compare> &origin)
			{
				this->ptr = origin.getPrev();
                this->save = origin.getSave();
				return (*this);
			}
			
			setReverseConstIterator<Key, Val, Compare>& operator=(const setIterator<Key, Val, Compare> &origin)
			{
				this->ptr = origin.getPrev();
                this->save = origin.getSave();
				return (*this);
			}

			~setReverseConstIterator()
			{
				
			}

            node<Key, Val, Compare>*  getPtr() const
            {
                return (this->ptr);
            }

            saver<Key, Val, Compare>* getSave() const
            {
                return (this->save);
            }

            node<Key, Val, Compare>*  getPrev() const
            {
                if (ptr == NULL)
                    return (ptr->getleftest(save->root));

                if (ptr->getRight() != NULL)
                    return (ptr->getleftest(ptr->getRight()));
                node<Key, Val, Compare>* tmp = ptr->getParent();
                while (tmp != NULL && cmp(tmp->set.first, ptr->set.first))
                    tmp = tmp->getParent();

                return (tmp);
            }

            node<Key, Val, Compare>*  getNext() const
            {
                if (ptr == NULL)
                    return (ptr->getRightest(save->root));

                if (ptr->getLeft() != NULL)
                    return (ptr->getRightest((ptr->getLeft())));
                node<Key, Val, Compare>* tmp = ptr->getParent();
                while (tmp != NULL && cmp(ptr->set.first, tmp->set.first))
                    tmp = tmp->getParent();

                return (tmp);
            }

			const Key& operator*(void) const
            {
                return (ptr->set->first);
            }

            const pair<const Key, Val>* operator->(void) const
            {
                return (&(this->operator*()));
            }

			//전위 - 미리 증가시키고 보낸다.
			setReverseConstIterator<Key, Val, Compare>& operator++(void)
			{
				this->ptr = getNext();
				return (*this);
			}
			//후위 - 보내고 증가 시킨다.
			setReverseConstIterator<Key, Val, Compare> operator++(int)
			{
				setReverseConstIterator<Key, Val, Compare> temp(*this);
				this->ptr = getNext();
				return (temp);
			}
			//전위 - 미리 증가시키고 보낸다.
			setReverseConstIterator<Key, Val, Compare>& operator--(void)
			{
				this->ptr = getPrev();
				return (*this);
			}
			//후위 - 보내고 증가
			setReverseConstIterator<Key, Val, Compare> operator--(int)
			{
				setReverseConstIterator<Key, Val, Compare> temp(*this);
				this->ptr = getPrev();
				return (temp);
			}

			bool		  operator==(const setReverseConstIterator<Key, Val, Compare> &origin) const
			{
				return (ptr == origin.getPtr());
			}

			bool		  operator==(const setReverseIterator<Key, Val, Compare> &origin) const
			{
				return (ptr == origin.getPtr());
			}

			bool		  operator!=(const setReverseConstIterator<Key, Val, Compare> &origin) const
			{
				return (!operator==(origin));
			}

			bool		  operator!=(const setReverseIterator<Key, Val, Compare> &origin) const
			{
				return (!operator==(origin));
			}

			bool		  operator<(const setReverseConstIterator<Key, Val, Compare> &origin) const
			{
				return (ptr > origin.getPtr());
			}

			bool		  operator<(const setReverseIterator<Key, Val, Compare> &origin) const
			{
				return (ptr > origin.getPtr());
			}

			bool		  operator<=(const setReverseConstIterator<Key, Val, Compare> &origin) const
			{
				return ( operator==(origin) || operator<(origin) );
			}

			bool		  operator<=(const setReverseIterator<Key, Val, Compare> &origin) const
			{
				return ( operator==(origin) || operator<(origin) );
			}

			bool		  operator>(const setReverseConstIterator<Key, Val, Compare> &origin) const
			{
				return (!operator<=(origin));
			}

			bool		  operator>(const setReverseIterator<Key, Val, Compare> &origin) const
			{
				return (!operator<=(origin));
			}

			bool		  operator>=(const setReverseConstIterator<Key, Val, Compare> &origin) const
			{
				return (operator>(origin) || operator==(origin));
			}

			bool		  operator>=(const setReverseIterator<Key, Val, Compare> &origin) const
			{
				return (operator>(origin) || operator==(origin));
			}

            setConstIterator<Key, Val, Compare> base(void) const
			{
				return (setConstIterator<Key, Val, Compare>(getPrev(), save));
			}
	};
};

#endif
