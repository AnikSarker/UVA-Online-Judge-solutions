import java.math.BigInteger;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
            BigInteger[] fact=new BigInteger[205];
            fact[0]=BigInteger.ONE;
            for(int i=1;i<=200;i++) {
                BigInteger p=BigInteger.valueOf(i);
                fact[i]=fact[i-1].multiply(p);
            }        
                    
           Scanner sc=new Scanner(System.in);
           int t=sc.nextInt();
           
           for(int i=1;i<=t;i++){
               int p=sc.nextInt();
               int n=sc.nextInt();
               int black=0;
               for(int j=1;j<=n;j++){
                   int x=sc.nextInt();
                   black+=x;
               }
               int white=p-black;
               
               if(white+1<n) System.out.println("0");    
               else{
                   BigInteger ans=fact[white+1].divide(fact[n].multiply(fact[white+1-n]));
                   System.out.println(ans);
               }
           }
    }
}