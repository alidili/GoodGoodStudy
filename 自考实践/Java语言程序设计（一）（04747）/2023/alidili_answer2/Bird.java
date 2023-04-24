package com.yangle.exam;

/**
 * 鸟
 * 
 * @author 杨乐
 *
 */
public abstract class Bird {

	// 生长天数
	private int days;

	public Bird(int days) {
		super();
		this.days = days;
	}

	public int getDays() {
		return days;
	}
}
