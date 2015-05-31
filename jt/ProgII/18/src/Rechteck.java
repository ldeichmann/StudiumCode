
public class Rechteck extends FigMZLA{
	
	public Rechteck(int x, int y, int z, int a, int b) {
		super(x,y,z,a,b);
		super.figurenTyp = "Rechteck";
	}
	
	public double berechneFlaeche() {
		return Math.abs(A * B);
	}
}
