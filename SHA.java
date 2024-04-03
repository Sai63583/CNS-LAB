import java.math.BigInteger; 
import java.security.MessageDigest; 
import java.security.NoSuchAlgorithmException; 
 
public class SHA { 
public static String generateMessageDigest(String input){ 
try { 
MessageDigest md = MessageDigest.getInstance("SHA-512"); 
byte[] messageDigest = md.digest(input.getBytes()); 
BigInteger no = new BigInteger(1, messageDigest); 
String hashtext = no.toString(16); 
while (hashtext.length() < 32) { 
hashtext = "0" + hashtext; 
} 
return hashtext; 
} 
catch (NoSuchAlgorithmException e) { 
throw new RuntimeException(e); 
} 
} 
public static void main(String args[]) throws NoSuchAlgorithmException{ 
int i, n; 
System.out.println("How many Strings for generating HashCodes : "); 
n = Integer.parseInt(System.console().readLine()); 
System.out.println("Enter " + n + " different messages"); 
for(i=1;i<=n;i++){ 
System.out.println("Enter "+ i+ " Message to generate HashCode : "); 
String s1 = System.console().readLine(); 
System.out.println(s1 + " : " + generateMessageDigest(s1)); 
} 
} 
}