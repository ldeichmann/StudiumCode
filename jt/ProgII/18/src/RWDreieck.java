
public class RWDreieck extends FigMZLA{
	
	public RWDreieck(int x, int y, int z, int a, int b) {
		super(x,y,z,a,b);
		super.figurenTyp = "Rechtwinkliges Dreieck";
	}
	
	public double berechneFlaeche() {
		return Math.abs(A * B / 2.0);
	}
}
