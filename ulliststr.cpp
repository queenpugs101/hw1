#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

void ULListStr::push_back(const std::string& val){
  if (tail_ == NULL){
    // make new node
    Item* newTail= new Item();
    // set it equal to head and tail 
    head_= newTail;
    tail_= newTail;
    // add value to end 
    tail_->val[0] = val;
    tail_->first= 0;
    tail_->last= 1; 
  }
  else if (tail_->last < ARRSIZE){
    //add to back
    tail_->val[tail_->last] = val;
    tail_->last = tail_->last+1;
  }
  else{
    // make new node
    Item* newTail = new Item();
    // set it equal to head and tail 
    Item* temp = tail_;
    tail_= newTail;
    tail_->prev = temp;
    tail_->next = nullptr;
    temp->next = tail_;

    // add value to index 0
    tail_->val[0] = val;
    tail_->first = 0;
    tail_->last = 1;
  }
  size_++;

}

void ULListStr::pop_back(){
   if (tail_ == NULL){
    return;
  }
  else if (tail_->last - tail_->first > 1 ){
    //delete item 
    tail_->last -= 1;
  }
  else{
    //delete node
    Item * oldtail = tail_;
    tail_ = tail_->prev;
    if (tail_ == nullptr){
      head_ = nullptr;
    }
    else{
      tail_->next = nullptr;
    }
    delete oldtail;
  }
  size_--;

}

void ULListStr::push_front(const std::string& val){
   if (head_ == NULL){
    // make new node
    Item* newHead = new Item();
    // set it equal to head and tail 
    head_= newHead;
    tail_= newHead;
    // add value to end 
    head_->val[ARRSIZE-1] = val;
    head_->first= ARRSIZE-1;
    head_->last= ARRSIZE;
  }
  else if (head_->first > 0 ){
    //add to front of head
    head_->val[head_->first-1] = val;
    head_->first = head_->first-1;
  }
  else{
     // make new node
    Item* newHead = new Item();
    // set it equal to head and tail 
    Item* temp = head_;
    head_= newHead;
    head_->next = temp;
    temp->prev = head_;
    head_->prev = nullptr;
    // add value to end 
    head_->val[ARRSIZE-1] = val;
    head_->first = ARRSIZE-1;
    head_->last = ARRSIZE;
  }
  size_++;
}

void ULListStr::pop_front(){
   if (head_ == NULL){
    return;
  }
  else if (head_->last - head_->first > 1 ){
    //delete item 
    head_->first += 1;
  }
  else{
    // delete node
    Item * oldHead = head_;
    head_ = head_->next;
    if (head_ == nullptr){
      tail_ = nullptr;
    }
    else{
      head_->prev = nullptr;
    }
    delete oldHead;

  }
  size_--;
  
}

std::string const & ULListStr::back() const{
  return tail_->val[tail_->last-1];

}

std::string const & ULListStr::front() const{
  return head_->val[head_->first];
}
std::string* ULListStr::getValAtLoc(size_t loc) const{
  if (loc >= size_){
    return nullptr; // loc is out of range
  }
  size_t counter = 0;// total number of indexes passed
  Item* current = head_;
  while(current != nullptr){
    size_t nodeSize(current->last - current->first); // in case node isn't full 
    if(counter + nodeSize > loc){ // 
      size_t distance = loc - counter; 
      return &current->val[current->first + distance];
    }
    counter += nodeSize;
    current= current->next;
  }
  return nullptr;

}
