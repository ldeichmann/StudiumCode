import java.io.InputStreamReader;
import java.sql.*;
import java.util.Scanner;

public class DBDemo {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		InputStreamReader isr = new InputStreamReader(System.in);

		try {
			Class.forName("com.mysql.jdbc.Driver");
		} catch (Exception f) {
			System.out.println("Can't load MySQL driver, exiting...");
			System.exit(-1);
		}

		final String dbURL = "jdbc:mysql://slo.swe.fh-luebeck.de:3306/Di2a";
		final String user = "Di2a";
		final String password = "CRFANe42c5mfxzD2";

		String tmp = "";

		final String pCall = "{call raise (?)}";

		try {
			Connection con = DriverManager.getConnection(dbURL, user, password);
			CallableStatement stmt = con.prepareCall(pCall);

			tmp = in.nextLine();

			stmt.setString(1, tmp);
			stmt.execute();

			System.out.println("Success");
			
			in.close();
			isr.close();
			
			con.close();

		} catch (SQLException ex) {
			System.out.println("statement failed");
			System.out.println("SQLException: " + ex.getMessage());
			System.out.println("SQLState: " + ex.getSQLState());
			System.out.println("VendorError: " + ex.getErrorCode());

		}

		 catch (Exception e) {
			 e.printStackTrace();
		 }

	}
}