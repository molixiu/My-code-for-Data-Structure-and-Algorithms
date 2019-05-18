package com.xjwfk.utils;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.RandomAccessFile;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;

import com.xjwfk.entity.HFcode;
import com.xjwfk.entity.HFlistNode;
import com.xjwfk.entity.HFtree;
import com.xjwfk.entity.HFtreeNode;

public class HaffManUtils {
	/*加密文件并把密钥返回*/
	public static ArrayList<HFcode<Byte,Byte>> encryptFile(RandomAccessFile in, OutputStream out) throws IOException {
		ArrayList<HFcode<Byte,Byte>> secretKeyList = HaffManModule.secretKeyList(in);
		in.seek(0);//把文件指针移到文件头
		byte[] buffer_read = new byte[1024];	//读的缓冲区
		byte[] buffer_write = new byte[1024];	//写的缓冲区
		int len = 0;
		while( (len = in.read(buffer_read)) != -1 ) {
			for(int i = 0,j; i < len; i++) {
				for( j = 0; j < secretKeyList.size() && buffer_read[i] != secretKeyList.get(j).original_Code; j++);
				buffer_write[i] = secretKeyList.get(j).after_Code;
			}
			out.write(buffer_write, 0, len);
		}
		
		return secretKeyList;
	}

	/*输入密钥解密文件*/
	public static void decryptFile(InputStream in, OutputStream out, ArrayList<HFcode<Byte, Byte>> secretKeyList) throws IOException {
		byte[] buffer_read = new byte[1024];	//读的缓冲区
		byte[] buffer_write = new byte[1024];	//写的缓冲区
		int len = 0;
		while( (len = in.read(buffer_read)) != -1 ) {
			for(int i = 0, j; i < len; i++) {
				for(j = 0; j < secretKeyList.size() && buffer_read[i] != secretKeyList.get(j).after_Code; j++);
				buffer_write[i] = secretKeyList.get(j).original_Code;
			}
			out.write(buffer_write, 0, len);
		}
	}

	static class HaffManModule{
		/*创建哈夫曼链表*/
		public static LinkedList<HFlistNode> create_HFList(RandomAccessFile in) throws IOException{
			if (in ==null) 
			return null;
			
			/*对输入文件的字节次数进行统计   出现多少次*/
			int[] priority = new int[256];
			int len;
			byte[] buffer = new byte[1024];
			while( (len =in.read(buffer)) != -1) {
				for(int i = 0; i < len; i++) {
					priority[ buffer[i] & 0xff ]++;
				}
			}
			
			//创建用于构建哈夫曼树的链表
			LinkedList<HFlistNode> hfList = new LinkedList<>();
			for(int i = 0; i < 256; i++) {
				if (priority[i] != 0) {
					HFtreeNode hFtreeNode = new HFtreeNode((byte) i);
					HFlistNode hFlistNode = new HFlistNode(hFtreeNode, priority[i]);
					hfList.add(hFlistNode);
				}
			}
			
		return hfList;
	}
		
		/*创建哈夫曼树*/
		public static HFtree create_HFtree(LinkedList<HFlistNode> hfList) {
			if (hfList == null) 
				return null;
			HFtree hfTree = new HFtree();
			link_hfTreeNode(hfList);
			hfTree.setRoot(hfList.peek().getHfNode());
			return hfTree;
		}
		
		/*把哈夫曼链表的节点消耗，只留一个节点*/
		public static void link_hfTreeNode(LinkedList<HFlistNode> hfList) {
			if (hfList == null)
				return;
			if(hfList.size() < 2)
				return;
			
			/*获取链表最小的两个节点并移除它们*/
			HFlistNode min1 = Collections.min(hfList,HFlistNode.comparatorMin);
			HFtreeNode hfTreeNode1 = min1.getHfNode();
			hfList.remove(min1);
			HFlistNode min2 = Collections.min(hfList,HFlistNode.comparatorMin);
			HFtreeNode hfTreeNode2 = min2.getHfNode();
			hfList.remove(min2);
			
			/*创建新节点并加入到链表中*/
			int new_weight = min1.getWeight() + min2.getWeight();
			HFtreeNode new_hfTreeNode = new HFtreeNode(hfTreeNode1, hfTreeNode2);
			HFlistNode new_hfListNode = new HFlistNode(new_hfTreeNode, new_weight);
			hfList.add(new_hfListNode);
			
			link_hfTreeNode(hfList);
		}
		
		/*根据哈夫曼树创建一个用于加密解密的密钥数组*/
		public static ArrayList<HFcode<Byte, Byte>> create_secretKey(HFtree hfTree){
			if (hfTree == null) 
				return null;
			if(hfTree.getRoot() == null)
				return null;
			if(hfTree.getRoot().getLeft() == null || hfTree.getRoot().getRight() == null)
				return null;
			
			ArrayList<HFcode<Byte, Byte>> secretKeyList = new ArrayList<>(); 
			
			link_secretKeyNode(secretKeyList,hfTree.getRoot().getLeft(),(byte)0,(byte)7);
			link_secretKeyNode(secretKeyList,hfTree.getRoot().getRight(),(byte)1,(byte)7);
			return secretKeyList;
		}
		
		/*创建密钥数组的节点*/
		public static void link_secretKeyNode(ArrayList<HFcode<Byte, Byte>> secretKeyList, HFtreeNode hftreeNode, byte value, byte leftShift_size) {
			if (hftreeNode.getLeft() == null && hftreeNode.getRight() == null) {//是叶子节点就停止递归
				byte original_Code = hftreeNode.getSymbol();
				byte after_Code = (byte)(value << leftShift_size);
				HFcode<Byte, Byte> hFcode = new HFcode<Byte, Byte>(original_Code, after_Code);
				secretKeyList.add(hFcode);
				return;
			}
			
			/*分别递归左子树和右子树完成密钥的生成*/
			link_secretKeyNode(secretKeyList, hftreeNode.getLeft(), (byte)(value << 1),(byte)(leftShift_size-1));
			link_secretKeyNode(secretKeyList, hftreeNode.getRight(), (byte)((value<< 1) + 1),(byte)(leftShift_size-1));
		}
		
		/*根据用户传来的文件生成密钥数组并返回*/
		public static  ArrayList<HFcode<Byte, Byte>> secretKeyList(RandomAccessFile in) throws IOException{
			LinkedList<HFlistNode> hfList = create_HFList(in);
			HFtree hFtree = create_HFtree(hfList);
			ArrayList<HFcode<Byte,Byte>> secretKeyList = create_secretKey(hFtree);
			return secretKeyList;
		}
	}
	
	
}
