public class Branch {

    private int id;
    private String name;
    private Account []  accounts;
    private  int accountCount;




    // add your code here

    public void setId(int id) {
        this.id = id;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public Account[] getAccounts() {
        return accounts;
    }

    // you are allowed to add variables here
    public static int branch_count = 0;
    // there can be at most 20 branches
    public static Branch[] branches = new Branch[20];

    // you are not allowed to write any other constructor
    public Branch(int id, String name) {
        this.id = id;
        this.name = name;
        this.accounts = new Account[10];
        // add your code here
        //branch_count++;
        branches[branch_count] = this;
        branch_count++;
    }

	// you are not allowed to modify this method
    public void addAccount(Account a) {
        accounts[accountCount++] = a;
    }

    // add your code here
    public double getBranchBalance()
    {
        double sum_balance=0;
        for(int i = 0; i<accountCount; i++)
        {
            sum_balance +=accounts[i].getBalance();
        }
        return sum_balance;
    }

    public Account getMinBalanceAccount() {
        int location = 0;
        for(int i = 1; i< accountCount; i++)
        {
            if(accounts[i].getBalance() < accounts[location].getBalance())
                location = i;
        }
        return accounts[location];
    }
    public static void transferBalance(Account account1, Account account2, int i) {
        account1.setBalance(account1.getBalance() - i);
        account2.setBalance(account2.getBalance() + i);
    }
    public static void printAllBranchesInfo() {
        for(int i = 0; i< branch_count; i++)
        {
            System.out.println("Branch Id: "+branches[i].getId()+", " + "Branch Name: " + branches[i].getName());
            for(int j = 0; j<branches[i].accountCount; j++)
            {
                System.out.println("Account Number: "+ branches[i].getAccounts()[j].getNumber() + ", "+ "Customer Name: "+ branches[i].getAccounts()[j].getCustomer() + ", Balance: " + branches[i].getAccounts()[j].getBalance());
            }
        }
    }

}
