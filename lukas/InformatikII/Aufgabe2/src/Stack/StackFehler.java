package Stack;

class StackFehler extends RuntimeException {
	 String message;
	 StackFehler(String m) {message = m; System.out.println(m);}
}