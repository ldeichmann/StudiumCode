package jBlog;

import java.util.*;
import java.io.*;
import java.sql.*;
import java.io.*;

public class tools {
	
	public static void postPicture() throws IOException {}
	
	public static void saveToDB() throws SQLException {}
	
	public static void connectDB() throws SQLException {}
	
	public static String readFile() throws IOException {
		
		String text = new Scanner(new File("/home/tweekx0r/iconclast/jblog/jblog.html")).useDelimiter("\\A").next();
		return text.substring(72);
	}

	public static String makePost(String capital, String input) throws IOException {
		
		File path = new File("/home/tweekx0r/iconclast/jblog/jblog.html");
		String htmlStr = "<html>\n<head>\n<title>jBlog</title>\n<h1><p>jBlog</p></h1>\n</head>\n<body>\n";
		String newString = htmlStr + "<h2>" + capital + "</h2>" + "\n" + input	+ "\n" + readFile();
		BufferedWriter writer = null;
		try {
			writer = new BufferedWriter(new FileWriter(path));
			writer.write(newString);

		} catch (IOException e) {
		} finally {
			try {
				if (writer != null)
					writer.close();
			} catch (IOException e) {
				System.err.print("Big ass IO Error");
			}
		}
		return newString;
	}

	public static void main(String[] args) throws Exception {
		
		Scanner in 	= new Scanner(System.in);
		String  cap 	= "";
		String 	post = "";
		
		cap  = in.nextLine();
		post = in.nextLine();
		
		//function Call
		makePost(cap,post);
		
		in.close();
		
	}
}
