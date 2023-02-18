public class FloatToInt {
	public static void main(String[] args) {
		float f =0.1f;
		int i=Float.floatToIntBits(f);
		System.out.println("Binary is: "+Integer.toBinaryString(i));
		i=i<<1;
		i=i>>24;
		System.out.println("Binary is: "+Integer.toBinaryString(i));
		i=i-127;
		System.out.println(i);
		System.out.printf("%.20f\n", 0.1f);
	}
}