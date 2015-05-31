
public class main {
	public static void main(String[] args) {
		new Rechteck	(5, 5, -10, 10, 20);
		new RWDreieck	(30, 2, 80, 3, 4);
		new Ellipse		(4, 10, 31, 10, 20);
		new Kreis		(10, 10, 31, 5);
		new Quadrat		(100, 200, 13, 35);
		new Rechteck	(5, 5, 7, 10, 20);
		new RWDreieck	(30, 2, -11, 3, 4);
		new Ellipse		(4, 10, -17, 10, 20);
		new Kreis		(10, 10, 50, 5);
		new Quadrat		(100, 200, 30, 35);
		new Rechteck	(5, 5, 25, 10, 20);
		new RWDreieck	(30, 2, 7, 3, 4);
		new Ellipse		(4, 10, 4, 10, 20);
		new Kreis		(10, 10, 10, 5);
		new Quadrat		(100, 200, 5, 35);
		
		for (Figur f : Figur.filterZ(0, 50, Figur.getZsortierteFiguren())) {
			System.out.println(f);
		}
		
		System.out.println("\nDie Gesamtfläche aller " + 
							Figur.anzFiguren() +  
							" Figuren beträgt " + 
							Figur.getAllF() + 
							" Flächeneinheiten.");
		
		System.out.println("\nDie durchschnittliche Fläche pro Figur beträgt " + 
						 	(Figur.getAllF() / Figur.anzFiguren()) + 
							" Flächeneinheiten.");
		
	}
}
