#include <iostream>

template <class Data>
class List {
	private:
		struct _list {
			Data value;
			struct _list *next;
			struct _list *prev;
		};
		typedef struct _list Dlist;

		size_t _size;
		Dlist *_front;
		Dlist *_back;

		void reccopy(const Dlist *ptr) {
			if(ptr) { // if(ptr != nullptr) {
				reccopy(ptr->next);
				push_front(ptr->value);
			}
		}
	public:
		List() {
			_size = 0;
			_front = nullptr;
			_back = nullptr;
		}

		List(const List &list) {
			_front=nullptr;
			_back=nullptr;
			_size=0;
			reccopy(list._front);
		}

		~List() {
			while(!empty()) {
			//while(_size > 0) {
				pop_front();
			}
		}

		Data &front() const {
			return _front->value;
		}

		Data &back() const {
			return _back->value;
		}

		size_t size() const {
			return _size;
		}

		size_t length() const {
			return _size;
		}

		List &operator=(const List &x){
			//TODO: Line below is not needed because push_back takes care of size
			//size = x.size();
			Dlist *tempe;
			//TODO: Line below messes up your linked list because you point the front to somewhere else
			//_front = tempe;

			//TODO: front is not an attribute, _front is
			for(tempe = x.front; tempe!=nullptr; tempe = tempe -> next){
				push_back(tempe->value);
			}
			
			return *this;

		}//overload = operator


		void push_front(Data data) {
			Dlist *newNode = new Dlist;
			newNode->value = data;
			newNode->prev = nullptr;

			if(_front==nullptr) {
				newNode->next=nullptr;
				_back=newNode;
			}
			else {
				newNode->next=_front;
				_front->prev = newNode;
			}

			_front=newNode;
			_size++;
		}

		void push_back(Data data) {
			Dlist *newNode = new Dlist;
			newNode->value = data;
			newNode->next=nullptr;

			if(_back!=nullptr) {
				_back->next=newNode;
				newNode->prev = _back;
			}

			if(_front==nullptr) {
				_front=newNode;
				newNode->prev = nullptr;
			}

			_back=newNode;
			_size+=1;
		}

		void pop_front() {
			Dlist *front_to_delete = _front;
			_front = _front->next;

			if(_front==nullptr) {
				_back = nullptr;
			}
			else {
				_front->prev = nullptr;
			}

			delete front_to_delete;
			_size -= 1;
		}

		void pop_back() {
			Dlist *back_to_remove = _back;

			_back = _back -> prev;
			if(_back == nullptr){
				_front = nullptr;
			} else {
				_back -> next = nullptr;
			}
			/*
			if(_front->next!=nullptr) {
				Llist *new_back = _front;
				while(new_back->next!=_back) {
					new_back=new_back->next;
				}
				new_back->next=nullptr;
				_back=new_back;
			}
			else {
				_front=nullptr;
				_back=nullptr;
			}
*/

			delete back_to_remove;
			_size-=1;
		}



		bool search(Data search_value){
			Dlist *temp;
			for(temp = _front; temp != nullptr; temp = temp -> next){
				if(temp -> value == search_value){
					return true;
				}
			}
			return false;
		}

		// leave this alone
		bool empty() const {
			return ((_front==nullptr) && (_back==nullptr));
		}

		//Modify this
		void print() {
			Dlist *temp;
			
			for(temp=_front; temp!=nullptr; temp=temp->next) {
				std::cout << temp->value << " ";
			}
			
			std::cout << std::endl;
		}

		void print_back() {
			Dlist *temp;
			for(temp = _back; temp!=nullptr; temp=temp->prev){
				std::cout <<temp->value<< " " ;
			}
			std::cout <<std::endl;
		}
		template<typename V> friend bool operator == (const List<V> &a, const List <V> &b);
		template<typename V> friend bool operator !=(const List<V> &a, const List<V>&b);
		template <class V> friend std::ostream &operator <<(std::ostream &os, const List<V> &list);
};


template<class V> bool operator ==(const List<V> &a, const List<V> &b){
	if(a.size() != b.size()){
		return false;
	}
	for(auto *aptr=a._front, *bptr=b._front; (aptr != nullptr) && (bptr != nullptr); aptr=aptr->next, bptr=bptr->next){
		if(aptr->value != bptr->value){
			return false;
		}
	}
	return true;
}

template <class V> std::ostream &operator<<(std::ostream &os, const List<V> &list){
	for(auto *iter = list._front; iter != nullptr; iter = iter -> next){
	os << iter -> value << " ";
	}
	return os;
}


template<class V> bool operator !=(const List<V> &a, const List <V> &b){
	return !(a==b);
}
