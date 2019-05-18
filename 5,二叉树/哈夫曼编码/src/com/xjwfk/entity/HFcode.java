package com.xjwfk.entity;

public class HFcode<O,A> {
	public final O original_Code;
	public final A after_Code;
	
	public HFcode(O original_Code, A after_Code) {
		super();
		this.original_Code = original_Code;
		this.after_Code = after_Code;
	}

	public O getOriginal_Code() {
		return original_Code;
	}

	public A getAfter_Code() {
		return after_Code;
	}
	
	
}
