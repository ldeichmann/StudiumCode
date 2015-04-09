package jBlog;
import java.util.*;
import java.io.*;
import java.net.*;
import java.lang.Object;


public class fileiomain {

	public static void readUrl(String strUrl, String destFile) throws Exception {
		URL url = new URL(strUrl);
		BufferedReader input = new BufferedReader(new InputStreamReader(
				url.openStream()));
		BufferedWriter output = new BufferedWriter(new OutputStreamWriter(
				new FileOutputStream(destFile)));

		String line = "";
		while ((line = input.readLine()) != null) {
			// System.out.prinln(line);
			output.write(line + "\n");
		}

		input.close();
		output.close();
	}

	public static void writeFile(String path, String input) throws Exception {
		try {
			OutputStream os = new FileOutputStream(path);
			OutputStreamWriter bridge = new OutputStreamWriter(os);
			BufferedWriter writer = new BufferedWriter(bridge);

			writer.write(input + "\n");
			os.close();
			bridge.close();
			writer.close();

		} finally {
		}
	}

	public static void printFile(String path) throws Exception {
		try {
			InputStream is = new FileInputStream(path);
			InputStreamReader bridge = new InputStreamReader(is);

			BufferedReader reader = new BufferedReader(bridge);

			String line = "";
			while ((line = reader.readLine()) != null) {
				System.out.println(line);
			}

			reader.close();
			bridge.close();
			is.close();
		} catch (FileNotFoundException e) {
			// System.out.println("File nicht gefunden");
		} finally {
		}
	}

	public static void showDir(String path) throws Exception {
		File f = new File(path);

		if (!f.exists()) {
			// System.out.println("dir does not exist");
		}

		if (f.isDirectory()) {
				for (File c : f.listFiles()) {
					System.out.println(c.getName());
				}
			}
		if (f.isFile()) {
			// System.out.println("parameter is a file");
		}
	}

	public static void copy(String path, String outPath) throws Exception {
		try {
			InputStream is = new FileInputStream(path);
			OutputStream os = new FileOutputStream(outPath);

			byte buff[] = new byte[1024];
			int length;

			while ((length = is.read(buff)) > 0) {
				os.write(buff, 0, length);
			}
			is.close();
			os.close();
		} finally {
			// System.out.println("copy successfull");
		}
	}

	public static void remove(String path) throws IOException {
		try {
			File f = new File(path);
			if(f.isFile())
				f.delete();
			
			if (f.isDirectory()) {
				for (File c : f.listFiles())
					f.delete();
			}
			if (!f.delete())
				throw new FileNotFoundException("Failed to delete file: " + f);
		}

		catch (Exception x) {
			// System.out.println(path + " wasnt removed");
		}
	}

	public static void main(String[] args) throws Exception {
	
//		File file = new File(System.getProperty("user.home") + File.separator);
		File file = new File("/home/tweekx0r");

	}
}
