#include <iostream>

template <class Q>
class Queue {
	private:
		List<Q> _data;
		size_t _size;  //QUESTION: uneeded?
				//Answer: no, it is needed
	public:
		//Default constructor
		Queue() {
		//EDIT: Took out _data here
		//	_size = _data.size();
			_size = 0;
		}


		//Copy constructor
		Queue(const Queue &q){ //EDIT: chanded List<Q> back to Queue
			_data = q._data;
			_size = q._size; 
		//TODO: Filled in a missing } for you, it caused a lot of trouble haha
		}

		//Getters
		size_t size() const {
			return _size;
		}


		Q front() const{
			return _data.front();
		}


		Q back() const{
			return _data.back();
		}


		//Push to queue
		void enqueue(Q value){
			_data.push_front(value);
			_size = _data.size();
		}


		//Pop from queue
		void dequeue(){
			_data.pop_back();
			_size = _data.size();
		}

		void print(){
			_data.print();
		}


		bool search(Q value){
			return _data.search(value);
		}


		bool empty(){
			return _data.empty();
		}


		//TODO: Get rid of <Q>!
		Queue<Q> operator=(const Queue<Q> q) {
			_data = q._data;
			_size = _data.size();
			return *this; //added this line
		}

		template <class U>
		friend std::ostream &operator<<(std::ostream &out, 
				const Queue<U> &q);

		template <class U>
		friend bool operator==(const Queue<U> &left_queue, 
				const Queue<U> &right_queue);

		template <class U>
		friend bool operator!=(const Queue<U> &left_queue, 
				const Queue<U> &right_queue);
};
/*
template <class U> std::ostream &operator<<(std::ostream &out, const Queue<U> &q){
	out << q._data;
	return out;
}

template <class U> bool operator ==(const Queue<U> &left_side, const Queue<U> &right_side){
	if(left_side.size() == right_side.size() && left_side._data == right_side._data){
		return true;
	}
	else{
		return false;
	}
}

template <class U> bool operator !=(const Queue<U> &left_side, const Queue<U> &right_side){
	if(left_side.size() == right_side.size() && left_side._data == right_side._data){
		return false;
	}
	else{
		return true;
	}
}
*/
