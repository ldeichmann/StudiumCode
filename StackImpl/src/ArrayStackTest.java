import static org.junit.Assert.*;

//import org.junit.Test;

public class ArrayStackTest {

	@org.junit.Test
	public void testStackfresh() {
		Stack<Integer> t = new ArrayStack<Integer>(1);
		assertTrue(t.istLeer());
	}
	
	@org.junit.Test
	public void testStackString() {
		
		String testStr = "Stack";
		Stack<Character> s = new ArrayStack<Character>(5);
		for (char ch: testStr.toCharArray()) {
			s.push(ch);
			System.out.println(ch);
		}
		
		System.out.println();
		assertTrue(!s.istLeer());
	}
	
	@org.junit.Test
	public void testStackPrint() {
		String testStr = "emosewAerAskcatS";
		Stack<Character> s = new ArrayStack<Character>(testStr.length());
		for (char ch: testStr.toCharArray()) {
			s.push(ch);
		}
	
		while(!s.istLeer()) {
			System.out.print(s.popTop());
		}
		
		System.out.println();
		assertTrue(s.istLeer());
	}
	
	@org.junit.Test
	public void testMultiPop() {
		String testStr = "emosewAerAskcatS";
		Stack<Character> s = new ArrayStack<Character>(testStr.length());
		for (char ch: testStr.toCharArray()) {
			s.push(ch);
		}
		
		s.multiPop(9);
		
		assertTrue(!s.istLeer());
		
		while(!s.istLeer()) {
			System.out.print(s.popTop());
		}
		
		System.out.println();
		
	}
}
