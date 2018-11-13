# include <iostream>
# include <stack>

using namespace std;

template <class T>
class StackExt {
	std::stack<T> stack;
	std::stack<T> minValues;
public:
	StackExt() {};
	bool empty() const;
	T& top();
	void pop();
	void push(const T& val);
	T& findMin();
};


template <class T>
bool StackExt<T>::empty() const {
	return stack.empty();

}

template <class T>
T& StackExt<T>::top() {
	// a alterar

	return stack.top();
}

template <class T>
void StackExt<T>::pop() {
	if(stack.top()== minValues.top())
		minValues.pop();
	stack.pop();

}

template <class T>
void StackExt<T>::push(const T& val) {
	if(minValues.empty() || val <= minValues.top())
		minValues.push(val);
	stack.push(val);
}

template <class T>
T& StackExt<T>::findMin() {
	return minValues.top();
}
