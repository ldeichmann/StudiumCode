import static org.junit.Assert.*;

import org.junit.Test;


public class ListStackTestTest {

	@org.junit.Test
	public void testStackfresh() {
		Stack<Integer> t = new ListStack<Integer>();
		assertTrue(t.istLeer());
	}
	
	@org.junit.Test
	public void testStackString() {
		
		String testStr = "Stack";
		Stack<Character> s = new ListStack<Character>();
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
		Stack<Character> s = new ListStack<Character>();
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
		Stack<Character> s = new ListStack<Character>();
		for (char ch: testStr.toCharArray()) {
			s.push(ch);
		}
		
		s.multiPop(testStr.length());
		
		assertTrue(s.istLeer());
		
		while(!s.istLeer()) {
			System.out.print(s.popTop());
		}
		
		System.out.println();
		
	}

}
