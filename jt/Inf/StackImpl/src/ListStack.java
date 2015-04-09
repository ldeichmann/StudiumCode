
class ListStack<E> implements Stack<E> {
	private Zelle<E> top; // 
	
	public boolean istLeer() {
		return top == null;
	}

	public void push(E e) {
		Zelle<E> newZ = new Zelle<E>(e);
		newZ.next = top;
		top = newZ;
	}
	
	public void pop() throws StackFehler {
		if (istLeer()) throw new StackFehler("Stack ist leer");
		top = top.next;
	}
	
	public E top() throws StackFehler { 
		if (istLeer()) throw new StackFehler("Stack ist leer");
		return top.inhalt;
	}

	public E popTop() throws StackFehler {
		E t = top();
		pop();
		return t;
	}
	
	public void multiPop(int k) {
		while(k >= 0) {
			if(istLeer()) break;
			pop();
			k--;
		}
	}
}

