package tech.yangle.test;

public class Reader {
	// 读者姓名
	private String name;
	// 读者手机号
	private String phone;
	
	public Reader(String name, String phone) {
		super();
		this.name = name;
		this.phone = phone;
	}
	
	public String getName() {
		return name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public String getPhone() {
		return phone;
	}
	
	public void setPhone(String phone) {
		this.phone = phone;
	}
}
