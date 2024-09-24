import java.applet.Applet;
import java.awt.event.*;
import java.awt.event.*;
import java.awt.*;
import java.applet.*;


public class  button extends Applet implements ActionListener{
    int msg=0;
    TextField tx;
    Button b1= new Button("Clicked");
    Button b2=new Button("Clear");
    
    public void init(){
        tx = new TextField(20);
        
       
       
        add(tx);
     add(b1);
    add(b2);
    b1.addActionListener(this);
    b2.addActionListener(this);
    }

    public void paint(Graphics g){
        g.drawString(""+msg,200,200);

    }

    public void actionPerformed(ActionEvent e){
        String s = e.getActionCommand();
        if(s.equals("Clicked")==true){

            msg=Integer.parseInt(tx.getText());

        }else{
            msg=0;
        }
        repaint();

    }
    
}
/*
 * 
 * <applet code=button.class height=200 width=300></applet>
 */