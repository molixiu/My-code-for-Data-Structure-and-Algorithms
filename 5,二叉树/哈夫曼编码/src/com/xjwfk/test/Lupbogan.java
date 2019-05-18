package com.xjwfk.test;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.ArrayList;

import org.junit.Test;

import com.xjwfk.entity.HFcode;
import com.xjwfk.utils.HaffManUtils;

public class Lupbogan {
	
	@Test
	 public void test2() throws IOException {
		RandomAccessFile bis = new RandomAccessFile("C:\\C++基础\\day24_code\\讲师代码\\day24\\src\\cn\\itcast\\copy\\V4.exe","r");
		FileOutputStream out = new FileOutputStream("C:\\C++基础\\day24_code\\讲师代码\\day24\\src\\cn\\itcast\\copy\\加密.enc");
		
		ArrayList<HFcode<Byte,Byte>> secretKeyList = HaffManUtils.encryptFile(bis, out);
		
		bis.close();
		out.close();
		
		FileInputStream in = new FileInputStream("C:\\C++基础\\day24_code\\讲师代码\\day24\\src\\cn\\itcast\\copy\\加密.enc");
		FileOutputStream out1 = new FileOutputStream("C:\\C++基础\\day24_code\\讲师代码\\day24\\src\\cn\\itcast\\copy\\解密.exe");
		
		HaffManUtils.decryptFile(in, out1, secretKeyList);
		
		in.close();
		out1.close();
		
	 }
	
	@Test
	public void test1() throws IOException {
		byte a = 1;
		byte b = (byte)((a << 1) + 1);
		System.out.println(b);
	}
	
	public static void main(String[] args) throws IOException {
		String inFile = args[0];	
		String suffix = inFile.substring(inFile.lastIndexOf(".") + 1);//获取后缀名
		String encryptFile = args[1].concat("\\加密后的文件.enc");
		String decryptFile = args[1].concat("\\解密后的文件.").concat(suffix);
		System.out.println(encryptFile);
		System.out.println(decryptFile);
		
		RandomAccessFile bis = new RandomAccessFile(inFile,"r");
		FileOutputStream out = new FileOutputStream(encryptFile);
		ArrayList<HFcode<Byte,Byte>> secretKeyList = HaffManUtils.encryptFile(bis, out);
		bis.close();
		out.close();
		
		FileInputStream in = new FileInputStream(encryptFile);
		FileOutputStream out1 = new FileOutputStream(decryptFile);
		HaffManUtils.decryptFile(in, out1, secretKeyList);
		in.close();
		out1.close();
	}
}
