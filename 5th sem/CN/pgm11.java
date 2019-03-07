importjava.util.*; 
importjava.math.BigInteger; 
importjava.lang.*; 
classRSAkeygen 
{ 
public static void main(String[] args) 
{ 
Random rand1=new Random(System.currentTimeMillis());
 Random rand2=new Random(System.currentTimeMillis()*10); 
intpubkey=Integer.parseInt(args[0]); 
BigIntegerbigB_p=BigInteger.probablePrime(32, rand1);
BigIntegerbigB_q=BigInteger.probablePrime(32, rand2); 
BigIntegerbigB_n=bigB_p.multiply(bigB_q); // n
BigInteger bigB_p_1=bigB_p.subtract(new BigInteger("1"));
BigInteger bigB_q_1=bigB_q.subtract(new BigInteger("1")); 
BigInteger bigB_p_1_q_1=bigB_p_1.multiply(bigB_q_1);  // z
while(true) 
{ 
BigIntegerBigB_GCD=bigB_p_1_q_1.gcd(new BigInteger(""+pubkey)); if(BigB_GCD.equals(BigInteger.ONE)) 
{ 
break; 
} 
pubkey++; 
} 
BigIntegerbigB_pubkey=new BigInteger(""+pubkey); // e
BigIntegerbigB_prvkey=bigB_pubkey.modInverse(bigB_p_1_q_1);  //d System.out.println("public key : "+bigB_pubkey+","+bigB_n);//(e,n)  System.out.println("private key : "+bigB_prvkey+","+bigB_n);//(d,n) 
} 
} 

RSA Encryption and Decryption 

importjava.math.BigInteger;
 importjava.util.*; 
classRSAEncDec 
{ 
public static void main(String[] args) 
{ 
BigIntegerbigB_pubkey = new BigInteger(args[0]);
BigIntegerbigB_prvkey = new BigInteger(args[1]);
BigIntegerbigB_n = new BigInteger(args[2]); 
intasciiVal=Integer.parseInt(args[3]); 
BigIntegerbigB_val=new BigInteger(""+asciiVal); 
BigIntegerbigB_cipherVal=bigB_val.modPow(bigB_pubkey,bigB_n); 
System.out.println("Cipher text: " + bigB_cipherVal); 
BigIntegerbigB_plainVal=bigB_cipherVal.modPow(bigB_prvkey,bigB_n);
intplainVal=bigB_plainVal.intValue(); 
System.out.println("Plain text:" + plainVal);
}
}
