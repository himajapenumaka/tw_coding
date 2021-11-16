import java.util.*;
public class CheckMangoTree {

    public static boolean isMangoTree(int rows, int cols, int tree_num){
        // checking if the tree is present in 1st row
        if(tree_num<cols && tree_num>=0)
            return true;
        else{
            // checking if tree is present in 1st or last columns
            if(tree_num%cols-1==0 || tree_num%cols==cols)
                return true;
        }
        return false;
    }

    public static void main(String[] args){
        Scanner sc= new Scanner(System.in);
        int rows= sc.nextInt();
        int cols= sc.nextInt();
        int tree_num= sc.nextInt();
        if(isMangoTree(rows, cols, tree_num)){
            System.out.println("Yes");
        }
        else{
            System.out.println("No");
        }
    }
}
