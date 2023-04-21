package tech.yangle.test;

import java.util.ArrayList;

public class ReadBooksMain {

	public static void main(String[] args) {
		Reader reader = new Reader("小明", "18511349856");
		Book book = new Book("莎士比亚文集", "莎士比亚", 49.99);
		Book book1 = new Book("资本论", "马克思", 59.99);
		Book book2 = new Book("理想国", "柏拉图", 69.99);
		ArrayList<String> bookNameList = new ArrayList<>();
		bookNameList.add(book.getName());
		bookNameList.add(book1.getName());
		bookNameList.add(book2.getName());

		ReadBooks bookReader = new ReadBooks(bookNameList, reader.getName());
		bookReader.read();
		bookReader.showBooksNum();
	}
}
