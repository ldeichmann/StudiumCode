import java.util.LinkedList;
import java.util.List;


public class Figur {
	protected int X = 0;
	protected int Y = 0;
	protected int Z = 0;

	
	private static List<Figur> figuren = new LinkedList<Figur>();
	
	public Figur(int x, int y, int z) {
		this.X = x;
		this.Y = y;
		this.Z = z;
		figuren.add(this);
	}
	
	public static final int anzFiguren() {
		return figuren.size();
	}
	
	public static List<Figur> getAlleFiguren() {
		return figuren;
	}
	
	static List<Figur> getZsortierteFiguren() {
		boolean unsorted=true;
		while (unsorted) {
			unsorted = false;
			for (int i=0; i < figuren.size()-1; i++) {
				if (!( figuren.get(i).Z <= figuren.get(i+1).Z ) ) {
					Figur dummy = figuren.get(i);
					figuren.set(i, figuren.get(i+1));
					figuren.set(i + 1, dummy);
					unsorted = true;
				}
			}
		 }
		return figuren;
	}
	
	public static List<Figur> filterZ(int a, int b, List<Figur> arg) {
		List<Figur> newFigures = new LinkedList<Figur>();
		
		for(int i = 0; i < arg.size(); i++) {
			if(arg.get(i).Z > a && arg.get(i).Z < b) {
				newFigures.add(arg.get(i));
			}
		}
		return newFigures;
	}
	
	public static double getAllF() {
		return FigMZLA.getF();
	}
}
