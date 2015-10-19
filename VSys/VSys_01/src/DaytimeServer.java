import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.util.Date;

public class DaytimeServer {
	private static final int BUFSIZE = 508;
	public static void main(String[] args) throws Exception {

		if (args.length != 1) {
			System.err.println("Usage: java DayTimeServer <port>");
			return;
		}
		int port = Integer.parseInt(args[0]);
		// Socket an anonymen Port binden
		try (DatagramSocket socket = new DatagramSocket(port)){
			// paket empfangen
			DatagramPacket packetIn = new DatagramPacket(new byte[BUFSIZE], BUFSIZE);
			socket.receive(packetIn);
			String received = new String(packetIn.getData(), 0, packetIn.getLength());
			System.out.println(received);
			// datum antworten
			byte data[] = new Date().toString().getBytes();			
			DatagramPacket packetOut = new DatagramPacket(data, data.length, packetIn.getAddress(), packetIn.getPort());
			socket.send(packetOut);
		}
	}
}