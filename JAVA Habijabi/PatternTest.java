
package pattern;

import java.util.regex.Matcher ;
import java.util.regex.Pattern;
import java.util.* ;

public class PatternTest {

    public static void main(String[] args) {
        
        Scanner sc  = new Scanner(System.in) ;
        
        String line  ;
        
        line = sc.next() ;
        
       //String pat = "^(s{2,8})$" ;
        String pat = "^(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])$" ;
        
        Pattern r = Pattern.compile(pat) ;
        
        Matcher m = r.matcher(line) ;
        
        System.out.print(m.find()? "Found Value. \n"+ line+"\n" : "No Match\n");
    }
 
}
