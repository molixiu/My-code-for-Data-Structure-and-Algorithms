package com.xjwfk.entity;

import java.util.Comparator;

public class HFlistNode {
	private HFtreeNode hfNode;
	private int weight;
	/*比较器 可以得出集合中最小的元素*/
	public static final Comparator<HFlistNode> comparatorMin = new Comparator<HFlistNode>() {
		@Override
		public int compare(HFlistNode node1, HFlistNode node2) {
			return node1.getWeight() - node2.getWeight();
		}
	};
	
	
	public HFlistNode(HFtreeNode hfNode, int weight) {
		super();
		this.hfNode = hfNode;
		this.weight = weight;
	}
	public HFtreeNode getHfNode() {
		return hfNode;
	}
	public void setHfNode(HFtreeNode hfNode) {
		this.hfNode = hfNode;
	}
	public int getWeight() {
		return weight;
	}
	public void setWeight(int weight) {
		this.weight = weight;
	}
	
	
}
