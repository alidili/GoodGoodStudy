package tech.yangle.test;

import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

public class MainFrame extends JFrame {

	private static final long serialVersionUID = 1L;
	private static MainFrame mainFrame;
	private JLabel mLabel1 = new JLabel("�������һ���ַ�����");
	private JTextField mInputString1 = new JTextField();
	private JLabel mLabel2 = new JLabel("������ڶ����ַ�����");
	private JTextField mInputString2 = new JTextField();
	private JLabel mResultLabel = new JLabel("�����");
	private JTextField mResultField = new JTextField();
	private JButton mAnalysis = new JButton("����");
	private JButton mClose = new JButton("�ر�");

	public MainFrame() {
		initView();
		initListener();
	}

	private void initView() {
		// �رհ�ť�¼�
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		// ���ò��ִ�С
		setSize(600, 350);
		setLayout(null);
		setTitle("���� Javaʵ��");

		// ���
		mLabel1.setBounds(20, 20, 150, 30);
		add(mLabel1);

		mInputString1.setBounds(170, 20, 390, 30);
		add(mInputString1);

		mLabel2.setBounds(20, 70, 150, 30);
		add(mLabel2);

		mInputString2.setBounds(170, 70, 390, 30);
		add(mInputString2);

		mResultLabel.setBounds(20, 120, 150, 30);
		add(mResultLabel);

		mResultField.setBounds(170, 120, 390, 30);
		mResultField.setEditable(false);
		add(mResultField);

		mAnalysis.setBounds(80, 220, 200, 30);
		add(mAnalysis);

		mClose.setBounds(320, 220, 200, 30);
		add(mClose);
	}

	private void initListener() {
		mAnalysis.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				String input1 = mInputString1.getText();
				String input2 = mInputString2.getText();
				if (input1.isEmpty() || input2.isEmpty()) {
					return;
				}
				if (input1.length() > input2.length()) {
					if (input1.contains(input2)) {
						mResultField.setText(input1 + " �а��� " + input2 + ", ��ʼλ�ã�" + input1.indexOf(input2));
					} else {
						mResultField.setText(input1 + " �в����� " + input2);
					}
				} else {
					if (input2.contains(input1)) {
						mResultField.setText(input2 + " ���� " + input1 + ", ��ʼλ�ã�" + input2.indexOf(input1));
					} else {
						mResultField.setText(input2 + " �в����� " + input1);
					}
				}
			}
		});
		mClose.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				mainFrame.dispose();
				System.exit(0);
			}
		});
	}

	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {

			@Override
			public void run() {
				mainFrame = new MainFrame();
				mainFrame.setVisible(true);
			}
		});
	}
}
