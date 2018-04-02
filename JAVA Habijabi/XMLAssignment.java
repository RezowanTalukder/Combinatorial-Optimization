package xmlassignment;

import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.DocumentBuilder;
import org.w3c.dom.Document;
import org.w3c.dom.NodeList;
import org.w3c.dom.Node;
import org.w3c.dom.Element;
import java.io.File;
import java.io.InputStream;
import java.util.* ;

public class XMLAssignment {

  public static void main(String argv[]) {

    try {

	DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
	DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
        InputStream fXmlFile = null;
        Document doc = dBuilder.parse(fXmlFile);
			
	
	doc.getDocumentElement().normalize();

	System.out.println("Root element :" + doc.getDocumentElement().getNodeName());
			
	NodeList nList = doc.getElementsByTagName("people");
			
         String email ;
         String pass ;
                        
         Scanner sc = new Scanner(System.in) ;
                        
         email = sc.next();
         pass = sc.next() ;
         

	for (int temp = 0; temp < nList.getLength(); temp++) {

		Node nNode = nList.item(temp);
				
		System.out.println("\nCurrent Element :" + nNode.getNodeName());
				
		if (nNode.getNodeType() == Node.ELEMENT_NODE) {

			Element eElement = (Element) nNode;
                       
                        if(email.equals( eElement.getElementsByTagName("email").item(0).getTextContent())){
                            if(pass.equals( eElement.getElementsByTagName("password").item(0).getTextContent())){
                                System.out.println("Logged in");
                                System.out.println("user id : " + eElement.getAttribute("id"));
                                System.out.println("First Name : " + eElement.getElementsByTagName("firstname").item(0).getTextContent());
                                System.out.println("Last Name : " + eElement.getElementsByTagName("lastname").item(0).getTextContent());
                                System.out.println("email : " + eElement.getElementsByTagName("email").item(0).getTextContent());
                                System.out.println("password : " + eElement.getElementsByTagName("password").item(0).getTextContent());
                             }
                        }	
		}
	}
    } catch (Exception e) {
	e.printStackTrace();
    }
  }

}