package com.yangle.exam;

/**
 * ����
 * 
 * @author ����
 *
 */
public class GeZi extends Bird {

	// ��������
	private String masterName;

	public GeZi(int days, String masterName) {
		super(days);
		this.masterName = masterName;
	}

	public String getMasterName() {
		return masterName;
	}
}
