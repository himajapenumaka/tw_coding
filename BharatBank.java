class BharatBank{
    
    private double balance;
    private String accountType;
    
    BharatBank(double bal, String acntType){
        this.balance=  bal;
        this.accountType= acntType;
    }
    
    public void deposit(double amount){
        this.balance += amount;
    }
    
    public void withdraw(double amount){
        if(this.balance<amount)
            System.out.println("Insufficient balance to withdraw!!");
        else
            this.balance -= amount;
    }
    
    public String getAccountType(){
        return this.accountType;
    }
    
    public double getBalance(){
        return this.balance;
    }
    
    public double getInterest(){
        double rate = 0;
        if(getAccountType().equalsIgnoreCase("Savings"))
            rate= 3;
        return getBalance() * rate * 0.25;
    }
    
}


public class Main
{
      public static void main(String[] args) {
          
        BharatBank Gopal = new BharatBank(50000, "Current");
          BharatBank Amrita = new BharatBank(100000, "Savings");
          Gopal.deposit(10000);
          Amrita.withdraw(45000);
          System.out.println("**The interests of both the accounts**");
          System.out.println("Gopal Account: "+ Gopal.getInterest());
          System.out.println("Amrita Account: "+ Amrita.getInterest());

          System.out.println("\n**Gopal has contacted bank to withdraw 70000**");
          Gopal.withdraw(70000);
	    
	}
}
