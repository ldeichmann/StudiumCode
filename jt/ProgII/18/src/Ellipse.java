
public class Ellipse extends FigMZLA implements Flaechenberechnung{
	
	public Ellipse(int x, int y, int z, int a, int b) {
		super(x,y,z,a,b);
		super.figurenTyp = "Ellipse";
	}
	
	public double berechneFlaeche() {
		return Math.abs(Math.PI * A * B);
	}
}
