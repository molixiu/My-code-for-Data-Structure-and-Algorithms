package com.xjwfk.entity;

public class HFtreeNode {
	private byte symbol;
	private HFtreeNode left;
	private HFtreeNode right;
	
	public HFtreeNode(HFtreeNode left, HFtreeNode right) {
		super();
		this.left = left;
		this.right = right;
	}
	public HFtreeNode(byte symbol) {
		super();
		this.symbol = symbol;
	}
	public HFtreeNode() {
		super();
		// TODO Auto-generated constructor stub
	}
	public byte getSymbol() {
		return symbol;
	}
	public void setSymbol(byte symbol) {
		this.symbol = symbol;
	}
	public HFtreeNode getLeft() {
		return left;
	}
	public void setLeft(HFtreeNode left) {
		this.left = left;
	}
	public HFtreeNode getRight() {
		return right;
	}
	public void setRight(HFtreeNode right) {
		this.right = right;
	}
	
	
}
