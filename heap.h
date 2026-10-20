#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>

#include <vector> //make data as vector
#include <utility> //wanna use swap.

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> data_;
  int m_;
  PComparator comp_;
};

// Add implementation of member functions here
//constructor
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : m_(m), comp_(c) {}

//destructor
template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const { return data_.empty(); } //true -> if empty

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const { return data_.size(); } //return size

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) //do same with role of push..
{
  data_.push_back(item);
  int index = data_.size()-1;

  while(index>0)
  {
    int parent = (index-1)/m_;

    if(comp_(data_[index], data_[parent])) //can use it both min max heap!
    {
      std::swap(data_[index], data_[parent]);
      index=parent;
    }
    else break;
  }
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data_[0]; //get the top
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }

  if(data_.size()==1) // for one ele, just del it
  {
    data_.pop_back();
    return;
  }

  data_[0]=data_.back(); //put last val at root
  data_.pop_back();

  int index = 0;

  while(true)
  {
    int firstC = m_*index+1; //find first child index of current node

    if(firstC>=static_cast<int>(data_.size())) break; //no child = leaf node
    //transfer size_t to int

    int bestC = firstC; //let first one as higher priority

    for(int i=1;i<m_;i++) //find real higher child
    {
      int child = firstC+i;

      if(child<static_cast<int>(data_.size())&&comp_(data_[child], data_[bestC])) bestC = child;

      if(comp_(data_[bestC], data_[index])) //do swap thing
      {
        std::swap(data_[bestC], data_[index]);
        index = bestC;
      }
      else break; // if the priority is correct already, end it
    }
  }
}



#endif

