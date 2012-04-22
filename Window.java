import java.awt.Container;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.net.MalformedURLException;
import java.net.URL;

import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;



public class Window {

	
	static JFrame myFrame;
	static Container myPane;
	static JLabel question;
    static String imageFileName = "darren.jpeg";
    private URL imageSrc;
	
	
	static JButton answerA;
	static JButton answerB;
	static JButton answerC;
	static JButton answerD;
	
	
	
	
	
	static class AnswersHandler implements ActionListener
	{
		
		@Override
		public void actionPerformed(ActionEvent e) 
		{
			char whichButton;
			whichButton = e.getActionCommand().charAt(0);
			
			switch(whichButton)
			{
			case 'A':
				break;
			case 'B':
				break;
			case 'C':
				break;
			case 'D':
				break;
			}			
		}
	}
	
	
	
	public Window(URL img) 
	{
	 imageSrc = img;
	}


/*
	public static void main(String[] args) 
	{
		
		//get Question
		//Question q = new Question();
		
	
		//wait for answer
		
	    //set Frame
		myFrame = new JFrame();
		myFrame.setSize(1000, 700);
		myFrame.setResizable(false);
		myFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		myFrame.setTitle("Lost Pyramid of Unix");
		myFrame.getContentPane();
		myFrame.setLayout(new GridLayout(4, 2));
		myFrame.setVisible(true);
		
		URL imageSrc = null;
        try {
             imageSrc = ((new File(imageFileName)).toURI()).toURL();
        } catch (MalformedURLException e) {}
        
        Window wind = new Window(imageSrc);
        
        */

		



	}



}
