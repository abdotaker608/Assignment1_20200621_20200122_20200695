#include<iostream>
using namespace std;
template<typename T>
class tArr
{
private:
    int cap;
    int nOfEle;
    T **arr;
public:
    tArr(int Size=5 );
    ~tArr();
    void initialize(int from);
    void expand();
    void push(const T &element);
    const int& size()const {return this->nOfEle;}
    T&operator[](const int index);
};

template<typename T>
  tArr<T>::tArr(int Size=5)
{
    this->cap = Size;
    this->nOfEle=0;
    this->arr=new T*[this->cap];
    initialize(this->nOfEle);

}

template<typename T>
tArr<T>::~tArr()
{
    for(size_t i=0;i<nOfEle;i++)
    {
        delete this->arr[i];
    }
    delete[] this->arr;
}
  template<typename T>
  T& tArr<T>::operator[](const int index)
  {
      if(indix<0 && index >= this ->nOfEle)
        throw ("out of ");
      return *this->arr[indix];
  }
  template<typename T>
  void tArr<T>::initialize(int from)
    {
        for(size_t i=from;i<cap;i++)
        {
            this->arr[i] = nullptr;
        }

    }

    template<typename T>
    void tArr<T>::expand()
    this ->cap*=2
    T *tempArr= new T[this->cap];
    for(size_t i=0;i<this->nOfEle;i++)
        {
            this->arr[i] = nullptr;
        }














int main()
{
    tArr<int>iArr;
    iArr.push(220)
    iArr.push(2003)
    iArr.push(20300)
    iArr.push(24000)
    iArr.push(20006)
    iArr.push(230)
    iArr.push(260)
    iArr.push(205)
    for(size_t i=0;i<iArr.size();i++)
    {
        cout<<iArr[i]<<endl;
    }
    system("pause");
    return 0;
}
