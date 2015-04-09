
class ArrayStack<E> implements Stack<E>{
	private E[] array;
	private int top;

	ArrayStack (int kapazität) {
		array = (E[]) new Object[kapazität];
		top = -1;
	}
	
	public boolean istLeer() { return top == -1;}
	
	public boolean istVoll() { return top+1 == array.length;}
	
	public void push (E e) throws StackFehler {
		if (istVoll()) throw new StackFehler("Stack ist voll");
		array[++top] = e;
	}
	
	public void pop() throws StackFehler {
		if (istLeer()) throw new StackFehler("Stack ist leer");
		array[top--] = null; // Element löschen
	}
	
	public E top() throws StackFehler {
		if (istLeer()) throw new StackFehler("Stack ist leer");
		return array[top];
	}

	public E popTop() {
		E e = top();
		pop();
		return e;
	}
	
	public void multiPop(int k) {
		while(k >= 0) {
			if(istLeer()) break;
			pop();
			k--;
		}
	}
}