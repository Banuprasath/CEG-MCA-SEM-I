
/*
 * 
 30-09-2024
 * You are tasked with developing a simple shopping cart system using a Java applet that allows users to add and remove products from the cart, view the current cart, and calculate the total cost of the selected items. The applet must provide an interface for selecting products, entering quantities, and viewing the total amount due.

Requirements:
Product Selection:

The applet should allow users to select from three predefined products.
The user should be able to enter the quantity of the selected product.
Buttons: The applet should have the following buttons:

Add: Adds the selected product and quantity to the cart.
Remove: Removes a specified quantity of a product from the cart.
View: Displays the items currently in the cart along with their quantities and prices.
Total: Calculates and displays the total cost of all items in the cart.
Input Fields:

Quantity to Add: A text field where the user can enter the number of items they want to add to the cart.
Quantity to Remove: A text field where the user can specify how many units of the product they want to remove from the cart.
Output:

The applet should display a text area that shows the current cart items, including the product name, quantity, and total price.
There should be a label that displays the total cost of all items in the cart after clicking the "Total" button.
 */

import java.awt.*;
import java.awt.event.*;
import java.applet.Applet;

public class shop extends Applet implements ActionListener {

	Label l1, l2, l3, l4, l5;
	TextField t1, t2;
	Choice ch;
	Button b1, b2, b3, b4;
	TextArea tx;
	String msg2 = "";
	String prod[] = new String[3];
	int totProd[] = { 0, 0, 0 };
	String cart = "";
	String msg = "";
	int qnt;
	int totAmt;
	int price[] = { 50000, 40000, 100 };
	int sum = 0;

	public void init() {
		setLayout(null);

		ch = new Choice();
		ch.add("Iphone-15");
		ch.add("ASUS-LAP");
		ch.add("Remote");

		l1 = new Label("Select Product:");
		l2 = new Label("Enter Quantity:");
		l3 = new Label("Total Cost: ");
		l4 = new Label("Enter Quantity to Remove:");
		l5 = new Label("");
		t1 = new TextField(20);
		t2 = new TextField(10);

		b1 = new Button("Add");
		b2 = new Button("Remove");
		b3 = new Button("View");
		b4 = new Button("Total");

		tx = new TextArea(10, 80);

		l1.setBounds(30, 30, 100, 20);
		ch.setBounds(150, 30, 100, 20);
		l2.setBounds(30, 70, 100, 20);
		t1.setBounds(150, 70, 100, 20);

		l4.setBounds(30, 110, 160, 20);
		t2.setBounds(200, 110, 100, 20);

		b1.setBounds(30, 150, 80, 30);
		b2.setBounds(120, 150, 80, 30);
		b3.setBounds(210, 150, 80, 30);
		b4.setBounds(300, 150, 80, 30);

		tx.setBounds(30, 200, 350, 120);

		l3.setBounds(30, 340, 100, 20);
		l5.setBounds(150, 340, 100, 20);

		add(l1);
		add(ch);
		add(l2);
		add(t1);
		add(l4);
		add(t2);
		add(b1);
		add(b2);
		add(b3);
		add(b4);
		add(tx);
		add(l3);
		add(l5);

		b1.addActionListener(this);
		b2.addActionListener(this);
		b3.addActionListener(this);
		b4.addActionListener(this);
	}

	public void actionPerformed(ActionEvent e) {
		String s = e.getActionCommand();

		// Handling "Total" button
		if (s.equals("Total")) {
			sum = 0;
			for (int i = 0; i < totProd.length; i++) {
				sum += totProd[i];
			}
			l5.setText("Rs. " + sum);
			repaint();
		}

		if (s.equals("Add")) {
			cart = ch.getSelectedItem();
			try {
				qnt = Integer.parseInt(t1.getText());
				if (qnt > 0) {
					if (cart.equals("Iphone-15")) {
						totAmt = price[0] * qnt;
						prod[0] = "Iphone-15";
						totProd[0] = totAmt;
					} else if (cart.equals("ASUS-LAP")) {
						totAmt = price[1] * qnt;
						prod[1] = "ASUS-LAP";
						totProd[1] = totAmt;
					} else if (cart.equals("Remote")) {
						totAmt = price[2] * qnt;
						prod[2] = "Remote";
						totProd[2] = totAmt;
					}
					msg += "Selected item: " + cart + " | Quantity: " + qnt + " | Price: Rs. " + totAmt + "\n";
					msg2 = "Added: " + cart;
				} else {
					msg = "No quantity entered";
				}
				repaint();
			} catch (NumberFormatException ex) {
				msg = "Please enter a valid quantity";
			}
		}

		if (s.equals("Remove")) {
			cart = ch.getSelectedItem();
			try {
				int removeQuantity = Integer.parseInt(t2.getText());
				if (removeQuantity > 0) {
					if (cart.equals("Iphone-15")) {
						totProd[0] = Math.max(0, totProd[0] - price[0] * removeQuantity);
					} else if (cart.equals("ASUS-LAP")) {
						totProd[1] = Math.max(0, totProd[1] - price[1] * removeQuantity);
					} else if (cart.equals("Remote")) {
						totProd[2] = Math.max(0, totProd[2] - price[2] * removeQuantity);
					}
					msg += "Removed item: " + cart + " | Quantity: " + removeQuantity + "\n";
				} else {
					msg = "Invalid quantity for removal";
				}
				repaint();
			} catch (NumberFormatException ex) {
				msg = "Please enter a valid quantity to remove";
			}
		}

		// Handling "View" button
		if (s.equals("View")) {
			tx.setText(msg);
			repaint();
		}
	}

	public void paint(Graphics g) {
		g.drawString(msg2, 250, 370); // Showing added item message
	}
}

/* <applet code="shop.class" height="450" width="500"></applet> */
