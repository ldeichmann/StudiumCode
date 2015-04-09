
public interface Stack<E> {
	boolean istLeer();
	void push(E e);
	void pop();
	void multiPop(int k);
	E top();
	E popTop();
}
