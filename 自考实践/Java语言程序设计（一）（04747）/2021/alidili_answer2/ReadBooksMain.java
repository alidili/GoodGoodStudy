package tech.yangle.test;

import java.util.ArrayList;

public class ReadBooksMain {

	public static void main(String[] args) {
		Reader reader = new Reader("С��", "18511349856");
		Book book = new Book("ɯʿ�����ļ�", "ɯʿ����", 49.99);
		Book book1 = new Book("�ʱ���", "���˼", 59.99);
		Book book2 = new Book("�����", "����ͼ", 69.99);
		ArrayList<String> bookNameList = new ArrayList<>();
		bookNameList.add(book.getName());
		bookNameList.add(book1.getName());
		bookNameList.add(book2.getName());

		ReadBooks bookReader = new ReadBooks(bookNameList, reader.getName());
		bookReader.read();
		bookReader.showBooksNum();
	}
}
