package tech.yangle.test;

import java.util.ArrayList;

public class ReadBooks {

	// ����
	private ArrayList<String> bookNameList;
	// ��������
	private String readerName;

	public ReadBooks(ArrayList<String> bookNameList, String readerName) {
		super();
		this.bookNameList = bookNameList;
		this.readerName = readerName;
	}

	/**
	 * ����
	 */
	public void read() {
		for (int i = 0; i < bookNameList.size(); i++) {
			System.out.println(readerName + " ��ʼ�� " + bookNameList.get(i));
		}
	}

	/**
	 * ��ʾ������
	 */
	public void showBooksNum() {
		System.out.println(readerName + " һ������ " + bookNameList.size() + " ����");
	}
}
