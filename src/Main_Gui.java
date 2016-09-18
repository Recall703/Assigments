import javax.swing.JFrame;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.IOException;
import java.awt.event.ActionEvent;
import javax.swing.SwingUtilities;

import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.Image;

import javax.swing.JPasswordField;
import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JTextField;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JComboBox;
import javax.swing.JOptionPane;

public class Main_Gui extends JFrame{
	
	//Setting up variable for JButton
	private JButton addLeave, logInAdmin, displayLeave;
	private JTextField[] Data = new JTextField[5];
	final String leavedays[] = {"half","1" ,"2" ,"3" ,"4" ,"5" ,"6" ,"7" ,"8" ,"9" ,"10" ,"11" ,"12" ,"13" ,"14" };
	final String days[] = {"1" ,"2" ,"3" ,"4" ,"5" ,"6" ,"7" ,"8" ,"9" ,"10" ,"11" ,"12" ,"13" ,"14" ,"15" ,"16" ,"17" ,"18" ,"19" ,"20" ,"21" ,"22" ,"23" ,"24" ,"25" ,"26" ,"27" ,"28" ,"29" ,"30" ,"31"};
	final String months[] = {"1","2","3","4","5","6","7","8","9","10","11","12"};
	final String years[] ={"2016" ,"2017" ,"2018" ,"2019" ,"2020" ,"2021" };
	JComboBox<String> day = new JComboBox<String> (days);
	JComboBox<String> month = new JComboBox<String> (months);
	JComboBox<String> year = new JComboBox<String> (years);
	JComboBox<String> leaveday = new JComboBox<String> (leavedays);
	JTextField AdminID = new JTextField(10);
	JTextField AdminPass = new JPasswordField(10);
	private static boolean isAdmin = false;
	private final String Admin_ID = "Admin";
	private final String Admin_Password = "root";
	//Constructor, all GUI will run automatically
	public Main_Gui(){
		
		super("Main Menu"); //set title
		GridLayout betterLayout = new GridLayout(0,1);
		JPanel aPanel = new JPanel();
		aPanel.setLayout(betterLayout); //set layout
		//set the button name
		addLeave = new JButton();
		logInAdmin = new JButton();
		displayLeave = new JButton();
		File image1 = new File("button.png");
		File image2 = new File("login1.png");
		File image3 = new File("button1.png");
		try{
			Image submitimage = ImageIO.read(image1);
			addLeave.setIcon(new ImageIcon(submitimage));
			addLeave.setBorder(null);
			addLeave.setContentAreaFilled(false);
			addLeave.setOpaque(false);
			addLeave.setFocusPainted(false);
			
			Image login = ImageIO.read(image2);
			logInAdmin.setIcon(new ImageIcon(login));
			logInAdmin.setBorder(null);
			logInAdmin.setContentAreaFilled(false);
			logInAdmin.setOpaque(false);
			logInAdmin.setFocusPainted(false);
		
			Image viewLeave = ImageIO.read(image3);
			displayLeave.setIcon(new ImageIcon(viewLeave));
			displayLeave.setBorder(null);
			displayLeave.setContentAreaFilled(false);
			displayLeave.setOpaque(false);
			displayLeave.setFocusPainted(false);
		}catch(IOException ex){
			System.out.println("File not exists");
		}
		//set the action when button clicked
		HandlerClass show = new HandlerClass();
		LogInClass login = new LogInClass();
		addClass adder = new addClass();
		
		addLeave.addActionListener(adder);
		logInAdmin.addActionListener(login);
		displayLeave.addActionListener(show);
		
		//add the button into the GUI
		aPanel.add(addLeave);
		aPanel.add(displayLeave);
		aPanel.add(logInAdmin);
		aPanel.setBackground(Color.DARK_GRAY);
		super.add(aPanel);
	}
	
