package com.yangle.exam;

/**
 * 鸽子
 * 
 * @author 杨乐
 *
 */
public class GeZi extends Bird {

	// 主人姓名
	private String masterName;

	public GeZi(int days, String masterName) {
		super(days);
		this.masterName = masterName;
	}

	public String getMasterName() {
		return masterName;
	}
}
