package lexer;

import StackImpl.*;

public class Postfix {

	public static void evalPostfix(String PostfixString) {
		
		Stack<Token> PFStack = new ListStack<Token>();
		ExprLexer exprl = new ExprLexer(PostfixString);
		
		Token Token = PFStack.nextToken();
		int v1, v2;
		
		while (Token.getType() != ExprLexer.EOF_TYPE) {
			
//			System.out.print(currentToken.getType() + " ");
//			System.out.println(currentToken.getText());
			
            switch ( Token.getType() ) {
	            // binary
            	case ExprLexer.PLUS: 
	            	v2 = Integer.parseInt(PFStack.popTop().getText());
	            	v1 = Integer.parseInt(PFStack.popTop().getText());
	            	PFStack.push(new Token(ExprLexer.INT, String.valueOf(v1 + v2)));
	            	break;
	            
	            case ExprLexer.MINUS: 
	            	v2 = Integer.parseInt(PFStack.popTop().getText());
	            	v1 = Integer.parseInt(PFStack.popTop().getText());
	            	PFStack.push(new Token(ExprLexer.INT, String.valueOf(v1 - v2)));
	            	break;
	            
	            case ExprLexer.MUL:
	            	v2 = Integer.parseInt(PFStack.popTop().getText());
	            	v1 = Integer.parseInt(PFStack.popTop().getText());
	            	PFStack.push(new Token(ExprLexer.INT, String.valueOf(v1 * v2)));
	            	break;
	            
	            case ExprLexer.DIV:
	            	v2 = Integer.parseInt(PFStack.popTop().getText());
	            	v1 = Integer.parseInt(PFStack.popTop().getText());
	            	PFStack.push(new Token(ExprLexer.INT, String.valueOf(v1 / v2)));
	            	break;
	            
	            
	            // unary
	            case ExprLexer.UMINUS:
	            	v1 = Integer.parseInt(PFStack.popTop().getText());
	            	PFStack.push(new Token(ExprLexer.INT, String.valueOf(-v1)));
	            	break;
	            
	            case ExprLexer.POW:
	            	v1 = Integer.parseInt(PFStack.popTop().getText());
	            	PFStack.push(new Token(ExprLexer.INT, String.valueOf(v1*v1)));
	            	break;
	            

	            case ExprLexer.INT:
	            	PFStack.push(Token);
	            	break;
	            
	            case ExprLexer.NL:
	            	System.out.print("Result: ");
	        		System.out.println(PFStack.popTop().getText());
	        		break;
	            	
	            default: 
	            	System.out.println("shit broke yo");
	    			System.out.print(Token.getType() + " ");
	    			System.out.println(Token.getText());
	            	break;
	            
            }

            Token = exprl.nextToken();
            
		}
			
	}
	
	public static void main(String args[]) {
		
		evalPostfix("3 # 3 8 4 / 2 ^ * 9 - + \n");
		evalPostfix("6 2 - ^ 7 2 # * + \n");
		evalPostfix("2 4 + ^ 11 4 + / \n");
		
	}
	
}
