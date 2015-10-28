//Martha Winger-Bearskin
//assignment 3
//September 27 2013


using namespace std;

template <typename T>
const LinkedList<T>& LinkedList<T>::operator= (const LinkedList<T>& rhs)
{
    if(this != &rhs)
    {
        if(!isEmpty())
            clear();
        const LinkedList<T>* r= &rhs;
        insert_front(r->m_data);
        r= r->m_next;
        //////cout << "& " << *this << endl;
        LinkedList<T> * p = this;
        while(r->m_next != NULL)
        {
            insert(r->m_data, p->m_next);
            p = p->m_next;
            r= r->m_next;
        }
    }
    return *this;
}


template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs)
{
    m_next = NULL;
    *this = rhs;
}

template <typename T>
int LinkedList<T>::size() const
{
    int counter =0;
    const LinkedList<T>* r;
    r = this;
    while(r-> m_next != NULL)
    {
        counter++;
        r = r-> m_next;
    }
    return counter;
    
}


template <typename T>
bool LinkedList<T>::isEmpty() const
{
    if(m_next == NULL)
        return true;
    else
        return false;
}

template <typename T>
LinkedList<T>* LinkedList<T>::getFirstPtr()
{
    if(m_next == NULL)
        return NULL;
    else
        return this;
    
}

template <typename T>
LinkedList<T>* LinkedList<T>::getLastPtr()
{
    LinkedList<T> * r;
    r=this;
    if(r-> m_next == NULL)
        return NULL;
    while(r-> m_next-> m_next!= NULL)
        r=r->m_next;
    return r;
    
}

template <typename T>
LinkedList<T>* LinkedList<T>::getAtPtr(int i)
{
    int counter =0;
    LinkedList<T> *r;
    r = this;
    while(r->m_next != NULL && counter < i)
    {
        counter++;
        r=r->m_next;
    }
    
    if(r-> m_next != NULL)
        return r;
    else
        return NULL;
    
}

template <typename T>
void LinkedList<T>::clear()
{
    LinkedList<T> * r;
    r = m_next;
    while(r->m_next != NULL)
    {
        m_next = r-> m_next;
        delete r;
        r = m_next;
    }
    m_next = NULL;
    delete r;
    
}

template <typename T>
void LinkedList<T>::insert_front(const T& x)
{
    LinkedList<T> * tmp;
    tmp= new LinkedList(m_data, m_next);
    m_data = x;
    m_next = tmp;
}

template <typename T>
void LinkedList<T>::insert(const T& x, LinkedList<T>* pos)
{
    LinkedList<T> * tmp;
    tmp = new LinkedList(pos->m_data, pos->m_next);
    pos-> m_data = x;
    pos-> m_next = tmp;
}



template <typename T>
void LinkedList<T>::remove(LinkedList<T>* pos)
{
    LinkedList<T>* tmp;
    
    tmp = pos-> m_next;
    pos->m_data = tmp->m_data;
    pos->m_next = tmp->m_next;
    delete tmp;
    
    return;
}


template <typename T>
bool LinkedList<T>::operator== (const LinkedList<T>& rhs) const
{
    bool isEqual = false;
    const LinkedList<T> *p= this;
    const LinkedList<T> * r;
    r = &rhs;
    do
    {
        if(p->m_data == r->m_data)
            isEqual = true;
        else
            isEqual = false;
        p= p->m_next;
        r = r->m_next;
        
    }while(r->m_next != NULL && isEqual);
    
    return isEqual;
}


template <typename T>
LinkedList<T>* LinkedList<T>::find(const T& x)
{
    LinkedList<T> * p = this;
    while(p->m_next != NULL)
    {
        if(p-> m_data == x)
        {
            return p;
        }
        p=p->m_next;
    }
    return NULL;
    
}


template <typename T>
void LinkedList<T>::reverse()
{
    LinkedList<T> *r = this;
    LinkedList<T> *tmp = new LinkedList;
    while(r->m_next != NULL)
    {
        tmp->insert_front(r->m_data);
        r= r->m_next;
    }
    //cout << "tmp = " << *tmp << endl;
    clear();
    m_data = tmp->m_data;
    m_next = tmp->m_next;
    delete tmp;
    

}


template <typename T>
void LinkedList<T>::append(const LinkedList<T>& xlist)
{
    const LinkedList<T> * r = &xlist;
    LinkedList<T> * p = getLastPtr();
    while(r->m_next != NULL)
    {
        insert(r->m_data, p->m_next);
        r = r->m_next;
        p=p->m_next;
    }
}
