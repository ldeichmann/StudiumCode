import java.util.*;
import java.sql.*;
import java.io.*;

public class db3 {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException {

		Scanner in = new Scanner(System.in);
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);

		try {
			Class.forName("com.mysql.jdbc.Driver");
		} catch (Exception f) {
			System.out.println("Can't load MySQL driver, exiting...");
			System.exit(-1);
		}
		
		final String dbURL = "jdbc:mysql://slo.swe.fh-luebeck.de:3306/Di2a";
		final String user = "Di2a";
		final String password = "CRFANe42c5mfxzD2";

		String inNamex;
		int rp_kostenx;
		int lp_kostenx;
		double pick_ratex;
		double win_ratex;
		double ban_ratex;
		String rollex;
		int jahr, monat, tag;
		String releasedx;
		
		String query = "insert into Champion (name, rp_kosten, lp_kosten, pick_rate, win_rate, ban_rate, rolle, released) values (?, ?, ?, ?, ?, ?, ?, ?)";

		System.out.println("Name Champion eingeben!");
		inNamex = in.nextLine();

		System.out.println("Riot Points kosten des Champions!");
		rp_kostenx = in.nextInt();

		System.out.println("League Point kosten des Champions!");
		lp_kostenx = in.nextInt();

		System.out.println("Pick Rate des Champions!");
		pick_ratex = in.nextDouble();

		System.out.println("Win-Rate des Champions!");
		win_ratex = in.nextDouble();

		System.out.println("Ban-Rate des Champions!");
		ban_ratex = in.nextDouble();

		System.out.println("Welche Rolle hat der Champion?");
		rollex = br.readLine();

		System.out.println("Wann wurde der Champion herausgebracht? \nBitte geben sie das jahr ein: ");
		jahr = in.nextInt();
		
		System.out.println("Bitte geben sie den Monat ein (zweistellige Zahl):");
		monat = in.nextInt();
		
		System.out.println("Und den Tag: ");
		tag = in.nextInt();

		releasedx = jahr + "-" + monat + "-" + tag;
		
		if(monat > 12 || tag > 31)
			System.out.println("Fehler bei Datumeingabe");
		
		in.close();
		try {
			Connection con = DriverManager.getConnection(dbURL, user, password);
			PreparedStatement cs = con.prepareStatement(query);
			cs.setString(1, inNamex);
			cs.setInt(2, rp_kostenx);
			cs.setInt(3, lp_kostenx);
			cs.setDouble(4, pick_ratex);
			cs.setDouble(5, win_ratex);
			cs.setDouble(6, ban_ratex);
			cs.setString(7, rollex);
			cs.setString(8, releasedx);

			cs.executeUpdate();

			System.out.println("Die Daten wurden erfolgreich eingefuegt! System wird nun geschlossen.");
			System.exit(-1);
			
			cs.close();
			con.close();
			
		} catch (SQLException ex) {
			System.out.println("statement failed");
			System.out.println("SQLException: " + ex.getMessage());
			System.out.println("SQLState: " + ex.getSQLState());
			System.out.println("VendorError: " + ex.getErrorCode());

		}

		catch (Exception e) {
			System.out.println("Fehler Programm wird geschlossen");
		}
	}
}
