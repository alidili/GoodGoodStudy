package tech.yangle.test;

import java.util.ArrayList;

public class ReadBooks {

	// 书名
	private ArrayList<String> bookNameList;
	// 读者姓名
	private String readerName;

	public ReadBooks(ArrayList<String> bookNameList, String readerName) {
		super();
		this.bookNameList = bookNameList;
		this.readerName = readerName;
	}

	/**
	 * 读书
	 */
	public void read() {
		for (int i = 0; i < bookNameList.size(); i++) {
			System.out.println(readerName + " 开始读 " + bookNameList.get(i));
		}
	}

	/**
	 * 显示读书量
	 */
	public void showBooksNum() {
		System.out.println(readerName + " 一共读了 " + bookNameList.size() + " 本书");
	}
}
