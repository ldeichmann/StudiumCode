package Stack;

public interface Stack<E> {
	 boolean istLeer();
	 void push(E e);
	 void pop();
	 E top();
	 E popTop();
	 void multiPop(int k);
}