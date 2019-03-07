importjava.io.BufferedReader; 
importjava.io.DataInputStream; 
importjava.io.DataOutputStream; 
importjava.io.EOFException; 
importjava.io.File; 
importjava.io.FileOutputStream; 
importjava.io.InputStreamReader; 
importjava.net.Socket; 
importjava.util.Scanner; 
class client 
{ 
public static void main(String args[])throws Exception 
{ 
String address = ""; 
Scanner sc=new Scanner(System.in); 
System.out.println("Enter Server Address: "); 
address=sc.nextLine(); 
Socket s=new Socket(address,5000); 
DataInputStream din=new DataInputStream(s.getInputStream()); 
DataOutputStreamdout=new DataOutputStream(s.getOutputStream()); 
BufferedReaderbr=new BufferedReader(new InputStreamReader(System.in)); 
System.out.println("Send Get to start..."); 
String str="",filename=""; 
try 
{ 
while(!str.equals("start")) 
 str=br.readLine(); 
dout.writeUTF(str); 
dout.flush(); 
System.out.println("Enter File Name: "); 
filename=sc.nextLine(); 
sc.close(); 
dout.writeUTF(filename); 
System.out.println("Receving file: "+filename); 
filename="client"+filename; 
System.out.println("Saving as file: "+filename); 
longsz=Long.parseLong(din.readUTF()); 
System.out.println ("File Size: "+(sz/(1024*1024))+" MB"); 
byte b[]=new byte [1024]; 
System.out.println("Receving file.."); 
FileOutputStreamfos=new FileOutputStream(new File(filename),true); 
longbytesRead; 
do 
{ 
bytesRead = din.read(b, 0, b.length); 
fos.write(b,0,b.length); 
}
while(!(bytesRead<1024)); 
System.out.println("Comleted"); 
fos.close(); 
dout.close(); 
s.close(); 
} 
catch(EOFException e) 
{ 
} 
} 
}
