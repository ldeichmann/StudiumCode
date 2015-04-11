package Stack;

public class ListStack<E> implements Stack<E> {
	private Zelle<E> top; // Anker
	
	public boolean istLeer() {

		return top == null;
		
	}

	public void push(E e) {
		
		Zelle<E> neueZelle = new Zelle<E>(e);
		neueZelle.next = top;
		top = neueZelle;
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
		E temp = top();
		pop();
		return temp;
		// TODO Auto-generated method stub
	}
	
	public void multiPop(int k) {
		 
		 while (k > 0) {
			 if (istLeer()) { break;}
			 pop();
			 k--;
			 
		 }
		 
	 }

}
