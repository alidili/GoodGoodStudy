package com.yangle.exam;

import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextField;

public class MainFrame extends JFrame {

	private static final long serialVersionUID = 1L;
	private JTextField mShow = new JTextField();
	private JTextField mResult = new JTextField();
	private JButton mButton0 = new JButton("0");
	private JButton mButton1 = new JButton("1");
	private JButton mButtonAdd = new JButton("+");
	private JButton mButtonResult = new JButton("=");

	public MainFrame() {
		initView();
		initListener();
	}

	private void initView() {
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setSize(450, 260);
		setLayout(null);
		setTitle("JavaÊµ¼ù¿¼ÊÔ");

		mShow.setBounds(40, 40, 270, 40);
		mShow.setEditable(false);
		add(mShow);

		mResult.setBounds(330, 40, 70, 40);
		mResult.setEditable(false);
		add(mResult);

		mButton0.setBounds(40, 120, 60, 40);
		add(mButton0);

		mButton1.setBounds(140, 120, 60, 40);
		add(mButton1);

		mButtonAdd.setBounds(240, 120, 60, 40);
		add(mButtonAdd);

		mButtonResult.setBounds(340, 120, 60, 40);
		add(mButtonResult);
	}

	private void initListener() {
		mButton0.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				mShow.setText(mShow.getText() + "0");
			}
		});
		mButton1.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				mShow.setText(mShow.getText() + "1");
			}
		});
		mButtonAdd.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				mShow.setText(mShow.getText() + "+");
			}
		});
		mButtonResult.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				String show = mShow.getText();
				String[] showArray = show.split("\\+");
				int firstNum = Integer.parseInt(showArray[0], 2);
				int secondNum = Integer.parseInt(showArray[1], 2);
				int result = firstNum & secondNum;
				mResult.setText(result + "");
			}
		});
	}

	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {

			@Override
			public void run() {
				new MainFrame().setVisible(true);
			}
		});
	}
}