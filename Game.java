import java.awt.Font;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;

public class Game extends JPanel {
	
		 static Player player1 = new Player(100,500);
		 static Player player2 = new Player(900,500);	   
		 static boolean correct;
		 int questions =0;
		 int turn = 1;
		 static ButtonHandler buttonSelect;
		 
	public Game() {	
	}
		
		static class ButtonHandler implements ActionListener
		{
			public void actionPerformed(ActionEvent eve) {
				char buttonText = eve.getActionCommand().charAt(0);
				if(buttonText == 'A')
				{
					System.out.print("hi");
                    player1.x = player1.x+100;
				}
					
			}
			
		}	
	public void paintComponent(Graphics g)
	{
        
		super.paintComponent(g);
		ImageIcon i = new ImageIcon("C:\\Users\\Roger\\workspace\\Lost Pyramid of Unix\\images\\gamemap.jpg");
		i.paintIcon(this, g, 0, 0);
		ImageIcon p1 = new ImageIcon("C:\\Users\\Roger\\workspace\\Lost Pyramid of Unix\\images\\player1.png");
		p1.paintIcon(this, g, player1.x, player1.y);
		ImageIcon p2 = new ImageIcon("C:\\Users\\Roger\\workspace\\Lost Pyramid of Unix\\images\\player2.png");
		p2.paintIcon(this, g, player2.x, player2.y);
		ImageIcon d = new ImageIcon("C:\\Users\\Roger\\workspace\\Lost Pyramid of Unix\\images\\darren.jpeg");
		d.paintIcon(this, g, 25, 560); 
		
	    setLayout(null);	
		JButton answer1 = new JButton("A");
		answer1.setBounds(205, 675, 50, 25);
		add(answer1);
		JButton answer2 = new JButton("B");
		answer2.setBounds(425, 675, 50, 25);
		add(answer2);
		JButton answer3 = new JButton("C");
		answer3.setBounds(645, 675, 50, 25);
		add(answer3);
		JButton answer4 = new JButton("D");
		answer4.setBounds(885, 675, 50, 25);
		add(answer4);
		
		JLabel answer11 = new JLabel("answer 1");
		answer11.setBounds(265, 675, 150, 25);
		add(answer11);
		
		JLabel answer22 = new JLabel("answer 2");
		answer22.setBounds(485, 675, 150, 25);
		add(answer22);
		
		JLabel answer33 = new JLabel("answer 3");
		answer33.setBounds(705, 675, 150, 25);
		add(answer33);
		
		JLabel answer44 = new JLabel("answer 4");
		answer44.setBounds(945, 675, 150, 25);
		add(answer44);
		
		buttonSelect = new ButtonHandler();
		answer1.addActionListener(buttonSelect);
		answer2.addActionListener(buttonSelect);
		answer3.addActionListener(buttonSelect);
		answer4.addActionListener(buttonSelect);
		
		
		JTextArea ques = new JTextArea("hthis is a sample question that goes on forevrthis is a samhthis is a sample question that goes on forevrthis is a samhthis is a sample question that goes on forevrthis is a samhthis is a sample question that goes on forevrthis is a samhthis is a sample question that goes on forevrthis is a samhthis is a sa4mple question that goes on forevrthis is a s5amhthis is a sample question that goes on forevrthis is a sample question that goes on forevrthis is ?");
		ques.setBounds(200, 570, 875, 100);
		ques.setLineWrap(true);
		ques.setEditable(false);
		ques.setOpaque(false);
		ques.setCursor(null);
		ques.setFocusable(false);
		Font font = new Font("Serif", Font.BOLD, 18);
		ques.setFont(font);
		add(ques);
	}
	
	public static void main(String [] args)
	{
		Question[] level1= new Question[7];
		Question[] level2= new Question[7];
		Question[] level3= new Question[7];
		Question[] level4= new Question[7];
		Question[] level5= new Question[7];
		
		Game game = new Game();
		JFrame jf = new JFrame();
		jf.setTitle("Lost Pyramid of Unix");
		jf.setSize(1100, 735);
		jf.setResizable(false);
		jf.setVisible(true);
		jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		jf.getContentPane().add(game);
	}
}
