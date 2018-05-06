import java.util.Arrays;
public class a
{
	private a() { }
	public static int index0f(int[] a, int key)
	{
		int lo = 0;
		int hi = a.length - 1;
		while (lo <= hi)
		{
			int mid = (lo + hi) >> 1;
			if (key < a[mid]) hi = mid - 1;
			else if (key > a[mid]) lo = mid + 1;
			else return mid;
		}
		return -1;
	}
	public static int rank(int key, int[]a) 
	{
		return index0f(a, key);
	}
	public static void main(String[] args)
	{
		In in = new In(args[0]);
		int[] whitelist = in.readAllInts();
		Arrays.sort(whitelist);
		while (!StdIn.isEmpty())
		{
			int key = StdIn.readInt();
			if (a.index0f(whitelist, key) == -1)
				StdOut.println(key);
		}
	}
}
