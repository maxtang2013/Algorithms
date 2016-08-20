////////////////////////////////////////////
// 一个优先队列实现
template<class T>
class PriorityQueue
{
public:
    PriorityQueue(T* priv, int n);
public:
    void                                   Pop();
    void                                   Push(int i);
    int                                    Top() const;
    bool                                   Empty() const;
    void                                   ChangePriv(int i);
private:
    inline bool                            Less(int i, int j) const;
    inline void                            Swap(int i, int j);
    inline void                            Swim(int i);
    inline void                            Sink(int j);
private:
    std::vector<int>                       mPq;
    std::vector<int>                       mQp;
    int                                    mSize;
    int                                    mMaxSize;
    T*                                     mPriv;
};

template<class T>
PriorityQueue<T>::PriorityQueue(T* priv, int n)
:mSize(1), mMaxSize(n+1), mPriv(priv)
{
    mPq.resize( mMaxSize );
    mPq[0] = -1;
    mQp.resize(mMaxSize);
}
template<class T>
bool PriorityQueue<T>::Empty() const
{
    return mSize == 1;
}

template<class T>
bool PriorityQueue<T>::Less(int i, int j) const
{
    return mPriv[mPq[i]] < mPriv[mPq[j]];
}

template<class T>
void PriorityQueue<T>::Swap(int i, int j)
{
    int tmp = mPq[i];
    mPq[i] = mPq[j];
    mPq[j] = tmp;
    mQp[mPq[i]] = i;
    mQp[mPq[j]] = j;
}
template<class T>
int PriorityQueue<T>::Top() const
{
    return mPq[1];
}
template<class T>
void PriorityQueue<T>::Pop()
{
    Swap(1, --mSize);
    Sink(1);
}
template<class T>
void PriorityQueue<T>::Push(int i)
{
    mPq[mSize]=i;
    mQp[i] = mSize++;
    Swim(mSize-1);
}
template<class T>
void PriorityQueue<T>::Sink(int i)
{
    int j = i << 1, p;
    while ( j < mSize )
    {
        p = j;
        if ( ++j < mSize && Less(j, p) ) ++p;
        if ( Less(p, i) ) Swap(p, i);
        else break;
        i = p;
        j = i << 1;
    }
}
template<class T>
void PriorityQueue<T>::Swim(int i)
{
    int j = i >> 1;
    while ( j > 0 && Less(i, j) )
    {
        Swap(i, j);
        i = j;
        j = i >> 1;
    }
}
template<class T>
void PriorityQueue<T>::ChangePriv(int i)
{
    Sink(mQp[i]);
    Swim(mQp[i]);
}
///////////////////////////////////////////////////////////////////////

