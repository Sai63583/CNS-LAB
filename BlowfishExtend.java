import javax.crypto.Cipher; 
import javax.crypto.spec.SecretKeySpec; 
public class BlowfishExtend { 
public static void main(String[] args) throws Exception { 
System.out.println("Enter the message for encryption : "); 
String data = System.console().readLine(); 
System.out.println("Enter the Key : "); 
String keyString = System.console().readLine(); 
SecretKeySpec secretKey = new SecretKeySpec(keyString.getBytes(),"Blowfish"); 
Cipher cipher = Cipher.getInstance("Blowfish"); 
cipher.init(Cipher.ENCRYPT_MODE, secretKey); 
byte[] encryptedData = cipher.doFinal(data.getBytes()); 
System.out.println("Encrypted " + new String(encryptedData)); 
cipher.init(Cipher.DECRYPT_MODE, secretKey); 
byte[] decryptedData = cipher.doFinal(encryptedData); 
System.out.println("Decrypted " + new String(decryptedData)); 
} 
} 