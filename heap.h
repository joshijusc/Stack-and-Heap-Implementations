#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

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
    std::vector<T> heap_; //Heap data structure
    int m_;
    PComparator c_;
    void heapify(int idx);


};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c /* Don't specify the default value here, only above */ ){
    m_ = m;
    c_ = c;
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {
    // pop back till empty?
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item){
//    void MinHeap<T>::trickleUp(int loc)
//    {
//// could be implemented recursively
//        int parent = loc/2;
//        while(parent >= 1 &&
//              items_[loc] < items_[parent] )
//        { swap(items_[parent], items_[loc]);
//            loc = parent;
//            parent = loc/2;
//        }
//    }
    heap_.push_back(item);
    int loc = heap_.size()-1;
    int parent = (loc-1)/m_;
    while (parent >= 0 && c_(heap_[loc], heap_[parent])) {
        std::swap(heap_[parent], heap_[loc]);
        loc = parent;
        parent = (loc-1)/m_;
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
      throw std::underflow_error("Empty heap");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
    return heap_[0]; // Top of heap assuming best item is at top
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
      throw std::underflow_error("Empty heap");
  }
//    if(idx == leaf node) return;
//    int smallerChild = 2*idx; // start w/ left
//    if(right child exists) {
//        int rChild = smallerChild+1;
//        if(items_[rChild] < items_[smallerChild])
//            smallerChild = rChild;
//    } }
//    if(items_[idx] > items_[smallerChild]){
//    swap(items_[idx], items_[smallerChild]);
//    heapify(smallerChild);

    heap_[0] = heap_.back();
    heap_.pop_back();
    heapify(0); // Trickle Down
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const {
    return heap_.empty();
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const {
    return heap_.size();
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::heapify(int idx) {
    if (m_*idx+1 >= size()){
        return;
    }
    int smallerChild = m_ * idx + 1; // start w/ left
    for (int i = m_*idx+2; i < m_*idx+1 + m_ && i<heap_.size(); i++) { //find the smallest child
        if (c_(heap_[i], heap_[smallerChild])) {
            smallerChild = i;
        }
    }
    if ((c_(heap_[smallerChild], heap_[idx]))) {
        std::swap(heap_[smallerChild], heap_[idx]);
        heapify(smallerChild);
    }
}

#endif