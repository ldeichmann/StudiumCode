package Stack;

import static org.junit.Assert.*;

public class Test {

	@org.junit.Test
	public void testNewStack() {
		Stack teststack = new ArrayStack(1);
		assertTrue(teststack.istLeer());
	}

	@org.junit.Test
	public void testStringInStack() {
		System.out.println("ArrayStack Push String Test:");

		String example = "Höhlenmahler";
		Stack<Character> teststack = new ArrayStack<Character>(12);
		for (char ch: example.toCharArray()) {
			
			teststack.push(ch);
			System.out.println(ch);
		}
		assertFalse(teststack.istLeer());
		System.out.println("\n");
	}
	
	@org.junit.Test
	public void testGetStringInStack() {
		System.out.println("ArrayStack Get String Test:");

		String example = "Pferdereiter";
		Stack<Character> teststack = new ArrayStack<Character>(12);
		for (char ch: example.toCharArray()) {
			
			teststack.push(ch);
		}
		assertFalse(teststack.istLeer());
		while (!teststack.istLeer()) {
			
			System.out.println(teststack.popTop());
		}
		assertTrue(teststack.istLeer());
		System.out.println("\n");
	}

	@org.junit.Test
	public void testListNewStack() {
		Stack teststack = new ListStack();
		assertTrue(teststack.istLeer());
	}
	
	@org.junit.Test
	public void testListStringInStack() {
		System.out.println("ListStack Push String Test:");

		String example = "Höhlenmahler";
		Stack<Character> teststack = new ListStack<Character>();
		for (char ch: example.toCharArray()) {
			
			teststack.push(ch);
			System.out.println(ch);
		}
		assertFalse(teststack.istLeer());
		System.out.println("\n");
	}
	
	@org.junit.Test
	public void testListGetStringInStack() {
		System.out.println("ListStack Get String Test:");

		String example = "Nachrichtensprecher";
		Stack<Character> teststack = new ListStack<Character>();
		for (char ch: example.toCharArray()) {
			
			teststack.push(ch);
		}
		assertFalse(teststack.istLeer());
		while (!teststack.istLeer()) {
			
			System.out.println(teststack.popTop());
		}
		assertTrue(teststack.istLeer());
		System.out.println("\n");
	}

//	@org.junit.Test
//	public void testListError() {
////		System.out.println("ListStack Error:");
//	
//		Stack<Character> teststack = new ListStack<Character>();
//		System.out.println(teststack.top());
//		
//	}

	@org.junit.Test	
	public void testMultipop() {
		
		String example = "Nachrichtensprecher";
		Stack<Character> teststack = new ListStack<Character>();
		for (char ch: example.toCharArray()) {
			
			teststack.push(ch);
		}
		assertFalse(teststack.istLeer());
		teststack.multiPop(20);
		assertTrue(teststack.istLeer());		
	}

	@org.junit.Test
	public void testMultipopArray() {
		
		String example = "Höhlenmahler";
		Stack<Character> teststack = new ArrayStack<Character>(12);
		for (char ch: example.toCharArray()) {
			
			teststack.push(ch);
		}
		assertFalse(teststack.istLeer());
		teststack.multiPop(20);
		assertTrue(teststack.istLeer());		
	}

}
