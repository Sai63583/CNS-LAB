import javax.crypto.Cipher; 
import javax.crypto.KeyGenerator; 
import javax.crypto.SecretKey; 
 
public class BlowFish{ 
public static void main(String args[]) throws Exception{ 
KeyGenerator keygen = KeyGenerator.getInstance("BlowFish"); 
SecretKey skey = keygen.generateKey(); 
Cipher cipher = Cipher.getInstance("BlowFish"); 
cipher.init(Cipher.ENCRYPT_MODE,skey); 
String plainText = "Hello world"; 
byte[] encrypted = cipher.doFinal(plainText.getBytes()); 
cipher.init(Cipher.DECRYPT_MODE,skey); 
byte[] decrypted = cipher.doFinal(encrypted); 
System.out.println("Plain Text : "+plainText); 
System.out.println("Encrypted Cipher Text is : "+new String(encrypted)); 
System.out.println("Decrypted PlainText is : "+new String(decrypted)); 
} 
} 
 
 
 
 
