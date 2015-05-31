
abstract public class FigMZLA extends Figur{
	protected int A = 0;
	protected int B = 0;
	protected static double F = 0;
	protected String figurenTyp;
	
	public FigMZLA(int x, int y, int z, int a, int b) {
		super(x,y,z);
		this.A = a;
		this.B = b;
		if(z > 0 && z < 50)
			F += berechneFlaeche();
	}
	
	abstract public double berechneFlaeche();
	
	public static double getF() {
		return F;
	}
	
	public String toString() {
		return figurenTyp + " an Position ( " + super.X + ", " + super.Y + ", " + super.Z + " )" +
				" mit einer Fläche von " + berechneFlaeche() + " Flächeneinheiten.";
	}
}
