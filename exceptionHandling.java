<readonly>
import java.util.Scanner;
import java.lang.Exception;
import java.util.*;
class exceptionHandling
{
	static void solve(int arr[]) throws Exception
	{
		int ans=0;
		
		for(int i=0;i<10;i++)
			for(int j=i+1;j<10;j++)
				ans+=arr[i]/arr[j];
		
		throw new MyException(ans);
	}
	public static void main(String args[])
	{
		try
		{
			Scanner in=new Scanner(System.in);
			int n=in.nextInt();
			int []arr= new int[n];
			in.nextLine();
			
			for(int i=0;i<10;i++)
				arr[i]=Integer.parseInt(in.nextLine());
			
			String s=in.nextLine();
			System.out.println(s.charAt(10));
			
			solve(arr);
		}
</readonly>
		// catch(InputMismatchException inputMismatchException) {
        //     System.out.println("Format mismatch");
        // }
		catch (ArrayIndexOutOfBoundsException arrayIndexOutOfBoundsException) {
            System.out.println("Array index is invalid");
        }
		catch (StringIndexOutOfBoundsException stringIndexOutOfBoundsException) {
            System.out.println("Index is invalid");
        }
		catch (ArithmeticException arithmeticException) {
            System.out.println("Invalid division");
        }
		catch (MyException myException) {
            System.out.println(myException);
        }
		catch (Exception exception) {
            System.out.println("Exception encountered");
        }
		finally {
            System.out.println("Exception Handling Completed");
        }
//Write your code here
<readonly>
	}
}
</readonly>
class MyException extends Exception {

    int param;

    MyException(int param) {
        this.param = param;
    }

    public String toString() {
        return "MyException[" + this.param + "]";
    }

}
