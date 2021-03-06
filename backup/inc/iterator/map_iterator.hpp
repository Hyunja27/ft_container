#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP


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

    template <typename Key, typename Val, typename Compare = less<Key> >
    class mapIterator
    {
        private :
            node<Key, Val, Compare>*    ptr;
            saver<Key, Val, Compare>*   save;
            Compare                     cmp;

        public :
            //=========================default==========================
            mapIterator()
            {
            }

            mapIterator(node<Key, Val, Compare>* ptr, saver<Key, Val, Compare>* save) : ptr(ptr), save(save)
            {
            }

            //===========================copy===========================
            mapIterator(const mapIterator<Key, Val, Compare> &origin) : ptr(origin.getPtr()), save(origin.getSave())
            {
            }

            //===========================operator= ======================
            mapIterator<Key, Val, Compare>& operator=(const mapIterator<Key, Val, Compare> &origin)
            {
                ptr = origin.getPtr();
                this->save = origin.getSave();
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

            bool		  operator<(const mapConstIterator<Key, Val, Compare> &origin) const
			{
				return (ptr < origin.getPtr());
			}

			bool		  operator<(const mapIterator<Key, Val, Compare> &origin) const
			{
				return (ptr < origin.getPtr());
			}

			bool		  operator<=(const mapConstIterator<Key, Val, Compare> &origin) const
			{
				return ( operator==(origin) || operator<(origin) );
			}

			bool		  operator<=(const mapIterator<Key, Val, Compare> &origin) const
			{
				return ( operator==(origin) || operator<(origin) );
			}

			bool		  operator>(const mapConstIterator<Key, Val, Compare> &origin) const
			{
				return (!operator<=(origin));
			}

			bool		  operator>(const mapIterator<Key, Val, Compare> &origin) const
			{
				return (!operator<=(origin));
			}

			bool		  operator>=(const mapConstIterator<Key, Val, Compare> &origin) const
			{
				return (operator>(origin) || operator==(origin));
			}

			bool		  operator>=(const mapIterator<Key, Val, Compare> &origin) const
			{
				return (operator>(origin) || operator==(origin));
			}


    };

    template <typename Key, typename Val, typename Compare = less<Key> >
    class mapConstIterator
    {
        private :
            node<Key, Val, Compare>*  ptr;
            saver<Key, Val, Compare>* save;
            Compare                   cmp;

        public :
            //=========================default==========================
            mapConstIterator()
            {

            }

            mapConstIterator(node<Key, Val, Compare>* ptr, saver<Key, Val, Compare> *save) : ptr(ptr), save(save)
            {

            }

            //===========================copy===========================
            mapConstIterator(const mapConstIterator<Key, Val, Compare> &origin) : ptr(origin.getPtr()), save(origin.getSave())
            {

            }

            mapConstIterator(const mapIterator<Key, Val, Compare> &origin) : ptr(origin.getPtr()), save(origin.getSave())
            {

            }

            //===========================operator= ======================
            mapConstIterator<Key, Val, Compare>& operator=(const mapConstIterator<Key, Val, Compare> &origin)
            {
                this->ptr = origin.getPtr();
                this->save = origin.getSave();
                return (*this);
            }

            mapConstIterator<Key, Val, Compare>& operator=(const mapIterator<Key, Val, Compare> &origin)
            {
                this->ptr = origin.getPtr();
                this->save = origin.getSave();
                return (*this);
            }


            //=========================== destruct ======================
            ~mapConstIterator ()
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

            const pair<const Key, Val>& operator*(void) const
            {
                return (ptr->set);
            }

            const pair<const Key, Val>* operator->(void) const
            {
                return (&(this->operator*()));
            }

            mapConstIterator<Key, Val, Compare>& operator++(void)
            {
                this->ptr = getNext();
                return (*this);
            }

            mapConstIterator<Key, Val, Compare> operator++(int)
            {
                mapConstIterator<Key, Val, Compare> temp(*this);
                this->ptr = getNext();
                return (temp);
            }

            mapConstIterator<Key, Val, Compare>& operator--(void)
            {
                this->ptr = getPrev();
                return (*this);
            }

            mapConstIterator<Key, Val, Compare> operator--(int)
            {
                mapConstIterator<Key, Val, Compare> temp(*this);
                this->ptr = getPrev();
                return (temp);
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

            bool		  operator<(const mapConstIterator<Key, Val, Compare> &origin) const
			{
				return (ptr < origin.getPtr());
			}

			bool		  operator<(const mapIterator<Key, Val, Compare> &origin) const
			{
				return (ptr < origin.getPtr());
			}

			bool		  operator<=(const mapConstIterator<Key, Val, Compare> &origin) const
			{
				return ( operator==(origin) || operator<(origin) );
			}

			bool		  operator<=(const mapIterator<Key, Val, Compare> &origin) const
			{
				return ( operator==(origin) || operator<(origin) );
			}

			bool		  operator>(const mapConstIterator<Key, Val, Compare> &origin) const
			{
				return (!operator<=(origin));
			}

			bool		  operator>(const mapIterator<Key, Val, Compare> &origin) const
			{
				return (!operator<=(origin));
			}

			bool		  operator>=(const mapConstIterator<Key, Val, Compare> &origin) const
			{
				return (operator>(origin) || operator==(origin));
			}

			bool		  operator>=(const mapIterator<Key, Val, Compare> &origin) const
			{
				return (operator>(origin) || operator==(origin));
			}
    };
    template <typename Key, typename Val, typename Compare = less<Key> >
    class mapReverseIterator
    {
        private :
            node<Key, Val, Compare>*  ptr;
            saver<Key, Val, Compare>*   save;
            Compare                   cmp;
        public :
            //=========================default==========================
            mapReverseIterator()
            {

            }

            mapReverseIterator(node<Key, Val, Compare>* ptr, saver<Key, Val, Compare>* save) : ptr(ptr), save(save)
            {

            }

            //===========================copy===========================
            mapReverseIterator(const mapReverseIterator<Key, Val, Compare> &origin) : ptr(origin.getPtr()), save(origin.getSave())
            {

            }

            // mapReverseIterator(const mapReverseConstIterator<Key, Val, Compare> &origin) : ptr(origin.getPtr()), save(origin.getSave())
            // {

            // }

            //@question
            mapReverseIterator(const mapIterator<Key, Val, Compare> &origin) : ptr(origin.getPrev()), save(origin.getSave())
            {

            }

            // //@question
            // mapReverseIterator(const mapConstIterator<Key, Val, Compare> &origin) : ptr(origin.getPtr()), save(origin.getSave())
            // {

            // }

            //===========================operator= ======================
            mapReverseIterator<Key, Val, Compare>& operator=(const mapReverseIterator<Key, Val, Compare> &origin)
            {
                this->ptr = origin.getPtr();
                this->save = origin.getSave();
                return (*this);
            }

            mapReverseIterator<Key, Val, Compare>& operator=(const mapIterator<Key, Val, Compare> &origin)
            {
                this->ptr = origin.getPrev();
                this->save = origin.getSave();
                return (*this);
            }

            ~mapReverseIterator()
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

            pair<const Key, Val>& operator*(void) const
            {
                return (ptr->set);
            }

            pair<const Key, Val>* operator->(void) const
            {
                return (&(this->operator*()));
            }

            mapReverseIterator<Key, Val, Compare>& operator++(void)
            {
                this->ptr = getNext();
                return (*this);
            }

            mapReverseIterator<Key, Val, Compare> operator++(int)
            {
                mapReverseIterator<Key, Val, Compare> temp(*this);
                this->ptr = getNext();
                return (temp);
            }

            mapReverseIterator<Key, Val, Compare>& operator--(void)
            {
                this->ptr = getPrev();
                return (*this);
            }

            mapReverseIterator<Key, Val, Compare> operator--(int)
            {
                mapReverseIterator<Key, Val, Compare> temp(*this);
                this->ptr = getPrev();
                return (temp);
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

			bool		  operator<(const mapReverseIterator<Key, Val, Compare> &origin) const
			{
				return (ptr > origin.getPtr());
			}

			bool		  operator<=(const mapReverseIterator<Key, Val, Compare> &origin) const
			{
				return ( operator==(origin) || operator<(origin) );
			}

			bool		  operator>(const mapReverseIterator<Key, Val, Compare> &origin) const
			{
				return (!operator<=(origin));
			}

			bool		  operator>=(const mapReverseIterator<Key, Val, Compare> &origin) const
			{
				return (operator>(origin) || operator==(origin));
			}

            mapIterator<Key, Val, Compare> base(void) const
			{
				return (mapIterator<Key, Val, Compare>(getPrev(), save));
			}

    };

    template <typename Key, typename Val, typename Compare = less<Key> >
    class mapReverseConstIterator
	{
		private	:
			node<Key, Val, Compare>* ptr;
            saver<Key, Val, Compare>*   save;
            Compare                  cmp;

		public	:
			//default
            mapReverseConstIterator()
			{
			}

			mapReverseConstIterator(node<Key, Val, Compare>* ptr, saver<Key, Val, Compare>* save) : ptr(ptr), save(save)
			{
			}

			//copy
			mapReverseConstIterator(const mapReverseConstIterator<Key, Val, Compare> &origin) : ptr(origin.getPtr()), save(origin.getSave())
			{
				
			}

			mapReverseConstIterator(const mapReverseIterator<Key, Val, Compare> &origin) : ptr(origin.getPtr()), save(origin.getSave())
			{
				
			}

			mapReverseConstIterator(const mapIterator<Key, Val, Compare> &origin) : ptr(origin.getPrev()), save(origin.getSave())
			{
				
			}

			mapReverseConstIterator(const mapConstIterator<Key, Val, Compare> &origin) : ptr(origin.getPrev()), save(origin.getSave())
			{
				
			}
			//operator=
			mapReverseConstIterator<Key, Val, Compare>& operator=(const mapReverseConstIterator<Key, Val, Compare> &origin)
			{
				this->ptr = origin.getPtr();
                this->save = origin.getSave();
				return (*this);
			}
			
			mapReverseConstIterator<Key, Val, Compare>& operator=(const mapReverseIterator<Key, Val, Compare> &origin)
			{
				this->ptr = origin.getPtr();
                this->save = origin.getSave();
				return (*this);
			}

            mapReverseConstIterator<Key, Val, Compare>& operator=(const mapConstIterator<Key, Val, Compare> &origin)
			{
				this->ptr = origin.getPrev();
                this->save = origin.getSave();
				return (*this);
			}
			
			mapReverseConstIterator<Key, Val, Compare>& operator=(const mapIterator<Key, Val, Compare> &origin)
			{
				this->ptr = origin.getPrev();
                this->save = origin.getSave();
				return (*this);
			}

			~mapReverseConstIterator()
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

			const pair<const Key, Val>& operator*(void) const
            {
                return (ptr->set);
            }

            const pair<const Key, Val>* operator->(void) const
            {
                return (&(this->operator*()));
            }

			//?????? - ?????? ??????????????? ?????????.
			mapReverseConstIterator<Key, Val, Compare>& operator++(void)
			{
				this->ptr = getNext();
				return (*this);
			}
			//?????? - ????????? ?????? ?????????.
			mapReverseConstIterator<Key, Val, Compare> operator++(int)
			{
				mapReverseConstIterator<Key, Val, Compare> temp(*this);
				this->ptr = getNext();
				return (temp);
			}
			//?????? - ?????? ??????????????? ?????????.
			mapReverseConstIterator<Key, Val, Compare>& operator--(void)
			{
				this->ptr = getPrev();
				return (*this);
			}
			//?????? - ????????? ??????
			mapReverseConstIterator<Key, Val, Compare> operator--(int)
			{
				mapReverseConstIterator<Key, Val, Compare> temp(*this);
				this->ptr = getPrev();
				return (temp);
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

            mapConstIterator<Key, Val, Compare> base(void) const
			{
				return (mapConstIterator<Key, Val, Compare>(getPrev(), save));
			}
	};
};

#endif
