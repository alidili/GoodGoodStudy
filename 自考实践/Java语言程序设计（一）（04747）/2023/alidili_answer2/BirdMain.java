package com.yangle.exam;

/**
 * 主方法类
 * 
 * @author 杨乐
 *
 */
public class BirdMain {

	public static void main(String[] args) {
		Bird[] birdArray = new Bird[4];
		birdArray[0] = new XiQue(15, 1001);
		birdArray[1] = new XiQue(15, 1002);
		birdArray[2] = new GeZi(30, "小明");
		birdArray[3] = new GeZi(30, "老王");
		for(int i=0;i<4;i++) {
			Bird bird = birdArray[i];
			if(bird instanceof XiQue) {
				XiQue xique = (XiQue)bird;
				System.out.println("喜鹊的生长天数是：" + xique.getDays() + 
						" 脚环码是：" + xique.getCode());
			}else {
				GeZi gezi = (GeZi)bird;
				System.out.println("鸽子的生长天数是："+gezi.getDays() + 
						" 主人姓名是：" + gezi.getMasterName());
			}
		}
	}
}
