/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
//package sanim;

/**
 *
 * @author Sanim
 */

import java.util.*;
import java.math.*;
public class Main{
	static BigInteger get(long n){return BigInteger.valueOf(n);}
	static BigInteger mul(BigInteger x , BigInteger y){ return x.multiply(y);}
	static BigInteger sub(BigInteger x , BigInteger y){ return x.subtract(y);}
	static BigInteger add(BigInteger x , BigInteger y){ return x.add(y);}
	static BigInteger div(BigInteger x , BigInteger y){ return x.divide(y);}
	static BigInteger mod(BigInteger x , BigInteger y){ return x.mod(y);}
    
  public static void main(String[] args) {
	  Scanner sc = new Scanner(System.in);
	  int t = sc.nextInt();
          for(int cs = 1;cs<=t;cs++){
              int L = sc.nextInt(), D = sc.nextInt(), S = sc.nextInt() , C = sc.nextInt();
              BigInteger num = BigInteger.ONE,tmp = mul(num,get(S)),tmp2;
              boolean flag = false;
              if(tmp.compareTo(get(L)) >= 0) flag = true;
              num = add(num,get(C));
              tmp = mul(num,get(S));
              if(D>1 && tmp.compareTo(get(L)) >= 0) flag = true;
              if(D>1 && flag == false){
                tmp2 = num;  
                for(int i = 2;i<D;i++){
                      tmp2 = mul(tmp2,num);
                      tmp = mul(tmp2,get(S));
                      if(tmp.compareTo(get(L)) >= 0) {
                          flag = true;
                          break;
                      }
                }
              }
              if(flag) System.out.println("ALIVE AND KICKING");
              else System.out.println("DEAD AND ROTTING");
          }
  }
}
