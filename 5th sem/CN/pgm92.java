importjava.io.DataInputStream; 
importjava.io.DataOutputStream; 
importjava.io.File; 
importjava.io.FileInputStream; 
importjava.net.ServerSocket; 
importjava.net.Socket; 
importjava.util.Scanner; 
class server 
{ 
public static void main(String args[])throws Exception 
{ 
while(true) 
{ 
ServerSocketss=new ServerSocket(5000); 
System.out.println ("Waiting for request"); 
Socket s=ss.accept(); 
System.out.println ("Connected With "+s.getInetAddress().toString()); 
DataInputStream din=new DataInputStream(s.getInputStream()); 
DataOutputStreamdout=new DataOutputStream(s.getOutputStream()); 
try 
{ 
String str=""; 
str=din.readUTF(); 
System.out.println("SendGet....Ok"); 
if(!str.equals("stop")) 
{ 
String filename=""; 
filename=din.readUTF(); 

System.out.println("Sending File: "+filename); 
File f=new File(filename); 
FileInputStream fin=new FileInputStream(f); 
longsz=(int) f.length(); 
byte b[]=new byte [1024]; int read; 
dout.writeUTF(Long.toString(sz)); 
dout.flush(); 
System.out.println ("Size: "+sz); 
System.out.println ("Buf size: "+ss.getReceiveBufferSize()); 
while((read = fin.read(b)) != -1) 
{ 
dout.write(b, 0, read); 
dout.flush(); 
} 
fin.close(); 
System.out.println("..ok"); 
dout.flush(); 
} 
dout.writeUTF("stop"); 
System.out.println("Send Complete"); 
dout.flush(); 
} 
catch(Exception e) 
{ 
e.printStackTrace(); 
System.out.println("An error occured"); 
} 
din.close(); 
s.close(); 
ss.close(); 
} 
} 
}
