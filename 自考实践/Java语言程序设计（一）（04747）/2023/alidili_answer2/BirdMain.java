package com.yangle.exam;

/**
 * ��������
 * 
 * @author ����
 *
 */
public class BirdMain {

	public static void main(String[] args) {
		Bird[] birdArray = new Bird[4];
		birdArray[0] = new XiQue(15, 1001);
		birdArray[1] = new XiQue(15, 1002);
		birdArray[2] = new GeZi(30, "С��");
		birdArray[3] = new GeZi(30, "����");
		for(int i=0;i<4;i++) {
			Bird bird = birdArray[i];
			if(bird instanceof XiQue) {
				XiQue xique = (XiQue)bird;
				System.out.println("ϲȵ�����������ǣ�" + xique.getDays() + 
						" �Ż����ǣ�" + xique.getCode());
			}else {
				GeZi gezi = (GeZi)bird;
				System.out.println("���ӵ����������ǣ�"+gezi.getDays() + 
						" ���������ǣ�" + gezi.getMasterName());
			}
		}
	}
}