	//the action when button clicked for display button
	private class HandlerClass implements ActionListener{
		public void actionPerformed(ActionEvent e){
			String Staff_ID;
			Brain zakum = new Brain();
			Staff_ID = JOptionPane.showInputDialog(null, "Enter your staff ID", "Search Function", JOptionPane.OK_CANCEL_OPTION); //read the ID
			zakum.display(Staff_ID); // pass the ID to the zakum.display(String s);
		}
	}
	
	
	//Log in Admin GUI( action when log in as admin is clicked)
	private class LogInClass implements ActionListener{
		public void actionPerformed(ActionEvent e){
			JFrame a = new JFrame("Log in menu");
			a.setSize(300, 150);
			JPanel aPanel = new JPanel(new FlowLayout());
			JButton aButton = new JButton();
			AdminFunction adminFunc = new AdminFunction();
			File image = new File("login.png");
			try{
				Image submitimage = ImageIO.read(image);
				aButton.setIcon(new ImageIcon(submitimage));
				aButton.setBorder(null);
				aButton.setContentAreaFilled(false);
				aButton.setOpaque(false);
				aButton.setFocusPainted(false);
			}catch(IOException ex){
				System.out.println("File not exists");
			}
			aPanel.add(new JLabel("Admin ID: "));
			aPanel.add(AdminID);
			aPanel.add(new JLabel("Admin Password: "));
			aPanel.add(AdminPass);
			aPanel.add(aButton);
			aPanel.setBackground(Color.CYAN);
			aButton.addActionListener(adminFunc);
			a.getRootPane().setDefaultButton(aButton);
			a.getContentPane().add(aPanel);
			a.setVisible(true);
			
		}
	}
	
	//The form for adding leave (GUI which will run when the add leave button is clicked)
	private class addClass implements ActionListener{
		public void actionPerformed(ActionEvent e){
			for(int i=0;i<4;i++)
				Data[i] = new JTextField(10);
			Data[4] = new JTextField(20);
			JFrame b = new JFrame("The form");
			FlowLayout form = new FlowLayout();
			JPanel bPanel = new JPanel(form);
			JButton aButton = new JButton();
			Actor a = new Actor();
			b.setSize(500, 600);
			aButton.addActionListener(a);
			bPanel.add(new JLabel("Name: "));
			bPanel.add(Data[0]);
			bPanel.add(new JLabel("Staff ID: "));
			bPanel.add(Data[1]);
			bPanel.add(new JLabel("Department: "));
			bPanel.add(Data[2]);
			bPanel.add(new JLabel("Position: "));
			bPanel.add(Data[3]);
			bPanel.add(new JLabel("Date"));
			bPanel.add(day);
			bPanel.add(month);
			bPanel.add(year);
			bPanel.add(new JLabel("Duration"));
			bPanel.add(leaveday);
			bPanel.add(new JLabel("Days"));
			bPanel.add(new JLabel("Reason: "));
			bPanel.add(Data[4]);
			File image = new File("index.png");
			try{
				Image submitimage = ImageIO.read(image);
				aButton.setIcon(new ImageIcon(submitimage));
				aButton.setBorder(null);
				aButton.setContentAreaFilled(false);
				aButton.setOpaque(false);
				aButton.setFocusPainted(false);
			}catch(IOException ex){
				System.out.println("File not exists");
			}
			bPanel.add(aButton);
			bPanel.setBackground(Color.LIGHT_GRAY);
			b.getContentPane().add(bPanel);
			b.setVisible(true);
			b.getRootPane().setDefaultButton(aButton);
			
		}
		
		
	}
		//save 
		public class Actor implements ActionListener{
			public void actionPerformed(ActionEvent ae){
				Brain a;
				String[] Information= new String[9];
				try{
					for(int i=0;i<4;i++)
						Information[i]=Data[i].getText();
					Information[4] = day.getSelectedItem().toString();
					Information[5] = month.getSelectedItem().toString();
					Information[6] = year.getSelectedItem().toString();
					Information[7] = leaveday.getSelectedItem().toString();
					Information[8] = Data[4].getText();
					a = new Brain(Information[0],Information[1],Information[2],Information[3],Information[4],Information[5],Information[6],Information[7],Information[8]);
				}catch(Exception e){
					System.out.println("Failed");
				}
			}
		}
		//Log in into admin
		public class AdminFunction implements ActionListener{
			public void actionPerformed(ActionEvent a){
				Brain admin;
				admin = new Brain();
				if((AdminID.getText().equals(Admin_ID)) && (AdminPass.getText().equals(Admin_Password)))
					isAdmin = true;
				else
					isAdmin = false;
				if(isAdmin)
					admin.display();
				else
					JOptionPane.showMessageDialog(null, "Incorrect ID or Password, please try again");
			}
		}
		

}
