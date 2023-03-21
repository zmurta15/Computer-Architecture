
public class Seis {
	public static void main(String[] args) {
	int b=127;
	b=(byte)(b|0b10);
	System.out.println("Binary is " + Integer.toBinaryString(b));
	b=(byte)(b&0b00001111);
	System.out.println("Binary is " + Integer.toBinaryString(b));
	b=(byte)(b&0b11111011);
	System.out.println("Binary is " + Integer.toBinaryString(b));
	System.out.println(b);
	//=(byte)(b&0b00000001);
	//System.out.println("Binary is " + Integer.toBinaryString(b));
	b=(byte)(b>>2);
	System.out.println("Binary is " + Integer.toBinaryString(b));
	System.out.println(b);
	}
}